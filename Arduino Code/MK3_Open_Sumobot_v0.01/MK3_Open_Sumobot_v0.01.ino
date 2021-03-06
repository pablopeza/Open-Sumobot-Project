/*
 * MK3 Open Sumobot Firmware V_0.01
 * CC license
 * @pablopeza
 * 
 * Contains NewPing.h library created by Tim Eckel - teckel@leethost.com
 * Copyright 2012 License: GNU GPL v3 http://www.gnu.org/licenses/gpl-3.0.html
 */
 
#include <NewPing.h>
#define PING 55 //Max distance reading
  NewPing izq(9, 9, PING);  //Only 1 wire for comunication with this sensor    
  NewPing dch(8, 8, PING);  //Only 1 wire for comunication with this sensor
  NewPing fnt(7, 7, PING);  //Only 1 wire for comunication with this sensor

#define DISTANCIA 30
#define DISTANCIA_IR 40
#define NUMERONEGRO 300

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

boolean turn_direction = true;        //The last movement was a turn, this is for repair the sensors orientation bug 
boolean front_detection = false;      //True when detects an enemy

unsigned long time;

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

  Serial.begin(9600);
 
  delay(1);
  }

void loop() 
  {
  time = millis();  
  left_distance = ping_sensor_left_raw();
  front_distance = ping_sensor_center_raw();
  right_distance = ping_sensor_right_raw();
  
  line_right = line_sensor_right_raw();
  line_left = line_sensor_left_raw();

  Serial.print(" L");
  print_data(left_distance);
  Serial.print(" C");
  print_data(front_distance);
  Serial.print(" R");
  print_data(right_distance);
  Serial.print(" LI ");
  print_data(line_left);
  Serial.print(" LD ");
  print_data(line_right);
  Serial.print(" time ");
  Serial.print(time);
  
  if(front_distance <= 50)
    {
    sumo_forward(250);
    delay(30);
    }else
      {
       if((left_distance < front_distance) && (left_distance < right_distance)) //add states
         {
         sumo_left(250);
         }
         
       if((right_distance < front_distance) && (right_distance < front_distance))
         {
         sumo_right(250);
         }
      }     
  if((line_right < 200)||(line_left < 200))
      {
      sumo_backward(200);
      delay(100);
      sumo_left(250);
      delay(100);
      }       
  Serial.println("");    
  }
  
