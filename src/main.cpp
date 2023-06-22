#include <Arduino.h>
#include <AccelStepper.h>              

AccelStepper stepper(AccelStepper::FULL4WIRE,33,32,25,14,true);  // 4 wire full stepper
long steering_val=0;

void setup() {
  /*
  Hier evtl. IN- bzw. OUTPUTS deklarieren, sollte jedoch in der AccelStepper Library automatisch passieren
  */
  stepper.setAcceleration(5000);        // Acceleration in steps/s^2
  stepper.setMaxSpeed(5000);            // Speed in steps/s
  stepper.setSpeed(2000);
  stepper.enableOutputs();
  //stepper.setOutputPins(AccelStepper::FULL4WIRE);
  stepper.setMinPulseWidth(20);         // 20 microseconds
}

void loop() 
{
  //if(uart.any())
  //{ 
      stepper.moveTo(steering_val*(-10)); // negative anticlockwise
      while(stepper.distanceToGo()!=0)
      {
        stepper.run();
      }
  //}
} 
