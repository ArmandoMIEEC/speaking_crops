/*transferir agua até o nivel de agua no recetor estar a High
 * codigo está bem
 * problema é o mesmo que no teste anterior (test_3)
 * com o sensor de agua 
 * 
*/

int valor = 0;  // holds the value
int pin_sens = A5; // sensor pin used
char nivel_agua[100]; //guarda o nivel de agua
char buf[100];
  
void setup()
{ 
  Serial.begin(9600);
  pinMode(8, OUTPUT); //Bomba branca
} 
  
void loop() 
{ 
  valor = analogRead(pin_sens); //Read data from analog pin and store it to valor variable
  update_nivel_agua();

  if(strcmp(nivel_agua,"High")==0)
    digitalWrite(8,LOW); //desliga branca
  else 
    digitalWrite(8,HIGH); //liga branca
  
  delay(1000);
}

void update_nivel_agua()
{
   valor = analogRead(pin_sens); //Read data from analog pin and store it to valor variable
   if (valor<=100)
  {
    sprintf(nivel_agua,"Empty");
    sprintf(buf, "Water level: Empty \t VAL: %d", valor);
    Serial.println(buf);
  } 
  else if (valor>100 && valor<=450)
  {
    sprintf(nivel_agua,"Low");
    sprintf(buf, "Water level: Low \t VAL: %d", valor);
    Serial.println(buf);
  } 
  else if (valor>450 && valor<=495)
  { 
    sprintf(nivel_agua,"Medium");
    sprintf(buf, "Water level: Medium \t VAL: %d", valor);
    Serial.println(buf); 
  } 
  else if (valor>485)
  {
    sprintf(nivel_agua,"High");
    sprintf(buf, "Water level: High \t VAL: %d", valor);
    Serial.println(buf);
  }
}
