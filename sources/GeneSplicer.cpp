#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "GeneSplicer.hpp"
#include <array>
using namespace pandemic;
const int MAX_CARDS =48;
const int five = 5;
const int four = 4;


GeneSplicer ::GeneSplicer(Board &board, enum City a){
    CurrentCity = a;
    theBorad = &board;
}
Player& GeneSplicer::discover_cure(enum Color a){
    int count = 0;
    if(!getMap()[CurrentCity].theBuild){
        throw invalid_argument("no research facility");
    }
    if(getCures()[a]){
        return *this;
    }   
    array <size_t , five> x = {MAX_CARDS};
    x.fill(MAX_CARDS);
    size_t temp = 0;
    for (size_t i = 0; i < MAX_CARDS; i++)
    {
        if(Cards.at(i)){
            count++;
            Cards.at(i)=false;
            
            if(count==five){
            break;
            }  
            x.at(temp)=i;
            temp++;
        }
    }
    // cout << count <<endl;
    if(count!=five){
        for (size_t i = 0; i < five; i++)
        {
            if(x.at(i)!=-1){
                Cards.at(x.at(i)) = true;
            }
            
        }
        
        throw invalid_argument("not enough chards");
    }
    getCures()[a]=true;
    return *this;
}
string GeneSplicer::role(){
    return "GeneSplicer";
}