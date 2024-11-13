// New feature! Overclocking WS2812
// #define FASTLED_OVERCLOCK 1.2 // 20% overclock ~ 960 khz.
#include <FastLED.h>
#define NUM_LEDS 100
#define DATA_PIN 6
CRGB leds[NUM_LEDS];
#define MY_COLOR  CRGB::Green
#define MY_BLACK  CRGB::Black

#define DOT	100	/* ms */
#define BUZZER	8	/* output pin */
#define SYSTEM_LED 13	/* output pin */

void led_push(int on)
    {
    int i;

    for (i = NUM_LEDS-1; i > 0; i--)
        {
        leds[i] = leds[i-1];
        }
    leds[0] = on ? MY_COLOR : MY_BLACK;
    FastLED.show();
    }
char *alphas[] = {
		"._", "_...", "_._.", "_..", ".",	/* A-E */
		".._.", "__.", "....", "..", ".___",	/* F-J */
		"_._", "._..", "__", "_.", "___",	/* K-O */
		".__.", "__._", "._.", "...", "_",	/* P-T */
		".._", "..._", ".__", "_.._", "_.__",	/* U-Y */
		"__.."					/* Z */
		};
char *numbers[] =	{
		"_____",					/* 0 */
		".____", "..___", "...__", "...._", ".....",	/* 1-5 */
		"_....", "__...", "___..", "____."		/* 6-9 */
		};
void silence(int n)
	{
  int i;

  for (i = 0; i < n; i++)
    {
    led_push(0);
    delay(DOT);
    }
	}
void beep(int n)
	{
  int i;

	digitalWrite(SYSTEM_LED, HIGH);
	digitalWrite(BUZZER, HIGH);
  for (i = 0; i < n; i++)
    {
    led_push(1);
    delay(DOT);
    }
	digitalWrite(BUZZER, LOW);
	digitalWrite(SYSTEM_LED, LOW);
	}
void send_c(char *str)
	{
	char c;

	while (c = *str++)
		{
		if (c == '.')
			beep(1);
		else	beep(3);
		silence(1);
		}
	silence(2);
	}
void send_s(char *str)
	{
	char c;

	while (c = *str++)
		{
		if (c >= 'A' && c <= 'Z')
			send_c(alphas[c - 'A']);
		if (c >= '0' && c <= '9')
			send_c(numbers[c - '0']);
		if (c == ' ')
			silence(4);
		}
	}
void setup()
	{
	pinMode(BUZZER, OUTPUT);
	pinMode(SYSTEM_LED, OUTPUT);
  FastLED.addLeds<WS2812B, DATA_PIN, BGR>(leds, NUM_LEDS);
	}
void loop()
	{
//	send_s("HELLO WORLD");
   send_s("SOS");
   silence(5);
   delay(5000);
	}
