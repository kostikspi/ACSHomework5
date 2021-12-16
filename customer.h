//
// Created by Константин Воронин on 15.12.2021.
//

#ifndef ACSHOMEWORK5_CUSTOMER_H
#define ACSHOMEWORK5_CUSTOMER_H


class customer {
public:

    std::mutex customerMutex;
    customer(int i, int numOfQueue);
    customer() = default;

    int id;
    void run();
    int cart;
    int numberOfQueue;
    static void sleep(int millisec);
    void goShopping();

    void wait();
};

#endif //ACSHOMEWORK5_CUSTOMER_H
