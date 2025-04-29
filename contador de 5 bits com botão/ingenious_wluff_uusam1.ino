const byte START_PIN = 2;
const byte END_PIN = 6;
const byte BUTTON_PIN = 13;
int incState = 0;

void setupPins() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  for (byte pin = START_PIN; pin <= END_PIN; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void highAllPins() {
  for (byte pin = START_PIN; pin >= END_PIN; pin++) {
    digitalWrite(pin, HIGH);
  }
}

void lowAllPins() {
  for (byte pin = START_PIN; pin <= END_PIN; pin++) {
    digitalWrite(pin, LOW);
  }
}

void startDefinedLeds(int currentStateValue){
  for(byte i=0; i<currentStateValue; i++){
  	Serial.print(i);
    
    digitalWrite(START_PIN + i, HIGH);
    
  }
}

void setup() {
  Serial.begin(9600);
  setupPins();
}

void loop() {
 
  
  if(digitalRead(BUTTON_PIN) == LOW){
    incState += 1;
    
    if(incState > 5) {
      incState = 0;
      Serial.print("Desligar todos os leds");
      lowAllPins();
    }
   
  	startDefinedLeds(incState);
  	delay(300);
  }
  
  
}