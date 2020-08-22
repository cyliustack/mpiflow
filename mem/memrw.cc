#include<iostream>
#include<cstdio>
#include<chrono>
#include<cstring>

int main(int argc, char* argv[]) {
    uint64_t size = 0;
    std::chrono::high_resolution_clock::time_point t1, t2;
    double dt = 0;
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " size_in_bytes  " << std::endl; 
        return -1;
    }
    else {
        size = atoll(argv[1]);
        std::cout << "# of elements = " << size << std::endl; 
    }
    
    t1 = std::chrono::high_resolution_clock::now();
    uint8_t *a = new uint8_t[size];
    t2 = std::chrono::high_resolution_clock::now();
    dt = (std::chrono::duration_cast<std::chrono::duration<double>> (t2-t1)).count();
    std::cout << "memory allocation time (s) : "<< dt << std::endl; 

    t1 = std::chrono::high_resolution_clock::now();
    int n = memcmp(a, a+1, size-1);
    t2 = std::chrono::high_resolution_clock::now();
    dt = (std::chrono::duration_cast<std::chrono::duration<double>> (t2-t1)).count();
    std::cout << "memory read time (s) : "<< dt << " ; memcmp = " << std::to_string(n) << std::endl; 

    t1 = std::chrono::high_resolution_clock::now();
    memset(a, 0, size);
    t2 = std::chrono::high_resolution_clock::now();
    dt = (std::chrono::duration_cast<std::chrono::duration<double>> (t2-t1)).count();
    std::cout << "memory write time (s) : "<< dt << std::endl; 
    
    t1 = std::chrono::high_resolution_clock::now();
    memmove(a,a+1,size-1);
    t2 = std::chrono::high_resolution_clock::now();
    dt = (std::chrono::duration_cast<std::chrono::duration<double>> (t2-t1)).count();
    std::cout << "memory read/write time (s) : "<< dt << std::endl; 

    free(a); 
    return 0;
}
