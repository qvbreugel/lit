// Pin of connected power button
int powerButton = 8;

// Pin of the solenoid valve
int solenoidValve = 4;

//Pin of the connected LED
int LED = 5;


void setup()
{
    pinMode(powerButton, INPUT);   //powerButton is input
    pinMode(solenoidValve, INPUT); //solenoid valve is input
    pinMode(LED, OUTPUT);          //LED is output
}

void loop()
{
    //Keep track of the current state of the button
    int stateOfButton = digitalRead(powerButton);
    
    // Check if button is not pressed
    if (stateOfButton == 0)
    {
        //Turn LED off if the button is not pressed
        digitalWrite(LED, LOW);

        //Close the valve if the button is not pressed
        digitalWrite(solenoidValve, LOW);
    }

    // Check if button is pressed
    if (stateOfButton == 1)
    {
        //Turn the LED on when button is pressed
         digitalWrite(LED, HIGH);
    
        //Open valve when button is pressed
        digitalWrite(solenoidValve, HIGH);
       

    }
}