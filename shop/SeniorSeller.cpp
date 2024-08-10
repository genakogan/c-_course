//
// Created by Genady Kogan on 10/08/2024.
//

#include "SeniorSeller.h"

#include <iostream>
#include <algorithm> // for std::copy

SeniorSeller::SeniorSeller(const std::string &name, const std::string &id, double percentage, double baseSalary)
        : Employee(name, id, percentage, baseSalary), salesCount(0), cancellationsCount(0),
          salesCapacity(10), cancellationsCapacity(10) {
    sales = new double[salesCapacity];
    cancellations = new double[cancellationsCapacity];
}

SeniorSeller::~SeniorSeller() {
    delete[] sales;
    delete[] cancellations;
}

void SeniorSeller::addSale(double amount) {
    if (salesCount == salesCapacity) {
        salesCapacity *= 2;
        double* newSales = new double[salesCapacity];
        std::copy(sales, sales + salesCount, newSales);
        delete[] sales;
        sales = newSales;
    }
    sales[salesCount++] = amount;
}

void SeniorSeller::addCancellation(double amount) {
    if (cancellationsCount == cancellationsCapacity) {
        cancellationsCapacity *= 2;
        double* newCancellations = new double[cancellationsCapacity];
        std::copy(cancellations, cancellations + cancellationsCount, newCancellations);
        delete[] cancellations;
        cancellations = newCancellations;
    }
    cancellations[cancellationsCount++] = amount;
}

double SeniorSeller::calculateSalary() const {
    double totalSales = 0;
    for (int i = 0; i < salesCount; ++i) {
        totalSales += sales[i];
    }
    return (baseSalary + (totalSales / salesCount)) * percentage * 1.5;
}

void SeniorSeller::printInfo() const {
    std::cout << "Senior Seller: " << name << ", ID: " << id
              << ", Salary: " << calculateSalary() << std::endl;
}
