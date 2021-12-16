//
// Created by Константин Воронин on 15.12.2021.
//

#ifndef ACSHOMEWORK5_CASHIER_H
#define ACSHOMEWORK5_CASHIER_H

#include "queue.h"

class cashier {
    int id;
    queue* customer_queue;

    void sleep(int millisec);

public:
    cashier(int id, queue* queue);
    void run();
    void cashOut(customer *currCustomer);
};

#endif //ACSHOMEWORK5_CASHIER_H
