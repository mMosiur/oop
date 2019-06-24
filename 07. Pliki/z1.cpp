//zadanie 1
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ostream>

using namespace std;

int main(int argc, char *argv[]) {

    string line;
    int number=atoi(argv[2]), i=3;
    int current=0;

    ifstream input;
    input.open(argv[1]);
    if(!input.is_open()) return 1;

    while(!input.eof()){
        getline(input, line);
        if(current==number){
            cout<<line<<endl;
            if(i==argc)
                break;
            number=atoi(argv[i++]);
        }
        current++;
    }
    input.close();


    return 0;
}
