#define PIN_ENC_A_L 34
#define PIN_ENC_B_L 35
#define PIN_ENC_A_R 32
#define PIN_ENC_B_R 25

//足回り用モータードライバー用
#define PIN_DIR_R   26
#define PIN_PWM_R   24
#define PIN_DIR_L   14
#define PIN_PWM_L   12

#define PIN_BATT_1  27  //メインバッテリー
#define PIN_BATT_2  4   //サブバッテリー

#define ROS_DOMAIN_ID 4

//水回り用
#define PIN_ENC_A_W   20
#define PIN_ENC_B_W   19
#define PIN_PEL     13
#define PIN_POMP    11
#define PIN_SERVO   10

//足回り速度制御用
double RKP = 172.5;
double RKI = 87.0;
double RKD = 18.5;
double LKP = 172.5;
double LKI = 87.0;
double LKD = 18.5;

//車体数値
#define COUNTS_PER_REV    4096.0
double WHEEL_RADIUS = 0.04;  //ホイール径
double WHEEL_BASE = 0.38;  //車輪間幅

// PWM設定
const int32_t r_Channel = 0;        // PWMチャンネル
const int32_t l_Channel = 1;
const int32_t pwmFrequency = 5000; // PWM周波数 (5kHz)
const int32_t pwmResolution = 8;   // PWM分解能 (8ビット = 0-255)
