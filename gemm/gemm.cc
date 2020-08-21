#include<cmath>
#include<cstdlib>
#include<cstdint>
#include<iostream>
#include<iomanip>
int main (int argc, char *argv[]) {
    if (argc < 4) {
        std::cout << "Usage : ./gemm I K J (IJ = IK x KJ)" << std::endl;
    }
    uint32_t I = atoi (argv[1]);
    uint32_t K = atoi (argv[2]);
    uint32_t J = atoi (argv[3]);
    
    double *A = (double *) malloc (I * K * sizeof (double));
    double *B = (double *) malloc (K * J * sizeof (double));
    double *C = (double *) malloc (I * J * sizeof (double));
    
    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) {
            for (int k = 0; k < K; k++) {
                  asm ("nop");
                  C[i*J+j] += A[i*K + k] * B[k*J + j];
                  asm ("nop");
            }
        }
    }
 
    if( I*J <= 100 ){
        std::cout << "Result Matrix:" << std::endl;
        for (int i = 0 ; i < I ; i++){
            for (int j = 0 ; j < J ; j++) 
                std::cout << std::setw(8) << C[i*J+j];
            std::cout << std::endl;
        }
    }
    std::cout << "Done.(Only matrixes with its size less than 10*10 will be shown.)" << std::endl;
   
    if (A) {
        free(A);
    }

    if (B) {
        free(B);
    }
  
    if (C) {
        free(C);
    }

    return 0;
}
