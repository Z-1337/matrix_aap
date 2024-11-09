#include <iostream>

class matrix
{
  private:
    size_t rows;
    size_t cols;
    int** data;

    int ** creatematrix(size_t rows, size_t cols)
    {
      int ** t = new int * [rows];
      size_t created = 0;
      try
      {
        for(; created < rows; ++created)
        {
          t[created] = new int[cols];
        }
      }
      catch (const std::bad_alloc &e)
      {
        destroymatrix(t, created);
        throw;
      }
      return t;
    }

    void destroymatrix(int ** t, size_t rows)
    {
      for (size_t i = 0; i < rows; i++)
      {
        delete[]t[i];
      }
      delete[]t;
    }

    public:
      matrix(size_t r, size_t c) : rows(r), cols(c)
      {
        data = creatematrix(rows, cols);
      }

      ~matrix()
      {
        destroymatrix(data, rows);
      }

      void printmatrix() const
      {
        for (size_t i = 0; i < rows; ++i)
        {
          for (size_t j = 0; j < cols; ++j)
          {
            std::cout << data[i][j] << " ";
          }
          std::cout << "\n";
        }
      }

      size_t getrows() const
      {
        return rows;
      }

      size_t getcols() const
      {
        return cols;
      }

      void fillmatrix()
      {
        size_t custom_rows, custom_cols;
        std::cin >> custom_rows >> custom_cols;

        if (custom_rows != rows or custom_cols != cols)
        {
            destroymatrix(data, rows);
            rows = custom_rows;
            cols = custom_cols;
            data = creatematrix(rows, cols);
        }
        for (size_t i = 0; i < rows; ++i)
        {
          for (size_t j = 0; j < cols; ++j)
          {
            std::cin >> data[i][j];
          }
        }
      }
};

int main() {
  matrix mtx(3,3);
  mtx.fillmatrix();
  mtx.printmatrix();
  mtx.getrows();
  mtx.getcols();
  return 0;
}
