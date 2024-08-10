//
// Created by Genady Kogan on 10/08/2024.
//

#ifndef SHOP_SENIORSELLER_H
#define SHOP_SENIORSELLER_H

#include "Employee.h"

class SeniorSeller : public Employee {
    double* sales;
    double* cancellations;
    int salesCount;
    int cancellationsCount;
    int salesCapacity;
    int cancellationsCapacity;

public:
    SeniorSeller(const std::string &name, const std::string &id, double percentage, double baseSalary);
    ~SeniorSeller() override;

    void addSale(double amount);
    void addCancellation(double amount);

    double calculateSalary() const override;
    void printInfo() const override;
};
#endif //SHOP_SENIORSELLER_H
