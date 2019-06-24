#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

class MathFile {
    string path;
    fstream file;
    string getLine(unsigned int index);
    bool verify(string line); // wydzielone do zadania 3

    string incompleteLine;  // do zadania 4
    bool equals;

public:
    MathFile(string path);
    bool open();
    void close();
    int sum(unsigned int index);
    bool verify(unsigned int index);

    friend ostream &operator <<(ostream &os, MathFile &mf);
    friend istream &operator >>(istream &is, MathFile &mf);
};

string MathFile::getLine(unsigned int index) {
    string line;
    for(unsigned int i=0; i<=index; i++)
        getline(file,line);

    return line;
}

int MathFile::sum(unsigned int index) {
    string line = getLine(index);
    stringstream ss;
    ss.str(line);
    int sum=0;
    int val;
    while(ss>>val)
        sum += val;
    return sum;
}

bool MathFile::verify(unsigned int index) {
    return verify(getLine(index));
}

bool MathFile::verify(string line) {
    stringstream ss;
    ss.str(line);
    string val;

    regex signRegex("-|\\+|=");
    regex numberRegex("(\\+|-)?[[:digit:]]+");

    bool expectNumber = true;
    int num, sum = 0;
    char lastSign = '+';

    while(ss>>val) {
        if(expectNumber && regex_match(val, numberRegex)) {
            num = atoi(val.c_str());
            switch(lastSign) {
            case '+':
                sum += num;
                break;
            case '-':
                sum -= num;
                break;
            case '=':
                return num == sum;
            }
        }
        else if(!expectNumber && regex_match(val, signRegex)) {
            lastSign = val[0];
        }
        else return false;
        expectNumber = !expectNumber;
    }
    return false;
}

MathFile::MathFile(string path) : path(path) {
    equals = false; // do 4
}

bool MathFile::open() {
    file.open(path,ios::in | ios::out);
    return file.is_open();
}

void MathFile::close() {
    file.close();
}

ostream &operator <<(ostream &os, MathFile &mf) {
    string line;
    while(getline(mf.file,line))
        os << mf.verify(line) << ' ';
    return os;
}

istream &operator >>(istream &is, MathFile &mf) {
    string val;
    is >> val;
    mf.incompleteLine += val + " ";
    if(mf.equals) {
        mf.file.seekg(0,ios::end);
        mf.file << mf.incompleteLine << endl;
        mf.equals = false;
        mf.incompleteLine.clear();
    }
    if(val == "=") {
        mf.equals = true;
    }
    return is;
}


int main()
{
    MathFile mf("/tmp/file.txt");
    mf.open();

    stringstream ss;
    ss.str("1 + 2 = 3 1 + 1 = 2");
    while(ss>>mf);
    mf.close();
    return 0;
}

