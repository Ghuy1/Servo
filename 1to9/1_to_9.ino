byte so [10] = {0B00000011, 0B10011111, 0B00100101, 0B00001101, 0B10011001, 0B01001001, 0B01000001, 0B00011111, 0B00000001, 0B00001001};
byte hang[4] = {0B00010000, 0B00100000, 0B01000000, 0B10000000};
byte kitu[10] = {0B01100011, 0B00111001, 0B11000101, 0, 0, 0, 0, 0, 0, 0};
// C=0,degree=1
//%=1+2
//Pin connected to ST_CP of 74HC595
int latchPin = 7;
//Pin connected to SH_CP of 74HC595
int clockPin = 6;
//Pin connected to DS of 74HC595
int dataPin = 8;
#include <DHT.h>
#include<DHT_U.h>

#define DHTPIN 2 
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

int t1,t2;



void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);
dht.begin();

}

  
}

void loop() {
   int h=dht.readHumidity();
int t=dht.readTemperature();
t2=t;
if (t2!=t1)
{
  digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, so[]);
    shiftOut(dataPin, clockPin, LSBFIRST, hang[]);
    digitalWrite(latchPin, HIGH);

}


t1=t2;


 
