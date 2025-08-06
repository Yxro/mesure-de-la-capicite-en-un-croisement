const int ROW_PIN = 2;  // D2 = ligne
const int COL_PIN = 6;  // D6 = colonne

unsigned long measureCapacitance() {
  // Décharge toute la capacité résiduelle
  pinMode(COL_PIN, OUTPUT);
  digitalWrite(COL_PIN, LOW);
  delay(5);  // brève décharge

  // Prépare la colonne en entrée (haute impédance)
  pinMode(COL_PIN, INPUT);

  // Envoie un signal sur la ligne (charge la capacité)
  pinMode(ROW_PIN, OUTPUT);
  digitalWrite(ROW_PIN, HIGH);

  // Mesure le temps que met COL_PIN à passer à HIGH
  unsigned long startTime = micros();
  while (digitalRead(COL_PIN) == LOW) {
    if ((micros() - startTime) > 3000) break; // timeout pour éviter boucle infinie
  }
  unsigned long elapsed = micros() - startTime;

  // Réinitialise ROW_PIN à LOW
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
