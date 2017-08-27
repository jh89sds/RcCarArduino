const int DIRA = 4;
const int PWMA = 5;

const int DIRB = 7;
const int PWMB = 6;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(DIRA, OUTPUT);

  digitalWrite(DIRA, LOW);
  analogWrite(PWMA, 0);

  pinMode(DIRB, OUTPUT);

  digitalWrite(DIRB, LOW);
  analogWrite(PWMB, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(DIRA, HIGH);
  analogWrite(PWMA, 200);

    digitalWrite(DIRB, HIGH);
    analogWrite(PWMB, 200);

    delay(2000);

    digitalWrite(DIRA, LOW);
    analogWrite(PWMA, 0);

    digitalWrite(DIRB, LOW);
    analogWrite(PWMA, 0);

    delay(2000);

    digitalWrite(DIRA, LOW);
    analogWrite(PWMA, 200);

    digitalWrite(DIRB, LOW);
    analogWrite(PWMB, 200);

    delay(2000);

    digitalWrite(DIRA, LOW);
    analogWrite(PWMA, 0);

    digitalWrite(DIRB, LOW);
    analogWrite(PWMB, 0);

    delay(2000);
}
