/*
	sevenSegment.cpp
    Allows user to configure and publish to a seven segment display
	pin diagram to follow
	
          _a_
        f|   |b
         |_g_|
        e|   |c
         |_d_|   . P
	
	array goes in order of {a,b,c,d,e,f,g,P} for a total of eight bits.

	
 */
#include "Arduino.h"
#include "sevenSegment.h"

sevenSegment::sevenSegment(int pinArray[8])
{
	// Initialization array is in order of pins for segments {a,b,c,d,e,f,g,P}
	// Recommend using 4,5,6,7,8,9,10,11
	for (int i = 0; i < 8; i++)
	{
		_pinArray[i] = pinArray[i];
		pinMode(pinArray[i], OUTPUT);
	}
	
	_reinitCounter = 0;
	
}

bool sevenSegment::compareArrays(int arr_a[8], int arr_b[8])
{
	for (int i=0; i < 8; i++)
	{
		if (arr_a[i] != arr_b[i])
		{
			return false;
		}
	}
	return true;
}

void sevenSegment::reinit()
{
	for (int i = 0; i < 8; i++)
	{
		digitalWrite(_pinArray[i], HIGH);
	}
	
	delay(50);
	
	for (int i = 0; i < 8; i++)
	{
		digitalWrite(_pinArray[i], LOW);
	}
	
}

bool sevenSegment::lightSegment(int seg)
{
	int segment = _pinArray[seg];
	
	if (digitalRead(segment))
	{
		// segment is already on
		return false;
	}
	else
	{
		digitalWrite(segment, HIGH);
		return true;
	}
}

bool sevenSegment::clearSegment(int seg)
{
	int segment = _pinArray[seg];
	
	if (digitalRead(segment) == LOW)
	{
		// segment is already off
		return false;
	}
	else
	{
		digitalWrite(segment, LOW);
		return true;
	}
}


void sevenSegment::clearDisplay()
{
	for (int i = 0; i < 8; i++)
	{
		digitalWrite(_pinArray[i], LOW);
	}
	return;
}

void sevenSegment::showDigit(int digit)
{
	if (digit >=0 && digit <= 12)
	{
		// digit is in range
		/*
			0 - {0,1,1,1,1,1,1,0}
			1 - {0,0,0,1,0,0,1,0}
			2 - {1,0,1,1,1,1,0,0}
			3 - {1,0,1,1,0,1,1,0}
			4 - {1,1,0,1,0,0,1,0}
			5 - {1,1,1,0,0,1,1,0}
			6 - {1,1,1,0,1,1,1,0}
			7 - {0,0,1,1,0,0,1,0}
			8 - {1,1,1,1,1,1,1,0}
			9 - {1,1,1,1,0,0,1,0}
			10 - (decmal point) {0,0,0,0,0,0,0,1}
			11 = (all) {1,1,1,1,1,1,1,1}
			12 = (hyphen) {0,0,0,0,0,0,1,0}
		
		
		*/
		switch (digit)
		{
			case 0:
			{
				writeBitfield(c0);
				break;
			}
			case 1:
			{
				writeBitfield(c1);
				break;
			}
			case 2:
			{
				writeBitfield(c2);
				break;
			}
			case 3:
			{
				writeBitfield(c3);
				break;
			}
			case 4:
			{
				writeBitfield(c4);
				break;
			}
			case 5:
			{
				writeBitfield(c5);
				break;
			}
			case 6:
			{
				writeBitfield(c6);
				break;
			}
			case 7:
			{
				writeBitfield(c7);
				break;
			}
			case 8:
			{
				writeBitfield(c8);
				break;
			}
			case 9:
			{
				writeBitfield(c9);
				break;
			}
			case 10:
			{
				writeBitfield(c10);
				break;
			}
			case 11:
			{
				writeBitfield(c11);
				break;
			}
			case 12:
			{
				writeBitfield(c12);
				break;
			}
			case 255:
			{
				writeBitfield(c255);
				break;
			}
			case 254:
			{
				writeBitfield(c254);
				break;
			}
			default:
			{
				writeBitfield(c255);
				break;
			}
		}
	}
	else
	{
		writeBitfield(c255);
	}
}

void sevenSegment::writeBitfield(int arr[8])
{
	for (int i = 0; i < 8; i++)
	{
		if (arr[i])
		{
			digitalWrite(_pinArray[i], HIGH);
		}
		else
		{
			digitalWrite(_pinArray[i], LOW);
		}
	}
}

void sevenSegment::flashDigit(int digit, int flashes, int duration_ms)
{
	// loop (flashes) times
	for (int i = 0; i < flashes; i++)
	{
		//flash
		showDigit(digit);
		// number stays on for duration_ms
		delay(duration_ms);
		// turn number off
		clearDisplay();
		// number stays off for duration_ms
		delay(duration_ms);
	}
}

int sevenSegment::readDigit()
{
	int currentPins[8];
	int outputInt;
	
	// Read the current pins
	for (int i = 0; i < 8; i++)
	{
		currentPins[i] = digitalRead(_pinArray[i]);
	}
	
	// Compare to known values	
	if (compareArrays(currentPins, c0))
	{
		outputInt = 0;	
	}
	else if (compareArrays(currentPins, c1))
	{
		outputInt = 1;
	}
	else if (compareArrays(currentPins, c2))
	{
		outputInt = 2;
	}
	else if (compareArrays(currentPins, c3))
	{
		outputInt = 3;
	}
	else if (compareArrays(currentPins, c4))
	{
		outputInt = 4;
	}
	else if (compareArrays(currentPins, c5))
	{
		outputInt = 5;
	}
	else if (compareArrays(currentPins, c6))
	{
		outputInt = 6;
	}
	else if (compareArrays(currentPins, c7))
	{
		outputInt = 7;
	}
	else if (compareArrays(currentPins, c8))
	{
		outputInt = 8;
	}
	else if (compareArrays(currentPins, c9))
	{
		outputInt = 9;
	}
	else if (compareArrays(currentPins, c10))
	{
		outputInt = 10;
	}
	else if (compareArrays(currentPins, c11))
	{
		outputInt = 11;
	}
	else if (compareArrays(currentPins, c12))
	{
		outputInt = 12;
	}
	else if (compareArrays(currentPins, c255))
	{
		outputInt = 255;
	}
	else if (compareArrays(currentPins, c254))
	{
		outputInt = 254;
	}
	else
	{
		// something has gone horribly wrong.
		outputInt = 255;
	}
	return outputInt;
}

void sevenSegment::showFloat(float num)
{
	String s_numberToShow = String(num);
	int i_numberToShow;
	
	// Start by flashing the decimal point slowly 3 times
	flashDigit(10, 3, 500);

	// Show each char, flashing 5 times for 50ms each flash
	for (int i = 0; i < (s_numberToShow.length()); i++)
	{
		if (s_numberToShow[i] == '.')
		{
			// DP is 10
			i_numberToShow = 10;
		}
		else if (s_numberToShow[i] == '-')
		{
			// minus (hyphen) is 12
			i_numberToShow = 12;
		}
		else if (s_numberToShow[i] == 'F')
		{
			i_numberToShow = 255;
		}
		else if (s_numberToShow[i] == 'C')
		{
			i_numberToShow = 254;
		}
		else
		{
			// just show digits as numbers (convert char to String to int)
			i_numberToShow = String(s_numberToShow[i]).toInt();
		}
		flashDigit(i_numberToShow, 5, 50);
		clearDisplay();
		delay(200);
	}
}

void sevenSegment::showString(String s_numberToShow)
{
	int i_numberToShow;
	
	// Start by flashing the decimal point slowly 3 times
	flashDigit(10, 3, 500);

	// Show each char, flashing 5 times for 50ms each flash
	for (int i = 0; i < (s_numberToShow.length()); i++)
	{
		if (s_numberToShow[i] == '.')
		{
			// DP is 10
			i_numberToShow = 10;
		}
		else if (s_numberToShow[i] == '-')
		{
			// minus (hyphen) is 12
			i_numberToShow = 12;
		}
		else if (s_numberToShow[i] == 'F')
		{
			i_numberToShow = 255;
		}
		else if (s_numberToShow[i] == 'C')
		{
			i_numberToShow = 254;
		}
		else
		{
			// just show digits as numbers (convert char to String to int)
			i_numberToShow = String(s_numberToShow[i]).toInt();
		}
		flashDigit(i_numberToShow, 5, 50);
		clearDisplay();
		delay(200);
	}
}

void sevenSegment::loadAnimation()
{
	int segmentDelay = 200; 		// X ms delay for each segment
	
	// Segments to show: a,b,c,d,e,f ==> 0,1,2,3,4,5
	
	for (int segment = 0; segment <= 5; segment++)
	{
		int previousSegment;
		
		if (segment == 0)
		{
			previousSegment = 5;
		}
		else
		{
			previousSegment = segment - 1;
		}
		
		clearSegment(previousSegment);
		lightSegment(segment);
		delay(segmentDelay);
	}

	clearDisplay();
}