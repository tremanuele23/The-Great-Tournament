#include "classes.h"
#include "fightFuncs.h"
    Soldier* avversario1;
    Soldier* avversario2;
    Soldier* avversario3;
int main()
{

    srand(time(0));
    cout<<"=================================================================================="<<endl<<"|";
    color(6);
    cout<<"\t\t\t\tTHE GREAT TOURNAMENT\t\t\t\t ";
    color(7);
    cout<<"|\n=================================================================================="<<endl;
    cout<<"\n\n\t\t\tPremi un tasto per iniziare: ";
    _getch();
    system("CLS");
    PlaySound("intro.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    digita("Benvenuto, giocatore! Desideri che ti spieghi i fondamenti del gioco? Digita 0 per leggere il tutorial. ");
    int tutorial;
    cin>>tutorial;
    cin.ignore();
    system("CLS");
    if(tutorial==0) {
        color(6);
        cout<<"\t\tINFORMAZIONI UTILI\n\n\n"; color(7);
        cout<<"Questo gioco e' un RPG a turni. "; _getch();
        cout<<"\nPer creare il tuo personaggio, potrai scegliere tra 7 classi diverse, ciascuna delle quali ha i suoi vantaggi e svantaggi. "; _getch();
        cout<<"\nOgni giocatore dispone di un inventario, che al momento della creazione e' ovviamente vuoto, e inizia a giocare con un arma di default che dipende dalla classe scelta. "; _getch();
        cout<<"\nQuando attacchi, infliggerai al nemico un colpo dal valore pari al danno dell'arma che impugni moltiplicato un valore che dipende da quanti click riesci a fare nell'intervallo di tempo d'attacco moltiplicato a sua volta per un fattore che varia per ciacuna classe. "; _getch();
        cout<<"\nNon c'e' molto altro da dire, avrai tutte le informazioni che ti serviranno per la scelta nella schermata successiva.";
        cout<<"\n\n\n\n";
        digita("Premi un tasto per continuare: ");
        _getch();
        system("CLS");
    }
    if(tutorial==1926) {
        PlaySound(0, NULL, 0);
        digita("Forza Napoli. Il tuo amore per il Napoli ti ha garantito l'accesso al ");
        color(6);
        Sleep(400);
        digita("tutorial pratico");
        color(7);
        digita(".");
        Sleep(400);
        digita("\n\nPremi un tasto per continuare: ");
        _getch();
        player=new Cavaliere("Manu");
        avversario1 = new Heavy("Frocho il Pesante");
        match(avversario1, "battle.wav");
        if(player->HP>0)
            post(avversario1);
        system("CLS");
    }

    if(tutorial!=1926) {

        digita("E' arrivato il momento di creare il tuo personaggio.\n\n");
        Sleep(500);
        cout<<"Seleziona la classe:";
        cout<<"\n1. Cavaliere           { Health Points = 180,  Arma iniziale: SPADA E SCUDO (25) }";
        cout<<"\n2. Spadaccino          { Health Points = 120,  Arma iniziale: SPADA A DUE MANI (35) }";
        cout<<"\n3. Fante               { Health Points = 150,  Arma iniziale: SPADA A UNA MANO (30) }";
        cout<<"\n4. Combattente Pesante { Health Points = 100,  Arma iniziale: MARTELLO DA GUERRA (70) }";
        cout<<"\n5. Lanciere            { Health Points = 140,  Arma iniziale: LANCIA (45) }";
        cout<<"\n6. Alabardiere         { Health Points = 110,  Arma iniziale: ALABARDA (60) }";
        cout<<"\n7. Mercenario          { Health Points = 150,  Arma iniziale: SPADA CORTA (15) }\n\n";
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
        _getch();
        system("CLS");
        digita("Inserisci il nome del tuo personaggio: ");
        string g;
        getline(cin, g);
        cout<<"\n\n";
        digita("Nome acquisito. Premi un tasto per andare avanti: ");
        _getch();
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
        _getch();
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
        digita("Vuoi partecipare al torneo?\n\t[1]: SI! SI! SI!\n\t[0]: Non mi va.\nRisposta: ");
        bool ans;
        cin>>ans;
        if(ans)
            digita("\n\nDecidi di partecipare senza la minima esitazione.",1);
        else
            digita("\n\nFanculo partecipi lo stesso.",1);
        digita("Premi un tasto per continuare. "); _getch();


        system("CLS");
        digita("Partecipanti al torneo (Fase 1)\n", 1);
        Sleep(200);
        int peop = 8;
        vector <string> listanomi;
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
        digita("\nPremi un tasto per procedere. "); _getch();
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
        cout<<endl<<endl;
        match(avversario1, "battle.wav");
        if(player->HP>0) {
            post(avversario1);
            system("CLS");
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
            _getch();
            randval=rand()%7+1;
        switch(randval) {
                case 1:
                    avversario2 = new Cavaliere(listanomi[1]);
                    break;
                case 2:
                    avversario2 = new Spadaccino(listanomi[1]);
                    break;
                case 3:
                    avversario2 = new Fante(listanomi[1]);
                    break;
                case 4:
                    avversario2 = new Heavy(listanomi[1]);
                    break;
                case 5:
                    avversario2 = new Lanciere(listanomi[1]);
                    break;
                case 6:
                    avversario2 = new Alabardiere(listanomi[1]);
                    break;
                case 7:
                    avversario2 = new Mercenario(listanomi[1]);
                    break;
            }
            cout<<endl<<endl;
            match(avversario2, "battle.wav");

            if(player->HP>0){
                post(avversario2);
                listanomi.erase(listanomi.begin()+1);
                randval=rand()%(2-1+1)+1;
                listanomi.erase(listanomi.begin()+randval);
                peop/=2;

                randval=rand()%7+1;
                switch(randval) {
                    case 1:
                        avversario3 = new Cavaliere(listanomi[1]);
                        break;
                    case 2:
                        avversario3 = new Spadaccino(listanomi[1]);
                        break;
                    case 3:
                        avversario3 = new Fante(listanomi[1]);
                        break;
                    case 4:
                        avversario3 = new Heavy(listanomi[1]);
                        break;
                    case 5:
                        avversario3 = new Lanciere(listanomi[1]);
                        break;
                    case 6:
                        avversario3 = new Alabardiere(listanomi[1]);
                        break;
                    case 7:
                        avversario3 = new Mercenario(listanomi[1]);
                        break;
                }
                system("CLS");
                digita("Finale");
                cout<<"\n\n";
                for(int i = 0; i<peop; i++) {
                    cout<<i+1<<". "<<listanomi[i]<<endl;
                    if((i+1)%2==0)
                    cout<<endl;
                }
                Sleep(230);
                digita("\nPremi un tasto per procedere. ");
                _getch();
                cout<<endl<<endl;
                match(avversario3, "finalBattle.wav");
                if(player->HP>0){
                    post(avversario3);
                    system("CLS");
                    PlaySound(NULL, 0, NULL);

                    color(6);
                    cout<<"=========================================="<<endl;Sleep(20);
                    cout<<"|                                        |"<<endl;Sleep(20);
                    cout<<"|                                        |"<<endl;Sleep(20);
                    cout<<"| 'Congratulazioni a te, prode guerriero!|"<<endl;Sleep(20);
                    cout<<"|                                        |"<<endl;Sleep(20);
                    cout<<"|                                        |"<<endl;Sleep(20);
                    cout<<"|   Hai dato prova delle tue virtu' in   |"<<endl;Sleep(20);
                    cout<<"|   battaglia e della tua audacia!       |"<<endl;Sleep(20);
                    cout<<"|   Per questo motivo l'imperatore ha    |"<<endl;Sleep(20);
                    cout<<"|   deciso di concederti il titolo       |"<<endl;Sleep(20);
                    cout<<"|   di Duca di Aurocastro, con il        |"<<endl;Sleep(20);
                    cout<<"|   diritto a tutti i suoi vigneti,      |"<<endl;Sleep(20);
                    cout<<"|   il suo bestiame ed il mare pescoso!  |"<<endl;Sleep(20);
                    cout<<"|   Che il futuro possa portare a te,    |"<<endl;Sleep(20);
                    cout<<"|   o prode guerriero, le piu' alte      |"<<endl;Sleep(20);
                    cout<<"|   glorie!                              |"<<endl;Sleep(20);
                    cout<<"|                                        |"<<endl;Sleep(20);
                    cout<<"|                                        |"<<endl;Sleep(20);
                    cout<<"|                                        |"<<endl;Sleep(20);
                    cout<<"|                                        |"<<endl;Sleep(20);
                    cout<<"|                                        |"<<endl;Sleep(20);
                    cout<<"|                                        |"<<endl;Sleep(20);
                    cout<<"|                                        |"<<endl;Sleep(20);
                    cout<<"|                                        |"<<endl;Sleep(20);
                    cout<<"=========================================="<<endl;Sleep(500);
                    color(7);
                    cout<<"\n\nPremi un tasto per continuare: ";
                    _getch();
                    system("CLS");

                } //if won fight 3
            } //if won fight 2
        } //if won fight 1
    } //if played normal game
    if(player->HP<=0) {
        lost();

    }
    cout<<"================================================================================="<<endl<<"|";
    color(6);
    cout<<"\t\t\t      Grazie per aver giocato a: \t\t\t";
    color(7);
    cout<<"|\n|";
    color(6);
    cout<<"\t\t\t\tTHE GREAT TOURNAMENT\t\t\t\t";
    color(7);
    cout<<"|\n================================================================================="<<endl;

    cout<<"\nPremi un tasto per chiudere. ";
    _getch();
    delete player;
    delete avversario1;
    delete avversario2;
    delete avversario3;
    return 0;
}
