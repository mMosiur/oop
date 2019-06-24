//zadanie 3
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ostream>

using namespace std;

int main(int argc, char *argv[]) {

    string line;
    int number=atoi(argv[3]), i=4;
    int current=0;

    if(string(argv[1])!=string(argv[2])){
        ifstream input;
        input.open(argv[1]);
        if(!input.is_open()) return 1;
        ofstream output;
        output.open(argv[2]);


        while(!input.eof()){
            getline(input, line);
            if(current==number){
                output<<line<<endl;
                if(i==argc)
                    break;
                number=atoi(argv[i++]);
            }
            current++;
        }
        input.close();
        output.close();
    }else {
        fstream input;
        input.open(argv[1],std::fstream::in | std::fstream::out);
        if(!input.is_open()) return 1;


        long pos;

        while(!input.eof()){
            getline(input, line);
            if(current==number){
                pos=input.tellg();
                input.seekg(0,ios_base::end);
                input<<line<<endl;
                if(i==argc)
                    break;
                number=atoi(argv[i++]);
                input.seekg(pos, ios_base::beg);
            }
            current++;
        }

        input.close();
    }
    return 0;
}
