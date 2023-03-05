#define PIN_BEEP 2
#define PIN_ECHO 3
#define PIN_TRIG 4

#define FREQ 2000
#define BEEP_DUR 100


long duration;
float inches, cm;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_BEEP, OUTPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

}

void loop() {
  tone(PIN_BEEP, FREQ, BEEP_DUR);
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  duration = pulseIn(PIN_ECHO, HIGH);
  cm = (duration / 2) / 29.1;
  inches = (duration / 2) / 74;

  Serial.print("Distance: ");
  Serial.print(inches);
  Serial.print(" in, ");
  Serial.print(cm);
  Serial.println(" cm.");

  delay(clamp(0, duration / 2, 2000));
}


long clamp(long min, long target, long max) {
  if (target <= min) return min;
  if (target >= max) return max;
  return target;
}