#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Scientist.hpp"
#include <array>
using namespace pandemic;
const int MAX_CARDS =48;
const int five = 5;
const int four = 4;
Scientist::Scientist(Board &board, enum City a, int toThrow1){
    CurrentCity = a;
    theBorad = &board;
    toThrow = toThrow1;
}
Player& Scientist::discover_cure(enum Color a){
    int count = 0;
    if(getCures()[a]){
        return *this;
    }  
    if(!getMap()[CurrentCity].theBuild){
        throw invalid_argument("no research facility");
    }
    array <size_t , five> x = {MAX_CARDS};
    x.fill(MAX_CARDS);
    size_t temp = 0;
    for (size_t i = 0; i < MAX_CARDS; i++)
    {
        if(Cards.at(i) && getMap()[(enum City)i].colorOfCity==a){
            
            
            
            count++;
            Cards.at(i)=false;
            x.at(temp)=i;
            temp++;
        }
        if(count==toThrow){
            
            getCures()[a]=true;
            break;
        }  
    }
    if(count!=toThrow){
        
        for (size_t i = 0; i < four; i++)
        {   
            if(!(x.at(i) == -1)){
                Cards.at(x.at(i))=true;
            }
            
        }
        
        throw invalid_argument("not enough chards");
    }
    
    return *this;
}
string Scientist::role(){
    return "Scientist";
}