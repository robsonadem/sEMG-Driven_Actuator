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
