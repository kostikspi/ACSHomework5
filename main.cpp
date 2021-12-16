#include <iostream>
#include <thread>
#include "queue.h"
#include "customer.h"
#include "cashier.h"


int main() {

    int n;
    std::cout << "Введите число покупателей: ";
    std::cin >> n;
    queue* firstQueue = new queue();
    queue* secondQueue = new queue();

    cashier* firstCashier = new cashier(1, firstQueue);
    cashier* secondCashier = new cashier(2, secondQueue);


    for (int i = n; i >= 0; i--) {
        customer *current_customer;

        int q = rand() % 2;
        if (q) {
            current_customer = new customer(i, 1);
            secondQueue->addCustomer(current_customer);
        } else {
            current_customer = new customer(i, 0);
            firstQueue->addCustomer(current_customer);
        }

        std::thread activeCustomer([current_customer](){
            current_customer->run();
        });

        activeCustomer.detach();
    }

    std::thread workingCashierOne([firstCashier](){
        firstCashier->run();
    });

    std::thread workingCashierTwo([secondCashier](){
        secondCashier->run();
    });

    workingCashierOne.join();
    workingCashierTwo.join();

    printf("Shop is closing... Bye!");
    return 0;
}
