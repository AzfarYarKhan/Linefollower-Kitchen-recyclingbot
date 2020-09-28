
#define lm1 4
#define lm2 5



#define rm1 6
#define rm2 7



#define set_point 2000

#define max_speed 100                        //Set Max Motor Speed

#define s1 38
#define s2 40
#define s3 42
#define s4 44
#define s5 46
#define s6 48
#define s7 50
#define s8 52


int Kp=1;                   //set Kp Value

int proportional=0;
int last_proportional=0;
int right_speed=0;
int left_speed=0;
int sensors_sum=0;
int sensors_average=0;
int sensors[8]={0,0,0,0,0,0,0,0};   
int Position=0;
int error_value=0;

void setup() 
{
  
   pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
   pinMode(s8,INPUT);
   pinMode(s7,INPUT);
   pinMode(s6,INPUT);
   pinMode(s5,INPUT);
   pinMode(s4,INPUT);
   pinMode(s3,INPUT);
   pinMode(s2,INPUT);
   pinMode(s1,INPUT);
   Serial.begin(9600);
}

void Stop()
{
  analogWrite(lm1,0);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,0);
  
  delay(100);
}
void forward()
{
  Serial.println("the bot will move forward");
  analogWrite(lm1,150);
    analogWrite(lm2,0);
  analogWrite(rm1,0);
    analogWrite(rm2,150);
 delay(300);   //you may have to vary the delay for perfect right turn..
  Stop();
}
void backward()
{
  Serial.println("the bot will move backward");
  analogWrite(lm1,75);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(lm2,75);
   delay(300);   //you may have to vary the delay for perfect right turn..
  Stop();
}
void left_turn()    //hard left turn
{
  Serial.println("the bot will take a hard left turn");
  analogWrite(lm1,100);
   analogWrite(lm2,0);
  analogWrite(rm1,150);
   analogWrite(rm2,0);
  delay(300);   //you may have to vary the delay for perfect right turn..
  Stop();
}
void right_turn()  //hard right turn
{
  Serial.println("the bot will take a hard right turn");
  analogWrite(lm1,150); 
  analogWrite(lm2,0);     
  analogWrite(rm1,100);
  analogWrite(rm2,0);   
  delay(300);   //you may have to vary the delay for perfect right turn..
  Stop();
}



void pid_calc() 
{
  proportional=Position-set_point;                         //P
  last_proportional = proportional;    
  error_value = int(proportional * Kp);      //error

  
  if (error_value< -256)     
   error_value = -256; 
  
  if (error_value> 256) 
   error_value = 256;  

  if (error_value<0) 
    { 
        left_speed= max_speed + error_value; 
        right_speed = max_speed; 
    }  
   else 
     { 
        left_speed = max_speed; 
        right_speed = max_speed - error_value; 
     } 
     
      if (right_speed>255)
                right_speed=255;
      if (right_speed<0)
                right_speed=0;
      if (left_speed>255)
                left_speed=255;
      if (left_speed<0)
                left_speed=0;
}

void run()
{  
  digitalWrite(lm1,1);
  digitalWrite(rm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm2,0);
  analogWrite(lm1,left_speed);
  analogWrite(rm1,right_speed);
  delay(200);
}
void read_sensors()
{
   int i;
   sensors_average = 0; 
   sensors_sum = 0;
 
      for (i = 0; i <=7; i++) 
            {
               sensors[i] = digitalRead(i);
            }
              
        for(i=0;i<=7;i++)
          { 
               if(sensors[i]<100)
                sensors[i]=0;
      
                else
               sensors[i]=1;
          }
}

void sensor_average()
   {
      for(int i=0;i<=7;i++)
       {
            sensors_average += sensors[i] * i * 1000;  
       }
       
   }
void sensor_sum()
   {
      for(int i=0;i<=7;i++)
       {
            sensors_sum += sensors[i]; 
       }
       
   }
void allon()
{
   analogWrite(lm1,1);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(lm2,1);
}
   
void loop() 
{
  read_sensors()'
  //if cond
  allon();
  Serial.print(s1);
  Serial.print(s2);
  Serial.print(s3);
  Serial.print(s4);
  Serial.print(s5);
  Serial.print(s6);
  Serial.print(s7);
  Serial.print(s8);
  Serial.print("\r\n");
} 
