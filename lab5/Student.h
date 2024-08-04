#ifndef STUDENT_H
#define STUDENT_H

#include "Mark.h"
#include <string>
#include <vector>

class Student {
private:
    static int student_counter;
    int student_id;
    std::string name;
    std::vector<Mark> marks;

public:
    // Constructor
    Student(const std::string& name);

    // Function to check if the student already has a grade in a specific course
    bool hasGradeInCourse(const std::string& course) const;

    // Function to add a mark to the student
    void addMark(const std::string& course, int grade);
    void addMark(const Mark& mark);

    // Function to get the grade for a specific course
    int getGrade(const std::string& course) const;

    // Function to print the student's details and achievements
    void printDetails() const;

    // Function to calculate the average grade
    double calculateAverageGrade() const;

    // Function to compare two students by their average grade
    static Student compareAverageGrade(const Student& s1, const Student& s2);
};

#endif // STUDENT_H
