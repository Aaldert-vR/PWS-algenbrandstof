#ifndef ATMEGA_H
#define ATMEGA_H
#include <chrono>
#include <iostream>
using namespace std;

auto startTime = std::chrono::high_resolution_clock::now();
#define HIGH 1
#define LOW 0
#define INPUT 0
#define OUTPUT 1
#define INPUT_pullup 2

//typedef char byte;

typedef struct {
    int mode=INPUT;
    int value=LOW;
    int writeResolution=10;
    bool pwm=false;
} digitalPort;

typedef struct{
    int readResolution=10;
    int value=0;
} analogPort;

digitalPort digitalPins[53];
analogPort analogPins[14];

void pinMode(int pin, int mode){
    digitalPins[pin].mode=mode;
}

int digitalRead(int pin){
    return digitalPins[pin].value;
}

void digitalWrite(int pin, int value){
    digitalPins[pin].value=value;
}

int analogRead(int pin){
    return analogPins[pin].value;
}

void analogReadResolution(int pin, int bits){
    if (bits==10 || bits==12 || bits==14 || bits==16){
        analogPins[pin].readResolution=bits;
    }
}

unsigned long millis(){
    auto end=std::chrono::high_resolution_clock::now();
    unsigned long mill=std::chrono::duration_cast<std::chrono::milliseconds>(end - startTime).count();
    //cout <<"millis: " << mill << "\n";
    return mill;
}

void simulateDigitalPort(int pin, int value){
    digitalPins[pin].value=value;
}

void simulateAnalogPort(int pin, int value){
    analogPins[pin].value=value;
}
#endif