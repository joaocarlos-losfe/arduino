//modulação de intensidade disponiveis 
//nos pinos ~3, ~5, ~6, ~9, ~10, ~11;
//0, 25%, 50%, 75%, 100%
const int PERCENTAGES_AVAILABLE_ON_ANALOG_PINS[] = {0, 63, 127, 191, 255};

int getNumberFromChar(char value)
{
  	return (int)value - 48;
}

void setup()
{
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop()
{
  
  if(Serial.available())
  {
  	int percentage = getNumberFromChar(Serial.read());
    
    if(percentage < 5)
      analogWrite(3, PERCENTAGES_AVAILABLE_ON_ANALOG_PINS[percentage]);
  }
}
     
