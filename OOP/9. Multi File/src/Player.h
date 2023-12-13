#ifndef __PLAYER
#define __PLAYER
#include <string>

class Player{
    public: 
    std::string name;

    // constructur
    Player(const char*); // dalam bentuk prototype
    void display();
    std::string getName();
    void setName(const char*);
};
#endif