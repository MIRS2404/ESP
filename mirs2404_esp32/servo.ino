void servo() {
  myServo.write(180);
  delay(1000);

  myServo.write(0);
  delay(100);
  count++;
}