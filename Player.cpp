#include "Game.h"
ostream& operator<<(ostream& os, Player& player) {
	os << player.getName() << " --> Power: " << player.getPow() << " --> Goals: " << player.getGoals() << endl;
	return os;
}
istream& operator>>(istream& is, Player& player) {
	string name, team;
	int def, attack;
	cout << "Enter name, team, def and attack powers" << endl;
	getline(is, name);
	is >> team >> def >> attack;
	player.setPlayer(name, team, def, attack);
	return is;
}
Player::Player() {
	this->name = "-";
	this->team = "-";
	this->def = 0;
	this->attack = 0;
	this->pow = 0;
	this->goals = 0;
}
Player::Player(string name, string team, int def, int attack) {
	setPlayer(name, team, def, attack);
	goals = 0;
}

Player& Player::operator=(Player& D)
{
	this->name = D.getName();
	this->team = D.getTeam();
	this->def = D.getDef();
	this->attack = D.getAttack();
	this->pow = (def + attack) / 2;
	this->goals = D.getGoals();
	return *this;
}

void Player::setPlayer(Player a) {
	this->name = a.getName();
	this->team = a.getTeam();
	this->def = a.getDef();
	this->attack = a.getAttack();
	this->pow = (def + attack) / 2;
	this->goals = a.getGoals();
}
void Player::setPlayer(string name, string team, int attack, int def) {
	this->name = name;
	this->team = team;
	this->def = def;
	this->attack = attack;
	this->pow = (def + attack) / 2;
}
void Player::setDef(int a){
	def = a;
	setPlayer(*this);
}
void Player::setAttack(int a){
	attack = a;
	setPlayer(*this);
}
void Player::setPow(int a,int b){
	setDef(a);
	setAttack(b);
}
void Player::print() {
	cout << team << ": " << name << " " << pow;
}
