#include <iostream>
#include <functional>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

void capitalizeToStream(ostream &os, const string &word) {
    os << static_cast<char>(toupper(word[0]));
    for(size_t i = 1; i < word.size(); i++) {
        os << (char) tolower(word[i]);
    }
    os << endl;
}

void showWordsWithLetter(const string &text, const char letter, function<void(const string &)> &display) {
    stringstream ss(text);

    while(!ss.eof()) {
        string word;
        ss >> word;
        if(word.find(letter) != string::npos) {
            display(word);
        }
    }
}

int main() {
    function<void(const string &)> f = bind(capitalizeToStream, ref(cout), placeholders::_1);
    showWordsWithLetter("Ala ma kota, a Tola ma kotleta", 'l', f);
    return 0;
}
