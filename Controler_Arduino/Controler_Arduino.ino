/*
    Copyright (C) 2017

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */unsigned short pitch,altitude,yaw,roll;

void setup() {
  Serial.begin(9600); //Initalize serial
  Serial.println("Controller Running"); //Make sure serial is initialized
  while (Serial.available() < 1) {} //wait until there is at least one byte comming from Serial
}

// this method reads a command and value as one byte, using the first 2 bits to determine the
// command and the last 6 to determine the value to set. Because 6 bits can only hold numbers
// between 0 and 63, we multiply by 2 to get numbers between 0 and 126. So only even numbers can
// be used as values to set.

void loop() {
  int input = Serial.read(); //Read one byte of Serial
  int command = input/64; //get front two bits
  int value = 2*(input%64); //get last 6 bits with modular division

  switch (command) { //Have a switch statement that determines what you're controlling
    case 1:
      pitch = value;
      Serial.println("pitch = " + pitch);
    break;
    
    case 2:
     roll = value; 
     Serial.println("roll = " + roll);
     break;
    
    case 3:
     yaw = value; 
     Serial.println("yaw = " + yaw);
     break;
       
    case 0:
     altitude = value; 
     Serial.println("altitude = " + altitude);
     break;
    
     default:
     
     break;
  }

  if(Serial.available() == false){//If we loss connection to the computer we drop
    pitch = 0;
    roll = 0;
    yaw = 0;
    altitude = 0;
  }
    Serial.flush();
    analogWrite(11,pitch);
    analogWrite(10,roll);
    analogWrite(9,yaw);
    analogWrite(6,altitude);
}
