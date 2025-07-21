// UART Version

//#include <WiFiUdp.h>
#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
// #include <PubSubClient.h>


Adafruit_PWMServoDriver right = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver left = Adafruit_PWMServoDriver(0x41);


#define SERVOMIN 80   // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 470  // This is the 'maximum' pulse length count (out of 4096)

#define SERVO_FREQ 50  // Analog servos run at ~50 Hz updates

// Calibrate the servo max-min based on your servo
int sermin[11] = { 140, 90, 140, 110, 470, 470, 470, 85, 85, 75, 75 };
int sermax[11] = { 500, 490, 500, 490, 85, 85, 85, 470, 470, 480, 480 };

float rightInitPose[11] = { 0, 85, 90, 0, 0, 0, 0, 0, 0, 180, 90 };
float leftInitPose[11];
float rightPose[11];
float leftPose[11];


int angle(float a, int i) {
  int pwmValue = map(a, 0, 180, sermin[i], sermax[i]);
  return pwmValue;
}

void initPose() {
  for (int i = 0; i < 11; i++) {
    rightPose[i] = rightInitPose[i];
    leftInitPose[i] = 180 - rightInitPose[i];
    leftPose[i] = leftInitPose[i];
    right.setPWM(i, 0, angle(rightPose[i], i));
    delay(5);
    left.setPWM(i, 0, angle(leftPose[i], i));
  }
  for (int i = 0; i < 11; i++){
    Serial.print(leftPose[i]);
    Serial.print(",");
  }
  Serial.println();
}

void resetPose() {
  for (int i = 0; i < 11; i++) {
    right.setPWM(i, 0, 0);
    left.setPWM(i, 0, 0);
  }
}

void setup() {
  Serial.begin(115200);

  Wire.begin(8, 9);
  right.begin();
  right.setOscillatorFrequency(26000000);
  right.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  left.begin();
  left.setOscillatorFrequency(26000000);
  left.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates


  delay(10);
  initPose();
}

int slowDown = 5; // higher = slower

void moveTo(float finalPose[11]) {
  float rightInc[11];
  float steps = 120;
  for (int i = 0; i < 11; i++) {
    rightInc[i] = (finalPose[i] - rightPose[i]) / steps;
  }
  for (float i = 0; i <= steps; i++) {
    for (int j = 0; j < 11; j++) {
      rightPose[j] = rightPose[j] + rightInc[j];
      right.setPWM(j, 0, angle(rightPose[j], j));
    }
    delay(slowDown);
  }
}

void moveToL(float finalPose[11]) {
  float leftInc[11];
  float steps = 120;
  for (int i = 0; i < 11; i++) {
    leftInc[i] = (finalPose[i] - leftPose[i]) / steps;
  }
  for (float i = 0; i <= steps; i++) {
    for (int j = 0; j < 11; j++) {
      leftPose[j] = leftPose[j] + leftInc[j];
      left.setPWM(j, 0, angle(leftPose[j], j));
    }
    delay(slowDown);
  }
}

void moveBoth(float finalPose[11], float finalPosel[11]) {
  float leftInc[11];
  float rightInc[11];

  float steps = 80;
  for (int i = 0; i < 11; i++) {
    leftInc[i] = (finalPosel[i] - leftPose[i]) / steps;
    rightInc[i] = (finalPose[i] - rightPose[i]) / steps;
  }
  for (float i = 0; i <= steps; i++) {
    for (int j = 0; j < 11; j++) {

      rightPose[j] = rightPose[j] + rightInc[j];
      right.setPWM(j, 0, angle(rightPose[j], j));
      delay(2);
      leftPose[j] = leftPose[j] + leftInc[j];
      left.setPWM(j, 0, angle(leftPose[j], j));
    }
    delay(slowDown);
  }
}


void alphabet(float alphPose[5]) {
  float rightInc[5];
  float steps = 120;
  for (int i = 0; i < 5; i++) {
    rightInc[i] = (alphPose[i] - rightPose[4 + i]) / steps;
  }

  for (float i = 0; i <= steps; i++) {
    for (int j = 0; j < 5; j++) {
      rightPose[4 + j] = rightPose[4 + j] + rightInc[j];
      right.setPWM(4 + j, 0, angle(rightPose[4 + j], 4 + j));
    }
    delay(slowDown);
  }
}


const byte MAX_VALUES = 11;

float leftArray[MAX_VALUES] = { 0 };
float rightArray[MAX_VALUES] = { 0 };

bool leftUpdated = false;
bool rightUpdated = false;

String inputString = "";
bool inputComplete = false;
//inputString.reserve(100);

void loop() {
  // Read serial input
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n' || inChar == '\r') {
      inputComplete = true;
    } else {
      inputString += inChar;
    }
  }

  if (inputComplete) {
    
    inputComplete = false;
    if (inputString[0]=='e') {
      Serial.println("Executing...");
      moveBoth(rightArray,leftArray);
      
      leftUpdated = false;   // Reset flags
      rightUpdated = false;
    }
    else{
      parseAndStore(inputString);
    }
    inputString = "";
  }
}

void parseAndStore(String data) {
  if (data.length() < 2 || data.charAt(1) != ':') {
    Serial.println("Invalid format. Use l: or r:");
    return;
  }

  char target = data.charAt(0);
  String csvData = data.substring(2);

  int tempArray[MAX_VALUES] = {0};
  int index = 0;
  int lastIndex = 0;
  int commaIndex;

  while ((commaIndex = csvData.indexOf(',', lastIndex)) != -1 && index < MAX_VALUES) {
    tempArray[index++] = csvData.substring(lastIndex, commaIndex).toInt();
    lastIndex = commaIndex + 1;
  }

  if (index < MAX_VALUES && lastIndex < csvData.length()) {
    tempArray[index] = csvData.substring(lastIndex).toInt();
  }

  if (target == 'l') {
    for (int i = 0; i < MAX_VALUES; i++) leftArray[i] = tempArray[i];
    leftUpdated = true;
    Serial.println("Left array updated:");
    printArray(leftArray);
  } else if (target == 'r') {
    for (int i = 0; i < MAX_VALUES; i++) rightArray[i] = tempArray[i];
    rightUpdated = true;
    Serial.println("Right array updated:");
    printArray(rightArray);
  } else {
    Serial.println("Unknown target. Use 'l' or 'r'");
  }
}

void printArray(float arr[]) {
  for (int i = 0; i < MAX_VALUES; i++) {
    Serial.print(arr[i]);
    if (i < MAX_VALUES - 1) Serial.print(", ");
  }
  Serial.println();
}
