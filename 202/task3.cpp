#include <iostream>
class Matrix {
    private:
        size_t rows;
        size_t cols;
        
        int **data;
    public:
        Matrix(const size_t rows, const size_t cols) {
            this->rows=rows;
            this->cols=cols;
            
            try
            {
                data = new int * [rows];
                
                for(size_t r = 0; r<rows; ++r)
                    data[r] = new int [cols];
                
                for (size_t i =0; i<rows; ++i)
                    for(size_t r = 0; r<rows; ++r)
                        for(size_t c = 0; c<cols; ++c)
                        {
                            if (r+i==c) 
                                data[r][c]=-i+1;
                            if (r-i==c) 
                                data[r][c]=-i+1;
                            
                            if (r==c) 
                                data[r][c]=1;
                        }
            }
            catch(...)    {
                std::cerr<<"Error allocating memory for matrix!"<<std::endl;
                exit(1);
            }
        }
        
        void WriteMatrix() const 
        {
            for (size_t i = 0; i<this->rows; ++i) {
                for(size_t j = 0; j<this->cols; ++j) std::cout << this->data[i][j] << ' ';
                std::cout << '\n';
            }
        }
};

void func3() {
    unsigned int M,N;
    std::cin >> M;
    std::cin >> N;
    Matrix Matr(M,N);
    Matr.WriteMatrix();
}

/*int main() {
    func3();
}*/
