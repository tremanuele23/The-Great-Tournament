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
    cout<<"Benvenuto, giocatore! E' arrivato il momento di creare il tuo personaggio.\n\n";

    cout<<"Seleziona la classe:\n1. Cavaliere\n2. Spadaccino\n3. Fante\n4. Combattente Pesante\n5. Lanciere\n6. Alabardiere\n7. Mercenario\n\n";
    int choice;
    do
    {
        cout<<"Scelta: ";
        cin>>choice;
        cin.ignore();
    }
    while(choice<=0||choice>7);
    cout<<"\n\n\n\nOttima scelta. Premi un tasto per procedere. ";
    a = getch();
    system("CLS");
    cout<<"Inserisci il nome del tuo personaggio: ";
    string g;
    getline(cin, g);
    cout<<"\n\nNome acquisito. Premi un tasto per andare avanti. \n";
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
    cout<<"Personaggio Creato.\n\n\n";


    player->msg(player->introduction());

    cout<<endl<<endl<<"Premi un tasto per continuare. ";
    a = getch();
    system("CLS");


    cout<<"================================="<<endl;
    cout<<"|                               |"<<endl;
    cout<<"|                               |"<<endl;
    cout<<"|  Attenzione, guerriero!       |"<<endl;
    cout<<"|                               |"<<endl;
    cout<<"|                               |"<<endl;
    cout<<"| L'Imperatore invita te ed     |"<<endl;
    cout<<"| altri III valorosi uomini     |"<<endl;
    cout<<"| d'arme a prender parte al     |"<<endl;
    cout<<"| Torneo che sancira' il degno  |"<<endl;
    cout<<"| erede al trono del ducato     |"<<endl;
    cout<<"| di Sassonia!                  |"<<endl;
    cout<<"|                               |"<<endl;
    cout<<"| Vieni a reclamare la tua      |"<<endl;
    cout<<"| gloria, a dimostrare          |"<<endl;
    cout<<"| il tuo valore!                |"<<endl;
    cout<<"|                               |"<<endl;
    cout<<"|                               |"<<endl;
    cout<<"|                               |"<<endl;
    cout<<"================================="<<endl;

    cout<<"\n\n\nDecidi di partecipare senza la minima esitazione.\n";
    cout<<"Premi un tasto per continuare. "; a = getch();


    system("CLS");
    cout<<"Partecipanti al torneo (Fase 1)\n"<<endl;

    Soldier* avversario1;
    Soldier* avversario2;
    string listanomi[4];
    int randval;
    listanomi[0] = player->getname();
    for(int i = 1; i<4; i++) {
        randval=rand()%40;
        listanomi[i] = allnames[randval];
    }


    for(int i = 0; i<4; i++) {
        cout<<i+1<<". "<<listanomi[i]<<endl;
        if((i+1)%2==0)
            cout<<endl;

    }
    cout<<"\nPremi un tasto per procedere. "; a = getch();
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
    randval=rand()%(3-2+1)+2;
    string giannipass= listanomi[randval];
        randval=rand()%7+1;
          switch(randval) {
            case 1:
                avversario2 = new Cavaliere(giannipass);
                break;
            case 2:
                avversario2 = new Spadaccino(giannipass);
                break;
            case 3:
                avversario2 = new Fante(giannipass);
                break;
            case 4:
                avversario2 = new Heavy(giannipass);
                break;
            case 5:
                avversario2 = new Lanciere(giannipass);
                break;
            case 6:
                avversario2 = new Alabardiere(giannipass);
                break;
            case 7:
                avversario2 = new Mercenario(giannipass);
                break;
        }
    cout<<endl<<endl;
    match(avversario1);
    if(player->HP>0) {
        cout<<"Finale\n"<<endl;
        cout<<"\n1. "<<player->getname();
        cout<<"\n2. "<<giannipass<<endl<<endl;
        cout<<"\nPremi un tasto per procedere. ";
        a = getch();
        cout<<endl<<endl;
        match(avversario2);

        if(player->HP>0){
            color(6);
            cout<<"========================================="<<endl;
            cout<<"|                                       |"<<endl;
            cout<<"|                                       |"<<endl;
            cout<<"| 'Congratulazioni a te, o vittorioso!  |"<<endl;
            cout<<"|                                       |"<<endl;
            cout<<"|                                       |"<<endl;
            cout<<"|   Hai dato prova delle tue virtu' in  |"<<endl;
            cout<<"|   battaglia e della tua audacia!      |"<<endl;
            cout<<"|   Per questo motivo l'imperatore ha   |"<<endl;
            cout<<"|   deciso di concederti il titolo      |"<<endl;
            cout<<"|   di Duca di Sassonia!                |"<<endl;
            cout<<"|   Che il futuro possa portare a te,   |"<<endl;
            cout<<"|   o prode guerriero, le piu' alte     |"<<endl;
            cout<<"|   glorie!                             |"<<endl;
            cout<<"|                                       |"<<endl;
            cout<<"|                                       |"<<endl;
            cout<<"|                                       |"<<endl;
            cout<<"|                                       |"<<endl;
            cout<<"========================================="<<endl;
            color(7);
            a=getch();
            system("CLS");


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
