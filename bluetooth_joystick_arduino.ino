//If youre not using a BTBee connect set the pin connected to the KEY pin high
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(4,5); 
void setup() {
  
  String setName = String("AT+NAME=arduino\r\n"); //Setting name as 'MyBTBee'
  String command="";
  
  Serial.begin(9600);
  BTSerial.begin(38400);
  BTSerial.print("AT\r\n"); //Check Status
  delay(500);
  
  // Acquiring signal........
  while (BTSerial.available()) Serial.write(BTSerial.read());
  
  BTSerial.print(setName); //Send Command to change the name
  delay(500);
  
  // Continuously receive commands
  // If signal is lost, restart Arduino
  while (BTSerial.available()) {
    command=BTSerial.read();   
    Serial.write(command);
  }
}
    
void loop() {}

                  
