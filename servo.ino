void servo() {
  //開栓
  int duty = angleToDuty(45); // 0度のデューティサイクル計算
  ledcWrite(servo_Channel, duty);
  delay(1000);

  //閉栓
  duty = angleToDuty(0); // 90度のデューティサイクル計算
  ledcWrite(servo_Channel, duty);
  delay(100);
  count++;
}

int angleToDuty(int angle) {
  int minDuty = 1638; // 0度に対応するデューティ（500µs）
  int maxDuty = 8192; // 180度に対応するデューティ（2400µs）
  return map(angle, 0, 180, minDuty, maxDuty);
}
