#include <iostream>
#include "game.h"
using namespace std;

int main()
{
    Game game("127.0.0.1" , 9595 ) ;
    if(game.connect_server())
    {
        game.start ("UnKnown" ); //Write your team name here
    }

}
