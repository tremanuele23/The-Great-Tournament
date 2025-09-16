#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED
#include "soldier.h"
string allnames[] = {
        "Aldrico", "Baldovino", "Agilulfo", "Godvino", "Astolfo",
        "Osvaldo", "Sigismondo", "Carlo", "Ottone", "Federico",
        "Vlad", "Berengario", "Wulfrico", "Rodolfo", "Armano",
        "Gervasio", "Emorio", "Elric", "Gavino", "Azzolino",
        "Cedric", "Edoardo", "Goffredo", "Armano", "Pietro",
        "Enrico", "Lotario", "Taddeo", "Benedetto", "Bartolomeo",
        "Osmondo", "Teobaldo", "Alarico", "Gerardo", "Orlando",
        "Tristano", "Ugo", "Lamberto", "Goffredo", "Bernardo"};

Weapon Spada_e_Scudo("Spada e scudo", 75);
Weapon Spada_2("Spada a due mani", 105);
Weapon Spada_1("Spada a una mano", 90);
Weapon Alabarda("Alabarda", 180);
Weapon Warhammer("Martello da guerra", 210);
Weapon Lancia("Lancia", 135);
Weapon Dagger("Spada corta", 45);
Weapon Claymore ("Claymore", 240);

Consumabile it_sucks("Mela", 60);
Consumabile meh("Stufato di carciofi", 80);
Consumabile not_bad("Focaccia", 100);
Consumabile good("Erba Medica", 140);
Consumabile super_good("Decotto di erbe",160);
Consumabile excellent("Pozione Magica", 200);
Consumabile Legendary("Torta Pan di Stelle", 360);

Consumabile allcures[] = {it_sucks, meh, not_bad, good, super_good, excellent, Legendary};

Weapon allweapons[] = {Spada_e_Scudo, Spada_1, Spada_2, Alabarda, Warhammer, Lancia, Dagger};

class Cavaliere: public Soldier {
public:
    Cavaliere() {
        name = " ";
        cw = noweapon;
        tone = 9;
        maxHP = 900;
        HP = maxHP;
        factor=0.2;
    }
    Cavaliere(string nome): Soldier(nome, Spada_e_Scudo, 900, 0.2) {
        tone = 9;
    }
     string battlecry() {
        return "Per la gloria del mio re, prendi questo!";
    }
    string type() {return "Cavaliere";}


};

class Spadaccino: public Soldier {
public:
    Spadaccino() {
        name = " ";
        cw = noweapon;
        tone = 6;
        maxHP = 600;
        HP = maxHP;
        factor=0.2;
    }
    Spadaccino(string x): Soldier(x, Spada_2, 600, 0.2) {
        tone = 6;
    }

     string battlecry() {
        return "La mia lama ti annientera'!";
    }
    string type() {return "Spadaccino";}
};

class Fante: public Soldier {
public:
    Fante() {
        name = " ";
        cw = noweapon;
        tone = 14;
        maxHP = 750;
        HP = maxHP;
        factor = 0.2;
    }
    Fante(string nome): Soldier(nome, Spada_1, 750, 0.2) {
        tone = 14;
    }

     string battlecry() {
        return "Questo attacco mi condurra' alla vittoria!";
    }
    string type() {return "Fante";}
};

class Alabardiere: public Soldier {
public:
    Alabardiere() {
        name = " ";
        cw = noweapon;
        tone = 10;
        maxHP = 550;
        HP = maxHP;
        factor = 0.15;
    }
    Alabardiere(string nome): Soldier(nome, Alabarda, 550, 0.15) {
        tone = 10;
    }

     string battlecry() {
        return "Il mio prossimo colpo sara' l'ultimo!";
    }
    string type() {return "Alabardiere";}
};

class Heavy: public Soldier  {
public:
    Heavy() {
        name = " ";
        cw = noweapon;
        tone = 11;
        maxHP=500;
        HP = maxHP;
        factor = 0.15;
    }
    Heavy(string nome): Soldier(nome, Warhammer, 500, 0.15) {
        tone = 11;
    }
    string battlecry() {return "Ti schiaccero' come un insetto!";}
    string type() {return "Combattente Pesante";}
};

class Lanciere: public Soldier {
public:
        Lanciere() {
        name = " ";
        cw = noweapon;
        tone = 5;
        maxHP= 700;
        HP = maxHP;
        factor = 0.2;
    }
    Lanciere(string nome): Soldier(nome, Lancia, 700, 0.2) {
        tone = 5;
    }
    string battlecry() {return "Sentirai la mia lancia persino prima di vedermi!";}
    string type() {return "Lanciere";}
};

class Mercenario: public Soldier {
public:
       Mercenario() {
        name = " ";
        cw = noweapon;
        tone = 12;
        maxHP=750;
        HP = maxHP;
        factor=0.4;
    }
    Mercenario(string nome): Soldier(nome, Dagger, 750, 0.4) {
        tone = 12;
    }
    string battlecry() {return "La tua fine sara' la mia fortuna!";}
    string type() {return "Mercenario";}
};


class Boss: public Soldier {
public:
    Boss() {
        name=" ";
        cw=noweapon;
        tone= 8;
        maxHP=1000;
        HP=maxHP;
        factor=0.5;
    }
    Boss(string nome): Soldier(nome, Claymore, 1000, 0.5)  {
        tone=8;
    }
    string battlecry() {return "Preparati alla mia venuta, verme!";}
    string type() {return "Guerriero d'Alto Rango";}
};

#endif // ITEM_H_INCLUDED
