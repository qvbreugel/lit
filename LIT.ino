//Nodig om waarde van de accelerometer en gyroscope te lezen
#include <Wire.h>

//Microprocessor van accelerometer/gyroscope
const int MPU = 0x68;

//Initialiseer op te nemen waarden
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;

// Aan/uit knop
int powerButton = 8;

// Circuit break om geen stroom door te laten als het apparaat uit staat
int circuitBreak = 5;

void setup()
{
    pinMode(powerButton, INPUT);   //powerButton is input
    pinMode(LED, OUTPUT);          //LED is output
    pinMode(circuitBreak, OUTPUT); //Circuit break is input

    //Koppeling van accelerometer/gyroscope
    Wire.begin();
    Wire.beginTransmission(MPU);
    Wire.write(0x6B);
    Wire.write(0);
    Wire.endTransmission(true);
    Serial.begin(9600);
}

void loop()
{
    //Houdt de huidige staat van de aan/uit knop bij
    int stateOfButton = digitalRead(powerButton);
    // Checken of de powerbutton is ingedrukt of niet
    if (stateOfButton == 0)
    {
        //Als de knop uitstaat, zorg dat er geen stroom door het circuit gaat
        digitalWrite(circuitBreak, LOW);
        //En zet de LED uit
        digitalWrite(LED, LOW);
    }

    if (stateOfButton == 1)
    {
        //Als de knop aanstaat, zorg dat er wel stroom door het circuit gaat
        digitalWrite(circuitBreak, HIGH);
        //En zet de LED aan
        digitalWrite(LED, HIGH);

        //Lees de waarden van accelerometer/gyroscope
        Wire.beginTransmission(MPU);
        Wire.write(0x3B);
        Wire.endTransmission(false);
        Wire.requestFrom(MPU, 12, true);
        AcX = Wire.read() << 8 | Wire.read();
        AcY = Wire.read() << 8 | Wire.read();
        AcZ = Wire.read() << 8 | Wire.read();
        GyX = Wire.read() << 8 | Wire.read();
        GyY = Wire.read() << 8 | Wire.read();
        GyZ = Wire.read() << 8 | Wire.read();

        Serial.print("Accelerometer: ");
        Serial.print("X = ");
        Serial.print(AcX);
        Serial.print(" | Y = ");
        Serial.print(AcY);
        Serial.print(" | Z = ");
        Serial.println(AcZ);

        Serial.print("Gyroscope: ");
        Serial.print("X = ");
        Serial.print(GyX);
        Serial.print(" | Y = ");
        Serial.print(GyY);
        Serial.print(" | Z = ");
        Serial.println(GyZ);
        Serial.println(" ");
    }
}