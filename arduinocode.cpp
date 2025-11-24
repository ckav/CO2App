#define PinCO2 5 // CO2 sensor pin

// CO2 timing variables
int ValorAnterior = LOW;
long tiempoenHIGH, tiempoenLOW, h, l, ppm;

// Moving average buffer
const int bufferSize = 10;
long ppmBuffer[bufferSize];
int bufferIndex = 0;
bool bufferFilled = false;

// Switch and LED
int PinSwitch = A2;
int Int;

// RGB LED pins (common anode)
int pinled1 = 6;   // Red
int pinled2 = 9;   // Green
int pinled3 = 10;  // Blue

void setup() {
  Serial.begin(9600);

  pinMode(PinCO2, INPUT);

  // Use internal pull-up on the switch pin
  // Wiring: A2 <-> switch <-> GND
  pinMode(PinSwitch, INPUT_PULLUP);

  pinMode(pinled1, OUTPUT);
  pinMode(pinled2, OUTPUT);
  pinMode(pinled3, OUTPUT);
}

void loop() {
  // Read switch as DIGITAL: LOW = ON, HIGH = OFF
  Int = digitalRead(PinSwitch);

  if (Int == LOW) {  // switch ON (closed to GND)
    long tt = millis();
    int ValorActual = digitalRead(PinCO2);

    if (ValorActual == HIGH) {
      if (ValorActual != ValorAnterior) {
        h = tt;
        tiempoenLOW = h - l;
        ValorAnterior = ValorActual;
      }
    } else {
      if (ValorActual != ValorAnterior) {
        l = tt;
        tiempoenHIGH = l - h;
        ValorAnterior = ValorActual;

        long rawPpm = 5000 * (tiempoenHIGH - 2) / (tiempoenHIGH + tiempoenLOW - 4);

        // Store in buffer
        ppmBuffer[bufferIndex++] = rawPpm;
        if (bufferIndex >= bufferSize) {
          bufferIndex = 0;
          bufferFilled = true;
        }

        // Calculate moving average
        long sum = 0;
        int count = bufferFilled ? bufferSize : bufferIndex;
        for (int i = 0; i < count; i++) {
          sum += ppmBuffer[i];
        }
        ppm = sum / count;

        // Serial output for Plotter
        Serial.print("CO2ppm:");
        Serial.println(ppm);
        // If you want a horizontal threshold line at 1000ppm, you can do:
        Serial.print("CO2ppm:"); Serial.print(ppm);
        Serial.print("\tThresholdLine:"); Serial.println(0);

        // Set LED color
        if (tt < 10000) { // Blue for first 10 seconds
          analogWrite(pinled1, 255); // Red OFF
          analogWrite(pinled2, 255); // Green OFF
          analogWrite(pinled3, 205); // Blue ON
        } else {
          if (ppm < 1000) {
            analogWrite(pinled1, 255); // Red OFF
            analogWrite(pinled2, 205); // Green ON
            analogWrite(pinled3, 255); // Blue OFF
          } else {
            analogWrite(pinled1, 205); // Red ON
            analogWrite(pinled2, 255); // Green OFF
            analogWrite(pinled3, 255); // Blue OFF
          }
        }
      }
    }
  } else {
    // Switch is OFF: LED OFF
    analogWrite(pinled1, 255);
    analogWrite(pinled2, 255);
    analogWrite(pinled3, 255);
  }

  delay(10); // Helps with timing stability
}
