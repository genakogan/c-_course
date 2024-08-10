//
// Created by Genady Kogan on 10/08/2024.
//

#ifndef SHOP_EMPLOYEE_H
#define SHOP_EMPLOYEE_H


#include <string>

class Employee {
protected:
    std::string name;
    std::string id;
    double percentage;
    double baseSalary;

public:
    Employee(const std::string &name, const std::string &id, double percentage, double baseSalary);
    virtual ~Employee();

    virtual double calculateSalary() const = 0;
    virtual void printInfo() const = 0;
};
#endif //SHOP_EMPLOYEE_H
