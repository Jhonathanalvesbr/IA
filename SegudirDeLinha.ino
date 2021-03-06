//Declara Variavel do Motor
int motor_d_f = 10;
int motor_d_t = 9;
int motor_e_t = 8;
int motor_e_f = 7;

//Declara Variavel do Sensor Velocidade
int vele = 11;
int veld = 6; 

//Velocidades
int reto1 = 255;
int reto2 = 255; 
int curva_direita1 = 200;
int curva_direita2 = 200; 
int curva_esquerda1 = 200;
int curva_esquerda2 = 200; 
int minimo1 = 255;
int minimo2 = 255; 

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


void setup() 
{
  for (int x=7; x<11; x++)
  {
    pinMode (x, OUTPUT);
  }
  
  pinMode (sensor_e, INPUT);
  pinMode (sensor_c, INPUT);
  pinMode (sensor_d, INPUT);  
  
  pinMode (vele, OUTPUT);
  pinMode (veld, OUTPUT);
  
  Serial.begin (9600);
}

void loop() 
{
  while(digitalRead(sensor_c) == LOW) //Linha Reta
  {
    reto();
    //if(digitalRead(sensor_d) == LOW || digitalRead(sensor_e) == LOW)
    //  {break;}
    Serial.println("Em linha");
  }
  
  while(1) //Procura Direta , Esquerda
  {
    minimo();
        
    Serial.println("Procurando..");
    
    if(digitalRead(sensor_d) == LOW) //Curva Direta
    {
      while(digitalRead(sensor_c) != LOW)
      {
        curva_direita();
        Serial.println("Direita");
      }
      break;
    }
    if(digitalRead(sensor_e) == LOW) //Curva Esquerda
    {
      while(digitalRead(sensor_c) != LOW)
      {
        curva_esquerda();
        Serial.println("Esquerda");
      }
      break;
    }
    if(digitalRead(sensor_c) == LOW) //Achou a linha
    {
      break;
    }
  }
}
