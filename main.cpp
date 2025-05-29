
#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    cout << "CPU count: " << omp_get_num_procs() << endl;
    cout << "Sequential code" << endl;

#pragma omp parallel
    {
/*
        cout << omp_get_thread_num() << endl;
    }
    cout << "Sequential code " << endl;
*/
/*
#pragma omp parallel
    {
        printf("Parallel code on CPU id: %d\n", omp_get_thread_num());
    }
    cout << "Sequential code" << endl;
*/
#pragma omp for
    for(int i = 1; i<= 36; i++) {
        printf("Iteration %d on CPU id: %d\n", i, omp_get_thread_num());
    }
    //cout << "Sequential code" << endl;
#pragma omp barrier
#pragma omp for schedule(static, 2)
    for(int i = 1; i<= 36; i++) {
        printf("Iteration %d on CPU id: %d\n", i, omp_get_thread_num());
    }
    }
    return 0;
}
