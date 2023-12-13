#include <iostream> 
#include <string>

using namespace std;

class Player{
    public: 
    string name;

    // constructur
    Player(const char*); // dalam bentuk prototype
    void display();
    string getName();
    void setName(const char*);
};

int main(int argc, char const *argv[])
{
    Player* playerObject = new Player("Marni");
    playerObject->display();
    string name = playerObject->getName();
    cout << name << endl;
    playerObject->setName("koko");
    cout << playerObject->getName() << endl;
    return 0;
}

Player::Player(const char* name){
    this->name = name;
}
void Player::display(){
    cout << "Nama Player: " << this->name << endl;
}

string Player::getName(){
    return this->name;
}

void Player::setName(const char* name){
    this->name = name;
}