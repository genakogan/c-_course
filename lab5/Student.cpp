#include "Student.h"

int Student::student_counter = 0;

// Constructor
Student::Student(const std::string& name) : name(name) {
    student_id = ++student_counter;
}

// Function to check if the student already has a grade in a specific course
bool Student::hasGradeInCourse(const std::string& course) const {
    for (const auto& mark : marks) {
        if (mark.getCourseName() == course) {
            return true;
        }
    }
    return false;
}

// Function to add a mark to the student
void Student::addMark(const std::string& course, int grade) {
    for (auto& mark : marks) {
        if (mark.getCourseName() == course) {
            mark.setCourseAndGrade(course, grade);
            return;
        }
    }
    marks.emplace_back(course, grade);
}

void Student::addMark(const Mark& mark) {
    for (auto& existing_mark : marks) {
        if (existing_mark.getCourseName() == mark.getCourseName()) {
            existing_mark.setCourseAndGrade(mark.getCourseName(), mark.getGrade());
            return;
        }
    }
    marks.push_back(mark);
}

// Function to get the grade for a specific course
int Student::getGrade(const std::string& course) const {
    for (const auto& mark : marks) {
        if (mark.getCourseName() == course) {
            return mark.getGrade();
        }
    }
    return -1; // indicates that the course was not found
}

// Function to print the student's details and achievements
void Student::printDetails() const {
    std::cout << "Student ID: " << student_id << ", Name: " << name << std::endl;
    for (const auto& mark : marks) {
        mark.printDetails();
    }
}

// Function to calculate the average grade
double Student::calculateAverageGrade() const {
    int total_grades = 0;
    int num_courses = 0;
    for (const auto& mark : marks) {
        if (mark.getGrade() > 0) {
            total_grades += mark.getGrade();
            num_courses++;
        }
    }
    return num_courses > 0 ? static_cast<double>(total_grades) / num_courses : 0.0;
}

// Function to compare two students by their average grade
Student Student::compareAverageGrade(const Student& s1, const Student& s2) {
    return s1.calculateAverageGrade() < s2.calculateAverageGrade() ? s1 : s2;
}
