#include <micro_ros_arduino.h>
#include <stdio.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <std_msgs/msg/int32_multi_array.h>
#include <geometry_msgs/msg/twist.h>
#include <mirs_msgs/srv/parameter_update.h>
#include <mirs_msgs/srv/simple_command.h>
#include <mirs_msgs/msg/basic_param.h>
#include <std_msgs/msg/float64_multi_array.h>
#include "config.h"

std_msgs__msg__Int32MultiArray enc_msg;               //エンコーダー情報
std_msgs__msg__Float64MultiArray vlt_msg;             //電圧情報
std_msgs__msg__Float64MultiArray curr_vel_msg;        //速度情報
geometry_msgs__msg__Twist cmd_vel_msg;                //速度指令値
mirs_msgs__msg__BasicParam param_msg;                 //パラメーターメッセージ
mirs_msgs__srv__ParameterUpdate_Response update_res;  
mirs_msgs__srv__ParameterUpdate_Request update_req;
mirs_msgs__srv__SimpleCommand_Response reset_res;
mirs_msgs__srv__SimpleCommand_Request reset_req;
//追加
mirs_msgs__srv__SimpleCommand_Response water_res;
mirs_msgs__srv__SimpleCommand_Request water_req;

rcl_publisher_t enc_pub;
rcl_publisher_t vlt_pub;
rcl_publisher_t curr_vel_pub;
rcl_subscription_t cmd_vel_sub;
rcl_subscription_t param_sub;
rcl_service_t update_srv;
rcl_service_t reset_srv;
//追加
rcl_service_t water_srv;
//

rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;
rcl_timer_t timer;

//エンコーダーカウント
int32_t count_l = 0;
int32_t count_r = 0;

int32_t prev_count_l = 0;
int32_t prev_count_r = 0;

//PID制御用の変数
double r_vel_cmd;
double l_vel_cmd;
double r_vel;
double l_vel;

float linear_x;   //  直進速度
float angular_z;  //  回転速度

float r_err_sum = 0;
float l_err_sum = 0;

float prev_r_err = 0;
float prev_l_err = 0;

double vlt_1 = 0;
double vlt_2 = 0;

//マルチタスク用の変数
int count = 0;
int cup = 13320;  //1杯分のエンコーダー読み取り値
int n_cup;
int32_t count_w;
float temp;


void setup() {
  ros_setup();

  encoder_open();
  vel_ctrl_set();
  vlt_setup();
  multi_setup();

  delay(500);
}

void loop() {
  servo();
  delay(1000);
}