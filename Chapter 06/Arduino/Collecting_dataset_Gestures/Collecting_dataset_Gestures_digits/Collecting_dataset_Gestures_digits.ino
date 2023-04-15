// CODE TO COLLECT DATASET FOR DIFFERENT AIR DIGIT RECOGNITION

#include <Arduino_LSM6DSOX.h>
unsigned int i=0;
void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println(" Board Failed to Initialize IMU, check the settings and configurations again !");
    while(1);
  }

  // Print the dataset header information

  Serial.println("timestamp,Accx,Accy,Accz");
}

void loop() {
  float Accx, Accy, Accz;

    if (IMU.accelerationAvailable()) {
      
      // READ THE DATA FROM ACCELEROMETER AND GYROSCOPE SENSORS
      
      IMU.readAcceleration(Accx,Accy,Accz);
      
      // Print the data in CSV format so that we can upload in Edge Impusle 
      
      Serial.print(i);
      Serial.print(',');
      Serial.print(Accx,3);
      Serial.print(',');
      Serial.print(Accy,3);
      Serial.print(',');
      Serial.print(Accz,3);
      Serial.println();
      i=i+40;
      delay(40);
       
    }
  
}
