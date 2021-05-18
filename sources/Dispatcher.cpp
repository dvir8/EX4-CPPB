#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Dispatcher.hpp"
using namespace pandemic;


Dispatcher::Dispatcher(Board &board, enum City city){
    CurrentCity = city;
    theBorad = &board;
    
}
Player& Dispatcher::fly_direct(enum City city){
    if(city==CurrentCity){
        throw invalid_argument("Cant do that");
    }
    if(!getMap()[CurrentCity].theBuild){
        Player::fly_direct(city);
    }
    else{
    CurrentCity = city;
    }
    
    return *this;
}
string Dispatcher::role(){
    return "Dispatcher";
}