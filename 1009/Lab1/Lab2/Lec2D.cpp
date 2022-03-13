#include <iostream>

using namespace std;

class House {
	int squareFeet = 1000;
public:
	House();
	~House();
};

House::House() { cout << "House created." << endl; }
// called automatically when an object goes out of scope
House::~House() { cout << "~ House destroyed." << endl; }

/*
int main() {
	// what is the scope for aHouse?
	House aHouse[3]; // int x[3]
	cout << ">>> End of program" << endl;
	return 0;
}//*/


//*
int main() {
	// what is the scope for aHouse?
	for (int i = 0; i < 3; i++) { // i 0 1 2
		cout << "i: " << i << " ";
		House aHouse;
	}
	cout << "End of program" << endl;
	return 0;
}//*/


