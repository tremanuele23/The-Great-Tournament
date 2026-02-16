#ifndef FIGHTFUNCS_H_INCLUDED
#define FIGHTFUNCS_H_INCLUDED
#include "soldier.h"
Soldier *player;


void match(Soldier* s2, char track[]) {
    bool battleFinished=false;
    PlaySound(TEXT(track), NULL, SND_FILENAME| SND_ASYNC | SND_LOOP);
    int weapdim = player->weaps.size();
    int consdim = player->consumabili.size();
    system("CLS");
    digita(player->getname()+ " ("+player->type()+") vs " +s2->getname()+" ("+s2->type()+")\n",1);
    Sleep(600);
    cout<<"\nCHE LO SCONTRO ABBIA INIZIO!\n\n";
    Sleep(600);
    digita("Premi un tasto per continuare: ");
    clearInputBuffer();
    _getch();
    system("CLS");
    int scelta;
    do {
        chosing:
            cout<<"Turno di "<<player->getname()<<"\n\n";
            Sleep(700);
            player->msg(player->introduction());
            cout<<"\nScegli cosa fare:";
            cout<<"\n1.Attacca (Arma equipaggiata: "<<player->getCWname()<<", di danni "<<player->getCWdamage()<<")";
            cout<<"\n2.Seleziona un'altra arma";
            cout<<"\n3.Utilizza una cura";
            cout<<endl<<endl<<endl;
            Sleep(700);
            do {
                digita("Scelta: ");
                cin>>scelta;
                cin.ignore();
            }
            while(scelta!=1&&scelta!=2&&scelta!=3&&scelta!=4&&scelta!=250445&&scelta!=230507&&scelta!=2512800);
        switch(scelta) {
            case 1:
                cout<<endl<<endl<<endl<<player->getname()<<" attacca!\n\n";
                player->fight(s2, true);
                break;
            case 2:
                cout<<endl;
                if(weapdim>0) {
                    player->showweaps();
                    int x;
                    do {
                        digita("\nQuale di queste armi vuoi equipaggiare? Inserisci il numero corrispondente (o -1 per tornare indietro): ");
                        cin>>x;
                        cin.ignore();
                    }
                    while(x<-1||x>=weapdim);
                    cout<<endl;
                    if(x!=-1) {
                        playItemUsed();
                        player->equip_weapon(player->weaps[x]);
                    }
                    else {

                        system("CLS");
                        goto chosing;
                    }
                }
                else {
                    digita("Non hai altre armi, dovrai utilizzare quella che gia' hai in mano!\nPremi un tasto per continuare il tuo turno. ");
                    clearInputBuffer();
                    _getch();
                    system("CLS");
                    goto chosing;
                }
                break;
            case 3:
                cout<<endl;
                if(consdim>0) {
                    player->showconsumabili();
                    int x;
                    do {
                        digita("\nQuale di queste cure vuoi utilizzare? Inserisci il numero corrispondente (o -1 per tornare indietro): ");
                        cin>>x;
                        cin.ignore();
                    }
                    while(x<-1 || x>=consdim);
                    cout<<endl;
                    if (x!=-1) {
                        playItemUsed();
                        player->use(player->consumabili[x]);
                    }
                    else {

                        system("CLS");
                        goto chosing;
                    }
                }
                else {
                    digita("A quanto pare non hai cure!\nPremi un tasto per continuare il tuo turno. ");
                    clearInputBuffer();
                    _getch();
                    system("CLS");
                    goto chosing;
                }
                break;
            case 250445:
                digita("Codice sviluppatore utilizzato.",1);
                s2->HP = 0;
                break;
            case 230507:
                digita("Codice sviluppatore utilizzato.",1);
                player->HP = 0;
                break;
            }


        cout<<"\n\n";
        digita("Clicca un tasto per procedere. ");
        clearInputBuffer();
        _getch();
        system("CLS");
        if(s2->HP<=0||player->HP<=0) {
            battleFinished=true;
            break;
        }
        cout<<"Turno di "+s2->getname()+".\n\n";
        Sleep(200);
        s2->msg(s2->introduction());
        cout<<endl<<endl<<endl;
        Sleep(700);
        cout<<s2->getname()<<" attacca!\n\n";
        s2->fight(player, false);

        cout<<"\n\nClicca un tasto per procedere. ";
        _getch();

        system("CLS");
    }
    while (!battleFinished);
    PlaySound(NULL, 0, 0);
    cout<<"\tDUELLO FINITO.\n"; Sleep(700);
    digita("Il vincitore e' "); Sleep(1500);
    if(s2->HP>0) {
        s2->msg1(s2->getname()+"!");
    }
    if(player->HP>0)
        player->msg1(player->getname()+"!");
    Sleep(700);
    cout<<"\n\n";
    digita("Clicca un tasto per procedere. ");
    _getch();
    system("CLS");

}

void lost() {
    PlaySound(TEXT("loseSong.wav"),NULL, SND_FILENAME|SND_ASYNC|SND_LOOP);
    color(4);
    cout<<"\tHAI PERSO!\n\n\n\n";
    Sleep(100);
    color(7);
    digita("Questa volta e' andata male...chissa', magari una prossima volta sarai piu' fortunato/a!\n\n"); Sleep(700);
    cout<<"Premi un tasto per continuare. ";
    _getch();
    PlaySound(NULL, 0,0);
    system("CLS");
}

void post(Soldier* s2) {
    PlaySound(TEXT("intro.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    player->restoreHP();
    Sleep(700);
    Consumabile reward = allcures[rand()%7];
    digita("Vuoi raccogliere l'arma dell'avversario? (Arma: " + s2->getCW().getname() + "; Danno: "+ real_tostring(s2->getCW().getdamage())+")");
    Sleep(700);
    cout<<"\n\n\t1: La prendi.\n\t0: Non la prendi.\n\nScelta: ";
    bool willtake;
    cin>>willtake;
    cin.ignore();
    if(willtake){
        player->add_to_inventory(s2->getCW());
        digita("\nHai aggiunto l'arma all'inventario.\n");
    }
    else {
        digita("\nDecidi di non prenderla.\n");
    }
    cout<<"\n\n\n";
    Sleep(900);
    digita("Tra gli oggetti dell'avversario trovi "+reward.getname()+" (capacita' curativa: "+real_tostring(reward.getHPboost())+")\n\n");
    Sleep(700);
    cout<<"\n\t1: La prendi.\n\t0: Non la prendi.\n\nScelta: ";
    cin>>willtake;
    cin.ignore();
    if(willtake){
        player->add_to_inventory(reward);
        digita("\nHai aggiunto l'oggetto all'inventario.\n");
    }
    else {
        digita("\nDecidi di non prendere l'oggetto.\n");
    }
    digita("Premi un tasto per continuare. ");
    _getch();
}


#endif // FIGHTFUNCS_H_INCLUDED
