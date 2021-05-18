#pragma once
#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"
#include <array>
namespace pandemic{
class Player {
   
    protected:
    Board * theBorad;
    enum City CurrentCity;
    array <bool , 48> Cards = {false};
    
    std::unordered_map<enum City ,Board::Node>& getMap(){
        return theBorad->theMap2;
    }
    std::unordered_map<enum Color, bool>& getCures(){
        return theBorad->Cures;
    }

    public:
    Player(Board &bo,enum City ci):theBorad(&bo),CurrentCity(ci){
        Cards.fill(false);
    };
    Player(){};
    virtual Player& drive (enum City);
    virtual Player& fly_direct(enum City);
    virtual Player& fly_shuttle(enum City);
    virtual Player& fly_charter(enum City);
    virtual Player& build();
    virtual Player& discover_cure(enum Color);
    virtual Player& treat(enum City);
    virtual string role() =0;
    Player& take_card(enum City);
    void remove_cards();
};
}
