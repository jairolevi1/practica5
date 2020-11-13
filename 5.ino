void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

double x1=0,x2=0,x3=0,x4=0,x5=0,x6=0,x7=0,ent,sal,X[7],aux;
int i,j;

void loop() {
  // put your main code here, to run repeatedly:
  ent= analogRead(A0);
  x7= (ent*5)/1023;
  X[0]=x1; 
  X[1]=x2; 
  X[2]=x3;
  X[3]=x4; 
  X[4]=x5; 
  X[5]=x6;
  
  for(i=0;i<7;i++)
  {
      j=0;
      while(j<6)
      {
        if(X[j]>X[j+1])
        {
         aux=X[j];
         X[j]=X[j+1];
         X[j+1]=aux;
        }
        j++;
    }
  }
  sal=X[3];
  Serial.println(sal);
  x1=x2;
  x2=x3;
  x3=x4;
  x4=x5;
  x5=x6;
  x6=x7;
  x7=0;
  delay(10);
}
