{\rtf1\ansi\ansicpg1252\deff0\nouicompat\deflang1033{\fonttbl{\f0\fnil\fcharset0 Calibri;}}
{\*\generator Riched20 10.0.19041}\viewkind4\uc1 
\pard\sa200\sl276\slmult1\f0\fs22\lang9 // Pin definitions\par
const int trigPin = 9;  // Trigger pin for HC-SR04\par
const int echoPin = 10; // Echo pin for HC-SR04\par
const int buzzerPin = 3; // Buzzer pin\par
\par
// Variables\par
long duration;\par
float distance;\par
\par
// Setup\par
void setup() \{\par
  pinMode(trigPin, OUTPUT);\par
  pinMode(echoPin, INPUT);\par
  pinMode(buzzerPin, OUTPUT);\par
\par
  Serial.begin(9600);\par
\}\par
\par
// Main loop\par
void loop() \{\par
  // Send ultrasonic pulse\par
  digitalWrite(trigPin, LOW);\par
  delayMicroseconds(2);\par
  digitalWrite(trigPin, HIGH);\par
  delayMicroseconds(10);\par
  digitalWrite(trigPin, LOW);\par
\par
  // Read the echo time and calculate distance\par
  duration = pulseIn(echoPin, HIGH);\par
  distance = duration * 0.034 / 2; // Convert to centimeters\par
\par
  Serial.print("Distance: ");\par
  Serial.print(distance);\par
  Serial.println(" cm");\par
\par
  // Feedback logic based on distance\par
  if (distance < 30) \{\par
    // Wall/Obstacle very close\par
    triggerContinuousBuzzer();\par
  \} else if (distance >= 30 && distance <= 50) \{\par
    // Small object detection\par
    triggerPulsingBuzzer();\par
  \} else \{\par
    // No obstacle nearby\par
    digitalWrite(buzzerPin, LOW);\par
  \}\par
\par
  delay(200); // Small delay for stability\par
\}\par
\par
// Trigger a continuous buzzer for very close obstacles\par
void triggerContinuousBuzzer() \{\par
  digitalWrite(buzzerPin, HIGH);\par
\}\par
\par
// Trigger a pulsing buzzer for small obstacles\par
void triggerPulsingBuzzer() \{\par
  digitalWrite(buzzerPin, HIGH);\par
  delay(100);\par
  digitalWrite(buzzerPin, LOW);\par
  delay(100);\par
\}\par
}
 
