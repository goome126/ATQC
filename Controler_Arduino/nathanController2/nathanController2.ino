int pitch,altitude,yaw,roll,command,value;

void setup() {
  Serial.begin(9600); //Initalize serial
  Serial.println("Controller Running"); //Make sure serial is initialized
  Serial.setTimeout(5); //Reduce delay on readstring
}

void loop() {
String cline = Serial.readString(); //Read a string out of serial and assign that to cline
char commandChar = cline.charAt(0); //Take the first character out of the string to determine what you're controlling
command = (int)commandChar - 48; //Convert that character to an int
value = cline.substring(1).toInt(); //Store the actual value you're trying to pass into a value

switch (command) { //Have a switch statement that determines what you're controlling
case 1:
 pitch = value;
 Serial.print("pitch = ");
 Serial.println(pitch);
 break;
    
case 2:
 roll = value; 
 Serial.print("roll = ");
 Serial.println(roll);
 break;

case 3:
 yaw = value; 
 Serial.print("yaw = ");
 Serial.println(yaw);
 break;
   
case 4:
 altitude = value; 
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
