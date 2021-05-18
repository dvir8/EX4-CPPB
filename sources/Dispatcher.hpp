
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;

class Dispatcher: public Player{

    public:
        Player& fly_direct(enum City city);
        string role(); 
        Dispatcher(Board &board, enum City city);
         


};