/**
 * Blink
 * Turns on an LED on for one second.
 * then off for one second. repeatedly.
 */

#ifndef UNIT_TEST

#include "Sample.h"
#include "Arduino.h"

Sample sample;

void setup()
{
	// initialize LED digital pin as an output.
	pinMode(LED_BUILTIN, OUTPUT);
	sample = Sample();
}

void loop()
{
	// turn the LED on (HIGH is the voltage elvel)
	digitalWrite(LED_BUILTIN, HIGH);
	// wait for a second
	delay(1000);
	// turn the LED off by making the voltage LOW
	digitalWrite(LED_BUILTIN, LOW);
	// wait for a second
	delay(1000);
}
#endif
