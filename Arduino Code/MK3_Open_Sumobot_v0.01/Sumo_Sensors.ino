//This code colects the data of the sensors of the sumo and save them into variables

int ping_sensor_left_raw()   //This function takes the value of the distance from the library of the ultrasonic sensors
  {
  int cmi = izq.ping_cm();   //Left Ping Sensor
  if (cmi <= 0)
    {
    cmi = PING;
    }
  return cmi;
  }

int ping_sensor_right_raw()  //Right Ping Sensor
  {
  int cmd = dch.ping_cm(); 
  if (cmd <= 0)
    {
    cmd = PING;
    }
  return cmd;
  }

int ping_sensor_center_raw()  //Center Ping Sensor
  {
  int cmc = fnt.ping_cm(); 
  if (cmc == 0)
    {
    cmc= PING;
    }
  return cmc;  
  }

int line_sensor_right_raw()   //Line Sensor Right
  {
  int sensorValue = analogRead(A7);
  return sensorValue;
  }

int line_sensor_left_raw()    //Line Sensor Left
  {
  int sensorValue = analogRead(A6); 
  return sensorValue; 
  }

int ir() //IR Sensor Front
  {
  int i,val;
  i=analogRead(redpin);
  val=(6762/(i-9))-4;
  if(val > DISTANCIA_IR)
    {
    val = DISTANCIA_IR;
    }
  return val;
  }

void print_data(int data)   //Function used to print properly the sensor data.
  {                         //If the number is not big enought, the function adds blank spaces.
  Serial.print(" ");        // bad 1 20 300     /without function
  if(data < 1000)           // bad 100 20 1     /without function
    {                       // well   1  20 300 /with function
      if(data < 100)        // well 300  20   1 /with function
        {
        Serial.print(" ");
        if(data < 10)
          {
          Serial.print(" ");
          }
        }
    }
  Serial.print(data);  
  }
