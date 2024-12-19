void pomp(){
  while(countt != 0){
    W_encoder_reset();
    while (count_w < cup) {
      ledcWrite(pomp_Channel,107);
      vTaskDelay(10 / portTICK_PERIOD_MS);
    }
    ledcWrite(pomp_Channel,0);
    countt--;
  }
}