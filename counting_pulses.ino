#include <elapsedMillis.h>

int anemometer = 2;
int led = 13;
volatile int spinCount = 0;
volatile int oldCount=0;

elapsedMillis timer0;
#define interval 10000

void setup() {
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    pinMode(anemometer, INPUT);
    attachInterrupt(digitalPinToInterrupt(anemometer), blink, CHANGE);
    
    timer0 = 0;
}

void loop() {
  if( timer0 > interval){
    timer0 -= interval;
    Serial.print("Revs this period: ");
    Serial.println(spinCount);
    spinCount = 0;
  }
;
}

void blink() {
    spinCount++;
}

