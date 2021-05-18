#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include "City.hpp"
#include"Color.hpp"
#include "Board.hpp"
using namespace std;
using namespace pandemic;


Board::Node::Node(const std::string &color, const std::string &city, set<City>& d){
    colorOfCity = StringToColor(color);
    CityNow = StringToEnum(city);
    t = d;
    city_s = city;
    cube =0;
    theBuild = false;
}
Board::Board(){
    Cures[Color::Yellow];
    Cures[Color::Black];
    Cures[Color::Blue];
    Cures[Color::Red];
    ifstream file("cities_map.txt");
    string Line;
    string city1;
    string city2;
    string color;
    while(getline(file,Line)){
        istringstream word{Line};
        word >> city1;
        word >> color;
        
        int i = 0;
        // enum City m[6];
        set<City> d;
        while(word){
            word >> city2;
            // m[i++]= StringToEnum(city2);
            d.insert(StringToEnum(city2));
                       
            
        }
        if (city1=="Manila") {d.insert(City::HongKong);}
        Node x{color,city1,d};
        theMap2.insert({StringToEnum(city1),x});
    }

}
void Board::remove_stations(){
       for(auto & theKeyOfMap:theMap2){
           if(theKeyOfMap.second.theBuild){
               theKeyOfMap.second.theBuild= false;
           }
       }
   }
int& Board::operator[](enum City a){
    return theMap2[a].cube;
}
void Board::remove_cures(){
    for(auto& it : Cures){
        it.second=false;
    }
}
bool Board::is_clean(){
    bool ans = true;
    for(auto & theKeyOfMap:theMap2){
        if(theKeyOfMap.second.cube != 0 ){
            ans = false;
            return ans;
        }
     }
     return ans;
}
ostream& pandemic::operator<<(ostream& os , Board& board){
 return os;
}


enum Color pandemic::StringToColor(const string &color){
    if(color=="Yellow"){
        return Color::Yellow;
    }
    if(color=="Black"){
        return Color::Black;
    }
    if(color=="Red"){
        return Color::Red;
    }
    if(color=="Blue"){
        return Color::Blue;
    }
    return Color::Red;


}
enum City pandemic::StringToEnum(const string &city){

    if(city=="Algiers"){
        return City::Algiers;
    }
    if(city=="Atlanta"){
        return City::Atlanta;
    }
    if(city=="Baghdad"){
        return City::Baghdad;
    }
    if(city=="Bangkok"){
        return City::Bangkok;
    }
    if(city=="Beijing"){
        return City::Beijing;
    }
    if(city=="Bogota"){
        return City::Bogota;}
        
    if(city=="BuenosAires"){
        return City::BuenosAires;}
    
    if(city=="Cairo"){
        return City::Cairo;}
    
    if(city=="Chennai"){
        return City::Chennai;}
    
    if(city=="Chicago"){
        return City::Chicago;}
    
    if(city=="Delhi"){
        return City::Delhi;}
    
    if(city=="Essen"){
        return City::Essen;}
    
    if(city=="HoChiMinhCity"){
        return City::HoChiMinhCity;}
    
    if(city=="HongKong"){
        return City::HongKong;}
    
    if(city=="Istanbul"){
        return City::Istanbul;}
    
    if(city=="Jakarta"){
        return City::Jakarta;}
    
    if(city=="Johannesburg"){
        return City::Johannesburg;}
    
    if(city=="Karachi"){
        return City::Karachi;}
    
    if(city=="Khartoum"){
        return City::Khartoum;}
    
    if(city=="Kinshasa"){
        return City::Kinshasa;}
    
    if(city=="Kolkata"){
        return City::Kolkata;}
    
    if(city=="Lagos"){
        return City::Lagos;}
    
    if(city=="Lima"){
        return City::Lima;}
    
    if(city=="London"){
        return City::London;}
    
    if(city=="LosAngeles"){
        return City::LosAngeles;}
    
    if(city=="Madrid"){
        return City::Madrid;}
    
    if(city=="Manila"){
        return City::Manila;}
    
    if(city=="MexicoCity"){
        return City::MexicoCity;}
    
    if(city=="Miami"){
        return City::Miami;}
    
    if(city=="Milan"){
        return City::Milan;}
    
    if(city=="Montreal"){
        return City::Montreal;}
    if(city=="Moscow"){
        return City::Moscow;
    }
    if(city=="Mumbai"){
        return City::Mumbai;
    }
    if(city=="NewYork"){
        return City::NewYork;
    }
    if(city=="Osaka"){
        return City::Osaka;
    }
    if(city=="Paris"){
        return City::Paris;
    }
    if(city=="Riyadh"){
        return City::Riyadh;
    }
    if(city=="SanFrancisco"){
        return City::SanFrancisco;
    }
    if(city=="Santiago"){
        return City::Santiago;
    }
    if(city=="SaoPaulo"){
        return City::SaoPaulo;
    }
    if(city=="Seoul"){
        return City::Seoul;
    }
    if(city=="Shanghai"){
        return City::Shanghai;
    }
    if(city=="StPetersburg"){
        return City::StPetersburg;
    }
    if(city=="Sydney"){
        return City::Sydney;
    }
    if(city=="Taipei"){
        return City::Taipei;
    }
    if(city=="Tehran"){
        return City::Tehran;
    }
    if(city=="Tokyo"){
        return City::Tokyo;
    }
    if(city=="Washington"){
        return City::Washington;
    }
    return City::SanFrancisco;

}
