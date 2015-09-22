/*
Board.h - Library created for wired communication between arduino boards.
by Curtis Sapp
September 11th, 2015
*/
#ifndef Board_h
#define Board_h

#include "Arduino.h"

class Board {
    
    public:
    const int commDelay = 600;
    int inputPin;
    int outputPin;
    Board(int inputPin_a, int outputPin_a);
    int getInputPin();
    int getOutputPin();
    void sendByte(int values[]);    
    bool syncWait() ;
    String getByte();
    void sendBit(int value);
    int getBit();

};

#endif

