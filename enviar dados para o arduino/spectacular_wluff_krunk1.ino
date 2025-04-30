byte pinLeds[] = {9, 10, 11, 12, 13};

void setup()
{
  	Serial.begin(9600);
  
  	for(byte i = 0; i<5; i++) 
      pinMode(pinLeds[i], OUTPUT);
}

void lowAllLeds()
{
  	for(byte i = 0; i<5; i++) 
      digitalWrite(pinLeds[i], LOW);
}

void highAllLeds()
{
  	for(byte i = 0; i<5; i++) 
      digitalWrite(pinLeds[i], HIGH);
}

int getNumberFromChar(char value)
{
  	return (int)value - 48;
}

void highDefinedLeds(int value)
{
  	if(value > 5) return;
  
  	lowAllLeds();
  
	for(int i = 0; i< value; i++) 
      digitalWrite(pinLeds[i], HIGH);
}

void loop()
{
  
  if(Serial.available())
  {
  	int number = getNumberFromChar(Serial.read());
    
    highDefinedLeds(number);
    
    //Serial.println(Serial.read());
  }
}