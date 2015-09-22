/*
Board.h - Library created for wired communication between arduino boards.
by Curtis Sapp
September 11th, 2015
*/
#ifndef Board
#define Board

#include "Arduino.h"

class Board {
    
    public:
    int dataPin;
    int inputConfirmationPin; 
    int outputConfirmationPin;


    Board(int dataPin_a, int inputConfirmationPin_a, int outputConfirmationPin_a, bool server);
    void sendByte(int values[]);    
    bool syncWait() ;
    String getByte();
    void sendBit(int value);
    int getBit();
    void sendConfirmation(int value);
    int getConfirmation();
};

#endif

