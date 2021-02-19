int redLED=2; // red LED assigned to pin 2
int yellowLED=3; // yellow LED assigned to pin 3
int greenLED=4; // green LED assigned to pin 4
int button=5; // button assigned to pin 5
int buzzer=12; // buzzer assigned to pin 12

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  
  // flashing red LED
  digitalWrite(redLED, HIGH);   // turn the red LED on 
  delay(1000);                       // wait for a second
  digitalWrite(redLED, LOW);    // turn red the LED off 
  delay(1000);                       // wait for a second

  // if button is pressed, begin traffic lights simulation
  if (digitalRead(button) == LOW)
  {
    digitalWrite(redLED, HIGH); // turn red LED on
    delay(15000);               // leave on for 15 seconds
    digitalWrite(redLED, LOW); // turn red LED off

    // call buzzerAlert() function to alert that lights are changing
    buzzerAlert();
    
    digitalWrite(greenLED, HIGH); // turn green LED on
    delay(15000);                 // leave on for 15 seconds
    digitalWrite(greenLED, LOW);  // turn green LED off

    // call buzzerAlert() function to alert that lights are changing
    buzzerAlert();

    // call buzzerAlert() function to alert that lights are changing
    digitalWrite(yellowLED, HIGH); // turn yellow LED on
    delay(15000);                  // leave on for 15 seconds
    digitalWrite(yellowLED, LOW);  // turn yellow LED off

    buzzerAlert();
  }
}

// function for turning buzzer on for 3 seconds before a light changes
void buzzerAlert() {
  
      digitalWrite(buzzer,HIGH); // turn buzzer on
      delay(3000); // wait for 3 seconds
      digitalWrite(buzzer,LOW); // turn buzzer off
}
