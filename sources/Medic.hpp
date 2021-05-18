
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;

class Medic: public Player{

    public:
        string role();
        Medic(Board &board, enum City);
        Player& drive (enum City);
        Player& fly_direct(enum City);
        Player& fly_shuttle(enum City);
        Player& fly_charter(enum City);
        Player& treat(enum City);
        

};