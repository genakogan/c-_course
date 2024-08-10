//
// Created by Genady Kogan on 10/08/2024.
//

#ifndef SHOP_JUNIORSELLER_H
#define SHOP_JUNIORSELLER_H
#include "Employee.h"

class JuniorSeller : public Employee {
    double* sales;
    int salesCount;
    int salesCapacity;

public:
    JuniorSeller(const std::string &name, const std::string &id, double percentage, double baseSalary);
    ~JuniorSeller() override;

    void addSale(double amount);

    double calculateSalary() const override;
    void printInfo() const override;
};
#endif //SHOP_JUNIORSELLER_H
