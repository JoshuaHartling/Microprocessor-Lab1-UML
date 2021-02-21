int redLED = 2; // red LED assigned to pin 2
int yellowLED = 3; // yellow LED assigned to pin 3
int greenLED = 4; // green LED assigned to pin 4
int button = 5; // button assigned to pin 5
int buzzer = 12; // buzzer assigned to pin 12

void setup() {
  bool isWait = true;
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  // if button is pressed, begin traffic lights simulation
  while (isWait)
  {
    if (digitalRead(button) == LOW)
    {
     isWait = false; 
    }
  }
}

void loop() {
    digitalWrite(redLED, HIGH); // turn red LED on
    delay(12000);               // leave on for 15 seconds
    buzzerAlert();                 // alert that lights are changing
    digitalWrite(redLED, LOW); // turn red LED off
    
    digitalWrite(greenLED, HIGH); // turn green LED on
    delay(12000);                 // leave on for 15 seconds
    buzzerAlert();                 // alert that lights are changing
    digitalWrite(greenLED, LOW);  // turn green LED off
  
    // call buzzerAlert() function to alert that lights are changing
    digitalWrite(yellowLED, HIGH); // turn yellow LED on
    delay(1000);                  // leave on for 15 seconds
    buzzerAlert();                 // alert that lights are changing
    digitalWrite(yellowLED, LOW);  // turn yellow LED off
}

// function for turning buzzer on for 3 seconds before a light changes
void buzzerAlert() {
    int i;
    for (i=0; i < 1500; i++)
    {
      digitalWrite(buzzer,HIGH);
      delay(1);//wait for Xms
      digitalWrite(buzzer,LOW);
      delay(1);//wait for Xms
    }
}
