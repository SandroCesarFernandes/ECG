void setup() {
  Serial.begin(9600);
  pinMode(34,INPUT);
  pinMode(35,INPUT);
 

}

void loop() {
  if((digitalRead(34) == 1)||(digitalRead(35) == 1)){
    Serial.println('!');
  }
  else{
    // send the value of analog input 0:
    int val = analogRead(A0);
    val = map(val, 0, 1900, 0, 128);
      Serial.println(val);
  }
  //Wait for a bit to keep serial data from saturating
  delay(20);
}
