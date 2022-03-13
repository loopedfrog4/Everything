#include <iostream>

using namespace std;

class Student {
private:
    int idNum;
    static double gymFee;
public:
    // 2: what if we make gymFee public?
    static double gymFeePub;
    void setIdNum(int);
    void setGymFee(double);
    int getIdNum();
    double getGymFee();
    static double getGymFeeStatic();
};

// 50 + 7% GST;  be prepared to be 54.5. 
double Student::gymFee = 53.5;
double Student::gymFeePub = 53.5;
double Student::getGymFeeStatic() { return gymFee; }

void Student::setIdNum(int num) { idNum = num; }

void Student::setGymFee(double fee) { this->gymFee = fee; }

int Student::getIdNum() { return idNum; }

double Student::getGymFee() { return gymFee; }

int main() {
    Student student1, student2; // two objects from class-student

    // student1 and student2 each has his/her own idNum but they share one (static) gymFee
    student1.setIdNum(8);
    student2.setIdNum(24); // 53.5
    // 1: what if we reset the static value?
    student1.setGymFee(0);
    cout << "Student 1: " << student1.getIdNum() << "; Gym fee: " << student1.getGymFee() << endl;
    cout << "Student 2: " << student2.getIdNum() << "; Gym fee: " << student2.getGymFee() << endl;

    // the public static function getGymFee() is accessible without object instantiation
    cout << "gymFee (static function): " << Student::getGymFeeStatic() << endl;
    // non-static functions can access static variables
    // static functions cannot access non-static variables, why?

    // for public static gymFee
    cout << "Public gymFee: " << Student::gymFeePub << endl; // directly from class instead of obj
    Student::gymFeePub = 0;
    cout << "Public gymFee (update): " << Student::gymFeePub << endl;
    // difference between static and const?

    return 0;
}

