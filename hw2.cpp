
#include <iostream>
#include <fstream>
#include <string>
#include "h2_functions.h"
#include <vector>

using namespace std;

struct creature{
    string name;
    string saying;
    int card_length;
    int card_width;

    creature(string name, string saying, int card_length, int card_width){
        this->name = name;
        this->saying = saying;
        this->card_length = card_length;
        this->card_width = card_width;
    }
};
int main(){
    
    ifstream creatures_file ("creatures.txt", ifstream::in);
    ifstream sayings_file ("sayings.txt", ifstream::in);
    string saying;
    string creature_line;
    string card_dimension;
    string creature_name;
    vector<creature> creatures;
    string doublespace = "\t";
    while (getline(sayings_file, saying) && getline(creatures_file,creature_line)){
        string name = creature_line.substr(0, creature_line.find(doublespace));
        string dimensions = creature_line.substr(0, creature_line.find(doublespace));
        creature_name = name;
        // cout << token;
        
        creature c = creature(creature_name, saying, 5, 5);
        creatures.push_back(c);
        
    }
    for(creature c : creatures){
        cout << c.name << "\n";
    }
    
    
}