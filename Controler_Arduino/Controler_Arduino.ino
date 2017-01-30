void setup() {
  //short command;  //pitch 1, roll 2, yah 3.
  int pitch=0,roll=0,yah=0,altitude=0,command;
  Serial.begin(57600);
  while (!Serial) { }
  Serial.println("Arduino Online");
}

void loop() {
  command = Serial.parseInt();

  if(command == 1)
    pitch = Serial.read();

  if(command == 2)
    roll = Serial.read();

  if(command == 3)
    yah = Serial.read();

  if(command == 4)
    altitude = Serial.read();

  analogWrite(11, pitch); 
  analogWrite(10, roll);
  analogWrite(9, yah);
  analogWrite(6, altitude);
}
