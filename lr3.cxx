#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
using namespace std;

class Character {
protected:
    string name;
    int health;
    int power;
public:
    Character(string _name, int _health, int _power) : name(_name), health(_health), power(_power) {}

    string getName() {
        return name;
    }
    int getHealth() {
        return health;
    }
    bool isAlive() {
        return health > 0;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) {
            health = 0;
        }
    }

    void attack(Character& target) {
        int damage = rand() % power + 1;
        target.takeDamage(damage);
        Sleep(500);
        cout << name << " attacks " << target.getName() << " for " << damage << " damage " << endl;
    }

};

class Hero : public Character {
public:
    Hero(string _name, int _health, int _power) : Character(_name, _health, _power) {}

    void heroAttack(Character& target) {
        attack(target);
        Sleep(500);
        cout << name << " shouts a heroic battle cry!" << endl;

    }
};

class Monster : public Character {
public:
    Monster(string _name, int _health, int _power) : Character(_name, _health, _power) {}

    void monsterAttack(Character& target) {
        attack(target);
        Sleep(500);
        cout << name << " growls menacingly!" << endl;
    }
};

void Menu();
void InputHero(vector<Hero>& heroes);
void InputMonster(vector<Monster>& monsters);
void StartBattle(vector<Hero>& heroes, vector<Monster>& monsters);

void main() {

    srand(static_cast<unsigned>(time(nullptr)));

    vector<Hero> heroes;
    vector<Monster> monsters;
    char taskNum;
    do
    {
        Menu();
        do
        {
            taskNum = _getch();
        } while (taskNum < '0' && taskNum>'3' && taskNum != 27);
        switch (taskNum)
        {
        case'1':
            system("cls");
            InputHero(heroes);
            break;
        case'2':
            system("cls");
            InputMonster(monsters);
            break;
        case'3':
            system("cls");
            StartBattle(heroes, monsters);
            break;
        default:
            break;
        }
    } while (taskNum != 27);
    system("cls");
    cout << "End of the program" << endl;


    if (heroes.empty()) {
        cout << "Monsters win!" << endl;
    }
    else {
        cout << "Heroes win!" << endl;
    }

}

void Menu()
{
    system("cls");
    cout << "1 - Input hero" << endl;
    cout << "2 - Input monster" << endl;
    cout << "3 - Start battle" << endl;
    cout << "Esc - exit" << endl;
}

void InputHero(vector<Hero>& heroes)
{
    string Name;
    int Health, Power;
    char task;
    do {
        cout << "Enter name: "; cin >> Name;
        cout << "Enter Health: "; cin >> Health;
        cout << "Enter Power: "; cin >> Power;
        heroes.push_back(Hero(Name, Health, Power));
        cout << "Esc-exit / Enter-Enter more";

        do
        {
            task = _getch();
        } while (task != 27 && task != 13);
        system("cls");
    } while (task != 27);
}

void InputMonster(vector<Monster>& monsters)
{
    string Name;
    int Health, Power;
    char task;
    do {
        cout << "Enter name: "; cin >> Name;
        cout << "Enter Health: "; cin >> Health;
        cout << "Enter Power: "; cin >> Power;
        monsters.push_back(Monster(Name, Health, Power));
        cout << "Esc-exit / Enter-Enter more";

        do
        {
            task = _getch();
        } while (task != 27 && task != 13);
        system("cls");
    } while (task != 27);
}

void StartBattle(vector<Hero>& heroes, vector<Monster>& monsters) {
    while (!heroes.empty() && !monsters.empty()) {
        int heroIndex = rand() % heroes.size();
        int indexMonster = rand() % monsters.size();
        heroes[heroIndex].heroAttack(monsters[indexMonster]);
        if (!monsters[indexMonster].isAlive()) {
            cout << monsters[indexMonster].getName() << " is defeated!" << endl;
            monsters.erase(monsters.begin() + indexMonster);
        }

        if (!heroes.empty()) {
            heroIndex = rand() % heroes.size();
            indexMonster = rand() % monsters.size();
            monsters[indexMonster].monsterAttack(heroes[heroIndex]);
            if (!heroes[heroIndex].isAlive()) {
                cout << heroes[heroIndex].getName() << " is defeated!" << endl;
                heroes.erase(heroes.begin() + heroIndex);
            }
        }
    }
    _getch();
}
