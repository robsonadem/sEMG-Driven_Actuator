    
/********************************************************
  Sketch title:  sEMG Processing Logic

  Reads signal from Mayo Muscle Sensor and Processes signal 
       to decide if a muscle has been contracted or not based 
        on a treshold.

         Using this processing, the sketch provides high voltage
         for two seconds, heating up the actuator, and low voltage 
         for 20 seconds to cool down the actuator

  The circuit:
  
   Mayo Muscle Sensor
            3 outputs- 
                  Signal --> A0
                   +     --> Vs
                   -     -->  GND
   Led
           pin 5

  Author: Robson Adem (ademr@lafayette.edu)

 

***************************************************/
byte pinActuator1 = 7;// pick any pin for voltage supply
byte LED = 5;// pick any pin for led
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);// led setup
  pinMode(pinActuator1, OUTPUT);// voltage supply setup
}

void loop() {
  boolean isContracted = emgControl(A0, LED, 200);// method to process emg signal 
  if (isContracted) {
    digitalWrite(pinActuator1, HIGH);
    delayControl(2, " APPLYING HIGH VOLTAGE FOR ");// 2 sec high voltage, heating
    digitalWrite(pinActuator1, LOW);//20 sec high voltage, cooling
    digitalWrite(LED, LOW);
    delayControl(20, "---RESTART IN ");// method to count sec and print message whilst 
  }
}

/**
 *  emgControl reads emg signal and decides true or false if muscle is contracted or not
 * @parameter  char analogPin --a pin connected to the emg signal output
 * @parameter  char Led - pin for the led
 * @parameter  int -- signal treshold 
 * @return     true or false
 */
boolean emgControl(char analogPin, char LED, int sensorValueThreshold) {

  // read the input on analog pin :
  int sensorValue = analogRead(analogPin);
  Serial.print(sensorValue);
  if (sensorValue > sensorValueThreshold) {
    Serial.println("---CONTRACTION DETECTED");
    digitalWrite(LED, HIGH);
    delay(1000);
    return true;
  }
  else {
    Serial.println("");
    digitalWrite(LED, LOW);
    delay(1000);
    return false;
  }

}

/**
 *  delayControl delays the system for the given sec and prints message while doing it
 * @parameter  byte secs --seconds for delay
 * @parameter  String msg--message to be printed
 */
void delayControl(byte secs, String msg) {
  for (byte i = 0; i < secs; i++) {
    byte s = secs - i;
    Serial.println("------" + msg + s + " secs");
    delay(1000);
  }
}


