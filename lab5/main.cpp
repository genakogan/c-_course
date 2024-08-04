#include <iostream>
#include "Mark.h"
#include "Student.h"

int main() {


    Mark mark2("Physics", 90);
    Mark mark3("Chemistry", 75);

    Student student1("John Doe");
    Student student2("Jane Smith");

    student1.addMark(mark1);
    student1.addMark(mark2);
    student2.addMark(mark3);
    student2.addMark("Computer Science", 95);

    std::cout << "Student 1 details:" << std::endl;
    student1.printDetails();
    std::cout << "Student 2 details:" << std::endl;
    student2.printDetails();

    Student lower_avg_student = Student::compareAverageGrade(student1, student2);
    std::cout << "Student with lower average grade:" << std::endl;
    lower_avg_student.printDetails();

    return 0;
}
