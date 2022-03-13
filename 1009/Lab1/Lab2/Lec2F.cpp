#include <stdio.h>
#include <iostream>

// #define CLS_CODE 1009 // cls_code state: defined
#ifndef CLS_CODE // cls_code not defined? -> true, it has been defined 
	#define CLS_CODE "ICT1009" // only if u ans true, but it is false
#else // false = cls_code defined
	#define YEAR_CODE 2022 // define year_code 2022; year_code status: defined
#endif // end 

using namespace std;

int main() {
	cout << "Course Code: " << CLS_CODE <<endl;
	cout << "Year: " << YEAR_CODE << endl;

	return 0;
}