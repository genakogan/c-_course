#ifndef MARK_H
#define MARK_H

#include <iostream>
#include <string>

class Mark {
private:
    std::string course_name;
    int grade;

public:
    // Default Constructor
    Mark(std::string course_name = "Unknown", int grade = 0);

    // Function to check if the course is in the list
    bool isCourseInList(const std::string& course) const;

    // Function to validate and set course name and grade
    void setCourseAndGrade(const std::string& course, int grade);

    // Function to print the object's details
    void printDetails() const;

    // Getters
    std::string getCourseName() const { return course_name; }
    int getGrade() const { return grade; }
};

#endif // MARK_H
