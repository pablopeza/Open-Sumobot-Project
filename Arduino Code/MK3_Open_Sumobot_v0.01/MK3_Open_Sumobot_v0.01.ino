/*
 * MK3 Open Sumobot Firmware V_0.01
 * CC license
 * @pablopeza
 */
#include <NewPing.h>
#define PING 50 //Max distance reading
  NewPing izq(9, 9, PING);  //Only 1 wire for comunication with this sensor    
  NewPing dch(8, 8, PING);  //Only 1 wire for comunication with this sensor
  NewPing fnt(7, 7, PING);  //Only 1 wire for comunication with this sensor

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
int front_distance = 0;
int left_distance = 0;
int right_distance = 0;
boolean turn_direction = true;        //True for left direction and false for right direction   
boolean front_detection = false;    //True when detects an enemy

 /*                                          [1]                          
  *                                        __._.__
  *  left_distance      left              |       |
  *  front_distance     center       [0] <|       |> [2]
  *  right_distance     right             |       |
  *                                         -------
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
  left_distance = ping_sensor_left_raw();
  front_distance = ping_sensor_center_raw();
  right_distance = ping_sensor_right_raw();
  
  line_right = line_sensor_right_raw();
  line_left = line_sensor_left_raw();

  Serial.print(" L ");
  Serial.print(left_distance);
  Serial.print(" C ");
  Serial.print(front_distance);
  Serial.print(" R ");
  Serial.print(right_distance);
  Serial.print(" . ");

  //Estado normal girar hasta ver algo

  if((front_distance < left_distance) && (front_distance < right_distance))
    {
    sumo_forward(150);
    front_detection = true;
    }
  
  if((left_distance < front_distance) && (left_distance < right_distance)) //add states
    {
    sumo_left(150);
    }
  
  if((right_distance < front_distance) && (right_distance < front_distance))
    {
    sumo_right(150);
    }
  
  }

