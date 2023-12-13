#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

Player::Player(const char* name){
    this->name = name;
}
void Player::display(){
    cout << "Nama Player: " << this->name << endl;
    cout << "Class ini berada di file terpisah\n";
}

string Player::getName(){
    return this->name;
}

void Player::setName(const char* name){
    this->name = name;
}