int button=13;
boolean button_signal,last_signal=0;
int count=0;
void setup() {
  // put your setup code here, to run once:
  for (int i=1;i<=10;i++)
  {
    pinMode(i,OUTPUT);
  }
  pinMode(button,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int n=1,m=5;
  for (int i=1; i<=10;i++)
  {
    digitalWrite(i,LOW);
  }
  button_signal= debounce(last_signal);
  if (button_signal==1&&last_signal==0)
  {
    count++;
    if(count>5)
    {
      count=0;
    }
  }
  last_signal=button_signal;

  switch (count)
  {
    case 1:
    for (int i=1; i<=5; i++)
    {
      digitalWrite(i, HIGH);
      //digitalWrite(5+i,LOW);
    }
    wait(300);
    for (int j=6; j<=10; j++)
    {
      digitalWrite (j, HIGH);
      digitalWrite (11-j, LOW);
    }
    wait(300);
    
    break;

    case 2:
    for (int i=1; i<=5; i++)
    {
      digitalWrite(i, HIGH);
      digitalWrite(11-i,HIGH);
      if (i>=2)
      {
        digitalWrite(i-1, LOW);
        digitalWrite(12-i, LOW);
      }
      wait(500);
    }
    break;

    case 3:
    for (int i=1; i<=10; i++)
    {
      digitalWrite(i, HIGH);
      if (i>=2)
      {
        digitalWrite(i-1, LOW);
      }
      wait(80);
    }
    wait(500);
    for (int i=1; i<=10; i++)
    {
      digitalWrite(11-i,HIGH);
      if (i>=2)
      {
        digitalWrite(12-i, LOW);
      }
      wait (100);
    }
     wait(500);
     break;

    case 4:
    for (int j=5; j>0; j--)
    {
      for (int j=1; j<=10; j++)
    {
      digitalWrite(j, HIGH);
      if (j>=2)
      {
        digitalWrite(j-1, LOW);
      }
      wait(100);
    }
    wait(300);
    for (int j=10; j>=n; j--)
    {
      digitalWrite(j,HIGH);
      if (j>=2)
      {
        digitalWrite(j+1, LOW);
      }
      wait (100);
    }
    n++;
     wait(300);
    }
    for (int i=1; i<5;i++)
    {
      for (int j=1; j<=m; j++)
    {
      digitalWrite(j, HIGH);
      digitalWrite(11-j,HIGH);
      wait(80);
      if (j>=2)
      {
        digitalWrite(j-1, LOW);
        digitalWrite(12-j, LOW);
      }
      wait(100);
    }
    for (int i=1;i<=10;i++)
    {
      digitalWrite(i,0);
      wait(100);
    }
    m--;
    }
    wait(300);
    break;
    
    case 5:
    for (int i=1;i<=4;i++)
    {
      digitalWrite(i, HIGH);
      wait(80);
    }
    wait(100);
    for (int i=10;i>=7;i--)
    {
      digitalWrite(i, HIGH);
      digitalWrite(11-i,LOW);
      wait(100);
    }
    wait(100);
    for (int i=10;i>=7;i--)
    {
      digitalWrite(i, LOW);
    }
    digitalWrite(5,1);
    wait(60);
    digitalWrite(5,0);
    digitalWrite(6,1);
    wait(100);
    break;
  }

}

boolean debounce (boolean button_last_state)
{
  boolean my_signal=digitalRead(button);
  if (my_signal!=button_last_state)
  {
    delay(2);
    my_signal=digitalRead(button);
  }
  return my_signal;
}
void wait (int time_constant)
{ 
  int current_time=millis();
  int executed_time=current_time;
  boolean check = (current_time-executed_time==time_constant);
  while(!check)
  {
    Serial.println("waitint..");
    check = (current_time-executed_time==time_constant);
  }
  
}
