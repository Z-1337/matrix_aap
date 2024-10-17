#include "mtx.hpp"
#include <cstddef>
#include <iostream>



int ** createMatrix(size_t m, size_t n)
{
  int ** t = new int * [m];
  size_t created = 0;
  try {
    for(;created<m; ++created){
      t[created]=new int[n];
    }
  } catch (const std::bad_alloc &e) {
    destroyMatrix(t, created);
      throw;
  }
  return t;
}

void destoyMatrix(int ** t, size_t m)
  {
  for (size_t i = 0; i < m; i++)
  {
    delete[]t[i];
  }
delete[]t;
}
