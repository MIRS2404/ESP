void pomp(int n){
  W_encoder_reset();

  n_cup = n*cup; //必要回転数の計算

  while(count == 0){
    while (count_w < n_cup) {
      ledcWrite(0,107);
      delay(10);
    }
    count--;
  }
}