//
// Created by Genady Kogan on 10/08/2024.
//

#include "Shop.h"
#include "Shop.h"

Shop::Shop() : size(0), capacity(10), isManagerExist(false) {
    db = new Employee*[capacity];
}

Shop::~Shop() {
    for (int i = 0; i < size; ++i) {
        delete db[i];
    }
    delete[] db;
}

void Shop::Init() {
    int numEmployees;
    std::cout << "Enter the number of employees: ";
    std::cin >> numEmployees;

    for (int i = 0; i < numEmployees; ++i) {
        if (size == capacity) {
            capacity *= 2;
            Employee** newDb = new Employee*[capacity];
            std::copy(db, db + size, newDb);
            delete[] db;
            db = newDb;
        }

        std::string name, id;
        double percentage, baseSalary;
        int type;

        std::cout << "Enter type of employee (1-Manager, 2-Senior Seller, 3-Junior Seller, 4-Cashier): ";
        std::cin >> type;
        std::cout << "Enter name, ID, percentage, and base salary: ";
        std::cin >> name >> id >> percentage >> baseSalary;

        if (type == 1) {
            if (isManagerExist) {
                std::cout << "Manager already exists!" << std::endl;
                continue;
            }
            int managementLevel;
            std::cout << "Enter management level (1-3): ";
            std::cin >> managementLevel;
            db[size++] = new Manager(name, id, percentage, baseSalary, managementLevel);
            isManagerExist = true;
        } else if (type == 2) {
            db[size++] = new SeniorSeller(name, id, percentage, baseSalary);
        } else if (type == 3) {
            db[size++] = new JuniorSeller(name, id, percentage, baseSalary);
        } else if (type == 4) {
            int transactions;
            std::cout << "Enter number of transactions: ";
            std::cin >> transactions;
            db[size++] = new Cashier(name, id, percentage, baseSalary, transactions);
        }
    }
}

void Shop::PrintInfo() const {
    for (int i = 0; i < size; ++i) {
        db[i]->printInfo();
    }
}
