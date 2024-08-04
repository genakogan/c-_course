#include "Mark.h"
#include <vector>
#include <algorithm>

// Default Constructor
Mark::Mark(std::string course_name, int grade) : course_name(course_name), grade(grade) {}

// Function to check if the course is in the list
bool Mark::isCourseInList(const std::string& course) const {
    std::vector<std::string> course_list = {"Math", "Physics", "Computer Science", "Chemistry"};
    return std::find(course_list.begin(), course_list.end(), course) != course_list.end();
}

// Function to validate and set course name and grade
void Mark::setCourseAndGrade(const std::string& course, int grade) {
    if (isCourseInList(course) && grade >= 0 && grade <= 100) {
        this->course_name = course;
        this->grade = grade;
    } else {
        this->course_name = "Unknown";
        this->grade = 0;
    }
}

// Function to print the object's details
void Mark::printDetails() const {
    std::cout << "Course: " << course_name << ", Grade: " << grade << std::endl;
}
