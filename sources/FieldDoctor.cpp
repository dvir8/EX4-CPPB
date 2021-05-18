#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "FieldDoctor.hpp"
using namespace pandemic;
const int MAX_CARDS =48;
const int six = 6;
FieldDoctor::FieldDoctor(Board &board, enum City city){
    CurrentCity = city;
    theBorad = &board;
}
Player& FieldDoctor::treat(enum City a){
    bool connect = false;
    if(CurrentCity == a){
        connect=true;
    }
    for (size_t i = 0; i < six; i++){
        
        if(getMap().at(CurrentCity).t.count(a)!=0 ||connect){
            connect = true;
            break;
        }
    }
    if(!connect){
        throw invalid_argument("you cant treat there");
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
string FieldDoctor::role(){
    return "FieldDoctor";
}