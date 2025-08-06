#include <CapacitiveSensor.h>

// Capteurs 4x4: chaque combinaison (X, Y)
CapacitiveSensor cs[4][4] = {
  { CapacitiveSensor(2, 6), CapacitiveSensor(2, 7), CapacitiveSensor(2, 8), CapacitiveSensor(2, 9) },
  { CapacitiveSensor(3, 6), CapacitiveSensor(3, 7), CapacitiveSensor(3, 8), CapacitiveSensor(3, 9) },
  { CapacitiveSensor(4, 6), CapacitiveSensor(4, 7), CapacitiveSensor(4, 8), CapacitiveSensor(4, 9) },
  { CapacitiveSensor(5, 6), CapacitiveSensor(5, 7), CapacitiveSensor(5, 8), CapacitiveSensor(5, 9) }
};

long touch[4][4];  // Mesures de chaque zone

void setup() {
  Serial.begin(9600);

  // Réglage de la sensibilité 
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      cs[i][j].set_CS_AutocaL_Millis(0xFFFFFFFF); // pour désactive l’auto calibration
}

void loop() {
  Serial.println("Grille tactile :");

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      touch[i][j] = cs[i][j].capacitiveSensor(10); // 10 mesures par point
      if (touch[i][j] > 1000) {
        Serial.print("X ");
      } else {
        Serial.print(". ");
      }
    }
    Serial.println();
  }

  Serial.println();
  delay(200);
}
