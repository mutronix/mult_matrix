#include <iostream>
#include <cstdlib> // rand()
#include <ctime> // time()
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

const size_t l = 250;
const size_t m = 120;
const size_t n = 360;

matrix<int> aMatrix(l, m);
matrix<int> bMatrix(m, n);
matrix<int> cMatrix(l, n);

matrix<int>* paMatrix = &aMatrix;
matrix<int>* pbMatrix = &bMatrix;

int matrixFill(matrix<int>* pMatrix){
  srand(time(NULL));
  if(pMatrix == paMatrix){
    int odd_check = 0;
    for(int row = 0; row < aMatrix.size1(); ++row){
      for(int col = 0; col < aMatrix.size2(); ++col){
	odd_check = rand();
	if(odd_check % 2 != 0){
	  aMatrix(row,col) = - (rand() % 21);
	}
	else{
	  aMatrix(row, col) = rand() % 21;
	}
      }
    }
  }
  if(pMatrix == pbMatrix){
    for(int row = 0; row < bMatrix.size1(); row++){
      for(int col = 0; col < bMatrix.size2(); col++){
	bMatrix(row, col) = rand() % 41;
      }
    }
  }
  
  return 0;
}
int matrixMult(){
  for(int row = 0; row < l; row ++){
    for(int col = 0; col < n; col++){
      for (size_t inner = 0; inner < m; inner++){
	cMatrix(row, col) += aMatrix(row, inner) * bMatrix(inner, col);
      }
    }
  }
  
  return 0;
}


int main (int argc, char** argv){

  matrixFill(paMatrix);
  matrixFill(pbMatrix);
  matrixMult(); 

  return 0;
}
