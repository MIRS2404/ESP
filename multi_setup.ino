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
    pomp(count);
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

//駆動系管理
void moveTask(void *pvParameters) {
  while (1) {
    rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
    vTaskDelay(10 / portTICK_PERIOD_MS);  // 1秒待機
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
  //pinMode(PIN_PEL, OUTPUT);
  //pinMode(PIN_POMP, OUTPUT);
  ledcSetup(servo_Channel, servo_Freq, servo_Resolution);
  ledcSetup(pomp_Channel, pwmFrequency, pwmResolution);
  ledcSetup(pel_Channel, pwmFrequency, pwmResolution);
  ledcAttachPin(PIN_SERVO, servo_Channel);
  ledcAttachPin(PIN_POMP, pomp_Channel);
  ledcAttachPin(PIN_PEL, pel_Channel);

  // タスクの作成
  xTaskCreate(
    pelTask,     // タスク関数
    "pel Task",  // タスク名
    1024,        // スタックサイズ（バイト数）
    NULL,        // 引数
    0,           // 優先度
    NULL         // タスクハンドル
  );

  xTaskCreate(
    thermistorTask,
    "thermistor Task",
    1024,
    NULL,
    0,
    NULL
  );

  xTaskCreate(
    moveTask,
    "Move Task",
    4096,
    NULL,
    2,
    NULL
  );

  xTaskCreate(
    pompTask,
    "pomp Task",
    1024,
    NULL,
    1,
    NULL
  );
}
