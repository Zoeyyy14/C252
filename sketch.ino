#include <lilParser.h>
#define LED_PIN 13

enum commands{
  noCommand, LEDOn, LEDOff
};
lilParser ourParser;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Type On or Off");
  pinMode(LED_PIN, OUTPUT);
  ourParser.addCmd(LEDOn, "on");
  ourParser.addCmd(LEDOff, "off");
}

void loop(void) {
  // put your main code here, to run repeatedly:
  char inChar;
  int command;
  if(Serial.available()){
    inChar=Serial.read();
    Serial.print(inChar);
    command=ourParser.addChar(inChar);
    switch(command){
      case noCommand : break;
      case LEDOn     : digitalWrite(LED_PIN, HIGH); break;
      case LEDOff    : digitalWrite(LED_PIN, LOW); break;
      default: Serial.println("What is this?"); break;
    }
  }
}
