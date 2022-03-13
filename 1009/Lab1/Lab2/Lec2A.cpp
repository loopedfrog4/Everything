#include "Student.h"

int main() {
    Student student1;
    Student student2;

    student1.setName("Jon Snow");
    student1.setIdNum(1234);
    student1.setGradeAverage(4.0);
    student1.displayStudent();

    student2.setName("King in the North");
    student2.setIdNum(10'000);
    student2.setGradeAverage(5.0);
    student2.displayStudent();

    return 0;
}
