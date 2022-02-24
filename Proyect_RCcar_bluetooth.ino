# include <Servo.h>
#define Pecho 3
#define Ptrig 2
int m1a = 10;            //Motor 1, pin 10 del arduino va al pin 15 del L293B.
int m1b = 9;             //Motor 1, pin 9 del arduino va al pin 10 del L293B.
int m2a = 12;            //Motor 2, pin 12 DEL arduino va al pin 2 del L293B.
int m2b = 11;            //Motor 2, pin 11 del arduino va al pin 7 del L293B.
int led=13;
int led2= 7;
Servo servo1;
long duracion, distancia;
char val;

void setup() 
{  
servo1.attach(5);
pinMode(m1a, OUTPUT);  // Digital pin 10 set as output Pin
pinMode(m1b, OUTPUT);  // Digital pin 9 set as output Pin
pinMode(m2a, OUTPUT);  // Digital pin 12 set as output Pin
pinMode(m2b, OUTPUT);  // Digital pin 11 set as output Pin
pinMode(Pecho,INPUT);
pinMode(Ptrig,OUTPUT);
pinMode(led,OUTPUT);
pinMode(led2,OUTPUT);
Serial.begin(9600);
}

void loop()
{
  
 digitalWrite (Ptrig,LOW);
 delayMicroseconds(2);
 digitalWrite(Ptrig,HIGH);
 delayMicroseconds(10);
 digitalWrite(Ptrig,LOW);
 duracion= pulseIn(Pecho,HIGH);
 distancia= (duracion/2)/29; 

     digitalWrite(Ptrig, HIGH);   // genera el pulso de trigger por 10us
     delay(0.01);
     digitalWrite(Ptrig, LOW);
     
     duracion = pulseIn(Pecho, HIGH);          // Lee el tiempo del Echo
     distancia = (duracion/2) / 29;            // calcula la distancia en centimetros
     delay(10); 
     
    
 
  while (Serial.available() > 0)
  {
  val = Serial.read();
  Serial.println(val);
  }
   if (distancia <= 15 && distancia >=2){    // si la distancia es menor de 15cm
        digitalWrite(13,HIGH);                 // Enciende LED
        
        digitalWrite(m1a, LOW);             // Parar los motores por 200 mili segundos
        digitalWrite(m1b, LOW); 
        digitalWrite(m2a, LOW);    
        digitalWrite(m2b, LOW); 
        delay (200);
        
        digitalWrite(m1b, HIGH);          // Reversa durante 500 mili segundos
        digitalWrite(m2b, HIGH); 
        delay(500);           
        
        
        digitalWrite(13,LOW);
        digitalWrite(m1b, LOW);          // Reversa durante 500 mili segundos
        digitalWrite(m2b, LOW); 
        delay(500);          
  }
   if( val == '1')                   // FOCOS ON
    {
      digitalWrite(led2, HIGH);
    }
   if( val == 'W')                   // prender led
    {
     
      digitalWrite(led2,HIGH);  
    }
    if( val == 'w')                   // apagar led
    {
     
      digitalWrite(led2,LOW);  
    }

  if( val == 'F')                   // Hacia adelante
    {
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);  
    }
     if( val == 'G')                   // Hacia adelante izquierda
    {
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);  
       servo1.write(50);
      delay (15);
      
    }
  else if(val == 'B')              // Hacia atras
    {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH); 
    }
      if( val == 'H')                   // Hacia atras izquierda
    {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);  
       servo1.write(50);
      delay (15);
      
    }
      if( val == 'I')                   // Hacia adelante izquierda
    {
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);  
       servo1.write(100);
      delay (15);
      
    }
      if( val == 'J')                   // Hacia atras derecha
    {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);  
       servo1.write(100);
      delay (15);
      
    }
    if (val== 'R')                // Hacia la derecha
    {
    servo1.write(100);
    delay (15);
  }
  if (val== 'L')                // Hacia la izquierda
    {
    servo1.write(50);
    delay (15);
  }
      else if(val == 'S')               //Stop - Pare, Carrito detenido
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 
    servo1.write(70);
    
    } 
  
   }
    
