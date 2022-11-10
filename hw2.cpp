
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "hw2_functions.h"
#include "hw2_functions.cpp"
#include <vector>
using namespace std;

vector<int> extractIntegerWords(string str)
{
    stringstream ss;
    ss << str;
    string temp;
    int found;
    int x= 0;
    vector<int> dimensions;
    while (!ss.eof())
    {
        ss >> temp;

        if (stringstream(temp) >> found){
            dimensions.push_back(found);
        }
        temp = "";
    }
    return dimensions;
}


struct creature
{
    string name;
    vector<int> dimensions;
    creature(string name,vector<int> dimensions)
    {
        this->name = name;
        this->dimensions = dimensions;
        // this->saying = saying;
    }

    

};
int randomIndex(int i, int j){
    int random = i + (rand() % j);
    return random;
}
int main()
{
    ifstream creatures_file("creatures.txt", ifstream::in);
    ifstream sayings_file("sayings.txt", ifstream::in);
    string saying;
    string creature_line;
    string card_dimension;
    string creature_name;
    vector<creature> creatures;
    string doublespace = "\t";
    vector<string> sayings;

    // create list of sayings
    while(getline(sayings_file, saying)){
        sayings.push_back(saying);
    }

    // parse each line for name and dimensions
    while (getline(creatures_file, creature_line))
    {
        string name = creature_line.substr(0, creature_line.find(doublespace));
        creature_name = name;
        vector<int> dimensions = extractIntegerWords(creature_line);
        saying = rand() % sayings.size();
        // creature c = creature(creature_name,saying, dimensions[0], dimensions[1], sayings);
        creature c = creature(creature_name, dimensions);
        creatures.push_back(c);
    }
    // for(creature c : creatures){
    //     cout << c.name << " " << c.dimensions[0] << " " <<c.dimensions[1] << "\n";
    // }
    srand((unsigned) (int) 37);
    cout << randomIndex(0, 14);


    
    
}