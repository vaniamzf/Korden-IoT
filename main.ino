#include <Servo.h>
Servo myservo;  

const int pinMotor_Servo = 2; //nama alias untuk pin 2
const int pinLDR = A1; //nama alias untuk pin A1

int sensorValueLDR = 0; //variabel penampung nilai LDR
float pos_servo = 0; //variabel penampung nilai posisi servo 
float a=180; //nilai maksimum posisi servo
float b=252; //nilai maksimum output tegangan LDR
float x; //kontanta nilai posisi servo

void setup()
{
  pinMode(pinMotor_Servo, OUTPUT); //status pin servo = output
  pinMode(pinLDR, INPUT); //status pin LDR = input

  myservo.attach(pinMotor_Servo); //beri tahu library servo bahwa servo terhubung ke pinMotor_Servo   
  Serial.print(9600); //inisialisasi kecep transfer data ke serial monitor = 9600 bps
}

void loop()
{   
  sensorValueLDR = analogRead(pinLDR); //menampung nilai dari LDR
  Serial.print(sensorValueLDR); //menampilkan nilai LDR ke serial monitor
  
  x = a/b; //menghitung konstanta posisi servo 
  pos_servo = x*sensorValueLDR; //menghitung posisi servo fungsi dari LDR
  Serial.print("  "); //beri spasi ke serial monitor 
  Serial.println(pos_servo); //menampilkan nilai posisi servo 

  myservo.write(pos_servo); //memerintahkan servo ke posisi yang ditunjuk                 
  delay(20); //Beri waktu untuk servo menuju ke posisi tujuan
}

