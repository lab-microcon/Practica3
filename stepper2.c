#include <avr/io.h> 
#include <util/delay.h>

#define MOTOR_PIN1 2 
#define MOTOR_PIN2 3 
#define MOTOR_PIN3 4 
#define MOTOR_PIN4 5 

// Secuencias de paso simple 
unsigned char step_sequence[] = { 
  (1 << MOTOR_PIN1), 
  (1 << MOTOR_PIN2), 
  (1 << MOTOR_PIN3), 
  (1 << MOTOR_PIN4)}; 

int main() { 
// Configurar los pines del motor como salidas 
  DDRD |= (1 << MOTOR_PIN1) | (1 << MOTOR_PIN2) | (1 << MOTOR_PIN3) | (1 << MOTOR_PIN4); 
  int step = 0; 
  while (1) { 
  // Activar la secuencia de paso 
    PORTD = step_sequence[step]; 
    _delay_ms(10); // Control de velocidad 
    // Incrementar el paso 
    step = (step + 1) % 4; 
  } 
  return 0;  
}
