// Aan/uit knop
int powerButton = 8;

// Led lampje om aan te tonen dat het systeem aanstaat
int LED = 2;

// Circuit break om geen stroom door te laten als het apparaat uit staat
int circuitBreak = 5;

void setup()
{

    pinMode(powerButton, INPUT);   //powerButton is input
    pinMode(LED, OUTPUT);          //LED is output
    pinMode(circuitBreak, OUTPUT); //Circuit break is input
}

void loop()
{

    // Checken of de powerbutton is ingedrukt of niet
    int stateOfButton = digitalRead(powerButton);

    Serial.write(stateOfButton);
}