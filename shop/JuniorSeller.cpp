//
// Created by Genady Kogan on 10/08/2024.
//

#include "JuniorSeller.h"
#include "JuniorSeller.h"
#include <iostream>
#include <algorithm> // for std::copy

JuniorSeller::JuniorSeller(const std::string &name, const std::string &id, double percentage, double baseSalary)
        : Employee(name, id, percentage, baseSalary), salesCount(0), salesCapacity(10) {
    sales = new double[salesCapacity];
}

JuniorSeller::~JuniorSeller() {
    delete[] sales;
}

void JuniorSeller::addSale(double amount) {
    if (salesCount == salesCapacity) {
        salesCapacity *= 2;
        double* newSales = new double[salesCapacity];
        std::copy(sales, sales + salesCount, newSales);
        delete[] sales;
        sales = newSales;
    }
    sales[salesCount++] = amount;
}

double JuniorSeller::calculateSalary() const {
    double totalSales = 0;
    for (int i = 0; i < salesCount; ++i) {
        totalSales += sales[i];
    }
    return (baseSalary + (totalSales / salesCount) + salesCount) * percentage;
}

void JuniorSeller::printInfo() const {
    std::cout << "Junior Seller: " << name << ", ID: " << id
              << ", Salary: " << calculateSalary() << std::endl;
}
