#include <SoftwareSerial.h> //library untuk membuat pin digital di arduino menjadi Tx dan Rx.

#define trigPin 9 //trigerpin di arduino pin 9
#define echoPin 8 //echopin di arduino pin 8
const int buzzer = 7; //buzzer di arduino pin 7
SoftwareSerial Serial1(3,4);//Set Rx (Reciever) di pin 3, dan Tx (transmiter) di pin 4, lalu pasang Tx di Telemtry di Rx di arduino atau pin 3, dan pasang Rx di telemetry di Tx di arduino atau pin 4

void setup() {
 
Serial.begin (57600); //serial monitor di alat

Serial1.begin (57600); //serial monitor di monitor yang dikontrol dari jauh

pinMode(buzzer, OUTPUT); //buzzer di set menjadi output
  
pinMode(trigPin, OUTPUT); //trigerpin adalah pin yang mentransmisikan sinyal radio yang di set menjadi output

pinMode(echoPin, INPUT); //echopin adalah pin yang menerima sinyal radio yang di set menjadi input 

}

void loop() {
  

long duration, distance;
  
digitalWrite(trigPin, LOW); //set trigerpin low atau mati

delayMicroseconds(2); //selama 2 microsecond

digitalWrite(trigPin, HIGH); //set trigerpin high atau nyala

delayMicroseconds(10); //selama 10 microsecond

digitalWrite(trigPin, LOW); //set tigerpin low atau mati

duration = pulseIn(echoPin, HIGH); //nilai durasi adalah nilai pulsa yang masuk di pin echo yang di set high atau nyala

distance = duration*0.034/2; //distance atau jarak adalah ( (waktu*kecepatan suara)/2 )kecepatan suara itu sendiri sebesar 340m/s lalu diubah ke 0.034 cm/microsec jika diubah ke meter menjadi 0.00034 m/microsecond
  


  if(distance < 300){
    
Serial.print("Ada Kapal yang Mendekat");
Serial1.print("Ada Kapal yang Mendekat");
Serial.print(" Distance in Centimeter : ");
Serial.println(distance); //tampilkan nilai jarak di dalam serial monitor
Serial1.print(" Distance in Centimeter : ");
Serial1.println(distance); //tampilkan nilai jarak di dalam serial monitor   

  
tone(buzzer, 400); //gelombang suara sebesar 400 Hz

delay(1000); //Suara tersebut selama 1 detik  

noTone(buzzer); //Suara akan berhenti

delay(1000); //Berhenti selama 1 detik
} else{
  Serial.print("Tidak ada Kapal yang Mendekat");
  Serial1.print("Tidak ada Kapal yang Mendekat");
  Serial.print(" Distance in Centimeter : ");
  Serial.println(distance); //tampilkan nilai jarak di dalam serial monitor
  Serial1.print(" Distance in Centimeter : ");
  Serial1.println(distance); //tampilkan nilai jarak di dalam serial monitor   
  } 
   
}

