//
// Created by Genady Kogan on 10/08/2024.
//

#ifndef SHOP_CASHIER_H
#define SHOP_CASHIER_H
#include "Employee.h"

class Cashier : public Employee {
    int transactions;

public:
    Cashier(const std::string &name, const std::string &id, double percentage, double baseSalary, int transactions);
    ~Cashier() override {}

    double calculateSalary() const override;
    void printInfo() const override;
};
#endif //SHOP_CASHIER_H
