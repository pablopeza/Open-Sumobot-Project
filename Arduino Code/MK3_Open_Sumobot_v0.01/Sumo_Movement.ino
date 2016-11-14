
void sumo_forward(int motor_speed)
  {
  digitalWrite( MOTOR_B_DIR, HIGH );              // Direction : Forward
  analogWrite( MOTOR_B_PWM, 255 - motor_speed );  // Motor_speed : PWM 
  digitalWrite( MOTOR_A_DIR, HIGH );              // Direction : Forward
  analogWrite( MOTOR_A_PWM, 255 - motor_speed );  // Motor_speed : PWM 
  }

void sumo_right(int motor_speed)
  {
  digitalWrite( MOTOR_B_DIR, HIGH );              // Direction : Forward
  analogWrite( MOTOR_B_PWM, 255 - motor_speed );  // Motor_speed : PWM
  digitalWrite( MOTOR_A_DIR, LOW );               // Direction : Backward
  analogWrite( MOTOR_A_PWM, motor_speed );        // Motor_speed : PWM
  }

void sumo_left(int motor_speed)
  {
  digitalWrite( MOTOR_B_DIR, LOW );               // Direction : Backward
  analogWrite( MOTOR_B_PWM,  motor_speed );       // Motor_speed : PWM
  digitalWrite( MOTOR_A_DIR, HIGH );              // Direction : Forward
  analogWrite( MOTOR_A_PWM,255 - motor_speed );   // Motor_speed : PWM
  }

void sumo_left2(int motor_speed)
  {
  digitalWrite( MOTOR_B_DIR, LOW );               // Direction : Backward
  analogWrite( MOTOR_B_PWM,  motor_speed );       // Motor_speed : PWM
  
  digitalWrite( MOTOR_A_DIR, HIGH );              // Direction : Forward
  analogWrite( MOTOR_A_PWM,255 );                 // Motor_speed : PWM
  }

void sumo_backward(int motor_speed)
  {
  digitalWrite( MOTOR_B_DIR, LOW );               // Direction : Backward
  analogWrite( MOTOR_B_PWM, motor_speed );        // Motor_speed : PWM
  digitalWrite( MOTOR_A_DIR, LOW );               // Direction : Backward
  analogWrite( MOTOR_A_PWM, motor_speed );        // Motor_speed : PWM
  }

void sumo_stop()
  {
  digitalWrite( MOTOR_B_DIR, LOW );
  digitalWrite( MOTOR_B_PWM, LOW );
  digitalWrite( MOTOR_A_DIR, LOW );
  digitalWrite( MOTOR_A_PWM, LOW );
  }
