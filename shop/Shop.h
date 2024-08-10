//
// Created by Genady Kogan on 10/08/2024.
//

#ifndef SHOP_SHOP_H
#define SHOP_SHOP_H


#include "Employee.h"
#include "Manager.h"
#include "SeniorSeller.h"
#include "JuniorSeller.h"
#include "Cashier.h"
#include <iostream>
#include <algorithm>

class Shop {
    Employee** db;
    int size;
    int capacity;
    bool isManagerExist;

public:
    Shop();
    ~Shop();

    void Init();
    void PrintInfo() const;
};


#endif //SHOP_SHOP_H
