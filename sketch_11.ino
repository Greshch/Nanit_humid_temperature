#include <NanitLib.h>
#include <DHT.h>

byte const pinDHT = P3_2;
byte const pinButton = P5_1;


DHT dht(pinDHT, DHT11);
bool buttonPressed = 0;

void setup() {
  // put your setup code here, to run once:
  Nanit_Base_Start();
  Serial.begin(9600);
  pinMode(pinButton, INPUT_PULLUP);
  dht.begin();
  attachInterrupt(0, buttonCalback, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  //buttonPressed = !digitalRead(pinButton);
  //Serial.println(buttonPressed);
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  if (buttonPressed) {
    Serial.print("humidity: "); Serial.print(humidity);
    Serial.print('\t');
    Serial.print("temperature: "); Serial.println(temperature);
    buttonPressed = 0;
  }
  
  delay(250);
}

void buttonCalback() {
  buttonPressed = 1;
}
