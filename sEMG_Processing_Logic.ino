*+----------------------------------------------------------------------
 ||
 ||         Author:  Robson Adem
 ||
 ||        Purpose:  This arduino code is made for sEMG signal processing hardware. 
 ||                  It reads the sEMG signal and performs a control. 
 ||
*+----------------------------------------------------------------------
int sensorValueThreshold = 400;
int LED=5;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  Serial.print(sensorValue);
  if (sensorValue > sensorValueThreshold){
    Serial.println("---CONTRACTION DETECTED");
    digitalWrite(LED, HIGH);
  }
  else{
    Serial.println("");
    digitalWrite(LED, LOW);
  }
  delay(100);
}





