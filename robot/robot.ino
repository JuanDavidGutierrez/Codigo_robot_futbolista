#include "Robot.h"

// Declaración de motores y robot
Motor motorIzq(8, 6);
Motor motorDer(9, 11);
Robot robot(motorIzq, motorDer);

void setup() {
  // Inicialización del robot
  robot.inicializar();

}

void loop() {
  robot.leerEstado();
  robot.ejecutarAccion();

}
