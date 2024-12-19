#define PIN_ENC_A_L 39
#define PIN_ENC_B_L 36
#define PIN_ENC_A_R 35
#define PIN_ENC_B_R 34

//足回り用モータードライバー用
#define PIN_DIR_R   25
#define PIN_PWM_R   26
#define PIN_DIR_L   32
#define PIN_PWM_L   33

#define PIN_BATT_1  27
#define PIN_BATT_2  4

#define ROS_DOMAIN_ID 4

//水回り用
#define PIN_ENC_A_W   26
#define PIN_ENC_B_W   17
#define PIN_PEL_DIR   23
#define PIN_PEL_PWM   22
#define PIN_POMP_PWM  18
#define PIN_POMP_DIR  19
#define PIN_SERVO     21
#define PIN_THERMISTOR    15
//サーミスタ用
#define SERIES_RESISTOR     16000   // 分圧用固定抵抗(Ω)
#define THERMISTOR_NOMINAL  10000   // サーミスタ抵抗(Ω)
#define TEMPERATURE_NOMINAL 25      // 公称温度(℃)
#define B_COEFFICIENT       3435    // サーミスタのB定数
#define ADC_MAX             4095    // ADC分解能


//足回り速度制御用
double RKP = 172.5;
double RKI = 87.0;
double RKD = 18.5;
double LKP = 172.5;
double LKI = 87.0;
double LKD = 18.5;

//車体数値
#define COUNTS_PER_REV    4096.0
double WHEEL_RADIUS = 0.04;   //ホイール径(ｍ)
double WHEEL_BASE = 0.38;     //車輪間幅(ｍ)

// PWM設定
#define servo_Freq 50          // サーボ用PWM周波数（50Hz）
#define servo_Resolution 16    // PWM分解能（16ビット）
const int32_t servo_Channel = 4;
const int32_t r_Channel = 2;        // 右モータ用PWMチャンネル
const int32_t l_Channel = 3;        // 左モータ用PWMチャンネル
const int32_t pomp_Channel = 4;     // ポンプ用PWMチャンネル
const int32_t pel_Channel = 5;      // ペルチェ用PWMチャンネル
const int32_t pwmFrequency = 5000;  // PWM周波数 (5kHz)
const int32_t pwmResolution = 8;    // PWM分解能 (8ビット = 0-255)
