#include "Game.h"
ostream& operator<<(ostream& osObj, Team& team) {
	osObj << endl << team.getName() << endl << "----------------------" << endl;
	int i;
	for (i = 0; i < team.getSize(); i++) {
		//team.getPlayerList()[i].print();
		osObj << team.getPlayerList()[i];
	}
	osObj << "Team power: " << team.getPow() << endl;
	osObj << "Team point: " << team.getPuan() << endl;
	return osObj;
}

Team::Team() {
	Player nullplyr;
	this->name = "-";
	playerlist = new Player[1];
	for (int i = 0; i < 1; i++) {
		playerlist[i] = nullplyr;
	}
	power = 0;
	puan = 0;
	def = 0;
	attack = 0;
}

Team::Team(string name, Player* players, int size) {
	setTeam(name, players, size);
	puan = 0;
}
Team::Team(Team& D)
{
	setTeam(D.getName(), D.getPlayerList(), D.getSize());
	this->puan = D.getPuan();
}
Team& Team::operator = (Team& D) {
	setTeam(D.getName(), D.getPlayerList(), D.getSize());
	this->puan = D.getPuan();
	return *this;
}
void Team::setTeam(string name, Player* players, int size) {
	this->name = name;
	this->size = size;
	playerlist = new Player[size];
	for (int i = 0; i < size; i++) {
		playerlist[i] = players[i];
	}
	power = 0;
	def = 0;
	attack = 0;
	for (int i = 0; i < size; i++) {
		power += playerlist[i].getPow();
		def += playerlist[i].getDef();
		attack += playerlist[i].getAttack();
	}
	def = def / size;
	attack = attack / size;
	power = power / size;
}
void Team::setPow(int def, int attack)
{
	this->def = def;
	this->attack = attack;
	this->power = (def + attack) / 2;
}
void Team::addPlayer(Player player) {
	int i;
	Player* temp = new Player[size + 1];
	for (i = 0; i < size; i++) {
		temp[i] = playerlist[i];
	}
	temp[size] = player;
	size++;
	setTeam(name, temp, size);
}
void Team::addPlayer(string name, int def, int attack) {
	int i;
	Player tempPlayer(name, this->name, def, attack);
	Player* temp = new Player[size + 1];
	for (i = 0; i < size; i++) {
		temp[i] = playerlist[i];
	}
	temp[size] = tempPlayer;
	size++;
	setTeam(this->name, temp, size);
}

Player Team::deletePlayer(Player player) {
	int i, j = 0;
	Player* temp = new Player[size - 1];
	for (i = 0; i < size; i++) {
		if (player.getName().compare(playerlist[i].getName())) {
			temp[j] = playerlist[i];
			j++;
		}
	}
	size--;
	setTeam(name, temp, size);
	return player;
}
Player Team::deletePlayer(string name) {
	int i, j = 0;
	Player* temp = new Player[getSize() - 1];
	Player deletedPlayer;
	for (i = 0; i < size; i++) {
		if (name.compare(playerlist[i].getName())) {
			temp[j] = playerlist[i];
			j++;
		}
		else {
			deletedPlayer.setPlayer(playerlist[i].getName(), playerlist[i].getTeam(), playerlist[i].getPow(), playerlist[i].getPow());
		}
	}
	size--;
	setTeam(this->name, temp, size);
	return deletedPlayer;
}

void Team::print() {
	cout << endl << endl << name << "-------" << endl;
	int i;
	for (i = 0; i < this->size; i++) {
		playerlist[i].print();
		cout << endl;
	}
	cout << "Team power: " << power << endl;
	cout << "Team point: " << puan << endl;
}

