#include <AnalogDistanceSensor.h>
#include <CombinedDistanceSensors.h>
#include <DistanceGP2Y0A21YK.h>
#include <DistanceGP2Y0A41SK.h>
#include <DistanceSensor.h>
#include <DistanceSRF04.h>
#include <UltrasonicDistanceSensor.h>

#include <Servo.h>
#include <LiquidCrystal.h>
#include <DistanceGP2Y0A21YK.h>

Servo esc1,esc2;
int a;
int limitdpn = 31;
int limitblk = 33;
char data = 0;
int br1=37,br2=36;
const int pingPin = 25;
long duration, cm;

DistanceGP2Y0A21YK Dist;
int distance;

void setup() {
  Serial1.begin(9600);
  Serial.begin(115200);
  esc1.attach(30);        //esc
  esc2.attach(32);
  esc1.write(10);
  esc2.write(10);
  pinMode(26, OUTPUT);//pn_a1
  pinMode(31, INPUT);
  pinMode(33, INPUT);
  pinMode(24, OUTPUT);//pn_a1
  pinMode(27, OUTPUT);//pn_a2
  pinMode(29, OUTPUT);//pn_b1
  pinMode(23, OUTPUT);//pn_b2
  pinMode(13, OUTPUT); //motor 1 
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT); //motor 2
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT); //motor naik turun
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT); //motor 3
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(53, OUTPUT); //pw
  pinMode(51, OUTPUT);
  pinMode(49, OUTPUT);
  
  digitalWrite(13, HIGH);//motor 1
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);//motor 2
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);//motor naik turun
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);//motor 3
  digitalWrite(3, HIGH);
  digitalWrite(2, HIGH);  
  digitalWrite(53, HIGH);//motor pw
  digitalWrite(51, HIGH);
  digitalWrite(49, HIGH);  
  //Dist.begin(A2);

}
void ping1()
{
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin,LOW); 

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  //distance = (duration / 2) * 0.0344 + 1;
  cm = microsecondsToCentimeters(duration);
  Serial.print("\t");
  Serial.print("\t");
  Serial.print(cm);
  Serial.print("cm");
 Serial.println();
  delay(20);
}

void drng()
{
  digitalWrite(53, LOW);//motor pw
  digitalWrite(51, HIGH);
  digitalWrite(49, LOW); 
}
void dorong()
{
  
  while(digitalRead(25)==HIGH){
  Serial.println("limit on");
  digitalWrite(53, LOW);//motor pw
  digitalWrite(51, HIGH);
  digitalWrite(49, HIGH);
  }
  while(digitalRead(33)==HIGH){
  Serial.println("limit belakang on");
  digitalWrite(53, HIGH);//motor pw
  digitalWrite(51, LOW);
  digitalWrite(49, LOW);
  delay(500);
  digitalWrite(53, HIGH);//motor pw
  digitalWrite(51, HIGH);
  digitalWrite(49, HIGH);
  } 
 }
  
void sharp()
 {
  distance = analogRead(A2);
  Serial.print("Distance in centimeters: ");
  Serial.println(distance);
  delay(150); 
 }

void naik1()
{ 
  ping1();
  while(cm >= 10 )
  {
  analogWrite(7, 20);
  digitalWrite(5, LOW);
  ping1();
   }
  stoptor();
//  goto ss;
//  
//  ss:
//  while(1){
  delay(100);
  digitalWrite(24, HIGH);
  delay(1500);
  digitalWrite(24, LOW);
  digitalWrite(26, HIGH);
  delay(1000);
  digitalWrite(26, LOW);

}

void naik()
{
  sharp();
  while(distance >= 12)
    {
      analogWrite(7, 10);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
    sharp();
    }
    stoptor();
  delay(1000);
  digitalWrite(24, HIGH);
  delay(500);
  digitalWrite(26, LOW);
  delay(1000);
  digitalWrite(24, HIGH);
  delay(500);
  digitalWrite(26, LOW);
  
} 

void turun()
{
    
   analogWrite(7, 10);
   digitalWrite(6, LOW);
   digitalWrite(5, HIGH);
  
}
void mandek()
{
  esc1.write(br1=37);
  esc2.write(br2=37);
}
void nambah()
{
  if (br1 <= 150 ) {br1 = br1 +1;}
        if (br1 >= 38)
            { 
              esc1.write(br1);
            }
        else 
              esc1.write(br1);
              delay(20); 
}
void kurang()
{
  if (br1>=39 ) {br1 = br1 -1;}
        if (br1 <= 150)
            { 
              esc1.write(br1);              
            }
        else  
              esc1.write(br1);
              delay(20);
}
void mandek1()
  {
    esc2.write(br2=37);
  }
void nambah1()
{
  if (br2 <= 150 ) {br2 = br2 +1;}
        if (br2 >= 38)
            { 
              esc2.write(br2);
            }
        else 
              esc2.write(br2);
              delay(20); 
}
void kurang1()
{
  if (br2>=39 ) {br2 = br2 -1;}
        if (br2 <= 150)
            { 
              esc2.write(br2);              
            }
        else 

              esc2.write(br1);
              delay(20);
}
void angin()
{  
  digitalWrite(27, HIGH);
  delay(500);
  digitalWrite(27, LOW);
}
void angintutup()
{
  digitalWrite(29, HIGH);
  delay(500);
  digitalWrite(29, LOW);
}

void maju()
{
  analogWrite(13, 116); //kanan
  digitalWrite(12, LOW);
  analogWrite(10, 138); //kiri
  digitalWrite(8, LOW);
}
void mundur()
{
  analogWrite(13, 116); //kanan
  digitalWrite(11, LOW);
  analogWrite(10, 138); //kiri
  digitalWrite(9, LOW);
}
void kiri()
{
  analogWrite(13, 167); //kanan
  digitalWrite(11, LOW);
  analogWrite(4, 80); //belakang
  digitalWrite(3, LOW);
  analogWrite(10, 200); //kiri
  digitalWrite(8, LOW);
}
void kanan()
{
  analogWrite(13, 200); //kanan
  digitalWrite(12, LOW);
  analogWrite(4, 80); //belakang
  digitalWrite(2 , LOW);
  analogWrite(10, 167); //kiri
  digitalWrite(9, LOW);
}
void putkan()
{
  analogWrite(13, 170); //kanan
  digitalWrite(11, LOW);
  analogWrite(4, 170); //belakang
  digitalWrite(2, LOW);
  analogWrite(10, 170); //kiri
  digitalWrite(8, LOW);
}
void putkir()
{
  analogWrite(13, 170); //kanan
  digitalWrite(12, LOW);
  analogWrite(4, 170); //belakang
  digitalWrite(3, LOW);
  analogWrite(10, 170); //kiri
  digitalWrite(9, LOW);
}

void majupelan()
{
  analogWrite(13, 186); //kanan
  digitalWrite(12, LOW);
  analogWrite(10, 208); //kiri
  digitalWrite(8, LOW);
}
void mundurpelan()
{
  analogWrite(13, 186); //kanan
  digitalWrite(11, LOW);
  analogWrite(10, 208); //kiri
  digitalWrite(9, LOW);
}
void kiripelan()
{
  analogWrite(13, 190); //kanan
  digitalWrite(11, LOW);
  analogWrite(4, 160); //belakang
  digitalWrite(3, LOW);
  analogWrite(10, 234); //kiri
  digitalWrite(8, LOW);
}
void kananpelan()
{
  analogWrite(13, 190); //kanan
  digitalWrite(12, LOW);
  analogWrite(4, 160); //belakang
  digitalWrite(2 , LOW);
  analogWrite(10, 234); //kiri
  digitalWrite(9, LOW);
}
void putkanpelan()
{
  analogWrite(13, 230); //kanan
  digitalWrite(11, LOW);
  analogWrite(4, 230); //belakang
  digitalWrite(2, LOW);
  analogWrite(10, 230); //kiri
  digitalWrite(8, LOW);
}
void putkirpelan()
{
  analogWrite(13, 230); //kanan
  digitalWrite(12, LOW);
  analogWrite(4, 230); //belakang
  digitalWrite(3, LOW);
  analogWrite(10, 230); //kiri
  digitalWrite(9, LOW);
}

void stoptor()
{
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);

  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  
  digitalWrite(7, HIGH);//motor naik turun
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  
  digitalWrite(4, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(2, HIGH);
  
//  digitalWrite(53, HIGH);//motor pw
//  digitalWrite(51, HIGH);
//  digitalWrite(49, HIGH); 
   
}
void loop() {
  bismillah:
  if (Serial1.available()){
    a = Serial1.read();
  
  if (a == 'A')
  {
    Serial.println("a");
    maju();
  }
  
  else if (a == 'B')
  {
    Serial.println("b");
    mundur();
  }
  
  else if(a == 'D')
  {
    Serial.println("d");
    kiri();
  }  
  else if(a == 'C')
  {
    Serial.println("c");
    kanan();
  }
  
  else if(a == '1')
  {
    Serial.println("1");
    majupelan();
  }
  
  else if(a == '2')
  {
    Serial.println("2");
    mundurpelan();
  }
  
  else if(a == '4')
  {
    Serial.println("4");
    kiripelan();
  }
  
  else if(a == '3')
  {
    Serial.println("3`");
    kananpelan();
  }

  else if(a == '5')
  {
    Serial.println("5");
    nambah1();
  }
  
  else if(a == '6')
  {
    Serial.println("6");
    kurang1();
  }
  
  else if(a == '7')
  {
    Serial.println("7");
    putkan();
  }

  else if(a == '8')
  {
    Serial.println("8");
    putkir();
  }
  
  else if(a == '0')
  {
    Serial.println("0");
    angin();
  }

  else if(a == 'E')
  {
    Serial.println("e");
    putkirpelan();
  }
  
  else if(a == 'F')
  {
    Serial.println("f");
    putkanpelan();
  }
  
  else if(a == 'H')
  {
    Serial.println("h");
    naik1();                                                                 
  }
  
  else if(a == 'I')
  {
    Serial.println("i");
    turun(); 
  }
  
  else if(a == 'K')
  {
    Serial.println("k");
    while(1){
      
      if(digitalRead(31)==HIGH)
      {
        while(1){
        digitalWrite(53, HIGH);//motor pw
        digitalWrite(51, LOW);
        digitalWrite(49, LOW);
        goto aaaa;
        }
      }
      else
      {
        digitalWrite(53, LOW);//motor pw
        digitalWrite(51, HIGH);
        digitalWrite(49, LOW);
      }    
    }
          aaaa:
   while(1)
   {
      
    if(digitalRead(33)==HIGH)
      {
      Serial.println("limit belakang on");
      digitalWrite(53, HIGH);//motor pw
      digitalWrite(51, HIGH);
      digitalWrite(49, LOW);
      delay(500);
      digitalWrite(53, HIGH);//motor pw
      digitalWrite(51, HIGH);
      digitalWrite(49, HIGH);
      delay(150); 
      
      goto bismillah;
      }
    } 
      
  }
  
  else if(a == 'J')
  {
    Serial.println("j");
    kurang();
  }
  
  else if(a == 'P')
  {
    Serial.println("p");
    nambah();
  }
  
  else if(a == 'Y')
  {
    Serial.println("y");
    mandek();
   // mandek1();
  }
    
  else if(a == 'V')
  {
    Serial.println("v");
    angintutup();
  }
  
  else if(a == 'L')
  {
    Serial.println("l");
  }
  
  else if(a == 'X')
  {
    Serial.println("x");
  }
  
  else if(a == 'Z')
  {
    stoptor();
    Serial.println("z");
  }
  }

} 
  long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}




