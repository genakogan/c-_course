//
// Created by Genady Kogan on 10/08/2024.
//

#include "Cashier.h"
#include "Cashier.h"
#include <iostream>

Cashier::Cashier(const std::string &name, const std::string &id, double percentage, double baseSalary, int transactions)
        : Employee(name, id, percentage, baseSalary), transactions(transactions) {}

double Cashier::calculateSalary() const {
    return (baseSalary + transactions) * percentage;
}

void Cashier::printInfo() const {
    std::cout << "Cashier: " << name << ", ID: " << id
              << ", Transactions: " << transactions
              << ", Salary: " << calculateSalary() << std::endl;
}
