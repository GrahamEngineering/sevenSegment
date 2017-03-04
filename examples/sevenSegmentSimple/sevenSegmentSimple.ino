/*
	A simple example of the seven-segment display, showing all possible display writings.
	
	Author: matthew.j.graham@gmail.com
	Date: 1 March 2017

*/
#include <sevenSegment.h>

int pinArray[8] = {4, 5, 6, 7, 8, 9, 10, 11};		// These are the default pins which are used if you just call sevenSegment::sevenSegment();
sevenSegment display_1 = sevenSegment(pinArray);
int delayTimer = 500;

void setup()
{
	Serial.begin(9600);
	While (!Serial){}
	Serial.println("---------------------------------");
	Serial.println("  Seven Segment Display Example  ");
	Serial.println("---------------------------------");
}

void loop()
{
	// Light each segment individually
	for (int i = 0; i < (sizeof)pinArray; i++)
	{
		display_1.lightSegment(i);
		delay(delayTimer);
		display_1.clearSegment(i);  // Alternatively, you can call clearDisplay() to clear all segments.
	}
	
	// Clear the display (turn all segments off)
	display_1.clearDisplay();
	delay(delayTimer);
	
	/*
		Show all of the digits.
			0 - 0
			1 - 1
			2 - 2
			3 - 3
			4 - 4
			5 - 5
			6 - 6
			7 - 7
			8 - 8
			9 - 9
			10 - decimal point
			11 - all segments
			12 - hyphen
			
	*/
	for (int j = 0; j < 13; j++)
	{
		display_1.showDigit(j);
		delay(delayTimer);
		display_1.clearDisplay();
	}
	
	// Show "F" in the display - useful for farenheit temperature
	display_1.showDigit(254);
	delay(delayTimer);
	
	// Show "C" in the display - useful for celsius temperature
	display_1.showDigit(255);
	delay(delayTimer);
	
	/*
		Flash example
		call "flashDigit()" with the digit you want to show, the number of flashes, and the ms for each flash.
		This is a blocking function - nothing else will run while flashing is happening for the delays
	*/
	for (int k = 0; k < (sizeof)pinArray; k++)
	{
		display_1.flashDigit(k, 3, 50);
	}
	
	/*
		String example
		Using "showString()" you can display a float value (e.g. 32.55) with a trailing "C" or "F"
			In all honesty, you can show any string that contains only [CF][0-9]\-\.
	*/
	
	display_1.showString("103.27F");
	
	display_1.clearDisplay();
	
	/*
		sevenSegment::showFloat(float num) will show a float value in the same manner as sevenSegment::showString(String s_numberToShow) but obviously 
			won't accept alphanumeric characters other than \- and \.  (hyophen representing a negative value and decimal point for the float value)
			
		Since it offers the same purpose as sevenSegment::showString, it is not demonstrated here.
	*/
	
	/*
		sevenSegment::readDigit() will return a value (0-12, 254, 255) representing which character is currently show on the display.  
	*/
}