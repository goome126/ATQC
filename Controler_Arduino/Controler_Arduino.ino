int pitch=0,roll=0,yah=0,altitude=0;
short command;
void setup() {
  Serial.begin(250000);
  while (!Serial) { }
  Serial.println("Arduino Online");
}

void loop() {
    
    command = nextInt();   //pitch 1, roll 2, yah 3, altitude 4
    Serial.println(command);

  if(command == 1) {
    pitch = nextInt();
    Serial.println("pitch=");
    Serial.println(pitch);
  }

  if(command == 2) {
    roll = nextInt();
    Serial.println("roll=");
    Serial.println(roll);
  }

  if(command == 3) {
    yah = nextInt();
    Serial.println("yah=");
    Serial.println(yah);
  }

  if(command == 4) {
    altitude = nextInt();
    Serial.println("altitude=");
    Serial.println(altitude);
  }

  analogWrite(11, pitch); 
  analogWrite(10, roll);
  analogWrite(9, yah);
  analogWrite(6, altitude);
}

int nextInt() {
  int input = NULL;
  while (input == NULL) {
    input = Serial.parseInt();
  }
  return input;
}

