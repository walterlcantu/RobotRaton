//Guía para robot ratón que resuelve laberintos

//Primero vamos a crear las variables para los pines que vamos a usar en Arduino
//Les pondremos los nombres de las señales que llevaran estos pines
int Trigger_F = 2;
int IN1 = 3;       //Motor Left
int Echo_F = 4;
int IN2 = 5;       //Motor Left
int IN3 = 6;       //Motor Right
int Trigger_L = 7;
int Echo_L = 8;
int IN4 = 9;       //Motor Right
int Trigger_R = 10;
int Echo_R = 11; 

void setup() {
  Serial.begin(9600); //Iniciamos la comunicación serial para leer datos en el monitor en serie.
  pinMode(IN1, OUTPUT); //Definimos los pines para manipular los motores como salida
  pinMode(IN2, OUTPUT); // ..
  pinMode(IN3, OUTPUT); // ..
  pinMode(IN4, OUTPUT); // ..
  pinMode(Trigger_F, OUTPUT);  //Trigger de ultrasónico frontal como salida
  pinMode(Echo_F, INPUT);      //Echo de ultrasónico frontal como entrada
  pinMode(Trigger_L, OUTPUT);  //Trigger de ultrasónico izquierdo como salida
  pinMode(Echo_L, INPUT);      //Echo de ultrasónico izquierdo como entrada
  pinMode(Trigger_R, OUTPUT);  //Trigger de ultrasónico derecho como salida
  pinMode(Echo_R, INPUT);      //Echo de ultrasónico derecho como entrada
  digitalWrite(Trigger1, LOW); //Inicializamos el pin con 0
  digitalWrite(Trigger2, LOW); //Inicializamos el pin con 0
  digitalWrite(Trigger3, LOW); //Inicializamos el pin con 0
}

void loop() {
  
  long t_F; //Tiempo que demora en llegar el echo
  long d_F; //Distancia en centímetros
  long t_L;
  long d_L;
  long t_R;
  long d_R;

  digitalWrite(Trigger_F, HIGH);
  delayMicroseconds(10);        //Enviamos un pulso de 10us
  digitalWrite(Trigger_F, LOW);
  t_F = pulseIn(Echo_F, HIGH);   //Obtenemos el ancho de pulso
  d_F = t_F/59;                    //Escalamos el tiempo a una distancia en cm

  digitalWrite(Trigger_L, HIGH);
  delayMicroseconds(10);        //Enviamos un pulso de 10us
  digitalWrite(Trigger_L, LOW);
  t_L = pulseIn(Echo_L, HIGH);   //Obtenemos el ancho de pulso
  d_L = t_L/59;                    //Escalamos el tiempo a una distancia en cm

  digitalWrite(Trigger_R, HIGH);
  delayMicroseconds(10);        //Enviamos un pulso de 10us
  digitalWrite(Trigger_R, LOW);
  t_R = pulseIn(Echo_R, HIGH);   //Obtenemos el ancho de pulso
  d_R = t_R/59;                    //Escalamos el tiempo a una distancia en cm

  //Mostrar en el monitor serial la distancia de cada sensor
  Serial.print("Distancia Frente: ");
  Serial.print(d_F);      //Enviamos serialmente el valor de la distancia Frente
  Serial.print("cm");
  Serial.println();
  Serial.print("Distancia Izquierda: ");
  Serial.print(d_L);      //Enviamos serialmente el valor de la distancia Izquierda
  Serial.print("cm");
  Serial.println();
  Serial.print("Distancia Derecha: ");
  Serial.print(d_R);      //Enviamos serialmente el valor de la distancia Derecha
  Serial.print("cm");
  Serial.println();
  delay(100); 

}

void avanzar(){
  analogWrite(IN1, 255);
  analogWrite(IN2, 0);
  analogWrite(IN3, 255);
  analogWrite(IN4, 0);
}

void retroceder(){
  analogWrite(IN1, 0);
  analogWrite(IN2, 255);
  analogWrite(IN3, 0);
  analogWRite(IN4, 255);
}

void detener(){
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWRite(IN4, 0);
}

void giroDerecha(){
  analogWrite(IN1, 255);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWRite(IN4, 255);
}

void giroIzquierda(){
  analogWrite(IN1, 0);
  analogWrite(IN2, 255);
  analogWrite(IN3, 255);
  analogWRite(IN4, 0);
}
