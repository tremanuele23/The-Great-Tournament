#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
class Item {
    protected:
    string name;
    public:
    string type;
        Item(string n) {name=n;}
        Item() {name = " ";}
    void setname(string x) {name = x;}
    string getname() {return name;}

    virtual void showstats() {
        cout<<"Oggetto: "<<name<<endl<<endl;
    }
};

class Weapon: public Item {
protected:
    int damage;
public:
    Weapon() {damage = 0; type = "Arma";}
    Weapon(string n, int dmg): Item(n) {type = "Arma"; damage = dmg;}
    void setdamage(int x) {damage=x;}
    int getdamage(){return damage;}
    void showstats() {
        cout<<"Arma: "<<name<<endl;
        cout<<"Danno: "<<damage<<endl<<endl;
    }
};

class Consumabile: public Item {
protected:
    int HP_boost;
public:
    Consumabile() {HP_boost=0; type = "Consumabile";}
    Consumabile(string n, int lf): Item(n) {HP_boost = lf; type="Consumabile";}

    void setHPboost(int x) {HP_boost=x;}
    int getHPboost() {return HP_boost;}
    void showstats() {
        cout<<"Consumabile: "<<name<<endl;
        cout<<"Boost vita: "<<HP_boost<<endl;
    }


};




#endif // ITEM_H_INCLUDED
