
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;

class Virologist: public Player{

    public:
        Player& treat(enum City a);
        Virologist(Board &board, enum City a);
        string role();
        

};