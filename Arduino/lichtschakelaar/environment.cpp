#include "../lib/atmega.h"
void environment(){
    cout << "Running environment";
    cout << digitalRead(13);
    simulateDigitalPort(12, HIGH);
    cout << digitalRead(13);
}