#include <iostream>
#include "mtx.hpp"

int main()
{
  size_t M = 0, N = 0;
  std::cin >> M >> N;
  int ** t = createMatrix (M, N);
  read (t, M, N);
  write (t, M, N);
  destroyMatrix (t, M);
}
