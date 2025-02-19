#ifndef SOLDIER_H_INCLUDED
#define SOLDIER_H_INCLUDED
#include "colors.h"
#include "item.h"
#include <vector>
#include <time.h>


Weapon noweapon(" ", 0);

int posizione(vector<Consumabile> v, Consumabile p) {
    for(int i = 0; i<v.size(); i++) {
        if(v[i].getname()==p.getname())
            return i;
    }
    return -1;

}
int posizione(vector<Weapon> v, Weapon p) {
    for(int i = 0; i<v.size(); i++) {
        if(v[i].getname()==p.getname())
            return i;
    }
    return -1;

}

class Soldier {
protected:
    Weapon cw; //current weapon
    string name;
    int tone;
    int maxHP;
    int low_mod;
    int up_mod;
public:
    vector<Consumabile> consumabili;
    vector<Weapon> weaps;
    int HP;
    Soldier() {
        maxHP = 100;
        HP = maxHP;
        name = " ";
        cw=noweapon;
        weaps.empty();
        consumabili.empty();
        low_mod = 0;
        up_mod = 0;
    }
    Soldier(string n, Weapon w, int max, int u, int l) {
        maxHP = max;
        HP = maxHP;
        name = n;
        cw = w;
        up_mod = u;
        low_mod = l;
        weaps.empty();
        consumabili.empty();

    }
    void svuotainventario() {
        weaps.empty();
        consumabili.empty();
    }
    void add_to_inventory(Weapon pippo) {
        weaps.push_back(pippo);
        }
    void add_to_inventory(Consumabile pippo) {
        consumabili.push_back(pippo);
        }
    void remove_from_inventory(Weapon pippo) {
        int pos = posizione(weaps, pippo);
        weaps.erase(weaps.begin()+pos);
    }
    void remove_from_inventory(Consumabile pippo) {
        int pos = posizione(consumabili, pippo);
        consumabili.erase(consumabili.begin()+pos);
    }
    void showweaps() {
        color(tone);
        cout<<"Armi di "<<name<<" (size = "<<weaps.size()<<"):\n";
        color(7);
        for(int i = 0; i<weaps.size(); i++) {
            cout<<"["<<i<<"]: "<<weaps[i].getname()<<" (DMG: "<<weaps[i].getdamage()<<")";
            if(i!=weaps.size()-1)
                cout<<";";
            cout<<endl;
        }
        cout<<endl;
    }
    void showconsumabili() {
        color(tone);
        cout<<"Consumabili di "<<name<<" (size = "<<consumabili.size()<<"):\n";
        color(7);
        for(int i = 0; i<consumabili.size(); i++) {
            cout<<"["<<i<<"]: "<<consumabili[i].getname()<<" (HP Bonus: "<<consumabili[i].getHPboost()<<")";
            if(i!=consumabili.size()-1)
                cout<<";";
            cout<<endl;
        }
        cout<<endl;
    }

    void showinventory() {
        showweaps();
        cout<<endl;
        showconsumabili();
    }


    void equip_weapon(Weapon w) {
        if (posizione(weaps, w)!=-1) {
            add_to_inventory(cw);
            cw = w;
            remove_from_inventory(w);
            cout<<"Arma equipaggiata.\n";
        }
        else
            cout<<"L'arma non e' presente nel tuo inventario.\n";
    }
    Weapon getCW() {return cw;}
    void setname(string n) {name = n;}
    string getCWname(){return cw.getname();}
    int getCWdamage() {return cw.getdamage();}
    string getname() {return name;}
    int getHP() {return HP;}

    void say(string sentence) {
        char a;
        color(tone);
        cout<<"'"<<name<<"': "<<sentence<<endl;
        color(7);


    }
     void msg(string sentence) {
        char a;
        color(tone);
        cout<<sentence<<endl;
        color(7);


    }

    void restoreHP() {HP=maxHP;
    cout<<"HP di "<<name<<" ripristinati!\n";}

    virtual string type() {return "Soldato";}
    string introduction() {
        return "Classe: " + type() + "\nNome: "+name+".\nArma equipaggiata: "+cw.getname()+", danno: "+to_string(cw.getdamage())+"\nHP: "+to_string(HP)+"/"+to_string(maxHP);
    }

    virtual string battlecry() = 0;

    void fight(Soldier *target) {
        color(tone);
        if(cw.getdamage()!=noweapon.getdamage()) {
            say(battlecry());
            int froppo = cw.getdamage()+rand()%(up_mod-low_mod+1)+low_mod;
            target->HP -= froppo;
            cout<<"["<<name<<" causa a "<<target->getname()<<" un danno di "<<froppo<<" punti!]\n";
        }
        else
            cout<<"[Nessuna arma equipaggiata!]\n\n";
    }
    ~Soldier() {};


    void use(Consumabile c) {
        if(posizione(consumabili, c)!=-1) {
            cout<<"Hai usato "<<c.getname()<<"!\n";
            if(HP+c.getHPboost()<=maxHP)
                HP+=c.getHPboost();
            else if(HP!=maxHP) {HP=maxHP;}
            cout<<"\nHP: "<<HP<<"/"<<maxHP<<endl;
            remove_from_inventory(c);
        }
        else
            cout<<"L'oggetto non e' nell'inventario.\n\n\n\n";
    }


};


#endif // SOLDIER_H_INCLUDED
