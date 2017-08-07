//If youre not using a BTBee connect set the pin connected to the KEY pin high
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(4,5); 
void setup() {
  
  String setName = String("AT+NAME=arduino\r\n"); //Setting name as 'MyBTBee'
  
  Serial.begin(9600);
  BTSerial.begin(38400);
  BTSerial.print("AT\r\n"); //Check Status
  delay(500);
  
  // Acquiring signal........
  while (BTSerial.available()) Serial.write(BTSerial.read());
  
  BTSerial.print(setName); //Send Command to change the name
  delay(500);
  
}

void parseCommand(int c, float *velocity, float *bearing) {
  
  if (true) {
   
    *velocity=0.0;
    *bearing=0.0; 
  }
  else {
    // No change to velocity or bearing
  }
}
    
void loop() {
  
  int command=0;
  float velocity=0;
  float bearing=0;

  // Continuously receive commands
  // If signal is lost, restart Arduino
  while (BTSerial.available()) {
    command=BTSerial.read(); 
    Serial.write(command);
    
    // Get velocity and directional input from incoming message
    parseCommand(command, &velocity, &bearing);  
    
    
    // SYSTEM SPECIFIC CONTROL CODE HERE


    // END
  }
}

                  
