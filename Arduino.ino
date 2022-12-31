// C++ code
//
void setup()
{
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(6900);
}
//int pins[] = {2,3,4,5,6,7};
//int pinsReverse[] = {7,6,5,4,3,2};
//int cloudPin = 8;

int pins[] = {4,5,6,8,9,10};
int pinsReverse[] = {10,9,8,6,5,4};
int cloudPin = 2;

void loop()
{
  
  clouds(cloudPin);
  
  // led lighting sequence
  for (byte i = 0; i < 3; i++){
    for (byte i = 0; i < (sizeof(pins) / sizeof(pins[0])); i++) {          
      digitalWrite(pins[i], HIGH);
      delay(100);
    }
    for (byte i = 0; i < (sizeof(pins) / sizeof(pins[0])); i++) {    
      digitalWrite(pins[i], LOW);
      delay(100);
    }
    clouds(cloudPin);
  }
  
  // led lighting sequence reverse
  for (byte i = 0; i < 3; i++){
    clouds(cloudPin);
    
    for (byte i = 0; i < (sizeof(pinsReverse) / sizeof(pinsReverse[0])); i++) {          
      digitalWrite(pinsReverse[i], HIGH);
      delay(100);
    }
    for (byte i = 0; i < (sizeof(pinsReverse) / sizeof(pinsReverse[0])); i++) {    
      digitalWrite(pinsReverse[i], LOW);
      delay(100);
    }
  }
  
  
  // Interspersed
  for (byte i = 0; i < 3; i++){
    for (byte i = 0; i < (sizeof(pins) / sizeof(pins[0])); i++) {    
      digitalWrite(pins[i], LOW);
      if(i % 2 == 0){
        digitalWrite(pins[i], HIGH);
        clouds(cloudPin);
        delay(200);
      }
    }
    
    delay(750);
    
    for (byte i = 0; i < (sizeof(pins) / sizeof(pins[0])); i++) {    
      digitalWrite(pins[i], LOW);
      clouds(cloudPin);
    }
    
    delay(500);
    
    for (byte i = 0; i < (sizeof(pins) / sizeof(pins[0])); i++) {    
      digitalWrite(pins[i], LOW);
      if(i % 2 == 1){
        digitalWrite(pins[i], HIGH);
        clouds(cloudPin);
        delay(200);
      }
    }
    
    clouds(cloudPin);
    clouds(cloudPin);
    delay(500);
  }
  
}

void clouds(int pin){
  digitalWrite(pin, HIGH);
  delay(25);
  digitalWrite(pin, LOW);
  delay(25);
  digitalWrite(pin, HIGH);
  delay(25);
  digitalWrite(pin, LOW);
}
