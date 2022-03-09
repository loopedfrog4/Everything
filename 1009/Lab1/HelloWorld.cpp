#include <iostream>

using namespace std;

int main() {
    string inputStr = "";
    int inputNumber;
    cout << "Type a number";
    cin >> inputStr;
    inputNumber = stoi(inputStr);

    if (inputNumber < 100){
        cout << "Too small";
    }else{
        cout << "Big enough";
    }
    
	return 0;
}