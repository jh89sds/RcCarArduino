const int DIRA = 4;
const int PWMA = 5;

const int DIRB = 7;
const int PWMB = 6;

const int POWER = 200;

void move_forward() {
  digitalWrite(DIRA, HIGH);
  analogWrite(PWMA, POWER);

  digitalWrite(DIRB, HIGH);
  analogWrite(PWMB, POWER);
}

void move_backward() {
  digitalWrite(DIRA, LOW);
  analogWrite(PWMA, POWER);

  digitalWrite(DIRB, LOW);
  analogWrite(PWMB, POWER);
}

void move_right() {
  digitalWrite(DIRA, HIGH);
  analogWrite(PWMA, POWER);

  digitalWrite(DIRB, LOW);
  analogWrite(PWMB, POWER);
}

void move_left() {
  digitalWrite(DIRA, LOW);
  analogWrite(PWMA, POWER);

  digitalWrite(DIRB, HIGH);
  analogWrite(PWMB, POWER);
}

void remote_setup() {
  Serial.begin(9600);
}

void motor_setup() {
  pinMode(DIRA, OUTPUT);

  digitalWrite(DIRA, LOW);
  analogWrite(PWMA, 0);

  pinMode(DIRB, OUTPUT);

  digitalWrite(DIRB, LOW);
  analogWrite(PWMB, 0);
}

const char MOVE_FORWARD = 'f';
const char MOVE_BACKWARD = 'b';
const char MOVE_RIGHT = 'r';
const char MOVE_LEFT = 'l';

void input_check() {
  if(Serial.available()) {
    char toward = Serial.read();

    switch(toward) {
      case MOVE_FORWARD:
        move_forward();
        break;
      case MOVE_BACKWARD:
        move_backward();
        break;
      case MOVE_RIGHT:
        move_right();
        break;
      case MOVE_LEFT:
        move_left();
        break;
    }
    delay(500);
    motor_setup();
  }
}

void setup() {
  // put your setup code here, to run once:
  remote_setup();
  motor_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  input_check();
}



