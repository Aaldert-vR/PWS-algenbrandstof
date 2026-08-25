#define AAN HIGH
#define UIT LOW
const int licht = 13;
const int knop = 12;
byte aan_uit = UIT;
const int uren_wachten[2]={12,12};
int wachten = uren_wachten[aan_uit];

void setup(){
    pinMode(licht, OUTPUT);
    pinMode(knop, INPUT);
    vorigeMillis=millis();
    digitalWrite(licht, aan_uit);
}

void loop(){
    knop_ingedrukt=digitalRead(knop);
    if (millis()-vorigeMillis==3600*1000*uren_aan || knop_ingedrukt==HIGH){
        aan_uit=!(aan_uit);
        wachten=uren_wachten[aan_uit];
    }
}