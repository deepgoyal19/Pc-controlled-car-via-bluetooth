#include <SoftwareSerial.h>
SoftwareSerial BT(0,1);//remove these two jumper wires before uploading the code
# define LEFT_A 5  
# define LEFT_B 7
# define RIGHT_A 2
# define RIGHT_B 4
# define enA 3 //pwm pins to control speed of the motor
#define enB 6
int i=100;
void setup()  
{pinMode(LED_BUILTIN, OUTPUT);
    pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(LEFT_A,OUTPUT);
  pinMode(LEFT_B,OUTPUT);
  pinMode(RIGHT_A,OUTPUT);
  pinMode(RIGHT_B,OUTPUT);

  BT.begin(9600);

  BT.println("Hello from Arduino");
  analogWrite(enB, 100);analogWrite(enA, 100);
}
char a; 
void loop() 
{
  
 
  if (BT.available())
  // if text arrived in from BT serial...
  {
    a=(BT.read());
    if (a=='w')
    {analogWrite(enB, i);analogWrite(enA, i);
     forward();  
    }
    if (a=='s')
    {analogWrite(enB, i);analogWrite(enA, i);
      backward();
    }
    if (a=='d')
    {analogWrite(enB, 100);analogWrite(enA, 100);
right();
    }   
    if (a=='a')
    {analogWrite(enB, 100);analogWrite(enA, 100);
left();
    }  
    if (a==' ')
    {analogWrite(enB, 100);analogWrite(enA, 100);
stop();
    }  
if (a=='j')
    {
  if(i>100)
 {
  i=i-10;
  analogWrite(enB,i);analogWrite(enA, i);
  }
    }      
if (a=='l')
    {
if(i<250)
  {
    i=i+10;
analogWrite(enB, i);analogWrite(enA, i);
  }
    }  
  }
}
void forward()//making a robot car move forward
{
  digitalWrite(LEFT_A,LOW);
  digitalWrite(LEFT_B,HIGH);
  digitalWrite(RIGHT_A,HIGH);
  digitalWrite(RIGHT_B,LOW);
}

void backward()//making a robot car moce backward
{
  digitalWrite(LEFT_A,HIGH);
  digitalWrite(LEFT_B,LOW);
  digitalWrite(RIGHT_A,LOW);
  digitalWrite(RIGHT_B,HIGH);
}

void left()//making my robot car rotate left direction
{
  digitalWrite(LEFT_A,LOW);
  digitalWrite(LEFT_B,HIGH);
  digitalWrite(RIGHT_A,LOW);
  digitalWrite(RIGHT_B,HIGH);
}
void right ()//making my robot car rotate in right direction
{
  digitalWrite(LEFT_A,HIGH);
  digitalWrite(LEFT_B,LOW);
  digitalWrite(RIGHT_A,HIGH);
  digitalWrite(RIGHT_B,LOW);
}
void stop()//to stop the robot from moving
{analogWrite(enB, 100);analogWrite(enA, 100);
  digitalWrite(LEFT_A,LOW);
  digitalWrite(LEFT_B,LOW);
  digitalWrite(RIGHT_A,LOW);
  digitalWrite(RIGHT_B,LOW);
}
