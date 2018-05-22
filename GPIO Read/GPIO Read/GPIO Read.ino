/*
 Name:		GPIO_Read.ino
 Created:	5/22/2018 9:12:07 PM
 Author:	MQ Crexcel
*/

#define Sw1 2
#define Sw2 3
#define Sw3 4
#define Sw4 5
#define Sw5 6
#define Sw6 7
#define Sw7 8
#define Sw8 9

#define Led 10

char bitpwm[8];
int pwm = 0;
int dem = 0;

void setup() {
/*Config GPIO IN , PWM OUT */

	pinMode(Sw1, INPUT);
	pinMode(Sw2, INPUT);
	pinMode(Sw3, INPUT);
	pinMode(Sw4, INPUT);
	pinMode(Sw5, INPUT);
	pinMode(Sw6, INPUT);
	pinMode(Sw7, INPUT);
	pinMode(Sw8, INPUT);

	pinMode(Led, OUTPUT);

	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {

	if (digitalRead(Sw1) == 0)
	{
		bitpwm[0] = 1;
	}
	    else{ bitpwm[0] = 0; }

	if (digitalRead(Sw2) == 0)
	{
		bitpwm[1] = 2;
	}
	    else { bitpwm[1] = 0; }

	if (digitalRead(Sw3) == 0)
	{
		bitpwm[2] = 4;
	}
		else { bitpwm[2] = 0; }

	if (digitalRead(Sw4) == 0)
	{
		bitpwm[3] = 8;
	}
		else { bitpwm[3] = 0; }

	if (digitalRead(Sw5) == 0)
	{
		bitpwm[4] = 16;
	}
		else { bitpwm[4] = 0; }

	if (digitalRead(Sw6) == 0)
	{
		bitpwm[5] = 32;
	}
		else { bitpwm[5] = 0; }

	if (digitalRead(Sw7) == 0)
	{
		bitpwm[6] = 64;
	}
		else { bitpwm[6] = 0; }

	if (digitalRead(Sw8) == 0)
	{
		bitpwm[7] = 128;
	}
		else { bitpwm[7] = 0; }
  
    for (dem = 0; dem <= 7; dem++)
	{
		pwm += bitpwm[dem];
	}

	analogWrite(Led, pwm);
	Serial.print(pwm, BIN);
	Serial.print("\n");    
	delay(1000);
	pwm = 0;

}
