#include <Time.h>

int motor_d_f = 10;
int motor_d_t = 9;
int motor_e_t = 8;
int motor_e_f = 7;

int vele = 11;
int veld = 6; 

//Velocidades
int reto1 = 150;
int reto2 = 150; 
int curva_direita1 = 150;
int curva_direita2 = 150; 
int curva_esquerda1 = 150;
int curva_esquerda2 = 150; 
int minimo1 = 150;
int minimo2 = 150; 


int sensor_d = A2;
int sensor_e = A1;
int sensor_c = A0;


bool obstaculo = HIGH;

void reto()
{
  
  analogWrite (vele, reto1);
  analogWrite (veld, reto2);
  
  digitalWrite (motor_d_f, HIGH);
  digitalWrite (motor_d_t, LOW);
  digitalWrite (motor_e_f, HIGH);
  digitalWrite (motor_e_t, LOW);
}

void curva_esquerda()
{
  
  analogWrite (veld, curva_direita1);
  analogWrite (vele, curva_direita2);
  
  digitalWrite (motor_d_f, HIGH);
  digitalWrite (motor_d_t, LOW);
  digitalWrite (motor_e_f, LOW);
  digitalWrite (motor_e_t, HIGH);
}

void curva_direita()
{
  analogWrite (veld, curva_esquerda1);
  analogWrite (vele, curva_esquerda2);
  
  digitalWrite (motor_d_f, LOW);
  digitalWrite (motor_d_t, HIGH);
  digitalWrite (motor_e_f, HIGH);
  digitalWrite (motor_e_t, LOW);
}

void minimo()
{
  analogWrite (vele, minimo1);
  analogWrite (veld, minimo2);
  
  digitalWrite (motor_d_f, HIGH);
  digitalWrite (motor_d_t, LOW);
  digitalWrite (motor_e_f, HIGH);
  digitalWrite (motor_e_t, LOW);
}


void parar()
{
  
  digitalWrite (motor_d_f, HIGH);
  digitalWrite (motor_d_t, HIGH);
  digitalWrite (motor_e_f, HIGH);
  digitalWrite (motor_e_t, HIGH);
}


void setup() {
  for (int x=7; x<11; x++){
    pinMode (x, OUTPUT);
  }
  pinMode (sensor_e, INPUT);
  pinMode (sensor_c, INPUT);
  pinMode (sensor_d, INPUT);  
  pinMode (vele, OUTPUT);
  pinMode (veld, OUTPUT);
  Serial.begin (9600);
  
}
void loop() {
  obstaculo = digitalRead(sensor_c);
  while(obstaculo == HIGH)
  {
    obstaculo = digitalRead(sensor_c);
    
    reto();
    
    Serial.println("Em linha");
  }
  
  while(obstaculo == LOW) //Procura Direta , Esquerda
  {
    
    minimo();
        
    Serial.println("Procurando..");
    
    if(digitalRead(sensor_d) == HIGH)
    {
      while(digitalRead(sensor_c) != HIGH)
      {
        curva_direita();
        Serial.println("Direita");
      }
      break;
    }
    else if(digitalRead(sensor_e) == HIGH)
    {
      while(digitalRead(sensor_c) != HIGH)
      {
        curva_esquerda();
        Serial.println("Esquerda");
      }
      break;
    }
    else if(digitalRead(sensor_c) == HIGH)
    {
      break;
    }
  }

}




