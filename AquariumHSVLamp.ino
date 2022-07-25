//Lampara para acuario

#include "FastLED.h"

#define NUM_LEDS 63
#define DATA_PIN 9
#define R 12
#define G 11
#define B 10
#define W 8
#define button 2
#define pot A0
#define pot2 A1

CRGB leds[NUM_LEDS];
int buttonCount, pushButton, hue, sat, val, cal, calibration, range, limits, time;

void setup() { 
  Serial.begin(9600);
  LEDS.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
  LEDS.setBrightness(255);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(W, OUTPUT);
  pinMode(button, INPUT);
  pinMode(pot, INPUT);
  pinMode(pot2, INPUT);
}
void loop() { 
	Serial.println(map(calibration, 0, 1023, 255, 0));
	Serial.println(limits);
    calibration = analogRead(pot);
    range = analogRead(pot2);
    pushButton = digitalRead(button);
    limits = map(range, 0, 1023, 50, 0);
    if (pushButton == HIGH){
      buttonCount++;
      delay(150);
    }
    else if (buttonCount>3) {
      buttonCount = 0;
    }
    if (buttonCount == 0) {
      digitalWrite(R, HIGH);
      digitalWrite(G, LOW);
      digitalWrite(B, LOW);
      digitalWrite(W, LOW);
      cal = map(calibration, 0, 1023, 255, 0);
      hue = cal;
    }
    else if (buttonCount == 1) {
      digitalWrite(R, LOW);
      digitalWrite(G, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(W, LOW);
      cal = map(calibration, 0, 1023, 255, 0);
      sat = cal;
    }
    else if (buttonCount == 2) {
      digitalWrite(R, LOW);
      digitalWrite(G, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(W, LOW);
      cal = map(calibration, 0, 1023, 255, 0);
      val = cal;
    }
    else if (buttonCount == 3){
        digitalWrite(R, LOW);
        digitalWrite(G, LOW);
        digitalWrite(B, LOW);
        digitalWrite(W, HIGH);
    }
    leds[random(0, 63)] = CHSV(random(hue-10, hue+10), sat, random(val-limits, val+limits));
    FastLED.show();
    leds[random(0, 63)] = CHSV(random(hue-10, hue+10), sat, random(val-limits, val+limits));
    FastLED.show();
    leds[random(0, 63)] = CHSV(random(hue-10, hue+10), sat, random(val-limits, val+limits));
    FastLED.show();
    leds[random(0, 63)] = CHSV(random(hue-10, hue+10), sat, random(val-limits, val+limits));
    FastLED.show();
    leds[random(0, 63)] = CHSV(random(hue-10, hue+10), sat, random(val-limits, val+limits));
    FastLED.show();
    leds[random(0, 63)] = CHSV(random(hue-10, hue+10), sat, random(val-limits, val+limits));
    FastLED.show();
    leds[random(0, 63)] = CHSV(random(hue-10, hue+10), sat, random(val-limits, val+limits));
    FastLED.show();
    leds[random(0, 63)] = CHSV(random(hue-10, hue+10), sat, random(val-limits, val+limits));
    FastLED.show();
    delay(10);
}
