#include<SPI.h>
int analogPin = A7; 
byte val = 0;  
void setup() {
  pinMode(analogPin, INPUT);
  Serial.begin(9600);          
  SPI.begin();                  
  SPI.setClockDivider(SPI_CLOCK_DIV8);   
  digitalWrite(SS,HIGH);   
}

void loop() {
  
  val = analogRead(analogPin)*254/1024;  
  Serial.println(val);
  digitalWrite(SS,LOW);
  SPI.transfer(val); 
  digitalWrite(SS,HIGH); 
  delay(1000);          
}
