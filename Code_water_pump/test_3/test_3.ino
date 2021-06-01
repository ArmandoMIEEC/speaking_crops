//Testar o sensor de agua
/*Resultados:
 * funciona mt bem para detetar agua.
 * mas para distingir niveis de agua diferentes nao é mt bom
 * quando a agua está a subir ele percebe bem, mas dps, qnd a agua desde ele tem dificuldades a perceber
 * ao inicio achava que era por o sensor ficar humido, mas nao faz mt sentido pq deteta perfeitamente quando a agua deixa de tocar no sensor
 * 
 * Os limites dos intervalos para detetar o nivel de agua
 * são mt variaveis de tipo de agua para tipo de agua
 * estes valores sao para a minha agua da torneira
 */

int valor = 0;  // holds the value
int pin_sens = A5; // sensor pin used
char buf[100];
  
void setup()
{ 
  Serial.begin(9600);
} 
  
void loop() 
{ 
  valor = analogRead(pin_sens); //Read data from analog pin and store it to valor variable
   
  if (valor<=100)
  {
    sprintf(buf, "Water level: Empty \t VAL: %d", valor);
    Serial.println(buf);
  } 
  else if (valor>100 && valor<=450)
  {
    sprintf(buf, "Water level: Low \t VAL: %d", valor);
    Serial.println(buf);
  } 
  else if (valor>450 && valor<=495)
  { 
    sprintf(buf, "Water level: Medium \t VAL: %d", valor);
    Serial.println(buf); 
  } 
  else if (valor>485)
  {
    sprintf(buf, "Water level: High \t VAL: %d", valor);
    Serial.println(buf);
  }
  delay(1000); 
}
