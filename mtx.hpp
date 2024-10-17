#include <cstddef>
#ifndef MTX_HPP
#define MTX_HPP

int ** createMatrix(size_t m, size_t n);
void destroyMatrix(int ** t, size_t m);
void read(int ** t, size_t m, size_t n);
void write(const int * const * t, size_t m, size_t n);

#endif
