/*
Board.h - Library created for wired communication between arduino boards.
by Curtis Sapp
September 11th, 2015
*/


#include "Board.h"
#include "Arduino.h"





    

    Board::Board(int inputPin_a, int outputPin_a) {
      inputPin = inputPin_a;
      outputPin = outputPin_a;
      pinMode(inputPin, INPUT);
      pinMode(outputPin, OUTPUT);
    }


    int Board::getInputPin() {
      return inputPin;
    }

    int Board::getOutputPin() {
      return outputPin;
    }

    //Must contain 8 elements

    void Board::sendByte(int *values) {
	sendBit(1);
Serial.print(commDelay);
        for (int i = 0; i < 8; i++) {
	sendBit(values[i]);
        delay(commDelay);
      }
	sendBit(0);

    }
	
    bool Board::syncWait() {
      if(getBit() == 1) {
        delay(commDelay);
	return true;
	} else {
           return false;
      }
    }

    String Board::getByte() {
      String recievedByte = "";

      for (int i = 0; i < 8; i++) {
        recievedByte = recievedByte + getBit();
        delay(commDelay);
      }

      return recievedByte;

    }

    void Board::sendBit(int value) {
      if (value == 0) {
        digitalWrite(outputPin, LOW);
      } else if (value == 1) {
        digitalWrite(outputPin, HIGH);
      }
	delay(commDelay);

    }


    int Board::getBit() {
      if (digitalRead(inputPin) == LOW) {
        return 0;
      } else if (digitalRead(inputPin) == HIGH) {
        return 1;
      }

    }






