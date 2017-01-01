unsigned long lastTransmit = 0;
int refreshTime = 30;

int tick = 0;

unsigned char colors[3][3] = {
    {0,   0, 255},
    {0, 255,   0},
  {255,   0,   0}
};

int mapping[10] =  { 37,33,29,25,21,17,13,9,5,1};


void setup() {
  Serial.begin(115200);
}

void loop() {
  if(millis() - lastTransmit >= refreshTime)
  {
    
    
    lastTransmit = millis();
    for (int i = 0; i < 80; i++) {
      if ((i/4) % 2 == 0 ) {
          Serial.write(tick%255);
          Serial.write(0);
          Serial.write(0);
        } else {
          
          Serial.write(0);
Serial.write(tick%255);
          Serial.write(0);
        }
      }
      
    tick++;
  }
  //delay(refreshTime);
}
