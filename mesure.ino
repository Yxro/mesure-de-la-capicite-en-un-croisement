const int ROW_PIN = 2;  // ligne selon le port digital de la carte arduino
const int COL_PIN = 6;  // colonne selon le port digital de la carte arduino

unsigned long measureCapacitance() {
  // Décharge toute la capacité 
  pinMode(COL_PIN, OUTPUT);
  digitalWrite(COL_PIN, LOW);
  delay(5);  // brève décharge
  pinMode(COL_PIN, INPUT);
  pinMode(ROW_PIN, OUTPUT);
  digitalWrite(ROW_PIN, HIGH);
  unsigned long startTime = micros();
  while (digitalRead(COL_PIN) == LOW) {
    if ((micros() - startTime) > 3000) break; 
  }
  unsigned long elapsed = micros() - startTime;

  digitalWrite(ROW_PIN, LOW);

  return elapsed;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long capTime = measureCapacitance();
  Serial.print("Temps de charge (µs) entre D2 et D6 : ");
  Serial.println(capTime);
  delay(500);
}
