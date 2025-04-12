#include <iostream>
#include <thread>
#include <chrono>
#include "module2.h"

void module2_function() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Module 2 - Step " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
