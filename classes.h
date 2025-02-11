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


Weapon Spada_e_Scudo("Spada e scudo", 30);
Weapon Spada_2("Spada a due mani", 35);
Weapon Spada_1("Spada a una mano", 25);
Weapon Alabarda("Alabarda", 60);
Weapon Warhammer("Martello da guerra", 70);
Weapon Lancia("Lancia", 45);
Weapon Dagger("Spada corta", 15);


Consumabile it_sucks("Mela", 30);
Consumabile meh("Stufato di carciofi", 40);
Consumabile not_bad("Focaccia", 50);
Consumabile good("Erba Medica", 70);
Consumabile super_good("Decotto di erbe", 80);
Consumabile excellent("Pozione Magica", 100);
Consumabile Legendary("Torta Pan di Stelle", 180);

Consumabile allcures[] = {it_sucks, meh, not_bad, good, super_good, excellent, Legendary};

Weapon allweapons[] = {Spada_e_Scudo, Spada_1, Spada_2, Alabarda, Warhammer, Lancia, Dagger};




class Cavaliere: public Soldier {
public:
    Cavaliere() {
        name = " ";
        cw = noweapon;
        tone = 9;
        maxHP = 180;
        HP = maxHP;
        low_mod=-10;
        up_mod=15;
    }
    Cavaliere(string nome): Soldier(nome, Spada_e_Scudo, 180, 15, -10) {
        tone = 9;
    }

     string battlecry() {
        return "Per la gloria del mio re, prendi questo!!!";
    }
    string type() {return "Cavaliere";}


};

class Spadaccino: public Soldier {
public:
    Spadaccino() {
        name = " ";
        cw = noweapon;
        tone = 6;
        maxHP = 120;
        HP = maxHP;
        low_mod=-5;
        up_mod=10;
    }
    Spadaccino(string x): Soldier(x, Spada_2, 120, 7, -5) {
        tone = 6;
    }

     string battlecry() {
        return "La mia lama ti annientera'!!!";
    }
    string type() {return "Spadaccino";}
};

class Fante: public Soldier {
public:
    Fante() {
        name = " ";
        cw = noweapon;
        tone = 14;
        maxHP = 150;
        HP = maxHP;
        low_mod=0;
        up_mod=7;
    }
    Fante(string nome): Soldier(nome, Spada_1, 150, 7, 0) {
        tone = 14;
    }

     string battlecry() {
        return "Questo attacco mi condurra' alla vittoria!!!";
    }
    string type() {return "Fante";}
};

class Alabardiere: public Soldier {
public:
    Alabardiere() {
        name = " ";
        cw = noweapon;
        tone = 10;
        maxHP = 110;
        HP = maxHP;
        low_mod=-15;
        up_mod=7;
    }
    Alabardiere(string nome): Soldier(nome, Alabarda, 110, 7, -15) {
        tone = 10;
    }

     string battlecry() {
        return "Il mio prossimo colpo sara' l'ultimo!!!";
    }
    string type() {return "Alabardiere";}
};

class Heavy: public Soldier  {
public:
    Heavy() {
        name = " ";
        cw = noweapon;
        tone = 11;
        maxHP=100;
        HP = maxHP;
        low_mod = -20;
        up_mod = 0;
    }
    Heavy(string nome): Soldier(nome, Warhammer, 100, 0, -20) {
        tone = 11;
    }
    string battlecry() {return "Ti schiaccero' come un insetto!!!";}
    string type() {return "Combattente Pesante";}
};

class Lanciere: public Soldier {
public:
        Lanciere() {
        name = " ";
        cw = noweapon;
        tone = 5;
        maxHP=140;
        HP = maxHP;
        low_mod = -5;
        up_mod = 15;
    }
    Lanciere(string nome): Soldier(nome, Lancia, 140, 15, -5) {
        tone = 5;
    }
    string battlecry() {return "Sentirai la mia lancia persino prima di vedermi!!!";}
    string type() {return "Lanciere";}
};

class Mercenario: public Soldier {
public:
       Mercenario() {
        name = " ";
        cw = noweapon;
        tone = 12;
        maxHP=150;
        HP = maxHP;
        low_mod = 10;
        up_mod = 25;
    }
    Mercenario(string nome): Soldier(nome, Dagger, 150, 25, 10) {
        tone = 12;
    }
    string battlecry() {return "La tua fine sara' la mia fortuna!!!";}
    string type() {return "Mercenario";}
};



Soldier *player;

void match(Soldier* s2) {
    int weapdim = player->weaps.size();
    int consdim = player->consumables.size();
    int a;
    system("CLS");
    cout<<player->getname()<< " ("<<player->type()<<") vs " <<s2->getname()<<" ("<<s2->type()<<")\n"<<endl;
    cout<<"\nCHE LO SCONTRO ABBIA INIZIO!\n\nPremi un tasto per continuare: ";
    a = getch();
    system("CLS");
    do {
        chosing:
            cout<<"Turno di "<<player->getname()<<".\n\n";
            player->msg(player->introduction());
            cout<<"\nScegli cosa fare:\n1.Attacca (Arma equipaggiata: "<<player->getCWname()<<", di danni "<<player->getCWdamage()<<")\n";
            cout<<"2.Seleziona un'altra arma\n3.Utilizza una cura\n\n";
            int scelta;
            do {
                cout<<"Scelta: ";
                cin>>scelta;
                cin.ignore();
            }
            while(scelta!=1&&scelta!=2&&scelta!=3&&scelta!=250445&&scelta!=230507);
        switch(scelta) {
            case 1:
                cout<<endl<<endl<<endl<<player->getname()<<" attacca!\n\n";
                player->fight(s2);
                break;
            case 2:
                cout<<endl;
                if(weapdim>0) {
                    player->showweaps();
                    int x;
                    do {
                        cout<<"\nQuale di queste armi vuoi equipaggiare? Inserisci il numero corrispondente (o -1 per tornare indietro): ";
                        cin>>x;
                        cin.ignore();
                    }
                    while(x<-1||x>=weapdim);
                    cout<<endl;
                    if(x!=-1)
                        player->equip_weapon(player->weaps[x]);
                    else {

                        system("CLS");
                        goto chosing;
                    }
                }
                else {
                    cout<<"Non hai altre armi, dovrai utilizzare quella che gia' hai in mano!\nPremi un tasto per continuare il tuo turno. ";
                    a = getch();
                    system("CLS");
                    goto chosing;
                }
                break;
            case 3:
                cout<<endl;
                if(consdim>0) {
                    player->showconsumables();
                    int x;
                    do {
                        cout<<"\nQuale di queste cure vuoi utilizzare? Inserisci il numero corrispondente (o -1 per tornare indietro): ";
                        cin>>x;
                        cin.ignore();
                    }
                    while(x<-1 || x>=consdim);
                    cout<<endl;
                    if (x!=-1) {
                        player->use(player->consumables[x]);
                    }
                    else {
                        cout<<"Decidi di tornare indietro.\nPremi un tasto per continuare il tuo turno. ";
                        a = getch();
                        system("CLS");
                        goto chosing;
                    }
                }
                else {
                    cout<<"A quanto pare non hai cure!\nPremi un tasto per continuare il tuo turno. ";
                    a = getch();
                    system("CLS");
                    goto chosing;
                }
                break;
            case 250445:
                cout<<"Codice sviluppatore utilizzato.\n";
                s2->HP = 0;
                break;
            case 230507:
                cout<<"Codice sviluppatore utilizzato.\n";
                player->HP = 0;
                break;
            }


        cout<<"\n\nClicca un tasto per procedere. ";
        a = getch();
        system("CLS");
        if(s2->HP<=0||player->HP<=0)
            break;
        cout<<"Turno di "<<s2->getname()<<".\n\n";
        s2->msg(s2->introduction());
        cout<<endl<<endl<<endl<<s2->getname()<<" attacca!\n\n";
        s2->fight(player);

        cout<<"\n\nClicca un tasto per procedere. ";
        a = getch();

        system("CLS");
    }
    while (s2->HP>0&&player->HP>0);

    cout<<"\tDUELLO FINITO.\nIl vincitore e' ";
    if(s2->HP>0) {
        s2->msg(s2->getname()+"!!!!!");
    }
    if(player->HP>0) {
        player->msg(player->getname()+"!!!!!");
    }

    cout<<"\n\nClicca un tasto per procedere. ";
    a = getch();

        system("CLS");
    if(player->HP>0) {
        player->restoreHP();
        Consumabile reward = allcures[rand()%7];
        cout<<"\n\nVuoi raccogliere l'arma dell'avversario?\n\n";
        s2->getCW().showstats();
        cout<<"\t1: La prendi.\n\t0: Non la prendi.\n\nScelta: ";
        bool willtake;
        cin>>willtake;
        cin.ignore();
        if(willtake){
            player->add_to_weapons(s2->getCW());
            cout<<"\nHai aggiunto l'arma all'inventario.\n";
        }
        else {
            cout<<"\nDecidi di non prenderla.\n";
        }
        cout<<"\n\n\n\n\nNoti che tra gli oggetti dell'avversario e' presente "<<reward.getname()<<" (capacita' curativa: "<<reward.getHPboost()<<")\nDecidi cosa fare.\n";
        cout<<"\n\t1: La prendi.\n\t0: Non la prendi.\n\nScelta: ";
        cin>>willtake;
        cin.ignore();
        if(willtake){
            player->add_to_consumables(reward);
            cout<<"\nHai aggiunto l'oggetto all'inventario.\n";
        }
        else {
            cout<<"\nDecidi di non prendere l'oggetto.\n";
        }
        cout<<"Premi un tasto per continuare. ";
        a = getch();
    }
    else
    {
        color(4);
        cout<<"\tHAI PERSO!\n\n\n\n";
        color(7);
        cout<<"Questa volta e' andata male...chissa', magari una prossima volta sarai piu' fortunato/a!\n\n";
        cout<<"Premi un tasto per continuare. ";
        a = getch();
    }

    system("CLS");
}










#endif // ITEM_H_INCLUDED

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


Weapon Spada_e_Scudo("Spada e scudo", 30);
Weapon Spada_2("Spada a due mani", 35);
Weapon Spada_1("Spada a una mano", 25);
Weapon Alabarda("Alabarda", 60);
Weapon Warhammer("Martello da guerra", 70);
Weapon Lancia("Lancia", 45);
Weapon Dagger("Spada corta", 15);


Consumabile it_sucks("Mela", 30, 0);
Consumabile meh("Stufato di carciofi", 40, 0);
Consumabile not_bad("Focaccia", 50, 0);
Consumabile good("Erba Medica", 70, 0);
Consumabile super_good("Decotto di erbe", 80, 0);
Consumabile excellent("Pozione Magica", 100, 0);
Consumabile Legendary("Torta Pan di Stelle", 180, 0);

Consumabile allcures[] = {it_sucks, meh, not_bad, good, super_good, excellent, Legendary};

Weapon allweapons[] = {Spada_e_Scudo, Spada_1, Spada_2, Alabarda, Warhammer, Lancia, Dagger};




class Cavaliere: public Soldier {
public:
    Cavaliere() {
        name = " ";
        cw = noweapon;
        tone = 9;
        maxHP = 180;
        HP = maxHP;
        low_mod=-10;
        up_mod=15;
    }
    Cavaliere(string nome): Soldier(nome, Spada_e_Scudo, 180, 15, -10) {
        tone = 9;
    }

     string battlecry() {
        return "Per la gloria del mio re, prendi questo!!!";
    }
    string type() {return "Cavaliere";}


};

class Spadaccino: public Soldier {
public:
    Spadaccino() {
        name = " ";
        cw = noweapon;
        tone = 6;
        maxHP = 120;
        HP = maxHP;
        low_mod=-5;
        up_mod=10;
    }
    Spadaccino(string x): Soldier(x, Spada_2, 120, 7, -5) {
        tone = 6;
    }

     string battlecry() {
        return "La mia lama ti annientera'!!!";
    }
    string type() {return "Spadaccino";}
};

class Fante: public Soldier {
public:
    Fante() {
        name = " ";
        cw = noweapon;
        tone = 14;
        maxHP = 150;
        HP = maxHP;
        low_mod=0;
        up_mod=7;
    }
    Fante(string nome): Soldier(nome, Spada_1, 150, 7, 0) {
        tone = 14;
    }

     string battlecry() {
        return "Questo attacco mi condurra' alla vittoria!!!";
    }
    string type() {return "Fante";}
};

class Alabardiere: public Soldier {
public:
    Alabardiere() {
        name = " ";
        cw = noweapon;
        tone = 10;
        maxHP = 110;
        HP = maxHP;
        low_mod=-15;
        up_mod=7;
    }
    Alabardiere(string nome): Soldier(nome, Alabarda, 110, 7, -15) {
        tone = 10;
    }

     string battlecry() {
        return "Il mio prossimo colpo sara' l'ultimo!!!";
    }
    string type() {return "Alabardiere";}
};

class Heavy: public Soldier  {
public:
    Heavy() {
        name = " ";
        cw = noweapon;
        tone = 11;
        maxHP=100;
        HP = maxHP;
        low_mod = -20;
        up_mod = 0;
    }
    Heavy(string nome): Soldier(nome, Warhammer, 100, 0, -20) {
        tone = 11;
    }
    string battlecry() {return "Ti schiaccero' come un insetto!!!";}
    string type() {return "Combattente Pesante";}
};

class Lanciere: public Soldier {
public:
        Lanciere() {
        name = " ";
        cw = noweapon;
        tone = 5;
        maxHP=140;
        HP = maxHP;
        low_mod = -5;
        up_mod = 15;
    }
    Lanciere(string nome): Soldier(nome, Lancia, 140, 15, -5) {
        tone = 5;
    }
    string battlecry() {return "Sentirai la mia lancia persino prima di vedermi!!!";}
    string type() {return "Lanciere";}
};

class Mercenario: public Soldier {
public:
       Mercenario() {
        name = " ";
        cw = noweapon;
        tone = 12;
        maxHP=150;
        HP = maxHP;
        low_mod = 10;
        up_mod = 25;
    }
    Mercenario(string nome): Soldier(nome, Dagger, 150, 25, 10) {
        tone = 12;
    }
    string battlecry() {return "La tua fine sara' la mia fortuna!!!";}
    string type() {return "Mercenario";}
};



Soldier *player;

void match(Soldier* s2) {
    int weapdim = player->weaps.size();
    int consdim = player->consumables.size();
    int a;
    system("CLS");
    cout<<player->getname()<< " ("<<player->type()<<") vs " <<s2->getname()<<" ("<<s2->type()<<")\n"<<endl;
    cout<<"\nCHE LO SCONTRO ABBIA INIZIO!\n\nPremi un tasto per continuare: ";
    a = getch();
    system("CLS");
    do {
        chosing:
            cout<<"Turno di "<<player->getname()<<".\n\n";
            player->msg(player->introduction());
            cout<<"\nScegli cosa fare:\n1.Attacca (Arma equipaggiata: "<<player->getCWname()<<", di danni "<<player->getCWdamage()<<")\n";
            cout<<"2.Seleziona un'altra arma\n3.Utilizza una cura\n\n";
            int scelta;
            do {
                cout<<"Scelta: ";
                cin>>scelta;
                cin.ignore();
            }
            while(scelta!=1&&scelta!=2&&scelta!=3&&scelta!=250445&&scelta!=230507);
        switch(scelta) {
            case 1:
                cout<<endl<<endl<<endl<<player->getname()<<" attacca!\n\n";
                player->fight(s2);
                break;
            case 2:
                cout<<endl;
                if(weapdim>0) {
                    player->showweaps();
                    int x;
                    do {
                        cout<<"\nQuale di queste armi vuoi equipaggiare? Inserisci il numero corrispondente (o -1 per tornare indietro): ";
                        cin>>x;
                        cin.ignore();
                    }
                    while(x<-1||x>=weapdim);
                    cout<<endl;
                    if(x!=-1)
                        player->equip_weapon(player->weaps[x]);
                    else {
                        cout<<"Decidi di tornare indietro.\nPremi un tasto per continuare il tuo turno. ";
                        a = getch();
                        system("CLS");
                        goto chosing;
                    }
                }
                else {
                    cout<<"Non hai altre armi, dovrai utilizzare quella che gia' hai in mano!\nPremi un tasto per continuare il tuo turno. ";
                    a = getch();
                    system("CLS");
                    goto chosing;
                }
                break;
            case 3:
                cout<<endl;
                if(consdim>0) {
                    player->showconsumables();
                    int x;
                    do {
                        cout<<"\nQuale di queste cure vuoi utilizzare? Inserisci il numero corrispondente (o -1 per tornare indietro): ";
                        cin>>x;
                        cin.ignore();
                    }
                    while(x<-1 || x>=consdim);
                    cout<<endl;
                    if (x!=-1) {
                        player->use(player->consumables[x]);
                    }
                    else {
                        cout<<"Decidi di tornare indietro.\nPremi un tasto per continuare il tuo turno. ";
                        a = getch();
                        system("CLS");
                        goto chosing;
                    }
                }
                else {
                    cout<<"A quanto pare non hai cure!\nPremi un tasto per continuare il tuo turno. ";
                    a = getch();
                    system("CLS");
                    goto chosing;
                }
                break;
            case 250445:
                cout<<"Codice sviluppatore utilizzato.\n";
                s2->HP = 0;
                break;
            case 230507:
                cout<<"Codice sviluppatore utilizzato.\n";
                player->HP = 0;
                break;
            }


        cout<<"\n\nClicca un tasto per procedere. ";
        a = getch();
        system("CLS");
        if(s2->HP<=0||player->HP<=0)
            break;
        cout<<"Turno di "<<s2->getname()<<".\n\n";
        s2->msg(s2->introduction());
        cout<<endl<<endl<<endl<<s2->getname()<<" attacca!\n\n";
        s2->fight(player);

        cout<<"\n\nClicca un tasto per procedere. ";
        a = getch();

        system("CLS");
    }
    while (s2->HP>0&&player->HP>0);

    cout<<"\tDUELLO FINITO.\nIl vincitore e' ";
    if(s2->HP>0) {
        s2->msg(s2->getname()+"!!!!!");
    }
    if(player->HP>0) {
        player->msg(player->getname()+"!!!!!");
    }

    cout<<"\n\nClicca un tasto per procedere. ";
    a = getch();

        system("CLS");
    if(player->HP>0) {
        player->restoreHP();
        Consumabile reward = allcures[rand()%7];
        cout<<"\n\nVuoi raccogliere l'arma dell'avversario?\n\n";
        s2->getCW().showstats();
        cout<<"\t1: La prendi.\n\t0: Non la prendi.\n\nScelta: ";
        bool willtake;
        cin>>willtake;
        cin.ignore();
        if(willtake){
            player->add_to_weapons(s2->getCW());
            cout<<"\nHai aggiunto l'arma all'inventario.\n";
        }
        else {
            cout<<"\nDecidi di non prenderla.\n";
        }
        cout<<"\n\n\n\n\nNoti che tra gli oggetti dell'avversario e' presente "<<reward.getname()<<" (capacita' curativa: "<<reward.getHPboost()<<")\nDecidi cosa fare.\n";
        cout<<"\n\t1: La prendi.\n\t0: Non la prendi.\n\nScelta: ";
        cin>>willtake;
        cin.ignore();
        if(willtake){
            player->add_to_consumables(reward);
            cout<<"\nHai aggiunto l'oggetto all'inventario.\n";
        }
        else {
            cout<<"\nDecidi di non prendere l'oggetto.\n";
        }
        cout<<"Premi un tasto per continuare. ";
        a = getch();
    }
    else
    {
        color(4);
        cout<<"\tHAI PERSO!\n\n\n\n";
        color(7);
        cout<<"Questa volta e' andata male...chissa', magari una prossima volta sarai piu' fortunato/a!\n\n";
        cout<<"Premi un tasto per continuare. ";
        a = getch();
    }

    system("CLS");
}










#endif // ITEM_H_INCLUDED
