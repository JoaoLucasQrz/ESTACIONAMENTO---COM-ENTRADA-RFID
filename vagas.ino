
void loop()
{
  float distancia1 = medirDistancia(Trig1, Echo1);
  float distancia2 = medirDistancia(Trig2, Echo2);
  float distancia3 = medirDistancia(Trig3, Echo3);
  float distancia4 = medirDistancia(Trig4, Echo4);

  Serial.print("Distancia 1: ");
  Serial.print(distancia1);
  Serial.print(" cm | Distancia 2: ");
  Serial.print(distancia2);
  Serial.print(" cm | Distancia 3: ");
  Serial.print(distancia3);
  Serial.print(" cm | Distancia 4: ");
  Serial.print(distancia4);
  Serial.println(" cm");  
  
  // === Sensor 1 ===
  if (distancia1 < 5){
    digitalWrite(Led1_verde, LOW);
    digitalWrite(Led1_vermelho, HIGH);
  } else {
    digitalWrite(Led1_verde, HIGH);
    digitalWrite(Led1_vermelho, LOW);
  }

  // === Sensor 2 ===
  if (distancia2 < 5){
    digitalWrite(Led2_verde, LOW);
    digitalWrite(Led2_vermelho, HIGH);
  } else {
    digitalWrite(Led2_verde, HIGH);
    digitalWrite(Led2_vermelho, LOW);
  }

  // === Sensor 3 ===
  if (distancia3 < 5){
    digitalWrite(Led3_verde, LOW);
    digitalWrite(Led3_vermelho, HIGH);
  } else {
    digitalWrite(Led3_verde, HIGH);
    digitalWrite(Led3_vermelho, LOW);
  }

  // === Sensor 4 ===
  if (distancia4 < 5){
    digitalWrite(Led4_verde, LOW);
    digitalWrite(Led4_vermelho, HIGH);
  } else {
    digitalWrite(Led4_verde, HIGH);
    digitalWrite(Led4_vermelho, LOW);
  }
  
  delay(200);
}
