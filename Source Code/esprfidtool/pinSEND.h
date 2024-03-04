void pinSEND(int pinDELAY,String pinBIN) {
  for (int i=0; i<=pinBIN.length(); i++) {
    if (pinBIN.charAt(i) == '0') {
      digitalWrite(DATA0, LOW);
      digitalWrite(DATA0_MOS, HIGH);
      delayMicroseconds(txdelayus);
      digitalWrite(DATA0, HIGH);
      digitalWrite(DATA0_MOS, LOW);
    }
    else if (pinBIN.charAt(i) == '1') {
      digitalWrite(DATA1, LOW);
      digitalWrite(DATA1_MOS, HIGH);
      delayMicroseconds(txdelayus);
      digitalWrite(DATA1, HIGH);
      digitalWrite(DATA1_MOS, LOW);
    }
    delay(txdelayms);
  }
  yield();
  delay(pinDELAY);
  pinBIN="";
  pinDELAY=100;
}
