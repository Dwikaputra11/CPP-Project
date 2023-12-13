#include <iostream> 
#include <string>

// external definition for file
#include "Player.h"


using namespace std;

int main(int argc, char const *argv[])
{
    Player* playerObject = new Player("Saitama");
    playerObject->display();
    string name = playerObject->getName();
    cout << name << endl;
    playerObject->setName("Tanjiro");
    cout << playerObject->getName() << endl;
    return 0;
}
