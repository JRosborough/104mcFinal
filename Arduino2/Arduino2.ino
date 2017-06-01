  // Wiring/Arduino code:
 // Read data from the serial and turn ON or OFF a light depending on the value
 
//int Value = 254;
int LEDgreen=9; //red
int LEDyellow=10; //Green
int LEDred=11; //blue

int ledPin = 13; // Set the pin to digital I/O LED
char val;
 
void setup() {

// declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  pinMode(LEDgreen, OUTPUT);
  pinMode(LEDyellow, OUTPUT);
  pinMode(LEDred, OUTPUT);
//  pinMode(SwitchPin, INPUT);
// initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
 pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
 int Value = 0;

  analogWrite(LEDgreen, 0);
  analogWrite(LEDyellow, 0); 
  analogWrite(LEDred, 0);  
 
}
 
void loop() {

if (Serial.available()) { // If data is available to read,
  val = Serial.read(); // read it and store it in val
 }
 if (val == '1') {
    digitalWrite(LEDgreen, 254);
    digitalWrite(LEDyellow, 254); 
    digitalWrite(LEDred, 254); 
 }
 else if (val == '0') {
    digitalWrite(LEDgreen, 0);
    digitalWrite(LEDyellow, 0); 
    digitalWrite(LEDred, 0); 
 }
}
 
