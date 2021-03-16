#include <iostream>
#include<fstream>
void func2() {
    std::ifstream in("input");
;    if( !in.is_open() )
    {
        std::cerr << "ERROR: " 
                << "unable to open file input"
                << std::endl;
    } else {
        double val, min_val;
        in >> val;
        min_val = val;
        //in.get();
        while ( !in.eof() ) {
            in >> val;
            //in.get();
            if (val<min_val) min_val=val;
        }
        std::cout << min_val;
    }
}

/*int main() {
    func2();
}*/
