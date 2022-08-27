/*this code is working but it's very hard to use on simulator because of delays (especially running case 5 needs some patience)
 * i've tried to create a function using millis() in another code that i intend to include in my file,
 * but i believe something is wrong with it too
 * also, i increased delay time on purpose for me to notice any problems with the patterns
 */

int button=13; //i prefer using integers here because i believe defining constants takes more space and im not gonna change them anyway
boolean button_signal,last_signal=0; 
int choice=0;
void setup() {
  // put your setup code here, to run once:
  for (int i=1;i<=10;i++) //didn't assign led pins to variables in order to use them in loops
  {
    pinMode(i,OUTPUT);
  }
  pinMode(button,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=1; i<=10;i++) //the part than handles the case selection
  {
    digitalWrite(i,LOW);
  }
  button_signal= debounce(last_signal);
  if (button_signal==1&&last_signal==0)
  {
    choice++;
    if(choice>5)
    {
      choice=0;
    }
  }
  last_signal=button_signal;
  siren(choice);
}

boolean debounce (boolean button_last_state) //in case someone runs this code on actual push buttons
{
  boolean my_signal=digitalRead(button);
  if (my_signal!=button_last_state)
  {
    delay(2);
    my_signal=digitalRead(button);
  }
  return my_signal;
}

void siren (int count)
{
  int n=1,m=5;
  switch (count)
  {
    case 1:
    for (int i=1; i<=5; i++)
    {
      digitalWrite(i, HIGH);
      //digitalWrite(5+i,LOW);
    }
    delay(300);
    for (int j=6; j<=10; j++)
    {
      digitalWrite (j, HIGH);
      digitalWrite (11-j, LOW);
    }
    delay(300);
    
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
      delay(500);
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
      delay(80);
    }
    delay(500);
    for (int i=1; i<=10; i++)
    {
      digitalWrite(11-i,HIGH);
      if (i>=2)
      {
        digitalWrite(12-i, LOW);
      }
      delay (100);
    }
     delay(500);
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
      delay(100);
    }
    delay(300);
    for (int j=10; j>=n; j--)
    {
      digitalWrite(j,HIGH);
      if (j>=2)
      {
        digitalWrite(j+1, LOW);
      }
      delay (100);
    }
    n++;
     delay(300);
    }
    for (int i=1; i<5;i++)
    {
      for (int j=1; j<=m; j++)
    {
      digitalWrite(j, HIGH);
      digitalWrite(11-j,HIGH);
      delay(80);
      if (j>=2)
      {
        digitalWrite(j-1, LOW);
        digitalWrite(12-j, LOW);
      }
      delay(100);
    }
    for (int i=1;i<=10;i++)
    {
      digitalWrite(i,0);
      delay(100);
    }
    m--;
    }
    delay(300);
    break;
    
    case 5:
    for (int i=1;i<=4;i++)
    {
      digitalWrite(i, HIGH);
      delay(40);
    }
    delay(200);
    for (int i=10;i>=7;i--)
    {
      digitalWrite(i, HIGH);
      digitalWrite(11-i,LOW);
      delay(40);
    }
    delay(200);
    for (int i=10;i>=7;i--)
    {
      digitalWrite(i, LOW);
    }
    digitalWrite(5,1);
    delay(100);
    digitalWrite(5,0);
    digitalWrite(6,1);
    delay(100);
    break;
  }
}
