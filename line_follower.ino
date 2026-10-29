int sensorLeft = A0;
int sensorRight = A1;

int motorLeftForward = 5;
int motorLeftBackward = 6;
int motorRightForward = 9;
int motorRightBackward = 10;

int thresholdValue = 500;

void setup() {
  pinMode(sensorLeft, INPUT);
  pinMode(sensorRight, INPUT);

  pinMode(motorLeftForward, OUTPUT);
  pinMode(motorLeftBackward, OUTPUT);
  pinMode(motorRightForward, OUTPUT);
  pinMode(motorRightBackward, OUTPUT);
}

void loop() {
  int leftValue = analogRead(sensorLeft);
  int rightValue = analogRead(sensorRight);

  bool leftOnLine = leftValue < thresholdValue;
  bool rightOnLine = rightValue < thresholdValue;

  if (leftOnLine && rightOnLine) {
    forward();
  } else if (leftOnLine && !rightOnLine) {
    turnLeft();
  } else if (!leftOnLine && rightOnLine) {
    turnRight();
  } else {
    stopMotors();
  }
}

void forward() {
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightBackward, LOW);
}

void turnLeft() {
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightBackward, LOW);
}

void turnRight() {
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightBackward, LOW);
}

void stopMotors() {
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightBackward, LOW);
}
