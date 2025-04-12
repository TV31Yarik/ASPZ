#include <iostream>
#include <thread>
#include "module1.h"
#include "module2.h"

int main() {
    std::thread t1(module1_function);
    std::thread t2(module2_function);

    t1.join();
    t2.join();

    return 0;
}