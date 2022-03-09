#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ofstream MyWriteFile("example.txt");

    if (MyWriteFile.is_open()) {
        cout << "File successfully opened";
    }else{
        cout << "Error opening file";
    }
        
    MyWriteFile << "Wei\nNew Line";

    MyWriteFile.close();
    
    return 0;
}