#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "OperationsExpert.hpp"

using namespace pandemic;


OperationsExpert::OperationsExpert(Board &board, enum City a){
    CurrentCity=a;
    theBorad = &board;
}
Player& OperationsExpert::build(){
    getMap()[CurrentCity].theBuild=true;
 return *this;
}
string OperationsExpert::role(){
    return "OperationsExpert";
}
