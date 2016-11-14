/*
 * MK3 Open Sumobot Firmware V_0.01
 * CC license
 * @pablopeza
 */
#include <NewPing.h>
#define PING 50 //Max distance
  NewPing izq(9, 9, PING);
  NewPing dch(8, 8, PING);
  NewPing fnt(7, 7, PING);

#define DISTANCIA 30
#define DISTANCIA_IR 40
#define NUMERONEGRO 5

#define HG7881_IA2 6  // D10 --> Motor B Input A --> MOTOR B +
#define HG7881_IB2 11 // D11 --> Motor B Input B --> MOTOR B -
#define HG7881_IA1 5  // D5  --> Motor A Input A --> MOTOR A +
#define HG7881_IB1 10 // D6  --> Motor A Input B --> MOTOR A -

#define MOTOR_B_PWM HG7881_IA2 // Motor B PWM Speed
#define MOTOR_B_DIR HG7881_IB2 // Motor B Direction
#define MOTOR_A_PWM HG7881_IA1 // Motor A PWM Speed
#define MOTOR_A_DIR HG7881_IB1 // Motor A Direction

int line_sensor_right;

int cont = 0;
int redpin=A3;
int line_left, line_right;
int distance_vector[3];
  
 /*                                    [1]                          
  *                                  __._.__
  *  distance_vector(0) left        |       |
  *  distance_vector(1) center [0] <|       |> [2]
  *  distance_vector(2) right       |       |
  *                                  -------
  *  Movements available:  
  *     - sumo_forward(speed)
  *     - sumo_left(speed)
  *     - sumo_right(speed)
  *     - sumo_backward(speed)
  *     - sumo_stop(speed)
   */

  
void setup() 
  {
  pinMode( MOTOR_B_DIR, OUTPUT );
  pinMode( MOTOR_B_PWM, OUTPUT );
  digitalWrite( MOTOR_B_DIR, LOW );
  digitalWrite( MOTOR_B_PWM, LOW );

  pinMode( MOTOR_A_DIR, OUTPUT );
  pinMode( MOTOR_A_PWM, OUTPUT );
  digitalWrite( MOTOR_A_DIR, LOW );
  digitalWrite( MOTOR_A_PWM, LOW );
 
  delay(1);
  }

void loop() 
  {
  distance_vector[0] = ping_sensor_left_raw();
  distance_vector[1] = ping_sensor_center_raw();
  distance_vector[2] = ping_sensor_right_raw();
  
  line_right = line_sensor_right_raw();
  line_left = line_sensor_left_raw();

  Serial.print(" L ");
  Serial.print(distance_vector[0]);
  Serial.print(" C ");
  Serial.print(distance_vector[1]);
  Serial.print(" R ");
  Serial.print(distance_vector[2]);
  Serial.print(" . ");

  if((distance_vector[1] < distance_vector[0]) && (distance_vector[1] < distance_vector[2]))
    {
    sumo_forward(150);
    }
  
  if((distance_vector[0] < distance_vector[1]) && (distance_vector[0] < distance_vector[2])) //add states
    {
    sumo_left(150);
    }
  
  if((distance_vector[2] < distance_vector[1]) && (distance_vector[2] < distance_vector[1]))
    {
    sumo_right(150);
    }
  
  }

