#include<iostream>
#include<armadillo>
#include<omp.h>

using namespace arma;
using std::cout;
using std::endl;

int main (){

  int  N_ROWS = 15;
  mat adapa(N_ROWS,N_ROWS,fill::eye), lanja(N_ROWS,N_ROWS,fill::eye) , result(N_ROWS,N_ROWS,fill::zeros);
  #pragma omp parallel for
  for (int i = 0; i < N_ROWS; ++i) {
    result.row(i) = lanja.row(i) + adapa.row(i);
    std::cout << "Processing" << i  << "  Thread NO:-" << omp_get_thread_num() << endl;
  }
  std::cout << result << "\n";
  return 0;
}
