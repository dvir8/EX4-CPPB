#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Virologist.hpp"
using namespace pandemic;

Virologist::Virologist(Board &board, enum City a){
    CurrentCity = a;
    theBorad = &board;
}
Player& Virologist::treat(enum City a){
    
    if(CurrentCity!=a){
        if(!(Cards.at(size_t(a)))){
        throw invalid_argument("you are not in this city");
    }
    }
    if(getMap()[a].cube == 0){
        throw invalid_argument("there are no cubes in this city");
    }
    if(getCures()[getMap()[a].colorOfCity]){
        getMap()[a].cube=0;
    }
    else{
        getMap()[a].cube--;
    }
        
    
    return *this;
}
string Virologist::role(){
    return "Virologist";
}