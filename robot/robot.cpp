#include "Robot.h"

// Implementación de la clase Motor
Motor::Motor(int pinA, int pinB) {
  this->pinA = pinA;
  this->pinB = pinB;
}

void Motor::adelante() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
}

void Motor::reversa() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
}

void Motor::parar() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
}

// Implementación de la clase Robot
Robot::Robot(Motor motorIzq, Motor motorDer) : motorIzq(motorIzq), motorDer(motorDer) {
  estado = 'c';
}

void Robot::inicializar() {
  pinMode(motorIzq.pinA, OUTPUT);
  pinMode(motorIzq.pinB, OUTPUT);
  pinMode(motorDer.pinA, OUTPUT);
  pinMode(motorDer.pinB, OUTPUT);
  Serial.begin(9600);
}

void Robot::leerEstado() {
  if (Serial.available() > 0) {
    estado = Serial.read();
    Serial.println(estado);
  }
}

void Robot::ejecutarAccion() {
  switch (estado) {
    case 'a':
      adelante();
      break;
    case 'b':
      izquierda();
      break;
    case 'c':
      parar();
      break;
    case 'd':
      derecha();
      break;
    case 'e':
      reversa();
      break;
  }
}
void Robot::adelante() {
  motorIzq.adelante();
  motorDer.adelante();
}
void Robot::izquierda() {
  motorIzq.reversa();
  motorDer.adelante();
}
void Robot::parar() {
  motorIzq.parar();
  motorDer.parar();
}
void Robot::derecha() {
  motorIzq.adelante();
  motorDer.reversa();
}
void Robot::reversa() {
  motorIzq.reversa();
  motorDer.reversa();
}