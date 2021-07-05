//transferir agua de um recipiente para o outro até o nivel de agua no recetor estar a High



int valor_1 = 0;  // holds the value
int valor_2 = 0;  // holds the value
int pin_sens_1 = A5; // sensor 1 pin used
int pin_sens_2 = A4; // sensor 2 pin used
char nivel_agua_1[100]; //guarda o nivel de agua
char nivel_agua_2[100]; //guarda o nivel de agua
char buf[100];
int estado=0; // estado 0 vai da bomba 1 para a bomba 2; estado 1 é o oposto
  
void setup()
{ 
  Serial.begin(9600);
  pinMode(8, OUTPUT); //Bomba preta (1)
  pinMode(9, OUTPUT); //Bomba branca (2)
} 
  
void loop() 
{ 
  
  update_nivel_agua_1();
  update_nivel_agua_2();
  
  switch (estado)
  {
  case 0:
  if(strcmp(nivel_agua_1,"High")==0)
    digitalWrite(8,LOW); //desliga bomba 1
  else
    {
      digitalWrite(8,HIGH); //liga bomba 1
      estado=1;
    } 
    
  break;
  case 1:
  if(strcmp(nivel_agua_2,"High")==0)
    digitalWrite(9,LOW); //desliga bomba 2 
  else 
    {
      digitalWrite(9,HIGH); //liga bomba 2
      estado=0;
    } 
  break;
  }
 
  delay(1000);
}

void update_nivel_agua_1()
{
   valor_1 = analogRead(pin_sens_1); //Read data from analog pin and store it to valor variable
   if (valor_1<=100)
  {
    sprintf(nivel_agua_1,"Empty");
  } 
  else if (valor_1>275)
  {
    sprintf(nivel_agua_1,"High");
  }
}

void update_nivel_agua_2()
{
   valor_2 = analogRead(pin_sens_2); //Read data from analog pin and store it to valor variable
   if (valor_2<=80)
  {
    sprintf(nivel_agua_2,"Empty");
  } 
  else if (valor_2>185)
  {
    sprintf(nivel_agua_2,"High");
  }
}
