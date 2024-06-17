int main(){
  Serial.begin(9600);
  //DDRD |=(1<<4);
  DDRD |= (1<<2);
  SREG |= (1<<7);//Глобальные прерывания
  EIMSK |= (1<<0);//Внешние прерывания
  EICRA |= (11);//условие прерывания 
  PORTD |=(1<<4);
  while(1){
   
  }
}
 ISR(INT0_vect){
          Serial.println("Button pressed!");
          
}