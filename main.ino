int r_motor_pwm_forward = 5;
int r_motor_pwm_backward = 6;
int motorA1en = 4;
int motorA2en = 2;

int l_motor_pwm_forward = 10;
int l_motor_pwm_backward = 9;
int motorB1en = 8;
int motorB2en = 7;

int speed = 245;

char serial_scan;

void setup()
{

    pinMode(r_motor_pwm_forward, OUTPUT);
    pinMode(r_motor_pwm_backward, OUTPUT);
    pinMode(motorA1en, OUTPUT);
    pinMode(motorA2en, OUTPUT);

    pinMode(l_motor_pwm_forward, OUTPUT);
    pinMode(l_motor_pwm_backward, OUTPUT);
    pinMode(motorB1en, OUTPUT);
    pinMode(motorB2en, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
    if (Serial.available() >= 0)
    {
        serial_scan = Serial.read();
    }

    switch (serial_scan)
    {
    case 'F':
        forward();
        break;
    case 'B':
        backward();
        break;
    case 'L':
        left();
        break;
    case 'R':
        right();
        break;
    case 'G':
        forward_left();
        break;
    case 'I':
        forward_right();
        break;

    case 'H':
        backward_left();
        break;
    case 'J':
        backward_right();
        break;

    case '0':
        speed = 0;
        break;

    case '1':
        speed = 25;
        break;

    case '2':
        speed = 50;
        break;

    case '3':
        speed = 75;
        break;

    case '4':
        speed = 100;
        break;

    case '5':
        speed = 125;
        break;

    case '6':
        speed = 150;
        break;

    case '7':
        speed = 175;
        break;

    case '8':
        speed = 200;
        break;

    case '9':
        speed = 225;
        break;

    case 'q':
        speed = 255;
        break;

    default:
        Stop();
        break;
    }
}

void forward()
{
    motorFunction();
    analogWrite(r_motor_pwm_forward, 0);
    analogWrite(r_motor_pwm_backward, speed);
    analogWrite(l_motor_pwm_forward, 0);
    analogWrite(l_motor_pwm_backward, speed);

    Serial.println("Forward");
}

void backward()
{
    motorFunction();
    analogWrite(r_motor_pwm_backward, 0);
    analogWrite(r_motor_pwm_forward, speed);
    analogWrite(l_motor_pwm_backward, 0);
    analogWrite(l_motor_pwm_forward, speed);
}

void left()
{
    motorFunction();

    analogWrite(l_motor_pwm_backward, speed);
    analogWrite(l_motor_pwm_forward, 0);
    analogWrite(r_motor_pwm_forward, speed);
    analogWrite(r_motor_pwm_backward, 0);
}

void forward_left()
{
    motorFunction();

    analogWrite(l_motor_pwm_backward, speed);
    analogWrite(l_motor_pwm_forward, 0);
    analogWrite(r_motor_pwm_forward, 0);
    analogWrite(r_motor_pwm_backward, 0);
}

void right()
{
    motorFunction();

    analogWrite(l_motor_pwm_forward, speed);
    analogWrite(l_motor_pwm_backward, 0);
    analogWrite(r_motor_pwm_backward, speed);
    analogWrite(r_motor_pwm_forward, 0);
}

void forward_right()
{
    motorFunction();

    analogWrite(l_motor_pwm_forward, 0);
    analogWrite(l_motor_pwm_backward, 0);
    analogWrite(r_motor_pwm_backward, speed);
    analogWrite(r_motor_pwm_forward, 0);
}

void backward_right()
{
    motorFunction();

    analogWrite(l_motor_pwm_backward, 0);
    analogWrite(l_motor_pwm_forward, speed);
    analogWrite(r_motor_pwm_backward, 0);
    analogWrite(r_motor_pwm_forward, 0);
}

void backward_left()
{
    motorFunction();

    analogWrite(l_motor_pwm_backward, 0);
    analogWrite(l_motor_pwm_forward, 0);
    analogWrite(r_motor_pwm_backward, 0);
    analogWrite(r_motor_pwm_forward, speed);
}

void motorFunction()
{
    digitalWrite(motorA1en, HIGH);
    digitalWrite(motorA2en, HIGH);
    digitalWrite(motorB1en, HIGH);
    digitalWrite(motorB2en, HIGH);
}
void Stop()
{
    motorFunction();

    Serial.println("Stop");

    analogWrite(l_motor_pwm_backward, 0);
    analogWrite(l_motor_pwm_forward, 0);
    analogWrite(r_motor_pwm_backward, 0);
    analogWrite(r_motor_pwm_forward, 0);
}