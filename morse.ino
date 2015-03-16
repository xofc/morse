#define DOT	100	/* ms */
#define PIN	8	/* output pin */

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
	delay(n * DOT);
	}
void beep(int n)
	{
	digitalWrite(13, HIGH);
	digitalWrite(PIN, HIGH);
	delay(n * DOT);
	digitalWrite(PIN, LOW);
	digitalWrite(13, LOW);
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
	}
void loop()
	{
	send_s("HELLO WORLD");
        delay(2000);
	}
