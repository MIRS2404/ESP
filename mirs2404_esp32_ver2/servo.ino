void servo() {
 //開栓
  // サーボを0度に移動
  int duty = angleToDuty(180); // 0度に対応するデューティサイクル
  ledcWrite(servo_Channel, duty);
  delay(1000);

  // サーボを90度に移動
  duty = angleToDuty(0); // 90度に対応するデューティサイクル
  ledcWrite(servo_Channel, duty);
  delay(100);

  countt += cup;
}

int angleToDuty(int angle) {
  int minDuty = 1638; // 0度（約500µs）に対応するデューティ値
  int maxDuty = 8192; // 180度（約2400µs）に対応するデューティ値
  return map(angle, 0, 180, minDuty, maxDuty);
}
