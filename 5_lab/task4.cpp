#include<iostream>
using namespace std;
class Character{
    public : 
    int health;
};

class Attacker{
    public : 
    virtual void attack() = 0;
};
class Defender{
    public : 
    virtual void defend() = 0;
};
class MagicUser{
    public : 
    virtual void castSpell() = 0;
};

class Paladin : public Character, public Attacker, public Defender, public MagicUser{
    public : 
    Paladin(int h){
        health = h;
    }
    void attack() override {
        cout << "I am attacking \n";
    }
    void defend() override {
        cout << "I am defending \n";
    }
    void castSpell() override {
        cout << "Wingardium Leviosa \n";
    }
}; 
int main()
{
    Paladin p1(90);
    p1.attack();
    p1.defend();
    p1.castSpell();

    return 0;
}