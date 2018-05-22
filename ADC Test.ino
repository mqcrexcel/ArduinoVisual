#define Sensor0 0
#define Sensor1 1

#define Led 13

#define L_OFF 0
#define L_ON 1

int analogSS1 = 0;
int analogSS2 = 0;

void setup()
{
	pinMode(Sensor0, INPUT);
	pinMode(Sensor1, INPUT);
	pinMode(Led, OUTPUT);
	Serial.begin(9600);
}


void loop()
{
	analogSS1 = analogRead(0);
	analogSS2 = analogRead(1);

	if (analogSS1 >= analogSS2)
	{
		digitalWrite(Led, L_ON);
		Serial.println("Led turn on");

	}
	else
	{
		digitalWrite(Led, L_OFF);
		Serial.println("Led turn off");
	}

}
