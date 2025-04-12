#include <iostream>
#include <thread>
#include <chrono>
#include "module1.h"

void module1_function() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Module 1 - Step " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
