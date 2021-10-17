#include "Game.h"

//NOT: DEV-C++'ta müzik fonksiyonu hata verdiği için yoruma alınmıştır.

int main() {

    int j,i, hafta = 0;
    char islem = '0';
  //PlaySound(TEXT("survivor.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    system("color 3");
    string team = "KYKSPOR";//Geçici takim
    Leauge lig1("FM KYK", 8, team);
    lig1.Teamprint();
    cout << "\n\n\n\n\n\n                      Sececeginiz takimin adini giriniz: ";
    cin >> team;
    lig1.chooseTeam(team);
//  PlaySound(TEXT("uefasong.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    while (hafta < 14) {
    a:
        system("PAUSE");
        system("cls");
        cout << *lig1.getMyTeam() << endl;
        if (hafta == 0 || hafta == 7) {
            cout << "1:Mac yaptir ve bir sonraki haftaya gec\n2:Antreman yaptir\n3:Transfer Yap\n9:Oyunu bitir\nYapmak istediginiz islemi seciniz:";
        }
        else
            cout << "1:Mac yaptir ve bir sonraki haftaya gec\n2:Antreman yaptir\n9:Oyunu bitir\nYapmak istediginiz islemi seciniz:";
        cin >> islem;
        system("cls");
        switch (islem) {
        case '1':
            cout << hafta + 1 << ". HAFTA" << endl;
            hafta++;
            lig1.kura2();
            cout << "BU HAFTANIN MACLARI\n------------------" << endl;
            for (j = 0; j < lig1.getSize(); j += 2) {
                cout << lig1.getTeam()[j].getName() << "-" << lig1.getTeam()[j+1].getName() << endl;
            }
            system("PAUSE");
            for (j = 0; j < lig1.getSize(); j += 2) {
                cout<<endl;
                lig1.macYap(lig1.getTeam()[j], lig1.getTeam()[j + 1]);
            }
            cout << endl << lig1 << endl;
            cout << "GOL SIRALAMASI" << endl;
            lig1.golSiralama();
            break;
        case '2':
            lig1.antreman();
            break;
        case '3':
            lig1.transfer();
            break;
        case '9':
            hafta = 14;
            break;
        default:
            cout << "Boyle bir secenek yoktur.Lutfen tekrar seciniz.\n";
            goto a;
        }
    }
    
    Team* finalList = new Team[lig1.getSize()];
    finalList = lig1.siralama();
    cout << endl << "FINAL PUAN SIRALAMASI" << endl;
    for (i = 0; i < lig1.getSize(); i++) {
        cout <<(i+1)<<"-) "<< finalList[i].getName() << " - "<< finalList[i].getPuan() << endl;
    }
    cout << endl << "********************** SAMPIYON **********************\n";
    cout <<"                      " << finalList[0].getName() << endl;

    system("Pause");
    return 0;
}
