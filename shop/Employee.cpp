//
// Created by Genady Kogan on 10/08/2024.
//

#include "Employee.h"
Employee::Employee(const std::string &name, const std::string &id, double percentage, double baseSalary)
        : name(name), id(id), percentage(percentage), baseSalary(baseSalary) {}

Employee::~Employee() {}