byte analogPotPin = 0;
byte pins[5] = {2, 3, 4, 5, 6};
byte numberOfPins = sizeof(pins) / sizeof(pins[0]);

bool stop = false;

void setupPins()
{
  Serial.print("Pinos definidos:\n");
  for(byte i=0; i<numberOfPins; i++)
  {
  	pinMode(pins[i], OUTPUT);
   	Serial.print(pins[i]);Serial.print(" ");
  }
  
  Serial.print("\n");
}

void startAllPins()
{
  for(byte i=0; i<numberOfPins; i++)
  {
  	digitalWrite(pins[i], HIGH);
  }
}


void stopAllPins()
{
  for(byte i=0; i<numberOfPins; i++)
  {
  	digitalWrite(pins[i], LOW);
  }
}

void startDefinedLeds(byte qtd)
{
  if(qtd > 5) return;
  
  stopAllPins();
  
  for(int i=0; i< qtd; i++)
  {
    digitalWrite(pins[i], HIGH);
  }
  
}

void setup()
{
  Serial.begin(9600);
  
  setupPins();
}

void loop()
{
  int potValue = analogRead(analogPotPin);
  
  byte totalLeds = potValue / 123 ;
  
  startDefinedLeds(totalLeds);
  
  Serial.println(totalLeds);
  
}