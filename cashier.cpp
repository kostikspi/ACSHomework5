//
// Created by Константин Воронин on 15.12.2021.
//

#include <thread>
#include <iostream>
#include "cashier.h"
#include "queue.h"

void cashier::run() {
    sleep(100);
    while (!customer_queue->done()) {
        sleep(100);
        customer *curr_customer = customer_queue->getCustomer();
        cashOut(curr_customer);
    }
}

cashier::cashier(int id, queue *queue) {
    this->id = id;
    this->customer_queue = queue;
}

void cashier::sleep(int millisec) {
    std::this_thread::sleep_for(std::chrono::milliseconds(millisec));
}

void cashier::cashOut(customer *currCustomer) {
    sleep(rand() % 150);
    printf(
            "Cashier %d : Customer %d , your total is %d$\nCustomer %d, thanks for your purchase! Good bye!\n\n",
            id,
            currCustomer->id,
            currCustomer->cart,
            currCustomer->id
    );
}



