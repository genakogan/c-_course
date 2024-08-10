//
// Created by Genady Kogan on 10/08/2024.
//

#include <iostream>
#include "Manager.h"
Manager::Manager(const std::string &name, const std::string &id, double percentage, double baseSalary, int managementLevel)
        : Employee(name, id, percentage, baseSalary), managementLevel(managementLevel) {}

double Manager::calculateSalary() const {
    return baseSalary * managementLevel * percentage;
}

void Manager::printInfo() const {
    std::cout << "Manager: " << name << ", ID: " << id
              << ", Management Level: " << managementLevel
              << ", Salary: " << calculateSalary() << std::endl;
}