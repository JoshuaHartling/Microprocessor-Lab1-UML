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

  // red light blinks and checks if button is pressed
  while (isWait)
  {
    digitalWrite(redLED, HIGH); // turn red LED on
    isWait = check_button();    // checks if the start button has been pressed and waits for 1 second
    digitalWrite(redLED, LOW);  // turn red LED off
    isWait = check_button();    // checks if the start button has been pressed and waits for 1 second
  }
}

// traffic lights simulation starts if button is pressed
void loop() {
    digitalWrite(redLED, HIGH); // turn red LED on
    delay(12000);               // leave on for 15 seconds
    buzzerAlert();                 // alert that lights are changing 
    digitalWrite(redLED, LOW); // turn red LED off
    
    digitalWrite(greenLED, HIGH); // turn green LED on
    delay(12000);                 // leave on for 15 seconds
    buzzerAlert();                 // alert that lights are changing
    digitalWrite(greenLED, LOW);  // turn green LED off
  
    digitalWrite(yellowLED, HIGH); // turn yellow LED on
    delay(1000);                  // leave on for 15 seconds
    buzzerAlert();                 // alert that lights are changing
    digitalWrite(yellowLED, LOW);  // turn yellow LED off
}

// function for turning buzzer on before a light changes
void buzzerAlert() {
    int i;

    // output a frequency
    for (i=0; i < 1500; i++)
    {
      digitalWrite(buzzer,HIGH); // turn buzzer on
      delay(1);// wait for 1 ms
      digitalWrite(buzzer,LOW); // turn buzzer off
      delay(1);// wait for 1 ms
    }
}

// function to check if button has been pressed
bool check_button() {
  int i;

  // loop to check if button has been pressed
  for (i=0; i < 1000; i++)
  {
    // if button is pressed
    if (digitalRead(button) == LOW)
      {
       return false; 
      }
      delay(1); // wait 1 ms
  }
  return true;
}
