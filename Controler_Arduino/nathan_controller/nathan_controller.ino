int pitch,altitude,yaw,roll;

void setup() {
  Serial.begin(9600);
  Serial.println("Controller Running");
}

void loop() {
char pos1,pos2,pos3;

switch (Serial.read()) {
case '1':
 delay(5);
 pos1 = Serial.read();
 Serial.println(pos1);
 pitch = ((int)pos1 - 48) * 100;
 pos2 = Serial.read();
 Serial.println(pos2);
 pitch = pitch + ((int)pos2 - 48) * 10;
 pos3 = Serial.read();
 Serial.println(pos3);
 pitch = pitch + ((int)pos3 - 48);
 Serial.print("pitch = ");
 Serial.println(pitch);
 break;
    
case '2':
 delay(5);
 pos1 = Serial.read();
 Serial.println(pos1);
 roll = ((int)pos1 - 48) * 100;
 pos2 = Serial.read();
 Serial.println(pos2);
 roll = roll + ((int)pos2 - 48) * 10;
 pos3 = Serial.read();
 Serial.println(pos3);
 roll = roll + ((int)pos3 - 48);
 Serial.print("roll = ");
 Serial.println(roll);
 break;

case '3':
 delay(5);
 pos1 = Serial.read();
 Serial.println(pos1);
 yaw = ((int)pos1 - 48) * 100;
 pos2 = Serial.read();
 Serial.println(pos2);
 yaw = yaw + ((int)pos2 - 48) * 10;
 pos3 = Serial.read();
 Serial.println(pos3);
 yaw = yaw + ((int)pos3 - 48);
 Serial.print("yaw = ");
 Serial.println(yaw);
 break;
   
case '4':
 delay(5);
 pos1 = Serial.read();
 Serial.println(pos1);
 altitude = ((int)pos1 - 48) * 100;
 pos2 = Serial.read();
 Serial.println(pos2);
 altitude = altitude + ((int)pos2 - 48) * 10;
 pos3 = Serial.read();
 Serial.println(pos3);
 altitude = altitude + ((int)pos3 - 48);
 Serial.print("altitude = ");
 Serial.println(altitude);
 break;

 default:
 
 break;
}
    Serial.flush();
    analogWrite(11,pitch);
    analogWrite(10,roll);
    analogWrite(9,yaw);
    analogWrite(6,altitude);
  
}
