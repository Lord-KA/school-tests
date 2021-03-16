#include <iostream>
#include <fstream>
#include <string>

void func8()
{   
    std::ifstream in("input", std::ifstream::binary);
    
    if( !in.is_open() )
    {
        std::cerr << "ERROR: " 
                << "unable to open file input"
                << std::endl;
    } else {
    std::string min="",current="";
    int min_cnt = 0,cnt = 0;
    int val = in.get();
    
    
    while ( !in.eof() ) {
        if (val!='\0') {
            current+=val;
            cnt++;
        } else {
            if (min_cnt==0) {
                min_cnt=cnt;
                min=current;
            } else if (cnt<min_cnt) {
                min_cnt=cnt;
                min=current;
            }
            cnt=0;
            current="";
        }
        
        val = in.get();
    }
    
    in.close();
    
    std::cout << min;
    }
}

/*int main() {
    func8();
}*/
