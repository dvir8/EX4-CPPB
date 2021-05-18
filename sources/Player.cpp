#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include <unordered_map>

using namespace pandemic;
const int MAX_CARDS =48;
const int five = 5;
const int four = 4;



Player& Player::fly_direct(enum City a){
    if(Cards.at((size_t)a)){
        CurrentCity = a;
        Cards.at((size_t)a) = false;
    }
    else{
        throw invalid_argument("you dont own the card");
    }
    return *this;
}
Player& Player::fly_shuttle(enum City a){
    if(!(theBorad->theMap2[CurrentCity].theBuild && theBorad->theMap2[a].theBuild)){
        throw invalid_argument("Can't do that, no research facility");
    }
    if(CurrentCity == a){
        throw invalid_argument("Can't do that fly to your place");
    }
    CurrentCity=a;
    return *this;
}
Player& Player::fly_charter(enum City a){
    if(!(Cards.at((size_t)CurrentCity))){
        throw invalid_argument("you dont own that card");
    }
    Cards.at((size_t)CurrentCity)=false;
    CurrentCity = a;
    return *this;
}
Player& Player::build(){
    if(!(Cards.at((size_t)CurrentCity))){
        throw invalid_argument("you dont own that card");
    }
    
    if(theBorad->theMap2[CurrentCity].theBuild){
            
        theBorad->theMap2[CurrentCity].theBuild=true;
    }
    else{
        theBorad->theMap2[CurrentCity].theBuild=true;
            
        Cards.at((size_t)CurrentCity)=false;
    }
    
    
    return *this;
}

Player& Player::take_card(enum City a){
    Cards.at(size_t(a))=true;
    return *this;
}
Player& Player::treat(enum City a){
    if(CurrentCity!=a){
        throw invalid_argument("you are not in this city");
    }
    if(theBorad->theMap2[CurrentCity].cube == 0){
        throw invalid_argument("there are no cubes in this city");
    }

    if(getCures()[getMap()[a].colorOfCity]){
        theBorad->theMap2[a].cube=0;
    }
    else{
        theBorad->theMap2[a].cube--;
    }

    return *this;
}
Player& Player::discover_cure(enum Color a){
    int count = 0;
    if(!theBorad->theMap2[CurrentCity].theBuild){
        throw invalid_argument("no research facility");
    }
    if(theBorad->Cures[a]){
        return *this;
    }   
    array <size_t , five> x = {0};
    size_t temp = 0;
    for (size_t i = 0; i < MAX_CARDS; i++)
    {
        if(Cards.at(i) && theBorad->theMap2[(enum City)i].colorOfCity==a){
            count++;
            Cards.at(i)=false;
            
            if(count==five){
            theBorad->Cures[a]=true;
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
Player& Player::drive (enum City a){
    if(CurrentCity == a){
        throw invalid_argument("City is not connected");
    }
    if (theBorad->theMap2.at(CurrentCity).t.count(a)!=0) {
        CurrentCity = a;
        return *this;
    }
    
    throw invalid_argument("City "+theBorad->theMap2.at(CurrentCity).city_s+" is not connected to "+theBorad->theMap2.at(a).city_s);
    return *this;
}
void Player::remove_cards(){
    Cards.fill(false);

}

