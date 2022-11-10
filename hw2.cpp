
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

bool stackable(int x1, int y1,int x2,int y2){
    if (x2 <= x1 || y2 <= y1){
        return true;
    }
    return false;
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
    int stackSize;
    int lastCard[2] = {0,0};
    
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

    // visit a random creature
    for(int i=14; i>0; i--){
        int index = randomIndex(0, i);
        string say = sayings[index];
        string name = creatures[index].name;
        cout << name <<" "<< say << "\n";
        if(stackable())
        // pop from the vector
        // creatures.erase(creatures.begin() + index);
    }
    
    // cout << "wtf";
    // srand((unsigned) (int) 37);
    // cout << randomIndex(0, 14);


    
    
}