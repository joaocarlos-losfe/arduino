#define start_pin 13
#define end_pin 10

bool startedLEDs = true;

void setupPins()
{
  for(byte pin = start_pin; pin >= end_pin; pin--)
  {
    pinMode(pin, OUTPUT);
  }
}

void highAllPins()
{
  for(byte pin = start_pin; pin >= end_pin; pin--)
  {
    digitalWrite(pin, HIGH);
  }
}

void lowAllPins()
{
  for(byte pin = start_pin; pin >= end_pin; pin--)
  {
    digitalWrite(pin, LOW);
  }
}

void blinkInSequency(){
  for(byte pin = start_pin; pin >= end_pin; pin--)
  {
  	digitalWrite(pin, HIGH);
    delay(500);
    digitalWrite(pin, LOW);
    delay(500);
  }
}

void trafficLight(){


}

void setup()
{
  setupPins();
}

void loop()
{
  if(startedLEDs)
  {
    for(byte blink = 0; blink < 1; blink++)
    {
      highAllPins();
      delay(1000);
      lowAllPins();
      delay(1000);
    }
    
    startedLEDs = false;
  }
  
  blinkInSequency();
  
}