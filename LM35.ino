float Valores[7]={0.00,0.00,0.00,0.00,0.00,0.00,0.00};
float Datos[7]={0.00,0.00,0.00,0.00,0.00,0.00,0.00};
int len=7;
int ln=6;
float tem=0.0;

void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

int a=0;
float T=0.00;
float t=0.00;

void loop() {
  T=0.00;
  t=0.00;
  a=analogRead(A0);
  Datos[6]=Datos[5];
  Datos[5]=Datos[4];
  Datos[4]=Datos[3];
  Datos[3]=Datos[2];
  Datos[2]=Datos[1];
  Datos[1]=Datos[0];
  Datos[0]=a;

  Valores[6]=Datos[6];
  Valores[5]=Datos[5];
  Valores[4]=Datos[4];
  Valores[3]=Datos[3];
  Valores[2]=Datos[2];
  Valores[1]=Datos[1];
  Valores[0]=Datos[0];

  //esto solo acomoda los valores de menor a mayor
  for(int j=0;j<len;j++)
  {
    for(int i=0;i<ln;i++)
    {
      if(Valores[i+1]>Valores[i])
      {
        tem=Valores[i];
        Valores[i]=Valores[i+1];
        Valores[i+1]=tem;
      }
    }
  }
  T=Valores[3];
  Serial.println(T);
      
}
