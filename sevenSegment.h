/*
 *  sevenSegment.h
*/
#ifndef sevenSegment_h
#define sevenSegment_h

#include "Arduino.h"

class sevenSegment
{
  public:
    sevenSegment();
	sevenSegment(int pinArray[8]);
	bool lightSegment(int seg);
	bool clearSegment(int seg);
	void clearDisplay();
	void showDigit(int digit);
	void flashDigit(int digit, int flashes, int duration_ms);
	void showString(String s_numberToShow);
	void showFloat(float num);
	int readDigit();
	void reinit();
	void loadAnimation();
	void loadAnimation(int repeatCount);
	
  private:
	void _writeBitfield(int arr[8]);
	bool _compareArrays(int arr_a[8], int arr_b[8]);
	int _pinArray[8];
	uint8_t _reinitCounter;
	int c0[8] = {1,1,1,1,1,1,0,0};
	int c2[8] = {1,1,0,1,1,0,1,0};
	int c1[8] = {0,1,1,0,0,0,0,0};
	int c3[8] = {1,1,1,1,0,0,1,0};
	int c4[8] = {0,1,1,0,0,1,1,0};
	int c5[8] = {1,0,1,1,0,1,1,0};
	int c6[8] = {1,0,1,1,1,1,1,0};
	int c7[8] = {1,1,1,0,0,0,0,0};
	int c8[8] = {1,1,1,1,1,1,1,0};
	int c9[8] = {1,1,1,0,0,1,1,0};
	int c10[8] = {0,0,0,0,0,0,0,1};		// decimal point
	int c11[8] = {1,1,1,1,1,1,1,1};		// all on
	int c12[8] = {0,0,0,0,0,0,1,0};		// hyphen
	int c255[8] = {1,0,0,0,1,1,1,0};	// Error (F)
	int c254[8] = {1,0,0,1,1,1,0,0}; 	// Celsius? (C)
};

#endif
