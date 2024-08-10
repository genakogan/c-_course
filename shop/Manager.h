//
// Created by Genady Kogan on 10/08/2024.
//

#ifndef SHOP_MANAGER_H
#define SHOP_MANAGER_H
#include "Employee.h"
class Manager : public Employee {
    int managementLevel;

public:
    Manager(const std::string &name, const std::string &id, double percentage, double baseSalary, int managementLevel);
    ~Manager() override {}

    double calculateSalary() const override;
    void printInfo() const override;
};

#endif //SHOP_MANAGER_H
