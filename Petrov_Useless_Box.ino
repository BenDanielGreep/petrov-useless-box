#include <Servo.h>                        //load the servo library

Servo handServo;                          //define the two servos as servos
Servo boxServo;

int switchStatus=0, action=1, vot, randNumber=0;                   //set the initial statuses of the pins
const int ledPin = 13;                    //set the pins
const int frontSwitchPin = 2;
const int handServoPin = 6;
const int boxServoPin = 5;

const int redLed = 10; // bulgaria LEDs
const int greenLed = 9; // bulgaria LEDs
const int whiteLed = 8;  // bulgaria LEDs


void setup()
{
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);                  //define LED pin as output
  pinMode(redLed, OUTPUT); //output
  pinMode(greenLed, OUTPUT); //output
  pinMode(whiteLed, OUTPUT); //output
  digitalWrite(ledPin,HIGH);
  
  handServo.attach(handServoPin);              //define servo signal pin
  boxServo.attach(boxServoPin);
  handServo.write(180);                        //servo reset
  boxServo.write(70);

  digitalWrite(redLed, HIGH);                  // bulgaria LED flash
  delay(1000);
  digitalWrite(redLed, LOW);
  
  digitalWrite(greenLed, HIGH);
  delay(1000);
  digitalWrite(greenLed, LOW);

  digitalWrite(whiteLed, HIGH);
  delay(1000);
  digitalWrite(whiteLed, LOW);
  delay(500);

  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, HIGH);
  digitalWrite(whiteLed, HIGH);
  delay(250);
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(whiteLed, LOW);
  delay(250);

  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, HIGH);
  digitalWrite(whiteLed, HIGH);
  delay(250);
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(whiteLed, LOW);
  delay(250);

  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, HIGH);
  digitalWrite(whiteLed, HIGH);
  delay(250);
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(whiteLed, LOW);
  delay(250);

}


void loop()
{
  switchStatus = digitalRead(frontSwitchPin); //read switch status


  if (switchStatus == LOW){                   //action==1 and action++ are used to cycle through the different actions
     digitalWrite(ledPin,LOW);

    if (action == 1)
    {
      Serial.println("Action 1");           //The first one is normal
      
      delay(200);
      for (int i = 70; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      handServo.write(28); // was 26. 28 is better. depends on the motor mount which can move a little
      
      delay(550);
      handServo.write(180);
      delay(400); //was 500
      boxServo.write(70);
//      action = 1; //changed from line below for testing
      action++;
  }
    
    
    else if (action == 2)
     {
      Serial.println("Action 2");           //The second one is normal also
      
      delay(200);
      for (int i = 70; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      handServo.write(28);
      
      delay(550);
      handServo.write(180);
      delay(400); //was 500
      boxServo.write(70);
//      action = 1; //changed from line below for testing
      action++;
  }
    
    else if (action == 3)
    {
      Serial.println("Action 1");           //look up slowly and turn off the switch slowly
      for (int i = 70; i <= 110; i++)
      {
        boxServo.write(i);
        delay(10);
      }
      for (int i = 180; i >= 35; i--)
      {
        handServo.write(i);
        delay(10);
      }
      delay(1000);
      handServo.write(26);
      delay(200);
      for (int i = 26; i <=180; i++)
      {
        handServo.write(i);
        delay(10);
      }
      for (int i = 110; i >= 70; i--)
      {
        boxServo.write(i);
        delay(10);
      }
      action++;
    }
    
   
   else if (action == 4)
   {
      Serial.println("Action 2");           //The fourth one, looks at it, then closes, then waits to close. Getting grumpy
      for (int i = 70; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      } 
      delay(1200);
      
      handServo.write(28);
      
      delay(550);
      handServo.write(180);
      delay(1000); //was 500
      boxServo.write(70);
      action++;
    }   


    else if (action == 5)
{
      Serial.println("Action 5");       //The fifth type: look up and wave to protest, and look after
      for (int i = 70; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(1000);
      handServo.write(40); //was 65
      delay(750);
      handServo.write(33);
      delay(200);
      handServo.write(40);
      delay(200);
      handServo.write(33);
      delay(200);
      handServo.write(40);
      delay(200);
      handServo.write(33);
      delay(200);
      handServo.write(40);
      delay(200);
      handServo.write(33);
      delay(200);
      handServo.write(40);
      delay(200);
      handServo.write(33);
      delay(200);
      handServo.write(40);
      delay(1000);
      handServo.write(26);
      delay(400);
      handServo.write(180);
      delay(400);
      boxServo.write(70);
      // look after
      delay(1500);
      for (int i = 70; i <= 110; i++){
        boxServo.write(i);
        delay(6);
      }
      delay(3000);
      boxServo.write(70);
      
      action++;
    }
//    
    else if (action == 6)             
    {
      Serial.println("Action 6");       //HEAD SLAMS Sixth, look up, then drop the box, turn off the switch, and look at it
      for (int i = 70; i <110; i++)
      {
        boxServo.write(i);
        delay(20);
      }
      delay(1000);
      for (int i = 0; i < 5; i++)       // slam the lid 5 times
      {
        for (int j = 70; j <= 110; j++){
          boxServo.write(j);
          delay(6);
        }
        delay(200);
      }
      for (int i = 180; i >= 35; i--)
      {
        handServo.write(i);
        delay(6);
      }
      handServo.write(26);
      delay(400);
      handServo.write(180);
      delay(400);
      boxServo.write(70);
      
      action++;
    }
    
    else if (action == 7)           // slam lid twice, close normally, hold hand over switch after and close slowly
    {
       Serial.println("Action 7");
       for (int i = 70; i <110; i++)
      {
        boxServo.write(i);
        delay(10);
      }
      delay(200);
      for (int i = 0; i < 2; i++)       // slam the lid 2 times
      {
        for (int j = 70; j <= 110; j++){
          boxServo.write(j);
          delay(6);
        }
        delay(200);
      }
                                           // then close normally
//        delay(1000);
//      for (int i = 70; i <= 110; i++){
//        boxServo.write(i);
//        delay(6);
//      }
      
      handServo.write(28); 
      
      delay(550);
      handServo.write(180);
      delay(400); //was 500
      boxServo.write(70);                 
      delay(2000);                        // after closing, wait 2s

      for (int i = 70; i <= 110; i++){     // hold over the switch after
      boxServo.write(i);
      delay(6);
      }
      handServo.write(33); 
      
      delay(3000);                       //hold over for 3s
      for (int i = 33; i <=100; i++)        // retreat slowly
      {
        handServo.write(i);
        delay(30);
      }
      for (int i = 100; i <=180; i++)        // retreat slowly
      {
        handServo.write(i);
        delay(6);
      }
      for (int i = 110; i >= 70; i--)
      {
        boxServo.write(i);
        delay(20);
      }               

      action = 1;

   }
    
//    else if (action == 8) {
//      add more functions here 
//    }

  }
  
}
