#define WHOLE 800
#define HALF 400
#define QUARTER 200
#define QUARTERD 300
#define EIGHTHD 150
#define EIGHTH 100
#define SIXTEENTH 50

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
    e5 = 659
};
double convtime(double sec)
{
    return (sec / (6.25 * 1024 * 0.00000001));
}
void mydelay(double sec)
{
    //Serial.begin(9600);
    TCCR1B = 0;
    TCCR1A = 0;
    TCCR1B |= (1 << CS10);
    TCCR1B |= (1 << CS12);
    double div = convtime(sec);

    TCNT1 = 65536 - convtime(sec);

    while (1)
    {
        if ((TIFR1 & 1 << 1))
        { 
            //Serial.println("time over");
            TIFR1 |= 1 << 1;
            break;
        }
    }
}

void mysound(double freq, double dur)
{   
    DDRD |= (1 << 4);
    double timeHigh = (1 / (2 * freq));
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
void fly(){
  mysound(c5, QUARTER);
  mysound(b4, QUARTER);
  mysound(a4, EIGHTH);
  mysound(g4, QUARTERD);
  mysound(f4, QUARTERD);
  mysound(g4, EIGHTH);
  mysound(a4, QUARTERD);
  mysound(c5, QUARTERD);
  mysound(b4, QUARTERD);
  mysound(a4, QUARTERD);
  mysound(g4, EIGHTH);
  mysound(f4, QUARTERD);
  mysound(e4, WHOLE);
  mysound(a4, QUARTERD);
  mysound(g4, QUARTERD);
  mysound(f4, EIGHTH);
  mysound(e4, QUARTERD);
  mysound(d4, QUARTERD);
  mysound(e4, EIGHTH);
  mysound(f4, QUARTER);
  mysound(a4, QUARTER);
  mysound(gs4, QUARTER);
  mysound(f4, QUARTER);
  mysound(e4, EIGHTH);
  mysound(d4, QUARTERD);
  mysound(c4, HALF);
  mydelay(4);


}
void cruel()
{
    mysound(c4, QUARTER);
    mysound(ds4, QUARTER);
    mysound(f4, EIGHTHD);
    mysound(ds4, EIGHTHD);
    mysound(f4, EIGHTH);
    mysound(f4, EIGHTH);
    mysound(f4, EIGHTH);
    mysound(bf4, EIGHTH);
    mysound(gs4, EIGHTH);
    mysound(g4, EIGHTH);
    mysound(f4, EIGHTH);
    mysound(g4, EIGHTHD);
    mydelay(EIGHTH);
    mysound(g4, QUARTER);
    mysound(bf4, QUARTER);
    mysound(c5, EIGHTHD);
    mysound(f4, EIGHTHD);
    mysound(ds4, EIGHTH);
    mysound(bf4, EIGHTH);
    mysound(bf4, EIGHTH);
    mysound(g4, EIGHTH);
    mysound(bf4, EIGHTH);
    mysound(bf4, EIGHTHD);
    mysound(c5, EIGHTH);
    mysound(c5, QUARTER);
    mysound(c5, HALF);
    mydelay(HALF);
    mydelay(WHOLE);
}
void abob(){
  mysound(bf4, HALF);
  mysound(f4, QUARTER);
  mysound(bf4, QUARTER);
  mysound(c5, QUARTER);
  mysound(d5, QUARTERD);
  mysound(c5, EIGHTH);
  mysound(bf4, HALF);
  mysound(ds5, QUARTER);
  mysound(d5, QUARTER);
  mysound(c5, QUARTER);
  mysound(bf4, QUARTER);
  mysound(a4, QUARTER);
  mysound(bf4, QUARTER);
  mysound(d5, QUARTER);
  mysound(c4, QUARTER);
  mydelay(QUARTER);
}

int main()
{

    
    double toneFrequency = 261;
    double timeHigh = (1 / (2 * toneFrequency)) * 1000;

    double tone = 1.9157;

    while (1)
    {
        //mysound(cs4, QUARTER);
        //mydelay(5);
       //cruel();
       fly();
       //elise();
       //tsar();
    }
}
