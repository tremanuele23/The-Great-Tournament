#include "classes.h"
int main()
{
    srand(time(0));


    cout<<"=================================================================================="<<endl<<"|";
    color(6);
    cout<<"\t\t\t\tTHE GREAT TOURNAMENT\t\t\t\t ";
    color(7);
    cout<<"|\n=================================================================================="<<endl;
    cout<<"\n\n\t\t\tPremi un tasto per continuare: ";
    int a = getch();
    system("CLS");
    digita("Benvenuto, giocatore! Desideri che ti spieghi i fondamenti del gioco? Digita 0 per saltare il tutorial. ");
    bool tutorial;
    cin>>tutorial;
    cin.ignore();
    system("CLS");
    if(tutorial) {
        color(6);  cout<<"\t\tINFORMAZIONI UTILI\n\n\n"; color(7);
        digita("Questo gioco e' un RPG a turni.\n", 1);
        digita("Per creare il tuo personaggio, potrai scegliere tra 7 classi diverse, ciascuna delle quali ha i suoi vantaggi e svantaggi.\n", 1);
        digita("Ogni giocatore dispone di un inventario, che alla creazione del personaggio e' ovviamente vuoto, e inizia a giocare con un arma di default che dipende dalla classe scelta.\n", 1);
        digita("Quando attacchi, infliggerai al nemico un colpo dal valore pari al danno dell'arma che impugni + un valore CASUALE generato in un intervallo i cui estremi cambiano per ciascuna classe.\n", 1);
        digita("Non c'e' molto altro da dire, avrai tutte le informazioni che ti serviranno per la scelta nella schermata successiva.", 1);
        cout<<"\n\n\n\n";
        digita("Premi un tasto per continuare: ");
        a = getch();
        system("CLS");
    }

    digita("E' arrivato il momento di creare il tuo personaggio.\n\n");
    Sleep(500);
    cout<<"Seleziona la classe:";
    cout<<"\n1. Cavaliere           { ATK Range: [-10; 15], Health Points = 180,       Arma iniziale: SPADA E SCUDO (30) }";
    cout<<"\n2. Spadaccino          { ATK Range: [-5; 10],  Health Points = 120,    Arma iniziale: SPADA A DUE MANI (35) }";
    cout<<"\n3. Fante               { ATK Range: [0; 7],    Health Points = 150,    Arma iniziale: SPADA A UNA MANO (25) }";
    cout<<"\n4. Combattente Pesante { ATK Range: [-20; 0],  Health Points = 100,  Arma iniziale: MARTELLO DA GUERRA (70) }";
    cout<<"\n5. Lanciere            { ATK Range: [-5; 15],  Health Points = 140,              Arma iniziale: LANCIA (45) }";
    cout<<"\n6. Alabardiere         { ATK Range: [-15; 7],  Health Points = 110,            Arma iniziale: ALABARDA (60) }";
    cout<<"\n7. Mercenario          { ATK Range: [10; 25],  Health Points = 150,         Arma iniziale: SPADA CORTA (15) }\n\n";
    Sleep(500);
    int choice;
    do
    {
        digita("Scelta: ");
        cin>>choice;
        cin.ignore();
    }
    while(choice<=0||choice>7);
    cout<<"\n\n\n\n";
    digita("Scelta registrata. Premi un tasto per procedere. ");
    a = getch();
    system("CLS");
    digita("Inserisci il nome del tuo personaggio: ");
    string g;
    getline(cin, g);
    cout<<"\n\n";
    digita("Nome acquisito. Premi un tasto per andare avanti.", 1);
    a = getch();
switch(choice) {
case 1:
    player = new Cavaliere(g);
    break;
case 2:
    player = new Spadaccino(g);
    break;
case 3:
    player = new Fante(g);
    break;
case 4:
    player = new Heavy(g);
    break;
case 5:
    player = new Lanciere(g);
    break;
case 6:
    player = new Alabardiere(g);
    break;
case 7:
    player = new Mercenario(g);
    break;
}
    system("CLS");
    digita("Personaggio Creato.\n\n\n");
    Sleep(500);

    player->msg(player->introduction());
    Sleep(500);
    cout<<endl<<endl;
    digita("Premi un tasto per continuare. ");
    a = getch();
    system("CLS");


    cout<<"================================="<<endl;Sleep(20);
    cout<<"|                               |"<<endl;Sleep(20);
    cout<<"|                               |"<<endl;Sleep(20);
    cout<<"|  Attenzione, guerriero!       |"<<endl;Sleep(20);
    cout<<"|                               |"<<endl;Sleep(20);
    cout<<"|                               |"<<endl;Sleep(20);
    cout<<"| L'Imperatore invita te ed     |"<<endl;Sleep(20);
    cout<<"| altri valorosi uomini d'arme  |"<<endl;Sleep(20);
    cout<<"| a prender parte al Torneo     |"<<endl;Sleep(20);
    cout<<"| che sancira' chi tra gli VIII |"<<endl;Sleep(20);
    cout<<"| migliori soldati delle vaste  |"<<endl;Sleep(20);
    cout<<"| terre Imperiali sara' il      |"<<endl;Sleep(20);
    cout<<"| degno erede del Feudo di      |"<<endl;Sleep(20);
    cout<<"| Aurocastro!                   |"<<endl;Sleep(20);
    cout<<"|                               |"<<endl;Sleep(20);
    cout<<"| Vieni a reclamare la tua      |"<<endl;Sleep(20);
    cout<<"| gloria, a dimostrare          |"<<endl;Sleep(20);
    cout<<"| il tuo valore!                |"<<endl;Sleep(20);
    cout<<"|                               |"<<endl;Sleep(20);
    cout<<"|                               |"<<endl;Sleep(20);
    cout<<"|                               |"<<endl;Sleep(20);
    cout<<"================================="<<endl;Sleep(500);

    cout<<"\n\n\n";
    digita("Decidi di partecipare senza la minima esitazione.",1);
    digita("Premi un tasto per continuare. "); a = getch();


    system("CLS");
    digita("Partecipanti al torneo (Fase 1)\n", 1);
    Sleep(200);
    int peop = 8;
    Soldier* avversario1;
    Soldier* avversario2;
    Soldier* avversario3;
    vector <string>listanomi;
    int randval;
    listanomi.push_back(player->getname());
    for(int i = 1; i<peop; i++) {
        randval=rand()%40;
        listanomi.push_back(allnames[randval]);
    }


    for(int i = 0; i<peop; i++) {
        cout<<i+1<<". "<<listanomi[i]<<endl;
        if((i+1)%2==0)
            cout<<endl;
        Sleep(50);
    }
    Sleep(230);
    digita("\nPremi un tasto per procedere. "); a = getch();
//nemico 1
    randval= rand()%7+1;
    switch(randval) {
    case 1:
        avversario1 = new Cavaliere(listanomi[1]);
        break;
    case 2:
        avversario1 = new Spadaccino(listanomi[1]);
        break;
    case 3:
        avversario1 = new Fante(listanomi[1]);
        break;
    case 4:
        avversario1 = new Heavy(listanomi[1]);
        break;
    case 5:
        avversario1 = new Lanciere(listanomi[1]);
        break;
    case 6:
        avversario1 = new Alabardiere(listanomi[1]);
        break;
    case 7:
        avversario1 = new Mercenario(listanomi[1]);
        break;
}
//nemico 2
    randval=rand()%7+1;
    switch(randval) {
            case 1:
                avversario2 = new Cavaliere("");
                break;
            case 2:
                avversario2 = new Spadaccino("");
                break;
            case 3:
                avversario2 = new Fante("");
                break;
            case 4:
                avversario2 = new Heavy("");
                break;
            case 5:
                avversario2 = new Lanciere("");
                break;
            case 6:
                avversario2 = new Alabardiere("");
                break;
            case 7:
                avversario2 = new Mercenario("");
                break;
        }
//nemico 3
    randval=rand()%7+1;
    switch(randval) {
            case 1:
                avversario3 = new Cavaliere("");
                break;
            case 2:
                avversario3 = new Spadaccino("");
                break;
            case 3:
                avversario3 = new Fante("");
                break;
            case 4:
                avversario3 = new Heavy("");
                break;
            case 5:
                avversario3 = new Lanciere("");
                break;
            case 6:
                avversario3 = new Alabardiere("");
                break;
            case 7:
                avversario3 = new Mercenario("");
                break;
        }

    cout<<endl<<endl;
    match(avversario1);
    if(player->HP>0) {
        listanomi.erase(listanomi.begin()+1);
        digita("Semifinale\n",1);
        randval=rand()%(2-1+1)+1;
        listanomi.erase(listanomi.begin()+randval);
        randval=rand()%(3-2+1)+2;
        listanomi.erase(listanomi.begin()+randval);
        randval=rand()%(5-4+1)+4;
        listanomi.erase(listanomi.begin()+randval);
        Sleep(200);
        peop/=2;
        for(int i = 0; i<peop; i++) {
            cout<<i+1<<". "<<listanomi[i]<<endl;
            if((i+1)%2==0)
                cout<<endl;
            Sleep(50);

        }
        Sleep(230);
        digita("\nPremi un tasto per procedere. ");
        a = getch();
        avversario2->setname(listanomi[1]);
        cout<<endl<<endl;
        match(avversario2);

        if(player->HP>0){
            listanomi.erase(listanomi.begin()+1);
            randval=rand()%(2-1+1)+1;
            listanomi.erase(listanomi.begin()+randval);
            peop/=2;
            digita("Finale");
            cout<<"\n\n";
            for(int i = 0; i<peop; i++) {
                cout<<i+1<<". "<<listanomi[i]<<endl;
                if((i+1)%2==0)
                cout<<endl;
            }
            avversario3->setname(listanomi[1]);
            Sleep(230);
            digita("\nPremi un tasto per procedere. ");
                a = getch();
                cout<<endl<<endl;
                match(avversario3);
                if(player->HP>0){
                    color(6);
                    cout<<"========================================="<<endl;Sleep(20);
                    cout<<"|                                       |"<<endl;Sleep(20);
                    cout<<"|                                       |"<<endl;Sleep(20);
                    cout<<"| 'Congratulazioni a te, o vittorioso!  |"<<endl;Sleep(20);
                    cout<<"|                                       |"<<endl;Sleep(20);
                    cout<<"|                                       |"<<endl;Sleep(20);
                    cout<<"|   Hai dato prova delle tue virtu' in  |"<<endl;Sleep(20);
                    cout<<"|   battaglia e della tua audacia!      |"<<endl;Sleep(20);
                    cout<<"|   Per questo motivo l'imperatore ha   |"<<endl;Sleep(20);
                    cout<<"|   deciso di concederti il titolo      |"<<endl;Sleep(20);
                    cout<<"|   di Duca di Aurocastro, con il       |"<<endl;Sleep(20);
                    cout<<"|   diritto a tutti i suoi vigneti,     |"<<endl;Sleep(20);
                    cout<<"|   il suo bestiame ed il mare pescoso! |"<<endl;Sleep(20);
                    cout<<"|   Che il futuro possa portare a te,   |"<<endl;Sleep(20);
                    cout<<"|   o prode guerriero, le piu' alte     |"<<endl;Sleep(20);
                    cout<<"|   glorie!                             |"<<endl;Sleep(20);
                    cout<<"|                                       |"<<endl;Sleep(20);
                    cout<<"|                                       |"<<endl;Sleep(20);
                    cout<<"|                                       |"<<endl;Sleep(20);
                    cout<<"|                                       |"<<endl;Sleep(20);
                    cout<<"========================================="<<endl;Sleep(500);
                    color(7);
                    a=getch();
                    system("CLS");
                }
        }
    }
    cout<<"================================================================================="<<endl<<"|";
    color(6);
    cout<<"\t\t\t      Grazie per aver giocato a: \t\t\t";color(7);cout<<"|\n|";
    color(6);cout<<"\t\t\t\tTHE GREAT TOURNAMENT\t\t\t\t";
    color(7);
    cout<<"|\n================================================================================="<<endl;
    delete player;
    delete avversario1;
    delete avversario2;
    cout<<"\nPremi un tasto per chiudere. ";
    a = getch();
    return 0;
}
