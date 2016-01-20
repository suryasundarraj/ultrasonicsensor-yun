/*********************************************************************************
SMART PARKING LOT SYSTEM
*********************************************************************************/
//Pin Setting for the 3 Ultrasonic Sensors
#define g_trigPin 13
#define g_echoPin 12
#define g_trigPin2 4
#define g_echoPin2 5
#define g_trigPin3 8
#define g_echoPin3 9

/**************************************************************************************
Function Name 		:	setup
Description		    :	Initialize the Sensor Trigger Pin as Output and 
                    echo pin as Input and begin the serial communication
                    with 9600 BAUD
Parameters 		    :	void
Return 			      :	void
**************************************************************************************/
//Initialize the Pins and BAUD rate 
void setup(void) {
        Serial1.begin (9600);
        Serial.begin(9600);
        pinMode(g_trigPin, OUTPUT);
        pinMode(g_echoPin, INPUT);
        pinMode(g_trigPin2, OUTPUT);
        pinMode(g_echoPin2, INPUT);
        pinMode(g_trigPin3, OUTPUT);
        pinMode(g_echoPin3, INPUT);
}

/**************************************************************************************
Function Name 		:	loop
Description		    :	Generate a Trigger signal and wait for the echo on 
                    HC-SR04 Ultrasonic Sensor and calculate the distance.
Parameters 		    :	void
Return 			      :	void
**************************************************************************************/
void loop(void) {
  //Variables to calculate the distance using the duration taken for 1 cycle of trigger and echo      
  long l_duration,l_distance,l_duration2,l_distance2,l_duration3,l_distance3;
  //Distance form the Ultrasonic Sensor 1
  //Generate a high pulse on Trigger Pin with 10 micro seconds delay and wait for the echo
  digitalWrite(g_trigPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(g_trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(g_trigPin, LOW);
  //Once received the Echo calculate the distance from the duration
  l_duration = pulseIn(g_echoPin, HIGH);
  l_distance = (l_duration/2) / 29.1;
  delay(300);
  
  //Distance form the Ultrasonic Sensor 2
  digitalWrite(g_trigPin2, LOW);
  delayMicroseconds(2); 
  digitalWrite(g_trigPin2, HIGH);
  delayMicroseconds(10); 
  digitalWrite(g_trigPin2, LOW);
  l_duration2 = pulseIn(g_echoPin2, HIGH);
  l_distance2 = (l_duration2/2) / 29.1;
  delay(300);
  
  //Distance form the Ultrasonic Sensor 3
  digitalWrite(g_trigPin3, LOW);
  delayMicroseconds(2); 
  digitalWrite(g_trigPin3, HIGH);
  delayMicroseconds(10); 
  digitalWrite(g_trigPin3, LOW);
  l_duration3 = pulseIn(g_echoPin3, HIGH);
  l_distance3 = (l_duration3/2) / 29.1;
  delay(300);
  l_distance = map(l_distance,0,500,5,300);
  l_distance2 = map(l_distance2,0,500,5,300);
  l_distance3 = map(l_distance3,0,500,5,300);
  String l_sensorStatus;
  l_sensorStatus += "{\"device1\":\"";
  l_sensorStatus += String(l_distance);
  l_sensorStatus += "\",\"device2\":\"";
  l_sensorStatus += String(l_distance2);
  l_sensorStatus += "\",\"device3\":\"";
  l_sensorStatus += String(l_distance3);
  l_sensorStatus += "\"}";
  Serial1.println(l_sensorStatus);
  //Provide a Delay for every 500 milli Seconds once data sent to the RPi
  delay(1000);
}

//End of the Program
/***************************************************************************************************/
