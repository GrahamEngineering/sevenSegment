# sevenSegment.h
A quick toolset to enable the simple manipulation of a 7-segment display.
### Current Version: 0.9
## Overview
A quickly-designed class for the use of setting a seven segment display
Useful for the following:
- Configuring your pin array quickly to map Arduino pin number to standard led letter _a-g_ or _decimal point (dp)_
- Setting/clearing an integer _[0-9]_
- Setting/clearing temperature-related characters _C_ elsius or _F_ ahrenheit
- Flashing a sequence _(with configurable timing)_ of any of the above
- Flashing an entire _string_ in a specific sequence
## Author
The author is Matthew Graham ([matthew.j.graham@gmail.com](mailto:matthew.j.graham@gmail.com])).  He don't know shit about programming.

Evidence:
> - Everything in this class is probably programmed incorrectly and/or inefficiently.
> - And it will probably somehow harm you and/or your loved ones.
> 	- Possibly will also destroy world.
>  		- And author may be currently in litigation regarding false claims.
>
## Class Members
Members of the sevenSegment class
### Public
- sevenSegment(int pinArray[8]);
- bool lightSegment(int seg);
- bool clearSegment(int seg);
- void showDigit(int digit);
- void clearDisplay();
- void flashDigit(int digit, int flashes, int duration_ms);
- void showFloat(float num);
- void showString(String s_numberToShow);
- int readDigit();
- void reinit();
### Private
- void writeBitfield(int arr[8]);
- bool compareArrays(int arr_a[8], int arr_b[8]);
- int _pinArray[8];
- uint8_t _reinitCounter;
- int c0[8] = {1,1,1,1,1,1,0,0};
- int c2[8] = {1,1,0,1,1,0,1,0};
- int c1[8] = {0,1,1,0,0,0,0,0};
- int c3[8] = {1,1,1,1,0,0,1,0};
- int c4[8] = {0,1,1,0,0,1,1,0};
- int c5[8] = {1,0,1,1,0,1,1,0};
- int c6[8] = {1,0,1,1,1,1,1,0};
- int c7[8] = {1,1,1,0,0,0,0,0};
- int c8[8] = {1,1,1,1,1,1,1,0};
- int c9[8] = {1,1,1,0,0,1,1,0};
- int c10[8] = {0,0,0,0,0,0,0,1};	// decimal point
- int c11[8] = {1,1,1,1,1,1,1,1};	// allon
- int c12[8] = {0,0,0,0,0,0,1,0};	// hyphen
- int c255[8] = {1,0,0,0,1,1,1,0};	// Fahrenheit (F)
- int c254[8] = {1,0,0,1,1,1,0,0}; 	// Celsius? (C)