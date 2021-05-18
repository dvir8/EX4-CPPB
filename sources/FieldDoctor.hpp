
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;

class FieldDoctor: public Player{

    public:
        Player& treat(enum City a);
        string role();
        FieldDoctor(Board &board, enum City city);
        

};