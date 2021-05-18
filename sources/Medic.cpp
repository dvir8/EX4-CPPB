#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Medic.hpp"
using namespace pandemic;


Medic ::Medic(Board &board, enum City a){
    CurrentCity = a;
    theBorad = &board;
}
Player& Medic::treat(enum City a){
    if(CurrentCity!=a){
        throw invalid_argument("you are not in this city");
    }
    if(getMap()[CurrentCity].cube == 0){
        throw invalid_argument("there are no cubes in this city");
    }
    getMap()[a].cube=0;
    return *this;
}
Player& Medic::drive (enum City a){ // לבדוק 
    if(getCures()[getMap()[a].colorOfCity]){
        getMap()[a].cube = 0;
    }
    
        Player ::drive(a);
        return *this;
}
        Player& Medic::fly_direct(enum City a){
            if(getCures()[getMap()[a].colorOfCity]){
            getMap()[a].cube = 0;
        }
            
            Player ::fly_direct(a);
            return *this;
        }
        Player& Medic::fly_shuttle(enum City a){
            if(getCures()[getMap()[a].colorOfCity]){
            getMap()[a].cube = 0;
        }
            
            Player ::fly_shuttle(a);
            return *this;
        }
        Player& Medic::fly_charter(enum City a){
            if(getCures()[getMap()[a].colorOfCity]){
            getMap()[a].cube = 0;
        }
            
            Player ::fly_charter(a);
            return *this;
        }
string Medic::role(){
    return "Medic";
}