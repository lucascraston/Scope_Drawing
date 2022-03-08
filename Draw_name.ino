int pinX = 6;
int pinY = 5;
#define vertices 46

 byte x_vertices[vertices] = {2,2,3,3,6,6,6,6,7,7,10,10,11,11,11,11,15,15,12,12,15,15,15,15,19,19,18,18,16,16,18,18,16,16,19,19,22,22,19,19,23,23,20,20,23,23};
 byte y_vertices[vertices] = {2,10,10,3,3,2,2,9,9,3,3,9,9,2,2,9,9,8,8,3,3,2,2,9,9,2,2,6,6,8,8,7,7,2,2,3,3,5,5,9,9,8,8,6,6,2};

void setup() {

  
  pinMode(pinX,OUTPUT);
  pinMode(pinY,OUTPUT);
  
  
  //Now we adjust PWM frequency using Prescale_factor
  TCCR0A =  (TCCR0A & B10100011 + TCCR0A | B10100011);  //(1<<COM0A1 | 0<<COM0A0 | 1<<COM0B1 | 0<<COM0B0 | 1<<WGM01 | 1<<WGM00);
  TCCR0B =  (TCCR0B & B00000001 + TCCR0B | B00000001);  //(0<<FOC0A | 0<<FOC0B | 0<<WGM02 | 0<<CS02 | 0<<CS01 | 1<<CS00);
  TIMSK0 =  (TIMSK0 & B11111000);                       //(0<<OCIE0B | 0<<OCIE0A  | 0<<TOIE0);

}

void loop() {
  unsigned char count;

    for (count =0; count<vertices;count++){
        analogWrite(pinX,x_vertices[count]);
        analogWrite(pinY,y_vertices[count]);
        delay(800);
    }


}
