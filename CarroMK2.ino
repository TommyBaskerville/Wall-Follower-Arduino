/*CODIGO PARA CARRO QUE EVITA OBSTACULOS */
/*Nota: Menos 15 grados*/
#include <NewPing.h>//Libreria para sensor ultrasonico    
#include <AFMotor.h>//Libreria para Puente H Shield   

NewPing distLeft(A0, A1, 200); //(trig,echo,dist max)
NewPing distFront(A2, A3, 200);//(trig,echo,dist max)
NewPing distRight(A4, A5, 200);//(trig,echo,dist max)

AF_DCMotor motorA(1); 
AF_DCMotor motorB(2);


int Case = 0;
int DIS = 15; //Distancia de izquerdA
int wall_threshold = 2;
int front_threshold = 6;

float mitad = (33/2)-18;

float rightSensor, leftSensor, frontSensor;

boolean frontwall ;
boolean leftwall ;
boolean rightwall ;

void setup() {
motorA.setSpeed(-200);
motorB.setSpeed(-200);
}

void loop() {
 
//========================================START========================================//
readSensors();
/*
if (frontSensor >= 6 && frontSensor <= 250)
{
  adelante();
}
else if (frontSensor < 6)
{
  frenar();
  delay(150);
  reversa();
  delay(250);
  frenar();
  delay(250);

  if(rightSensor >= leftSensor)
    {
      girarRight();
      frenar();
    }
    else if(leftSensor >= rightSensor)
    {
      girarLeft();
      frenar();
    }
  }

*/
 if ( frontSensor < front_threshold && leftSensor <DIS) // obstaculos enfrente y a la izquierda

 { 
  frenar();
  delay(150);
  reversa();
  delay(250);
  frenar();
  delay(250);
  girarRight(); 

//then reverse

 }

 else if (leftSensor>DIS) //Sin obstaculo a la izquierda
    {
 frenar();
  delay(150);
  reversa();
  delay(100);
  frenar();
  delay(250);
 girarLeft(); 

// turn right side


 }
/*
 else if (frontSensor <front_threshold  &&  leftSensor>DIS) // obstacle enfrente = girar derecha

 {
  frenar();
  delay(150);
  reversa();
  delay(250);
  frenar();
  delay(250);
  girarRight(); 

// turn right side

 }

 else if (frontSensor <front_threshold && leftSensor<DIS) //obstaculo izquierda y en frente
    {
 frenar();
  delay(150);
  reversa();
  delay(250);
  frenar();
  delay(250);
 girarRight(); 

// turn right side


 }
 */
 else if ( leftSensor>DIS)//obstaculo a la izquiera  

 {
 adelante();

 }

}
//--------------------------------- Sensors ---------------------------------//
void readSensors(){

  frontSensor = distFront.ping_cm();
  leftSensor = distLeft.ping_cm();
  rightSensor = distRight.ping_cm();
  
}
//--------------------------------- direction control ---------------------------------//

void frenar(){
motorA.run(RELEASE);
motorB.run(RELEASE);
delay(1000);
}

void adelante(){
motorA.run(FORWARD);
motorB.run(FORWARD);

}

void reversa(){
  motorA.run(BACKWARD);
  motorB.run(BACKWARD);
 
}

void girarLeft(){
  motorB.run(FORWARD);
  delay(590  );
}

void girarRight(){
  motorA.run(FORWARD);
  
  delay(600);
}

void giro180(){
  motorA.run(BACKWARD);
  motorB.run(FORWARD);
  delay(610);
}



/*void Enderezar(){
  if (leftSensor < mitad && rightSensor > mitad){
      motorA.setSpeed();
      motorB.setSpeed();
  }
  else if(leftSensor > mitad && rightSensor < mitad){
      motorA.setSpeed();
      motorB.setSpeed();
  }
}
*/
