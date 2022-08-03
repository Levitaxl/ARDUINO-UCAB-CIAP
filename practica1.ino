int cont=0;
int tiempo=100;
char valor;
int LED1=1;
int LED2=2;
int LED3=3;
int LED4=4;
int LED5=5;
int LED6=6;
int LED7=7;
int LED8=8;
int LED9=9;
int LED10=10;
int LED11=11;
int LED12=12;

void setup()
{
  	Serial.begin(9600);
    pinMode(LED2,INPUT);
 	pinMode(LED3,OUTPUT);
  	pinMode(LED4,OUTPUT);
  	pinMode(LED5,OUTPUT);
  	pinMode(LED6,OUTPUT);
	pinMode(LED7,OUTPUT);
	pinMode(LED8,OUTPUT);
  	pinMode(LED9,OUTPUT);
  	pinMode(LED10,OUTPUT);
  	pinMode(LED11,OUTPUT);
  	pinMode(LED12,OUTPUT);
  
  	attachInterrupt(digitalPinToInterrupt(LED2),
                    modificar_contador, 
                    RISING);
}



void loop(){  
  if(cont==0) encendido_arriba_abajo();
  else if(cont==1)    encendido_centro();
}

void encendido_centro(){
  int leds_primer_centro[1]  =  {LED9};
  int leds_segundo_centro[4] =  {LED8,LED10,LED3,LED5}; 
  int leds_tercer_centro[5]  =  {LED4,LED6,LED7,LED11,LED12}; 
  
  encender_leds(leds_primer_centro,1);
  manejo_delay();
  encender_leds(leds_segundo_centro,4);
  manejo_delay();
  encender_leds(leds_tercer_centro,5);
  manejo_delay();
  
  apagar_leds(leds_primer_centro,1);
  manejo_delay();
  apagar_leds(leds_segundo_centro,4);
  manejo_delay();
  apagar_leds(leds_tercer_centro,5);
  manejo_delay();
}

void encendido_arriba_abajo(){
  int leds_primera_fila[1] = {LED4};
  int leds_segunda_fila[2] = {LED3,LED5}; 
  int leds_tercera_fila[3] = {LED7,LED9,LED11}; 
  int leds_cuarta_fila[4]  = {LED6,LED8,LED10,LED12}; 

  encender_leds(leds_primera_fila,1);
  manejo_delay();
  encender_leds(leds_segunda_fila,2);
  manejo_delay();
  encender_leds(leds_tercera_fila,3);
  manejo_delay();
  encender_leds(leds_cuarta_fila,4);
  manejo_delay();
   
  apagar_leds(leds_primera_fila,1);
  manejo_delay();
  apagar_leds(leds_segunda_fila,2);
  manejo_delay();
  apagar_leds(leds_tercera_fila,3);
  manejo_delay();
  apagar_leds(leds_cuarta_fila,4);
  manejo_delay();
}

void modificar_contador(){
  cont++;
  if(cont==2)cont=0;
}
void encender_leds(int leds[],int cantidad_leds){
  	for (int i=0 ; i< cantidad_leds; i++) 
       digitalWrite(leds[i],HIGH);
}

void apagar_leds(int leds[],int cantidad_leds){
  	for (int i = 0; i< cantidad_leds; i++) 
       digitalWrite(leds[i],LOW);
}

void manejo_delay(){
  manejo_serial_tiempos();
  delay(tiempo); 
}

void manejo_serial_tiempos(){
  if(Serial.available()){
    valor = Serial.read();
  	Serial.println(valor);
    if(valor=='-' )tiempo=tiempo+10;
    if(tiempo>0 && valor=='+')tiempo=tiempo-10;
   }
}
  