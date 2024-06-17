#define SIXTEENTH 100


enum notes
{
    c4 = 261,
    cs4 = 277,
    d4 = 294,
    ds4 = 311,
    e4 = 329,
    f4 = 349,
    g4 = 392,
    gs4 = 415,
    a4 = 440,
    bf4 = 466,
    b4 = 493,
    c5 = 523,
    d5 = 587,
    ds5 = 622,
    e5 = 659,
    f5 = 698
};
float convtime(float sec)
{
    return (sec / (6.25 * 1024 * 0.00000001));
}
void mydelay(float sec)
{
    Serial.begin(9600);
    TCCR1B = 0;
    TCCR1A = 0;
    TCCR1B |= (1 << CS10);
    TCCR1B |= (1 << CS12);
    float div = convtime(sec);

    TCNT1 = 65536 - convtime(sec);

    while (1)
    {
        if ((TIFR1 & 1 << 1))
        {
            TIFR1 |= 1 << 1;
            Serial.println("time over");
            break;
        }
    }
}

void mysound(float freq, float dur)
{   
    DDRD |= (1 << 4);
    float timeHigh = (1 / (2 * freq));
    for (int i = 0; i < dur; i++)
    {
        PORTD &= ~(1 << 4);
        //_delay_ms(timeHigh*1000);
        mydelay(timeHigh);
        PORTD |= (1 << 4);
        //_delay_ms(timeHigh*1000);
        mydelay(timeHigh);
    }
}
int main(){
  Serial.begin(9600);
  DDRB &= ~(1<<4);
  DDRB &= ~(1<<3);
  DDRB &= ~(1<<2);
  DDRB &= ~(1<<1);
  DDRB |=(1<<0);
  DDRD |=(1<<7);
  DDRD |=(1<<6);
  DDRD |=(1<<5);
  PORTB |= (1<<4);
  PORTB |= (1<<3);
  PORTB |= (1<<2);
  PORTB |= (1<<1);
  int count = 0;
  while(1){
    mysound(c4, SIXTEENTH);
    mydelay(SIXTEENTH);
    PORTB &= ~(1<<0);
    mydelay(0.00001);
    if((!(PINB &(1<<4)))) mysound(c4, SIXTEENTH);
    if((!(PINB &(1<<3)))) mysound(cs4, SIXTEENTH);
    if((!(PINB &(1<<2)))) mysound(d4, SIXTEENTH);
    if((!(PINB &(1<<1)))) mysound(ds4, SIXTEENTH);
    PORTB |= (1<<0);
    //_delay_ms(50);
    PORTD &= ~(1<<7);
    mydelay(0.00001);
    if((!(PINB &(1<<4)))) mysound(e4, SIXTEENTH);
    if((!(PINB &(1<<3)))) mysound(f4, SIXTEENTH);
    if((!(PINB &(1<<2)))) mysound(g4, SIXTEENTH);
    if((!(PINB &(1<<1)))) mysound(gs4, SIXTEENTH);
    PORTD |= (1<<7);
    //_delay_ms(50);
    PORTD &= ~(1<<6);
    mydelay(0.00001);
    if((!(PINB &(1<<4)))) mysound(a4, SIXTEENTH);
    if((!(PINB &(1<<3)))) mysound(bf4, SIXTEENTH);
    if((!(PINB &(1<<2)))) mysound(b4, SIXTEENTH);
    if((!(PINB &(1<<1)))) mysound(c5, SIXTEENTH);
    PORTD |= (1<<6);
    //_delay_ms(50);
    PORTD &= ~(1<<5);
    mydelay(0.00001);
    if((!(PINB &(1<<4)))) mysound(d5, SIXTEENTH);
    if((!(PINB &(1<<3)))) mysound(ds5, SIXTEENTH);
    if((!(PINB &(1<<2)))) mysound(e5, SIXTEENTH);
    if((!(PINB &(1<<1)))) mysound(f5, SIXTEENTH);
    PORTD |= (1<<5);
    
      

    }
  }