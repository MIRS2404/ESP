//ペルチェ温度管理
void pelTask(void *pvParameters) {
  while (1) {
    if (temp >= 5) {
      peltier();
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

//くみ上げ用ポンプ
void pompTask(void *pvParameters) {
  while (1) {
    pomp();
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

//ミニタンク温度監視
void thermistorTask(void *pvParameters) {
  while (1) {
    thermistor();
    vTaskDelay(30000 / portTICK_PERIOD_MS);
  }
}

void multi_setup() {
  pinMode(PIN_PEL_DIR, OUTPUT);
  pinMode(PIN_PEL_PWM, OUTPUT);
  pinMode(PIN_SERVO, OUTPUT);
  pinMode(PIN_POMP_DIR, OUTPUT);
  pinMode(PIN_POMP_PWM, OUTPUT);

  ledcSetup(pomp_Channel, pwmFrequency, pwmResolution);
  ledcSetup(pel_Channel, pwmFrequency, pwmResolution);
  ledcAttachPin(PIN_POMP_PWM, pomp_Channel);
  ledcAttachPin(PIN_PEL_PWM, pel_Channel);

  ledcSetup(servo_Channel, servo_Freq, servo_Resolution);
  ledcAttachPin(PIN_SERVO, servo_Channel);

  // タスクの作成
  xTaskCreate(
    pelTask,     // タスク関数
    "pel Task",  // タスク名
    2048,        // スタックサイズ（バイト数）
    NULL,        // 引数
    0,           // 優先度
    NULL         // タスクハンドル
  );

  xTaskCreate(
    thermistorTask,
    "thermistor Task",
    2048,
    NULL,
    0,
    NULL
  );


  xTaskCreate(
    pompTask,
    "pomp Task",
    2048,
    NULL,
    1,
    NULL
  );
}
