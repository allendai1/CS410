
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
    string saying;
    int card_length;
    int card_width;
    vector<string> list_of_sayings;
    creature(string name,string saying,  int card_length, int card_width, vector<string> sayings)
    {
        this->name = name;
        this->saying = saying;
        this->card_length = card_length;
        this->card_width = card_width;
        this->list_of_sayings = sayings;
    }

    string randomSaying(){
        // srand(37);
        int randomIndex = rand() % list_of_sayings.size();
        return list_of_sayings[randomIndex];

    }

};
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
        creature c = creature(creature_name,saying, dimensions[0], dimensions[1], sayings);
        
        creatures.push_back(c);
        

    }
    for(creature x  : creatures){
        cout<< x.randomSaying()+"\n";
    }


    
    
}