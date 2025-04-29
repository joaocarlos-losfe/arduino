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

void flashingLEDs()
{
  startAllPins();
  delay(1000);
  stopAllPins();
  delay(1000);
}

void decimalToBinary(byte number) {
  stop = true;

  byte binNumber[5] = {0, 0, 0, 0, 0}; 
  byte result = number;
  byte i = 0;

  Serial.print(number);
  Serial.print(": ");

  do {
    byte mod = result % 2;
    result = result / 2;
    binNumber[i] = mod;
    i++;
  } while (result > 0);

  for (int j = numberOfPins - 1; j >= 0; j--) {
    Serial.print(binNumber[j]);
    
    digitalWrite(pins[j], binNumber[j] == 0 ? LOW : HIGH);
  }
  Serial.println();
}
               
void setup() {
  Serial.begin(9600);
  setupPins();
  
  Serial.print("Total de pinos: \n");
  Serial.print(numberOfPins);
}
              

void loop()
{
  byte value = 0;
  
  //if(!stop) decimalToBinary(22);
  
  while(true)
  {
    if(value == 32) value = 0;
  	decimalToBinary(value);
    delay(1000);
    value+=1;
  }
  
  
}