#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include <array>
using namespace pandemic;
const int MAX_CARDS =48;
const int five = 5;
const int four = 4;

Researcher::Researcher(Board &board, enum City a){
    CurrentCity = a;
    theBorad = &board;
}
Player& Researcher::discover_cure(enum Color a){
    int count = 0;
    if(getCures()[a]){
        return *this;
    }  
    array <size_t , five> x = {0};
    size_t temp = 0;
    for (size_t i = 0; i < MAX_CARDS; i++)
    {
        if(Cards.at(i) && getMap()[(enum City)i].colorOfCity==a){
            count++;
            Cards.at(i)=false;
            
            if(count==five){
            getCures()[a]=true;
            break;
            }  
            x.at(temp)=i;
            temp++;
        }
    }
    if(count!=five){
        for (size_t i = 0; i < four; i++)
        {   
            Cards.at(x.at(i))=true;
        }
        
        throw invalid_argument("not enough chards");
    }
    return *this;
}
string Researcher::role(){
    return "Researcher";
}