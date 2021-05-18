
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;

class GeneSplicer: public Player{

    public:
        Player& discover_cure(enum Color a);
        GeneSplicer(Board &board, enum City);
        string role();

};