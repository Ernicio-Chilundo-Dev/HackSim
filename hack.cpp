#include <iostream>
#include <vector>
#include <string>
#include <ncurses.h>
#include <fstream>
#include  <cstdlib>
#include <unistd.h>
#include <ctime>

using namespace std;

vector<string> loadFakeCode (const string& filename){
    ifstream file(filename);
    vector<string>lines;
    string line;

    while(getline(file, line)){
        lines.push_back(line);
    }

    return line;
}

int main(){

    return 0;
}