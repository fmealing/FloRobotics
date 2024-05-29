// Constants
const int ledPin = 13;       // LED pin number
const int sensorPin = A0;    // Sensor pin number

// Variables
int sensorValue;             // Variable to store sensor value
int sensorLow = 1023;        // Variable to store the lowest sensor value
int sensorHigh = 0;          // Variable to store the highest sensor value

void setup() {
    pinMode(ledPin, OUTPUT);      // Set the LED pin as output
    digitalWrite(ledPin, HIGH);   // Turn on the LED to indicate calibration start

    // Calibrate sensor for the first 5 seconds
    while (millis() < 5000) {
        sensorValue = analogRead(sensorPin);  // Read sensor value
        if (sensorValue > sensorHigh) {
            sensorHigh = sensorValue;        // Update the highest sensor value
        }
        if (sensorValue < sensorLow) {
            sensorLow = sensorValue;         // Update the lowest sensor value
        }
    }

    digitalWrite(ledPin, LOW);    // Turn off the LED to indicate calibration end
}

void loop() {
    sensorValue = analogRead(sensorPin);  // Read sensor value
    int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000); // Map sensor value to pitch range
    tone(8, pitch, 20);  // Play tone on pin 8 with the calculated pitch for 20 ms

    delay(10);  // Small delay to stabilize sensor reading
}
