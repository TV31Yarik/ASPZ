#include <stdio.h>
#include <omp.h>
#include "module1.h"
#include "module2.h"

int main() {
    #pragma omp parallel sections
    {
        #pragma omp section
        module1_function();

        #pragma omp section
        module2_function();
    }

    return 0;
}