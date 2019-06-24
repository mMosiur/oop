//zadanie 4
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ostream>

using namespace std;

static ofstream logfile;

void log(const char *text) {
    logfile << time(nullptr) << " " << text << endl;
}

/*[[ noreturn ]] */void handleTerm() {
    const exception_ptr &p = std::current_exception();
    try { std::rethrow_exception(p); }
    catch(exception &e) {
        log(e.what());
    }
    logfile.close();
    std::abort();
}

int main(int argc, char *argv[]) {
    logfile.open("log.txt", std::fstream::app);
    if(!logfile.is_open()) return 1;
    set_terminate(handleTerm);

    fstream input, output;
    bool append = (string(argv[1])==string(argv[2]));

    if(!append) {
        input.open(argv[1], std::fstream::in);
        if(!input.is_open()) return 1;
        output.open(argv[2], std::fstream::out);
        if(!output.is_open()) return 2;
    }
    else {
        input.open(argv[1],std::fstream::in | std::fstream::out);
        if(!input.is_open()) return 1;
    }

    string line;
    int number=atoi(argv[3]), i=3;
    int current=0;
    long pos;

    int lines = 0;
    while((!input.eof())){
        getline(input, line);
        lines++;
    }

    input.clear();
    input.seekg(0,ios_base::beg);


    if(number>lines) throw std::runtime_error(string(string("wrong line: ")+to_string(number)));

    if(!append) {
        while((!input.eof())){
            getline(input, line);
            if(current==number){
                output<<line<<endl;
                i++;
                if(i<argc) {
                    number=atoi(argv[i]);
                    if(number>lines) throw std::runtime_error(string(string("wrong line:")+to_string(number)));
                }
                else break;
            }
            current++;
        }
        output.close();
    }
    else {
        while((!input.eof())){
            getline(input, line);
            if(current==number){
                pos=input.tellg();
                input.seekg(0,ios_base::end);
                input<<'\n'<<line;
                i++;
                if(i<argc) {
                    number=atoi(argv[i]);
                    if(number>lines) throw std::runtime_error(string(string("wrong line:")+to_string(number)));
                }
                else break;
                input.seekg(pos, ios_base::beg);
            }
            current++;
        }

    }
    input.close();

    log((string(argv[1])+" "+string(argv[2])+" "+to_string(argc-3)).c_str());
    logfile.close();
    return 0;
}
