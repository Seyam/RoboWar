#include <SoftwareSerial.h>
SoftwareSerial mySerial(4, 2); // RX, TX

const int led=12;

String command = ""; // Stores response of the HC-06 Bluetooth device



int motorA1=6;
int motorA2=7;

int motorB1=8;
int motorB2=9;

int speedA=10;
int speedB=11;




void setup(){
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  pinMode(speedA, OUTPUT);
  pinMode(speedB, OUTPUT);

  pinMode(led,OUTPUT);

  
  Serial.begin(9600);
  Serial.println("Enter your command.");
    
  mySerial.begin(9600); // The HC-06 defaults to 9600 according to the datasheet.
}

void loop(){
  // Read device output if available.
  if (mySerial.available()) {
    while(mySerial.available()) { // While there is more to be read, keep reading.
      command += (char)mySerial.read();
    }
    
    Serial.println(command);


    
    if(command=="1"){
      MotorAForward();
      Serial.println("MotorAForward");
    }
    else if(command=="2"){
      MotorBForward();
      Serial.println("MotorBForward");
    }
    else if(command=="3"){
      MotorBBackward();
      Serial.println("MotorBBackward");
    }
    else if(command=="4"){
      MotorABackward();
      Serial.println("MotorABackward");
    }
    else if(command=="5"){
      MotorAStop();
      Serial.println("MotorAStop");
    }
    else if(command=="6"){
      MotorBStop();
      Serial.println("MotorBStop");
    }

    
    
    command = ""; // No repeats
  }



    // Read user input if available.
  // if (Serial.available()){
  //   delay(10); // The delay is necessary to get this working!
  //   mySerial.write(Serial.read());
  // }

}





  void MotorAForward(){
    analogWrite(speedA,128);
    digitalWrite(motorA1,LOW);
    digitalWrite(motorA2,HIGH); 
  }

  void MotorABackward(){
      analogWrite(speedA,128);
      digitalWrite(motorA1,HIGH);
      digitalWrite(motorA2,LOW);
  }

  void MotorAStop(){
      analogWrite(speedA,0);
      digitalWrite(motorA1,LOW);
      digitalWrite(motorA2,LOW);
  }




  void MotorBForward(){
      analogWrite(speedB,128);                                                                   
      digitalWrite(motorB1,LOW);
      digitalWrite(motorB2,HIGH);
  }

  void MotorBBackward(){
      analogWrite(speedB,128);
      digitalWrite(motorB1,HIGH);
      digitalWrite(motorB2,LOW);
  }

  void MotorBStop(){
      analogWrite(speedB,0);
      digitalWrite(motorB1,LOW);
      digitalWrite(motorB2,LOW);
  }