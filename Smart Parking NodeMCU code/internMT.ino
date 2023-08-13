#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Firebase.h>  
#include <FirebaseArduino.h>  
#include <FirebaseCloudMessaging.h>  
#include <FirebaseError.h>  
#include <FirebaseHttpClient.h>  
#include <FirebaseObject.h>      
#include <FirebaseArduino.h>  

// //Provide the token generation process info.
// #include "addons/TokenHelper.h"
// //Provide the RTDB payload printing info and other helper functions.
// #include "addons/RTDBHelper.h"

#define FIREBASE_HOST "smart-parking-project-csd-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "mykoBVAu3sC2rfOeBtegJN2gP0oK8O4Nb5nsRh6a"  
#define WIFI_SSID "Redmi mk"  
#define WIFI_PASSWORD "mk123456"  
  
//Define Firebase Data object
// FirebaseData fbdo;
// FirebaseAuth auth;
// FirebaseConfig config;

const int trigPin = 12;
const int echoPin = 14;

//define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034

long duration;
float distanceCm;
int count = 0;

void setup() {
  Serial.begin(115200); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

 WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();  
  Serial.print("connected: ");  
  Serial.println(WiFi.localIP());
  Serial.println();          

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
  //    /* Assign the api key (required) */
  // config.api_key = API_KEY;

  // /* Assign the RTDB URL (required) */
  // config.database_url = DATABASE_URL;

  // /* Assign the callback function for the long running token generation task */
  // config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  // Firebase.begin(&config, &auth);
  // Firebase.reconnectWiFi(true);  
}
 
int slot1 = 0;
int slot2 = 0;
int slot3 = 0;
int slot4 = 0;
int n=0;

void loop() {

  // Firebase.setString("CHECK", "YESSSSSSS");
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_VELOCITY/2;
  
  String dis = String(distanceCm);
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);

  if(distanceCm<10.0)
  {
     Serial.print("Slot is Occupied ");
     slot1=1;
  }
  else
  {
     Serial.print("Slot is Empty!");
     slot1=0;
  }
   // set value  
  Firebase.setFloat("slot1", slot1);  
  // handle error  
  if (Firebase.failed()) {  
      Serial.print("setting /number failed:");  
      Serial.println(Firebase.error());    
      return;  
  }  
  
  delay(1000);

  // append a new value to /logs  
  String name = Firebase.pushInt("logs", n++);  
  // handle error  
  if (Firebase.failed()) {  
      Serial.print("pushing /logs failed:");  
      Serial.println(Firebase.error());    
      return;  
  }  
  Serial.print("pushed: /logs/"); 
  Serial.println(name);  
  delay(1000);  

  // if (Firebase.RTDB.setInt(&fbdo, "test/int", count)){
  //     Serial.println("PASSED");
  //     Serial.println("Distance: ");
  //     Serial.println(distanceCm);
  //   }
  //   else {
  //     Serial.println("FAILED");
  //     Serial.println("REASON: " + fbdo.errorReason());
  //   }
}