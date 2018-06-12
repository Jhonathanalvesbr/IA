#include <Time.h>

//Declara Variavel do Motor
int motor_d_f = 10;
int motor_d_t = 9;
int motor_e_t = 8;
int motor_e_f = 7;

//Declara Variavel do Sensor Velocidade
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

//Declara Sensores
int sensor_d = A2;
int sensor_e = A1;
int sensor_c = A0;

//Segue linha reta
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

//Velocidade Minima
void minimo()
{
  analogWrite (vele, minimo1);
  analogWrite (veld, minimo2);
  
  digitalWrite (motor_d_f, HIGH);
  digitalWrite (motor_d_t, LOW);
  digitalWrite (motor_e_f, HIGH);
  digitalWrite (motor_e_t, LOW);
}

//Freio
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
  
  while(digitalRead(sensor_c) == HIGH) //Linha Reta
  {
    reto();
    
    Serial.println("Em linha");
  }
  
  while(obstaculo == LOW) //Procura Direta , Esquerda
  {
    
    minimo();
        
    Serial.println("Procurando..");
    
    if(digitalRead(sensor_d) == HIGH) //Curva Direta
    {
      while(digitalRead(sensor_c) != HIGH)
      {
        curva_direita();
        Serial.println("Direita");
      }
      break;
    }
    else if(digitalRead(sensor_e) == HIGH) //Curva Esquerda
    {
      while(digitalRead(sensor_c) != HIGH)
      {
        curva_esquerda();
        Serial.println("Esquerda");
      }
      break;
    }
    else if(digitalRead(sensor_c) == HIGH) //Achou a linha
    {
      break;
    }
  }
}
