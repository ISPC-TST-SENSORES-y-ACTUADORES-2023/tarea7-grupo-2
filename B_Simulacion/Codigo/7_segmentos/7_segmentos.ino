//Asignacion de pines a cada segmento.-

//               a, b, c, d, e, f, g
int pines[7] = {13,12,11,10, 9, 8, 7};
//Matriz con sistema hexa, por cada digito asignado a cada 
//combinacion de segmentos.

int estados[16][7] = { 
{1,1,1,1,1,1,0},  //0          			   
{0,1,1,0,0,0,0},  //1
{1,1,0,1,1,0,1},  //2
{1,1,1,1,0,0,1},  //3  
{0,1,1,0,0,1,1},  //4
{1,0,1,1,0,1,1},  //5
{1,0,1,1,1,1,1},  //6
{1,1,1,0,0,0,0},  //7
{1,1,1,1,1,1,1},  //8
{1,1,1,0,0,1,1},  //9
{1,1,1,0,1,1,1},  //A
{0,0,1,1,1,1,1},  //B
{1,0,0,1,1,1,0},  //C
{0,1,1,1,1,0,1},  //D
{1,0,0,1,1,1,1},  //E
{1,0,0,0,1,1,1}   //F
                     }; 

void setup(){
  // configuracion de los pines como salida
  for (int i = 0; i < 7; i++) {
    pinMode(pines[i], OUTPUT);
  }
}


void loop(){
  
  for (int j = 0; j < 16; j++) {
    for (int i = 0; i < 7; i++) {
      digitalWrite(pines[i], estados[j][i]);
  }
         delay(1000);
  }
   for (int i = 0; i < 7; i++) 
       digitalWrite(pines[i], 0); //apago los 7 segmentos y comienzo nuevamente
       delay(2000);
}