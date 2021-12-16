//
// Created by Константин Воронин on 15.12.2021.
//

#include <mutex>
#include <vector>
#include "queue.h"
#include "customer.h"

queue::queue(){
    customers = std::vector<customer*>();
}

bool queue::done() {
    std::lock_guard<std::mutex> lock(queue_mutex);
    return customers.empty();
}

void queue::addCustomer(customer *curr_customer) {
    std::lock_guard<std::mutex> lock(queue_mutex);
    customers.push_back(curr_customer);
}

customer* queue::getCustomer() {
    std::unique_lock<std::mutex> lock(queue_mutex);
    customer* curr_customer = customers.back();

    lock.unlock();
    curr_customer->wait();

    lock.lock();
    customers.pop_back();
    return curr_customer;
}



