
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;

class Researcher: public Player{
     
    public:

        Researcher(Board &board, enum City a);
        Player& discover_cure(enum Color a);
        string role();

};