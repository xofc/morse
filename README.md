# morse
A small Arduino sketch to send morse

Synopsis : send_s("HELLO WORLD");

The sketch controls pin-8 and pin-13 (default LED) to send
a string in morse code.

DOT is the duration in milliseconds of a 'dot'; a 'dash' is 3 dots;
there is a 'dot' silence between dots and dashes, 3 dot silence between letters;
7 dot silence between words.

ref: https://en.wikipedia.org/wiki/Morse_code
https://commons.wikimedia.org/wiki/File:International_Morse_Code.svg

The 'silences' implementation is a little bit tricky
as a dot/dash (beep(duration)) is unconditionaly followed by a silence(1).
silence(2) is added to a letter (to make a silence(3)).
And silence(4) is added to a letter at the and of a word
to make silence(7).  Multiple spaces are not multiple of 7...

It only sends A-Z and 0-9 at constant speed.
