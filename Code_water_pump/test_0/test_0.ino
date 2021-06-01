void setup()
{
pinMode(10, OUTPUT); //sets the digital pin as output
}

void loop()
{
digitalWrite(10,HIGH); //liga  a bomba
delay(5000);  
digitalWrite(10,LOW); //desliga
delay(5000);
}
