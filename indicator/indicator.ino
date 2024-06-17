#define DEL 50
void light_off(){
PORTD &= ~(1<<5);//B
PORTD &= ~(1<<6);//A
PORTD &= ~(1<<7);//F
PORTB &= ~(1<<0);//G
PORTB &= ~(1<<1);//C
PORTB &= ~(1<<2);//D
PORTB &= ~(1<<3);//E
}
void char0(){
PORTD |= (1<<5);//B
PORTD |= (1<<6);//A
PORTD |= (1<<7);//F
PORTB &= ~(1<<0);//G
PORTB |= (1<<1);//C
PORTB |= (1<<2);//D
PORTB |= (1<<3);//E
}
void char1(){
PORTD |= (1<<5);//B
PORTD &= ~(1<<6);//A
PORTD &= ~(1<<7);//F
PORTB &= ~(1<<0);//G
PORTB |= (1<<1);//C
PORTB &= ~(1<<2);//D
PORTB &= ~(1<<3);//E
}

void char2(){
PORTD |= (1<<5);//B
PORTD |= (1<<6);//A
PORTD &= ~(1<<7);//F
PORTB |= (1<<0);//G
PORTB &= ~(1<<1);//C
PORTB |= (1<<2);//D
PORTB |= (1<<3);//E
}
void char3(){
PORTD |= (1<<5);//B
PORTD |= (1<<6);//A
PORTD &= ~(1<<7);//F
PORTB |= (1<<0);//G
PORTB |= (1<<1);//C
PORTB |= (1<<2);//D
PORTB &= ~(1<<3);//E
}

void char4(){
PORTD |= (1<<5);//B
PORTD &= ~(1<<6);//A
PORTD |= (1<<7);//F
PORTB |= (1<<0);//G
PORTB |= (1<<1);//C
PORTB &= ~(1<<2);//D
PORTB &= ~(1<<3);//E
}
void char5(){
PORTD &= ~(1<<5);//B
PORTD |= (1<<6);//A
PORTD |= (1<<7);//F
PORTB |= (1<<0);//G
PORTB |= (1<<1);//C
PORTB |= (1<<2);//D
PORTB &= ~(1<<3);//E
}

int main(){
Serial.begin(9600);
DDRD |= (1<<3);
DDRD |= (1<<4);
PORTD &= ~(1<<3);
PORTD &= ~(1<<4);
//PORTD |=(1<<4);
DDRD |= (1<<5);//B
DDRD |= (1<<6);//A
DDRD |= (1<<7);//F
DDRB |= (1<<0);//G
DDRB |= (1<<1);//C
DDRB |= (1<<2);//D
DDRB |= (1<<3);//E
//PORTB |= (1<<1);
while(1){
;

char4();
PORTD |= (1<<3);
PORTD &= ~(1<<4);
_delay_ms(1);
char2();
PORTD &= ~(1<<3);
PORTD |= (1<<4);
_delay_ms(1);
}
}