#include "Game.h"

ostream& operator<<(ostream& os, Leauge& lig) {
	int i;
	os << lig.getName() << " Leauge:" << endl << "-------------------------------------------" << endl;
	for (i = 0; i < lig.getSize(); i++) {
		os << lig.teamList[i].getName() << " ->" << lig.teamList[i].getPow() << ", Point:" << lig.teamList[i].getPuan() << endl;
	}
	os << endl;
	return os;
}
Leauge::Leauge(string name = "-", int num = 1, string team = "-") {
	setLeauge(name, num, team);
}
void Leauge::setLeauge(string name = "-", int num = 1, string team = "-") {
	this->name = name;
	this->size = num;
	teamList = new Team[num];
	//TEAMS
	Player GALATASARAY[5];
	GALATASARAY[0].setPlayer("Fernando Muslera", "GALATASARAY", 69, 92);
	GALATASARAY[1].setPlayer("Radamel Falcao", "GALATASARAY", 91, 49);
	GALATASARAY[2].setPlayer("Mario Lemina", "GALATASARAY", 75, 71);
	GALATASARAY[3].setPlayer("Mariano Ferreira", "GALATASARAY", 87, 87);
	GALATASARAY[4].setPlayer("Younes Belhanda", "GALATASARAY", 77, 59);
	Player FENERBAHCE[5];
	FENERBAHCE[0].setPlayer("Altay Bayindir", "FENERBAHCE", 23, 69);
	FENERBAHCE[1].setPlayer("Serdar Aziz", "FENERBAHCE", 41, 77);
	FENERBAHCE[2].setPlayer("Luiz Gustavo", "FENERBAHCE", 83, 92);
	FENERBAHCE[3].setPlayer("Max Kruse", "FENERBAHCE", 82, 45);
	FENERBAHCE[4].setPlayer("Vedat Muriqi", "FENERBAHCE", 72, 33);
	Player BESIKTAS[5];
	BESIKTAS[0].setPlayer("Loris Karius", "BESIKTAS", 54, 82);
	BESIKTAS[1].setPlayer("Domagoj Vida", "BESIKTAS", 47, 83);
	BESIKTAS[2].setPlayer("Mohamed Elneny", "BESIKTAS", 73, 80);
	BESIKTAS[3].setPlayer("Adem Ljajic", "BESIKTAS", 83, 43);
	BESIKTAS[4].setPlayer("Burak Yilmaz", "BESIKTAS", 79, 39);
	Player KYKSPOR[5];
	KYKSPOR[0].setPlayer("Furkan Kucuk", "KYKSPOR", 60, 75);
	KYKSPOR[1].setPlayer("Asim Uyanik", "KYKSPOR", 76, 75);
	KYKSPOR[2].setPlayer("Serkan Eren", "KYKSPOR", 80, 82);
	KYKSPOR[3].setPlayer("Oguzhan Tokuc", "KYKSPOR", 84, 82);
	KYKSPOR[4].setPlayer("Ebubekir Senoglu", "KYKSPOR", 77, 73);
	Player TRABZONSPOR[5];
	TRABZONSPOR[0].setPlayer("Ugurcan Cakir", "TRABZONSPOR", 55, 76);
	TRABZONSPOR[1].setPlayer("Filip NovAk", "TRABZONSPOR", 69, 72);
	TRABZONSPOR[2].setPlayer("Badou Ndiaye", "TRABZONSPOR", 73, 80);
	TRABZONSPOR[3].setPlayer("Jose Sosa", "TRABZONSPOR", 89, 81);
	TRABZONSPOR[4].setPlayer("Alexander Sorlorth", "TRABZONSPOR", 91, 53);
	Player BASAKSEHIR[5];
	BASAKSEHIR[0].setPlayer("Mert Gunok", "BASAKSEHIR", 57, 75);
	BASAKSEHIR[1].setPlayer("Gael Clichy", "BASAKSEHIR", 71, 86);
	BASAKSEHIR[2].setPlayer("Irfan Can Kahveci", "BASAKSEHIR", 73, 80);
	BASAKSEHIR[3].setPlayer("Edin Visca", "BASAKSEHIR", 91, 59);
	BASAKSEHIR[4].setPlayer("Enzo Crivelli", "BASAKSEHIR", 72, 35);
	Player SIVASSPOR[5];
	SIVASSPOR[0].setPlayer("Mamadou Samassa", "SIVASSPOR", 56, 76);
	SIVASSPOR[1].setPlayer("Goiano", "SIVASSPOR", 63, 75);
	SIVASSPOR[2].setPlayer("Claudemir", "SIVASSPOR", 70, 72);
	SIVASSPOR[3].setPlayer("Yasin Öztekin", "SIVASSPOR", 73, 48);
	SIVASSPOR[4].setPlayer("Kone", "SIVASSPOR", 73, 40);
	Player ALANYASPOR[5];
	ALANYASPOR[0].setPlayer("Marafona", "ALANYASPOR", 37, 74);
	ALANYASPOR[1].setPlayer("Baiano", "ALANYASPOR", 66, 72);
	ALANYASPOR[2].setPlayer("Djalma", "ALANYASPOR", 78, 53);
	ALANYASPOR[3].setPlayer("Demba Cisse", "ALANYASPOR", 91, 51);
	ALANYASPOR[4].setPlayer("Junior Fernandes", "ALANYASPOR", 75, 38);
	
	teamList[0].setTeam("GALATASARAY", GALATASARAY, 5);
	teamList[1].setTeam("FENERBAHCE", FENERBAHCE, 5);
	teamList[2].setTeam("BESIKTAS", BESIKTAS, 5);
	teamList[3].setTeam("KYKSPOR", KYKSPOR, 5);
	teamList[4].setTeam("TRABZONSPOR", TRABZONSPOR, 5);
	teamList[5].setTeam("BASAKSEHIR", BASAKSEHIR, 5);
	teamList[6].setTeam("SIVASSPOR", SIVASSPOR, 5);
	teamList[7].setTeam("ALANYASPOR", ALANYASPOR, 5);
	chooseTeam(team);
}
void Leauge::chooseTeam(string name) {
	int i,sayac=0;
	harfBuyut(name);
	for (i = 0; i < size; i++) {
		if (teamList[i].getName().compare(name) == 0) {
			Team temp(teamList[0]);
			teamList[0] = teamList[i];
			teamList[i] = temp;
			sayac=1;
		}
	}
	if(sayac==0){
		cout<<endl <<"BOYLE BIR TAKIM YOK TEKRAR DENEYIN!!"<<endl;
		string name2="kykspor";
		cin>>name2;
		chooseTeam(name2);
	}
	myTeam = teamList;
}
Team& Leauge::kimAtti(Team& team1, Team& team2,int team1gol,int team2gol) {
	
	int i, j, temp1, temp2;
	//falcao(4), lemina(2)
	cout <<team1.getName() <<"------------------\n";
	for (i = 0; i <team1gol; i++) {
		temp1 = team1.getPlayerList()[0].getAttack();
		int ihtimal1;// = rand() % (team1.getAttack() * team1.getSize());
		ihtimal1 = team1.getPlayerList()[0].getAttack() + (rand() % static_cast<int>(team1.getAttack() * team1.getSize() - team1.getPlayerList()[0].getAttack()));
	
		for (j = 1; j < team1.getSize() ; j++) {
			if (ihtimal1 < temp1 + team1.getPlayerList()[j].getAttack()) {
				cout << team1.getPlayerList()[j].getName() << " , ";
				team1.getPlayerList()[j].golAttir();
				j = team1.getSize();//Döngüden çýkmasý için
			}
			else {	
				temp1 += team1.getPlayerList()[j].getAttack();
			}
		}
	}
	cout << endl <<team2.getName() <<"------------------\n";
	for (i = 0; i < team2gol; i++) {
		temp2 = team2.getPlayerList()[0].getAttack();
		int ihtimal2;// = rand() % (team2.getAttack() * team2.getSize());//Random
		ihtimal2 = team2.getPlayerList()[0].getAttack() +(rand() % static_cast<int>(team2.getAttack() * team2.getSize() - team2.getPlayerList()[0].getAttack()));
		
		for (j = 1; j < team2.getSize(); j++) {
			if (ihtimal2 < temp2 + team2.getPlayerList()[j].getAttack()) {
				cout << team2.getPlayerList()[j].getName() << " , ";
				team2.getPlayerList()[j].golAttir();
				j = team2.getSize();
			}
			else {
				temp2 += team2.getPlayerList()[j].getAttack();
			}
		}
	}
	cout<<endl;
	return team1;//önemsiz
}
Team& Leauge::macYap(Team& team1, Team& team2) {
	int i;
	team1.getAttack();
	team1.getDef();
	team2.getAttack();
	team2.getDef();
	int team1gol = 0;
	int team2gol = 0;
	int toplamGol = 0;

	for (i = 0; i < size; i++) {
		int sayi = (rand() % static_cast<int>(team1.getAttack() + team2.getDef()));
		if (sayi <= team1.getAttack()) {
			team1gol++;
		}
		sayi = (rand() % static_cast<int>(team2.getAttack() + team1.getDef()));
		if (sayi <= team2.getAttack()) {
			team2gol++;
		}
	}
	toplamGol = team1gol + team2gol;
	if (team2gol < team1gol) {
		cout << team1.getName() << " " << team1gol << " - " << team2gol << " " << team2.getName() << endl;
		team1.winMatch();
		kimAtti(team1,team2,team1gol,team2gol);
		return team1;
	}
	else if (team2gol == team1gol) {
		team1.berabere();
		team2.berabere();
		cout << team1.getName() << " " << team1gol << " - " << team2gol << " " << team2.getName() << endl;
		kimAtti(team1,team2,team1gol,team2gol);
	}
	else {
		cout << team2.getName() << " " << team2gol << " - " << team1gol << " " << team1.getName() << endl;
		team2.winMatch();
		kimAtti(team2,team1,team2gol,team1gol);
		return team2;
	}
	
	
	return team1;//Bi önemi yok
}


int** Leauge::kura() {
	

	int** temp = new int * [7];
	for (int i = 0; i < 7; ++i)
		temp[i] = new int[8];
	
	int tempList[8];
	int atamaList[8];
	for (int i = 0; i < 8; i++) {
		tempList[i] = i;
		atamaList[i] = i;
	}

	
	
	for (int i = 0; i < 7; i++) {
		tempList[0] = atamaList[0];
		tempList[1] = atamaList[3];
		tempList[2] = atamaList[1];
		tempList[3] = atamaList[5];
		tempList[4] = atamaList[2];
		tempList[5] = atamaList[7];
		tempList[6] = atamaList[4];
		tempList[7] = atamaList[6];
		for (int j = 0; j < 8; j++) {
			temp[i][j] = tempList[j];
			atamaList[j] = tempList[j];
		}
		
	}

	return temp;



}
Team* Leauge::kura2()
{
	int i;
	string name;
	name = myTeam->getName();
	Team* temp = new Team[size];
	temp[0] = teamList[0];
	temp[1] = teamList[3];
	temp[2] = teamList[1];
	temp[3] = teamList[5];
	temp[4] = teamList[2];
	temp[5] = teamList[7];
	temp[6] = teamList[4];
	temp[7] = teamList[6];
	for (i = 0; i < getSize(); i++) {
		teamList[i] = temp[i];
	}
	chooseTeam(name);

	return teamList;
}


void Leauge::transfer() {
	system("cls");
	fflush(stdin);
	string player, takim;
	//Player gecici;

	int i, j, option, sayac = 0;
	cout << *getMyTeam() << endl;
	cout << "---------- TRANSFER DONEMI ----------" << endl << "1-Baska takimdan oyuncu transfer et" << endl << "2-Benim takimimdan oyuncu transfer et";
	cout << endl << "3-Takimima yeni bir oyuncu ekle" << endl << "4-Takim sec ve oyuncularini goster" << endl << "5-Transferi sonlandir\n"<<"Yapmak istediginiz islemi seciniz:" << endl;
	fflush(stdin);
	cin >> option;

	switch (option) {
	case 1:
		cin.ignore();
		cout << "Transfer yapilacak oyuncu tam adini giriniz" << endl;
		getline(cin, player);
		oyuncuAdDuzenle(player);
		sayac = 0;
		for (i = 0; i < this->size; i++) {
			for (j = 0; j < teamList[i].getSize(); j++) {
				if (player.compare(teamList[i].getPlayerList()[j].getName()) == 0) {
					if (teamList[i].getSize() <= 3) {
						cout << "Seçtiðiniz oyuncunun takiminda 3 veya daha az oyuncu bulunduðundan bu takimdan transfer gerçekleþtirilemedi.." << endl;
						goto a;
					}
					Player gecici = teamList[i].deletePlayer(player);
					getMyTeam()->addPlayer(gecici.getName(), gecici.getDef(), gecici.getAttack());
					sayac++;
				}
			}
		}
		if (sayac == 0) {
			cout << "Boyle bir oyuncu bulunmamaktadir!" << endl;
		}
		a:
		transfer();
		break;
	case 2:
		cin.ignore();
		if (getMyTeam()->getSize() <= 3) {
			cout << "Takim oyuncu sayisi 3 veya daha az oldugu icin bu takimdan oyuncu transfer edilemez.." << endl;
			transfer();
		}
		else {
			cout << "Transfer yapilacak oyuncu tam adini giriniz" << endl;
			getline(cin, player);
			oyuncuAdDuzenle(player);
			Player gecici = getMyTeam()->deletePlayer(player);
			cout << "Enter team name" << endl;
			cin >> takim;
			harfBuyut(takim);
			sayac = 0;
			for (i = 0; i < this->size; i++) {
				if (takim.compare(teamList[i].getName()) == 0) {
					teamList[i].addPlayer(gecici.getName(), gecici.getDef(), gecici.getAttack());
					cout << teamList[i];
					sayac++;
				}
			}
			if (sayac == 0) {
				cout << "Boyle bir oyuncu bulunmamaktadir!" << endl;
			}
			cout << *getMyTeam();
		}
		transfer();
		break;
	case 3:
		cin.ignore();
		cout << "Eklenecek olan oyuncu tam adini giriniz" << endl;
		getline(cin, player);
		oyuncuAdDuzenle(player);
		cout << "Yeni oyuncu adi: " << player << endl << "Oyuncunun defans ve atak gucunu giriniz.." << endl;
		cin >> i >> j;
		getMyTeam()->addPlayer(player, i, j);
		cout << *getMyTeam();
		transfer();
		break;
	case 4:
		cout << "Oyunculari gosterilecek takimi seciniz.." << endl;
		cin >> takim;
		harfBuyut(takim);
		sayac = 0;
		for (i = 0; i < this->size; i++) {
			if (teamList[i].getName().compare(takim) == 0) {
				cout << teamList[i];
				sayac++;
			}
		}
		if (sayac == 0) {
			cout << "Boyle bir takim bulunmamaktadir!" << endl;
		}
		transfer();
		break;
	case 5:
		cout << "Transfer yapilmayacak.." << endl;
		break;
	default:
		cout << "Hatali secim yaptýnýz.." << endl;
		transfer();
		break;
	}

}
void Leauge::antreman() {//ASIM UYANIK
	int islem, i;
	cout << "1:DEFANS\n2:ATAK\n3:GENEL\n4:AGIR\nYapmak istediginiz antreman turunu seciniz:";
	cin >> islem;
	switch (islem) {
	case 1:
		for (i = 0; i < myTeam->getSize(); i++) {
			myTeam->getPlayerList()[i].setDef(myTeam->getPlayerList()[i].getDef() + 2);
		}
		myTeam->setPow(myTeam->getDef() + 2, myTeam->getAttack());
		cout << "TAKIMINIZIN DEFANS GUCU ARTTIRILDI.\n";
		break;



	case 2:
		for (i = 0; i < myTeam->getSize(); i++) {
			myTeam->getPlayerList()[i].setAttack(myTeam->getPlayerList()[i].getAttack() + 2);
		}
		myTeam->setPow(myTeam->getDef(), myTeam->getAttack() + 2);
		cout << "TAKIMINIZIN ATAK GUCU ARTTIRILDI.\n";
		break;
	case 3:
		for (i = 0; i < myTeam->getSize(); i++) {
			myTeam->getPlayerList()[i].setDef(myTeam->getPlayerList()[i].getDef() + 1);
			myTeam->getPlayerList()[i].setAttack(myTeam->getPlayerList()[i].getAttack() + 1);
		}
		myTeam->setPow(myTeam->getDef() + 1, myTeam->getAttack() + 1);



		cout << "TAKIMINIZIN DEFANS VE ATAK GUCU ARTTIRILDI.\n";
		break;
	case 4:
		int ihtimal = rand() % (50);
		if (ihtimal < 25) {
			cout << "OYUNCULARINIZDA SAKATLIK OLUSTU VE GUCLERI AZALDI!";
			for (i = 0; i < myTeam->getSize(); i++) {
				myTeam->getPlayerList()[i].setDef(myTeam->getPlayerList()[i].getDef() - 3);
				myTeam->getPlayerList()[i].setAttack(myTeam->getPlayerList()[i].getAttack() - 3);
			}
			myTeam->setPow(myTeam->getDef() - 3, myTeam->getAttack() - 3);
		}
		else {
			cout << "OYUNCULARINIZIN DEFANS VE ATAK GUCLERI EKSTRA ARTTIRILDI.";
			for (i = 0; i < myTeam->getSize(); i++) {
				myTeam->getPlayerList()[i].setDef(myTeam->getPlayerList()[i].getDef() + 3);
				myTeam->getPlayerList()[i].setAttack(myTeam->getPlayerList()[i].getAttack() + 3);
			}
			myTeam->setPow(myTeam->getDef() + 3, myTeam->getAttack() + 3);
		}
		break;
	}
}

void Leauge::Print(){
	int i;
	cout << name << " Leauge:" << endl << "-------------------------------------------" << endl;
	for (i = 0; i < size; i++) {
		cout << teamList[i].getName() << " Power:" << teamList[i].getPow() << ", Point:" << teamList[i].getPuan() << endl;
	}
}
void Leauge::Teamprint() {
	int i;
	cout << "                               TAKIMLAR\n";
	cout << "                             ------------\n";
	for (i = 0; i < size; i++) {
		cout << "                              " << teamList[i].getName() << endl;
	}
}

void Leauge::harfBuyut(string& name)
{
	int i;
	for (i = 0; i < name.length(); i++) {
		if (islower(name[i]))
			name[i] = toupper(name[i]);
	}
}

void Leauge::oyuncuAdDuzenle(string& name)
{
	int i;
	if (islower(name[0]))
		name[0] = toupper(name[0]);

	for (i = 1; i < name.length(); i++) {
		if (isupper(name[i]))
			name[i] = tolower(name[i]);
		if (name[i-1] == ' ') {
			if (islower(name[i]))
				name[i] = toupper(name[i]);
		}
	}
}
Team* Leauge::siralama()
{
	Team* siralama = new Team[size];
	Team temp;
	int i,j;
	for (i = 0; i < size; i++) {
		siralama[i] = teamList[i];
	}
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (siralama[i].getPuan() >= siralama[j].getPuan()) {
				temp = siralama[i];
				siralama[i] = siralama[j];
				siralama[j] = temp;
			}
		}
	}

	return siralama;
}

Player* Leauge::golSiralama()
{
	int i, j, k=0, toplamOyuncu=0;
	for (i = 0; i < size; i++) {
		toplamOyuncu += teamList[i].getSize();//TOPLAM OYUNCU SAYISI HESAPLANIYOR
	}
	Player* siralama = new Player[toplamOyuncu];
	for (i = 0; i < size; i++) {
		for (j = 0; j < teamList[i].getSize(); j++) {
			siralama[k] = teamList[i].getPlayerList()[j];
			k++;
		}
	}
	Player temp;
	for (i = 0; i < toplamOyuncu; i++) {
		for (j = 0; j < toplamOyuncu; j++) {
			if (i == j) {
				continue;
			}
			else if (siralama[i].getGoals() >= siralama[j].getGoals()) {
				temp = siralama[i];
				siralama[i] = siralama[j];
				siralama[j] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++) {//ilk 10 kisi yazdiriyor
		cout << (i + 1) << "-) " << siralama[i];
	}
	return siralama;
}