//Teste bombas a mandar uma para a outra
//a bomba preta não funciona assim mt bem 
void setup()
{
pinMode(9, OUTPUT); //Bomba preta
pinMode(8, OUTPUT); //Bomba branca
}

void loop()
{
digitalWrite(9,HIGH); //liga preta
delay(30000);  
digitalWrite(9,LOW); //desliga preta
digitalWrite(8,HIGH); //liga branca
delay(30000);
digitalWrite(8,LOW); //desliga branca
}
