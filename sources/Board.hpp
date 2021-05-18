#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <set>
#include "City.hpp"
#include "Color.hpp"
using namespace std;
using namespace pandemic;
namespace pandemic{
enum Color StringToColor(const std::string &color);
enum City StringToEnum(const string &city);
class Board  {
    
    class Node{
        public:
            enum Color colorOfCity;
            enum City CityNow;
            set<City> t;
            string city_s;
            int cube;
            bool theBuild;
            Node() { }
            Node(const std::string &color,const std::string& city, set<City>& d);

    };
    private:
    std::unordered_map<enum City ,Node> theMap2;
    std::unordered_map<enum Color, bool> Cures;    
    public:
    
    Board();
    int& operator[](enum City);    
    friend ostream& operator<<(ostream& os , Board& board);
    bool is_clean();
    void remove_cures();
    void remove_stations();

    friend class Player;

    
    
    


    
};


}


