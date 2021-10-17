#ifndef GAME_H
#define GAME_H
#include <iostream>
//#include <stdlib.h>
//#include <time.h>//Random deðer için
//#include <windows.h>//Þarký ve random deðer için
#include <string>
#include <cstdlib>
#include <ctime>
//#include <mmsystem.h> //Arkada çalan þarký için

using namespace std;
class Player {
    friend ostream& operator<<(ostream&, Player&);
    friend istream& operator>>(istream&, Player&);
public:
    Player();
    //~Player();
    Player(string, string, int, int);
    Player& operator = (Player& D);
    void setPlayer(string, string, int, int);
    void setPlayer(Player);
    void golAttir() { goals++; }
    const string getName() { return name; }
    const string getTeam() { return team; }
    const int getPow() { return pow; }
    const int getDef() { return def;  }
    const int getAttack() { return attack; }
    const int getGoals() { return goals; }
    void setDef(int);
    void setAttack(int);
    void setPow(int,int);
    void print();
private:
    string name;
    string team;
    int def;
    int attack;
    int pow;
    int goals;

};


class Team{
    friend ostream& operator<<(ostream&, Team&);
public:
    Team();
    Team(string, Player* , int);
    Team(Team&);
   // ~Team(){ delete []playerlist; }
    Team& operator = (Team& D);
    void setTeam(string, Player*, int);
    void setPow(int, int);
    const string getName() { return name; }
    Player* getPlayerList() { return playerlist; }
    const int getPow() { return power; }
    const int getDef() { return def;  }
    const int getAttack() { return attack; }
    const int getPuan() { return puan; }
    const int getSize() { return size; }
    void addPlayer(Player player);
    void addPlayer(string, int, int);
    void winMatch() { puan += 3; }
    void berabere() { puan++;  }
    Player deletePlayer(Player player);
    Player deletePlayer(string name);
    void print();


private:
    string name;
    Player* playerlist;
    int size;
    int power;
    int attack;
    int def;
    int puan;
};


class Leauge{
    friend ostream& operator<<(ostream&, Leauge&);
public:
    Leauge(string, int, string);
    //~Leauge(){ delete []teamList; }
    void setLeauge(string, int, string);
    void chooseTeam(string name);
    Team& macYap(Team& team1, Team& team2);
    Team& kimAtti(Team& team1, Team& team2,int,int);
    int** kura();
    Team* getMyTeam() { return myTeam; }
    Team* getTeam() { return teamList; }
    int getSize() { return size; }
    string getName() { return name; }
    Team* kura2();
    void transfer();//Oðuzhan Tokuç
    void antreman();//Asim Uyanik
    void Print();
    void Teamprint();
    void harfBuyut(string&);
    void oyuncuAdDuzenle(string&);
    Team* siralama();
    Player* golSiralama();
private:
    Team* myTeam;
    string name;
    Team* teamList;
    int size;
};

#endif
