
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;

class OperationsExpert: public Player{

    public:

        OperationsExpert(Board &board, enum City);
        Player& build();
        string role();

};