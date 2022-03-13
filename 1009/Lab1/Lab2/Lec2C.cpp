#include <iostream>

using namespace std;

class Employee {
    int idNum;
    double hourlyRate;
public:
    Employee();
    Employee(int, double); // non-default and function overloading int int/double
    Employee(int, double, int); // non-default and function overloading int int/double
    void setIdNum(const int);
    void setHourlyRate(const double);
    int getIdNum();
    double getHourlyRate();
};

Employee::Employee() { // default
    idNum = 1009;
    cout << "hello ict se is!" << endl;
} // boss obj does not call this constructor

Employee::Employee(int idNum, double hourlyRate) { // non-default
    this->idNum = idNum;
    this->hourlyRate = hourlyRate;
}

void Employee::setIdNum(const int id) { 
    idNum = id; 
}

void Employee::setHourlyRate(const double rate) {
    hourlyRate = rate;
}

int Employee::getIdNum() {
    return idNum;
}

double Employee::getHourlyRate() {
    return hourlyRate;
}

int main() {
    Employee admin; // obj 1009
    // 1. what will happen without defining a constructor?
    cout << "Before setting values:" << endl;
    cout << "ID: " << admin.getIdNum() << ", Rate: " << admin.getHourlyRate() << endl;
    
    admin.setIdNum(8);
    admin.setHourlyRate(24);
    cout << "After setting values:" << endl;
    cout << "ID: " << admin.getIdNum() << ", Rate: " << admin.getHourlyRate() << endl;

    // 2. what will happen if we define a non-default constructor?
    Employee boss(1, 66); // another obj int int
    cout << "Boss using non-default constructor:" << endl;
    cout << "ID: " << boss.getIdNum() << ", Rate: " << boss.getHourlyRate() << endl;
    
    return 0;
}


