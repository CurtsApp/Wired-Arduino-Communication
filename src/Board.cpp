/*
Board.cpp - Library created for wired communication between arduino boards.
by Curtis Sapp
September 11th, 2015
*/


#include "Board.h"
#include "Arduino.h"

Board::Board(int dataPin_a, int inputConfirmationPin_a, int outputConfirmationPin_a, bool server) {

  dataPin = dataPin_a;
  inputConfirmationPin = inputConfirmationPin_a;
  outputConfirmationPin = outputConfirmationPin_a;

  if(server) {
  pinMode(dataPin, OUTPUT);
  } else {
  pinMode(dataPin,INPUT);
  }
  pinMode(inputConfirmationPin, INPUT);
  pinMode(outputConfirmationPin, OUTPUT);
}

//Must contain 8 elements

void Board::sendByte(int values[]) {
    int confirmationValue;  
    bool firsthalf;

for (int i = 0; i < 8; i++) {
      confirmationValue = 1;
  firsthalf = true;  
  while(true){
  sendBit(values[i]);
  sendConfirmation(confirmationValue);
  
  if(getConfirmation() == 1 && firsthalf) {
        confirmationValue = 0;
    firsthalf = false;
        }
  if(getConfirmation() == 0 && !firsthalf) {
    break;
     }    
   }
 }
}


String Board::getByte() {
  String recievedByte = "";
    int confirmationValue;  
    bool firsthalf;
  for (int i = 0; i < 8; i++) {
      confirmationValue = 0;
  firsthalf = true;  
  while(true){

  sendConfirmation(confirmationValue);
  
  if(getConfirmation() == 1 && firsthalf) {
    recievedByte = recievedByte + getBit();
    firsthalf = false;
    confirmationValue = 1;
        }
  if(getConfirmation() == 0 && !firsthalf) {
    break;
     }    
   }
  }

  return recievedByte;

}

void Board::sendBit(int value) {
  if (value == 0) {
    digitalWrite(dataPin, LOW);
  } else if (value == 1) {
    digitalWrite(dataPin, HIGH);
  }
}

    int Board::getBit() {
      if (digitalRead(dataPin) == LOW) {
        return 0;
      } else if (digitalRead(dataPin) == HIGH) {
        return 1;
      }

    }
void Board::sendConfirmation(int value) {
  if (value == 0) {
    digitalWrite(outputConfirmationPin, LOW);
  } else if (value == 1) {
    digitalWrite(outputConfirmationPin, HIGH);
  }
}
int Board::getConfirmation() {
  if (digitalRead(inputConfirmationPin) == LOW) {
    return 0;
  } else if (digitalRead(inputConfirmationPin) == HIGH) {
    return 1;
  }

}









