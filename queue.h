//
// Created by Константин Воронин on 15.12.2021.
//

#ifndef ACSHOMEWORK5_QUEUE_H
#define ACSHOMEWORK5_QUEUE_H

#include <vector>
#include <condition_variable>
#include "customer.h"

class queue {
    int number_of_customers;
    std::mutex queue_mutex;
    std::condition_variable isReadyForTheNextCustomer;
public:
    std::vector<customer*> customers;
    queue();

    bool isEmpty() const;

    void addCustomer(customer* curr_customer);

    bool done();

    customer *getCustomer();
};


#endif //ACSHOMEWORK5_QUEUE_H
