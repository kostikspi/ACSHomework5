//
// Created by Константин Воронин on 15.12.2021.
//

#include <thread>
#include <iostream>
#include "customer.h"


customer::customer(int id, int numOfQueue) {
    this->id = id;
    this->cart = (rand() % 150);
    this->numberOfQueue = numOfQueue;
    customerMutex.lock();
}


void customer::goShopping(){
    int time = 200 + (rand() % 2000);
    sleep(time);
}

void customer::run() {
    goShopping();
    customerMutex.unlock();
}

void customer::wait() {
    customerMutex.lock();
}

void customer::sleep(int millisec) {
    std::this_thread::sleep_for(std::chrono::milliseconds(millisec));
}
