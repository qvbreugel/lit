// Pin of the solenoid valve
int solenoidValve = 4;

//Pin of the connected buzzer
int buzzer = 5;

// Pin of lighter
int lighter = 7;

// Pin of connected power button
int powerButton = 8;




void setup()
{
    Serial.begin(9600);
    pinMode(solenoidValve, OUTPUT);  //solenoid valve is input
    pinMode(buzzer, OUTPUT);        //LED is output
    pinMode(powerButton, INPUT);    //powerButton is input
    pinMode(lighter, OUTPUT);    //Lighter is output
    digitalWrite(solenoidValve, LOW);
    digitalWrite(lighter, LOW);

    beep();

}

void loop()
{
    //Keep track of the current state of the button
    int stateOfButton = digitalRead(powerButton);
    
    // Check if button is not pressed
    if (stateOfButton == 0)
    {
        //Close the valve and lighter if the button is not pressed
        digitalWrite(solenoidValve, LOW);
        digitalWrite(lighter, LOW);
    }

    // Check if button is pressed
    if (stateOfButton == 1)
    {
        //Open valve and lighter when button is pressed
        digitalWrite(solenoidValve, HIGH);
        digitalWrite(lighter, HIGH);
    }
}

void beep(){
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(500);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(500);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
}