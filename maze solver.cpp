#define trig_pinF A3
#define echo_pinF A2
#define trig_pinL A5
#define echo_pinL A4
#define trig_pinR A1
#define echo_pinR A0

int enA = 5;
int in1 = 4;
int in2 = 3;
int enB = 10;
int in3 = 8;
int in4 = 9;

int duration, distanceF, distanceL, distanceR;

void setup()
{
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(enB, OUTPUT);

    pinMode(trig_pinF, OUTPUT);
    pinMode(echo_pinF, INPUT);
    pinMode(trig_pinL, OUTPUT);
    pinMode(echo_pinL, INPUT);
    pinMode(trig_pinR, OUTPUT);
    pinMode(echo_pinR, INPUT);

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    Serial.begin(9600);
}

void loop()
{
    digitalWrite(trigPinF, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinF, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinF, LOW);
    duration = pulseIn(echoPinF, HIGH);
    distanceF =  duration * 0.034 / 2;
    
    digitalWrite(trigPinR, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinR, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinR, LOW);
    duration = pulseIn(echoPinR, HIGH);
    distanceR =  duration * 0.034 / 2;
    
    digitalWrite(trigPinL, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinL, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinL, LOW);
    duration = pulseIn(echoPinL, HIGH);
    distanceL =  duration * 0.034 / 2;


    if (distanceL <= 10)
    {
        analogWrite(enA, 80);
        analogWrite(enB, 10);
    }
    else if (distanceR <= 10)
    {
        analogWrite(enA, 10);
        analogWrite(enB, 80);
    }
    else
    {
        analogWrite(enA, 80);
        analogWrite(enB, 80);
    }
}
