#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;

#include <iostream>
#include <stdexcept>
using namespace std;

TEST_CASE("GOOD TRAVEL"){
    
    Board board;  // Initialize an empty board (with 0 disease cubes in any city).
    board[City::Kinshasa] = 3;      // put 3 yellow disease cubes in Kinshasa.
	board[City::Kinshasa] = 2;      // change number of disease cubes in Kinshasa to 2.
	board[City::MexicoCity] = 3;    // put 3 yellow disease cubes in MexicoCity
	board[City::HoChiMinhCity] = 1; // put 1 red disease cube in HoChiMinhCity
	board[City::Chicago] = 1;       // put 1 blue disease cube in Chicago
    board[City::Algiers] = 4;      
	board[City::Atlanta] = 1;      
	board[City::Baghdad] = 3;    
	board[City::Bangkok] = 1; 
	board[City::Bogota] = 1;       
    OperationsExpert player {board, City::Atlanta};
    CHECK_EQ(board[City::Kinshasa] , 2);
    CHECK_EQ(board[City::MexicoCity] , 3);
    CHECK_EQ(board[City::HoChiMinhCity] , 1);
    CHECK_EQ(board[City::Chicago] , 1);
    CHECK_EQ(board[City::Algiers] , 4);
    CHECK_EQ(board[City::Atlanta] , 1);
    CHECK_EQ(board[City::Baghdad] , 3);
    CHECK_EQ(board[City::Bangkok] , 1);
    CHECK_EQ(board[City::Bogota] , 1);
    CHECK_THROWS(player.take_card(City::Miami)
	 .take_card(City::LosAngeles)
	 .take_card(City::SaoPaulo)
	 .take_card(City::Bogota)
	 .take_card(City::Lima));

    board[City::Miami] = 4;      
	board[City::Lagos] = 1;      
	board[City::SaoPaulo] = 3;    
	board[City::Bogota] = 1; 
	board[City::Johannesburg] = 1;
    
    CHECK_NOTHROW(player.drive(City::Miami));
    CHECK_NOTHROW(player.treat(City::Miami));
    CHECK_EQ(board[City::Miami] , 3);    

    CHECK_THROWS(player.drive(City::Bogota));
    CHECK_THROWS(player.treat(City::Bogota));
    CHECK_EQ(board[City::Bogota] , 0);
    

    CHECK_THROWS(player.drive(City::SaoPaulo));
    CHECK_THROWS(player.treat(City::SaoPaulo));
    CHECK_EQ(board[City::SaoPaulo] , 2);
    

    CHECK_THROWS(player.drive(City::Lagos));
    CHECK_THROWS(player.treat(City::Lagos));
    CHECK_EQ(board[City::Lagos] , 0);
    

     CHECK_THROWS(player.drive(City::Johannesburg));
     CHECK_THROWS(player.treat(City::Johannesburg));
    CHECK_EQ(board[City::Johannesburg] , 0);
    

    board[City::Khartoum] = 4;      
	board[City::Cairo] = 4;      
	board[City::Istanbul] = 4;    
	board[City::Baghdad] = 4; 
	board[City::Tehran] = 4;


    CHECK_THROWS(player.take_card(City::Khartoum));
    CHECK_THROWS(player.take_card(City::Cairo));
    CHECK_THROWS(player.take_card(City::Istanbul));
    CHECK_THROWS(player.take_card(City::Lagos));
    CHECK_THROWS(player.take_card(City::Johannesburg));

    CHECK_THROWS(player.fly_direct(City::Khartoum));
    CHECK_THROWS(player.treat(City::Khartoum));
    CHECK_EQ(board[City::Khartoum] , 3);
    
    CHECK_THROWS(player.drive(City::Cairo));
    CHECK_THROWS(player.treat(City::Cairo));
    CHECK_EQ(board[City::Cairo] , 3);
    

    CHECK_THROWS(player.drive(City::Istanbul));
    CHECK_THROWS(player.treat(City::Istanbul));
    CHECK_EQ(board[City::Istanbul] , 3);

    CHECK_THROWS(player.drive(City::Lagos));
    CHECK_THROWS(player.treat(City::Lagos));
    CHECK_EQ(board[City::Lagos] , 3);

     CHECK_THROWS(player.drive(City::Johannesburg));
     CHECK_THROWS(player.treat(City::Johannesburg));
    CHECK_EQ(board[City::Johannesburg] , 3);

    OperationsExpert player1 {board, City::Tokyo};
    CHECK_THROWS(player1.build());

    OperationsExpert player2 {board, City::Beijing};
    CHECK_THROWS(player2.build());

    CHECK_THROWS(player2.take_card(City::Seoul));
    CHECK_THROWS(player2.take_card(City::Shanghai));
    CHECK_THROWS(player2.take_card(City::HongKong));
    CHECK_THROWS(player2.take_card(City::Kolkata));
    

    board[City::Beijing] = 4;
    board[City::Seoul] = 4;      
	board[City::Shanghai] = 4;          
	board[City::Tokyo] = 4; 
	board[City::HongKong] = 4;
    board[City::Taipei] = 4;
    board[City::Kolkata] = 4;
    board[City::Manila] = 4;


    CHECK_THROWS(player2.fly_shuttle(City::Tokyo));
    CHECK_THROWS(player2.treat(City::Tokyo));
    CHECK_EQ(board[City::Tokyo] , 3);
    
    CHECK_THROWS(player2.fly_direct(City::Shanghai));
    CHECK_THROWS(player2.treat(City::Shanghai));
    CHECK_EQ(board[City::Shanghai] , 3);

    CHECK_THROWS(player2.drive(City::HongKong));
    CHECK_THROWS(player2.treat(City::HongKong));
    CHECK_EQ(board[City::HongKong] , 3);

    CHECK_THROWS(player2.drive(City::Taipei));
    CHECK_THROWS(player2.treat(City::Taipei));
    CHECK_EQ(board[City::HongKong] , 3);
    
    CHECK_THROWS(player2.fly_direct(City::Manila));
    CHECK_THROWS(player2.treat(City::Manila));
    CHECK_EQ(board[City::Manila] , 3);
    ////////////////////////////////// -1 red
    CHECK_THROWS(player2.discover_cure(Color::Red));
    CHECK_THROWS(player2.treat(City::Tokyo));
    CHECK_EQ(board[City::Tokyo] , 2);
    
    CHECK_THROWS(player2.treat(City::Shanghai));
    CHECK_EQ(board[City::Shanghai] , 2);

    CHECK_THROWS(player2.treat(City::HongKong));
    CHECK_EQ(board[City::HongKong] , 2);

    CHECK_THROWS(player2.treat(City::Taipei));
    CHECK_EQ(board[City::HongKong] , 2);
    
    CHECK_THROWS(player2.treat(City::Manila));
    CHECK_EQ(board[City::Manila] , 2);

    board[City::Milan] = 3;      
	board[City::Paris] = 3;      
	board[City::Madrid] = 3;    
	board[City::Washington] = 3; 
	board[City::NewYork] = 3;

    Dispatcher player3{board, City::Tokyo};
    CHECK_THROWS(player2.fly_shuttle(City::Milan));
    CHECK_THROWS(player2.treat(City::Milan));
    CHECK_EQ(board[City::Milan] , 2);

    CHECK_THROWS(player2.drive(City::Paris));
    CHECK_THROWS(player2.treat(City::Paris));
    CHECK_EQ(board[City::Paris] , 2);

    CHECK_THROWS(player2.drive(City::Madrid));
    CHECK_THROWS(player2.treat(City::Madrid));
    CHECK_EQ(board[City::Madrid] , 2);

    CHECK_THROWS(player2.drive(City::NewYork));
    CHECK_THROWS(player2.treat(City::NewYork));
    CHECK_EQ(board[City::NewYork] , 2);
    
    CHECK_THROWS(player2.drive(City::Washington));
    CHECK_THROWS(player2.treat(City::Washington));
    CHECK_EQ(board[City::Washington] , 2);





}

