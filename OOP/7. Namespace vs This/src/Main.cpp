#include <iostream>
#include <string>

using namespace std;

class ClassTypes{
    public:
        string dataStr;
        double dataDouble;
        double m_dataDouble; // data punyanya class

        ClassTypes(const char* dataStr, double dataDouble){
            // dengan menggunakan namspace dari class
            ClassTypes::dataStr = dataStr;

            // dengan menggunakan "this"
            cout << this << endl;
            this->dataDouble =dataDouble;

            // dengan menggunakan konvensi penamaan;
            m_dataDouble = dataDouble; // biasanya digunain untuk memperhatiin memory karena gak makek namespace / this yang memakan memori
        }
};

namespace Super{
    class Player{
        public:
            string name;
            int health;
            double power;

            Player(const char* name, double power){
                Player::setName(name);
            }

            void setName(const char* name){
                this->name = name;
            }

            void setPower(double power){
                this->power = power;
            }

            void setHealth(int);
    };

    // prototype
    void Player::setHealth(int health){
        this->health = health;
    }
};

int main(int argc, char const *argv[])
{
    ClassTypes* object1 = new ClassTypes("Object 1", 0.05);
    cout << object1->dataStr << endl;
    cout << object1->dataDouble << endl;
    cout << object1->m_dataDouble << endl;

    // karena didalam namespace perlu jabarkan namespacenya juga
    Super::Player* player1 = new Super::Player("ucup",100);

    cout << player1->name << endl;
    player1->setHealth(99);

    cout << player1->health << endl;

    return 0;
}

/**
 * @attention Penggunaan namespace
 * bisa mengelompokkan class yang bisa diakses dengan ::
 * namespace juga digunakan untuk membuat method diluar class dengan protoype 
 * 
 * @attention Penggunaan this
 * this adalah address dari class itu sendiri
 * sehingga kita bsa mengakses member dari class dengan this->
 * 
 */
