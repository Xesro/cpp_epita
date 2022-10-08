#include <regex>
#include <fstream>
#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{
    ifstream file (argv[1]);
    string pattern = ".*" + string (argv[2]) + ".*";
    regex reg (pattern);
    long count = 0;

    if (file.is_open()) {
        string word;
        while(file >> word) {
            if(regex_match(word, reg))
                count++;
        }
        cout << "The file " + string(argv[1]) + " contains " + to_string(count) +  " words containing the motive " + string(argv[2]);
        file.close();
    } else {
        cout << "The file " + string(argv[1]) + " could not be opened.";
        return 1;
    }

    return 0;
}