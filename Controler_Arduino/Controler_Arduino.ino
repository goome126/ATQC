int pitch=0,roll=0,yah=0,altitude=0,command;
void setup() {
  //short command;  //pitch 1, roll 2, yah 3, altitude 4
  Serial.begin(57600);
  while (!Serial) { }
  Serial.println("Arduino Online");
}

void loop() {
    command = Serial.parseInt();

  if(command == 1)
    pitch = Serial.parseInt();

  if(command == 2)
    roll = Serial.parseInt();

  if(command == 3)
    yah = Serial.parseInt();

  if(command == 4)
    altitude = Serial.parseInt();

  analogWrite(11, pitch); 
  analogWrite(10, roll);
  analogWrite(9, yah);
  analogWrite(6, altitude);
}
