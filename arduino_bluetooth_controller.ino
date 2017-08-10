/* 
 * Easy Bluetooth Controller
 * 
 * For use with the Arduino Bluetooth Controller by Giumig Apps
 * 
 * Yonder Dynamics 2017
 *
 */

char val;

void setup() {
  Serial.begin(9600);
}

void parseCommand(char input) {
  switch (input) {
    case '1': // LEFT
      //turnLeft();   
      break;
    case '2': // UP
      //setVelocity(1);
      break;
    case '3': // RIGHT
      //turnRight();
      break;
    case '4': // DOWN
      //setVelocity(-1)
      break;
    case '5': // SELECT
      //toggleMode();
      break;
    case '6': // START
      //pause();
      break;  
    case 's': // SQUARE
      //hop();
      break; 
    case 't': // TRIANGLE
      //skip();
      break;  
    case 'x': // X
      //jump();
      break;
    case 'c': // CIRCLE
      //crawl();
      break;
  }
}

    
void loop() {
  
  // Check for incoming command
  if (Serial.available()) {
    val=Serial.read(); 
    Serial.println(val); // Use the IDE's Tools > Serial Monitor
    parseCommand(val); // parse the input
  }

}

                  
