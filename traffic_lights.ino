int redLED=2;
int yellowLED=3;
int greenLED=4;
int button=5;
int buzzer=12;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  digitalWrite(redLED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(redLED, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  // if button is pressed, begin traffic lights simulation
  if (digitalRead(button) == LOW)
  {
    digitalWrite(redLED, HIGH); // turn red LED on
    delay(15000);               // leave on for 15 seconds
    digitalWrite(redLED, LOW); // turn red LED off
    digitalWrite(greenLED, HIGH); // turn green LED on
    delay(15000);                 // leave on for 15 seconds
    digitalWrite(greenLED, LOW);  // turn green LED off
    digitalWrite(yellowLED, HIGH); // turn yellow LED on
    delay(15000);                  // leave on for 15 seconds
    digitalWrite(yellowLED, LOW);  // turn yellow LED off
  }

}
