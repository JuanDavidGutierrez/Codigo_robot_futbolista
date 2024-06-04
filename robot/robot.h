#ifndef ROBOT_H
#define ROBOT_H

#include <Arduino.h>

class Motor {
public:
  int pinA;
  int pinB;

  Motor(int pinA, int pinB);
  void adelante();
  void reversa();
  void parar();
};

class Robot {
public:
  Motor motorIzq;
  Motor motorDer;
  char estado;

  Robot(Motor motorIzq, Motor motorDer);
  void inicializar();
  void leerEstado();
  void ejecutarAccion();
  void adelante();
  void izquierda();
  void parar();
  void derecha();
  void reversa();
};

#endif