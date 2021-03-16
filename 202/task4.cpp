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
                
                for(size_t r = 0; r<rows; ++r)
                    for(size_t c = 0; c<cols; ++c)
                        data[r][c] = 0;
            }
            catch(...)    {
                std::cerr<<"Error allocating memory for matrix!"<<std::endl;
                exit(1);
            }
        }
        
        void WriteMatrix() const 
        {
            for (size_t i = 0; i<this->rows; ++i) {
                int min=data[i][0];
                for(size_t j = 1; j<this->cols; ++j) 
                    if (data[i][j]<min) min=data[i][j];
                std::cout << min << '\n';
            }
        }
        
        void ReadMatrix() {
            if (data != nullptr) {
                for (size_t i=0; i<rows; ++i) delete[] data[i];
                delete[] data;
                data = nullptr;
            };
            
            if (!(std::cin >> rows) || !(std::cin >> cols)) {};
            
            try
            {
                data = new int * [rows];
                
                for(size_t r = 0; r<rows; ++r)
                    data[r] = new int [cols];
                
                for(size_t r = 0; r<rows; ++r)
                    for(size_t c = 0; c<cols; ++c)
                    if(!(std::cin >> data[r][c])) {}; 
            }
            catch(...)    {
                std::cerr<<"Error allocating memory for matrix!"<<std::endl;
                exit(1);
            }
        }
};

void func4() {
    Matrix Matr(0,0);
    Matr.ReadMatrix();
    Matr.WriteMatrix();
}

/*int main() {
    func4();
}*/
