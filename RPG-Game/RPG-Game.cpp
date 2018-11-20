//Rip Stan Lee, press F to pay respects
#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <stdio.h>
#include <Windows.h>

using namespace std;

//Weapon stats
int Sword = 7;

//Armour stats
int LeatherJacket = 10;
int LeatherPants = 10;

//Spillerens navn samt stats
string HeroName;

int BaseAttckDamage = 10;
double AttackDamage;
int FightChance;
double CriticalChance;
int CriticalValue;
int MaxHP = 100;
int CurrentPlayerStats[3] = { };
int Agility = 1;
int Defence = 1;
int Strength = 1;
int Luck = 1;
int EquipedWeapon = Sword;
int EquipedArmour = LeatherJacket;
int EquipedLegs = LeatherPants;

int Death = 0;

// Stats på modstanderne i combat systemet
int EnemyBaseAttckDamage = 39;
double EnemyAttackDamage;
int EnemyFightChance;
int EnemyAttackMultiplier = 1;
double EnemyCriticalChance;
int EnemyCriticalValue;
int EnemyHP = 100;
int EnmeyAgility = 1;
int EnemyDefence = 1;
int EnemyStrength = 1;
int EnemyLuck = 1;

int CurentEnemyAStats[2] = { };

int CurentEnemyBStats[2] = { };

int EnemyMood = 0;

//Item stats
int SmallPotion = 15;
int MediumPotion = 30;
int LargePotion = MaxHP / 1.43;

//Tale sekvens variable
int Action;
int EndlLoop = 1;

//Chancen for at få et Critical hit
void CombatStart()
{
	if (CriticalChance >= 20 and CriticalChance <= 40)
	{
		CriticalValue = BaseAttckDamage + EquipedWeapon * 20 / 100;
		AttackDamage = BaseAttckDamage + EquipedWeapon + CriticalValue;
	}
}

//Chancen for at ende i en kamp
void Combatchance()
{
	FightChance = rand() % 100 + 1;
	if (FightChance >= 20 and FightChance <= 40)
	{
		CombatStart();
	}
}

//
void CombatEncounter()
{
}

void CombatBoss()
{
}

void ScriptedEncounter()
{
	system("cls");
	EndlLoop = 1;

	if (EnemyMood > 0)
	{
		cout << "Leland hands starts glowing, and he send a spell right by nix." << endl;
		cout << "Nix set off runing wildly around, you strugle to get the bird" << endl;
		cout << "under control, but you ultimately fail. You feal the bird loseing" << endl;
		cout << "its grip, as it backs into a ravine. Last thing you see before passing" << endl;
		cout << "out, is the trees getting smaller as you keep falling." << endl;
	}
	else if (EnemyMood == 0)
	{
		cout << "Leland summons two undead wolfs the wolfs rushes towards you." << endl << endl;
		cout << "Take action:" << endl;
		cout << "1. Attack" << endl;
		cout << "2. Try to flee" << endl;
		cout << "3. Try to disarm the situation" << endl;
		do {
			cin >> Action;
			if (Action == 1)
			{
				do //combatloop
				{
					CurentEnemyAStats[0] = 22;
					CurentEnemyAStats[1] = 5;
					CurentEnemyBStats[0] = 22;
					CurentEnemyBStats[1] = 5;

					CurrentPlayerStats[0] = 100;
					CurrentPlayerStats[1] = 4;
					CurrentPlayerStats[2] = 7;

					CurentEnemyAStats[0] = CurentEnemyAStats[0] - (CurrentPlayerStats[1] + CurrentPlayerStats[2]);
					cout << CurentEnemyAStats[0];
					cin.get();
					EndlLoop = 2;
				} while (EndlLoop == 1);
			}
			else if (Action == 2)
			{
				cout << "You start backing away from the wolves, while keeping them in sight." << endl;
				cout << "Sadly you don't notice the ravine behind you, so you fall to you lonly death." << endl << endl;
				cout << HeroName << "'s journey sadly ends here.";
				Death = 1;

				EndlLoop = 2;
			}
			else if (Action == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02);
				cout << "'Give it over i need it to restore the standing of the kingdom!'" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
				EndlLoop = 2;
			}
			else
			{
				cout << "PLEASE ENTER A VALID OPTION" << endl;
			}
		} while (EndlLoop == 1);
	}
	else if (EnemyMood < 0)
	{
	}
}

//Del 1 af historien
void Story1()
{
	system("cls");
	cout << "The valley of souls, if anything, was a place of silence. From time to time," << endl;
	cout << "you could hear gas escaping from the bog, or the sound of falling rocks would" << endl;
	cout << "disturb the silence, but the sound of living things was almost never heard." << endl;
	cout << "It's not like anything could live there, the fog that covered the valley was a" << endl;

	cout << "very dangerous toxic gas. Still, that didn't stop you from crossing through it." << endl;
	cout << "A search of many years dove you here and you aren't planning to turn back" << endl;
	cout << "because of a little bit of air." << endl << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02);
	cout << "'Go on Nix, faster!'";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
	cout << "You mutter from under the scarf, you use to cover mouth" << endl;
	cout << "and nose. It isn't the best protection against the gas, but it allows you to" << endl;
	cout << "stay in the fog, for now. Nix, the large, bright blue bipedal bird you are" << endl;
	cout << "riding on, followed your command and fastened his pace." << endl << endl;

	cout << "You come upon an illuminated lake. The gas around it appears to be gone, and you" << endl;
	cout << "lower the scarf to catch some fresh air. In the middle of the lake you notice" << endl;
	cout << "a small rock sticking out above the water. Your face lights up in a smile when" << endl;
	cout << "when you realize that this could be the end of your journey. The necromancers" << endl;
	cout << "amulet, a magical necklace that had been passed down in his family for ages," << endl;
	cout << "until it disappeared during the war of Havenport. This would proof your royal" << endl;
	cout << "blood and allow you to retake the throne and restore order to the kingdom." << endl << endl << endl;

	cout << "PRESS ENTER TO CONTINUE" << endl;
}

//Del 2 af historien
void Story2()
{
	system("cls");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02);
	cout << "'Swim Nix'";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
	cout << " you whisper, while pointing at the rock. The bird carefully felt the" << endl;
	cout << "water before swimming towards the rock. You patt the bird on his head, before" << endl;
	cout << "dismounting to go checkout the stone. Legend has it that the stone will be" << endl;
	cout << "laying in a small out carveing in a stone. Upon looking in the stone you" << endl;
	cout << "find that it is empty. Surprised, you let out a deep sigh of disappointment." << endl;
	cout << "Suddenly, from the banks of the lake, you hear a familiar voice." << endl << endl;

	cout << endl << "PRESS ENTER TO CONTINUE" << endl;

	cin.get();
}

//Første møde med Leland
void LelandEncounter()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 03);
	cout << "'Took you long enough..." << endl << "...Little brother.'" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02);
	cout << "'Leland? How... When...'" << endl;
	cout << " 'You... Youre alive!?!'" << endl;
	cout << " 'I thought the rebels got to you! What are you doing here?'" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 03);
	cout << "'The same reason as you, I went to get the amulet.'" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
	cout << "Leland reached into his clothes, and pulled out the amulet from under his shirt," << endl;
	cout << " revealing a small golden skull dangling from his neck." << endl << endl;

	cout << endl << "PRESS ENTER TO CONTINUE" << endl << endl << endl;

	cin.get();

	cout << "CHOOSE SPEACH OPTION:" << endl << endl;

	cout << "1. 'Well, what are we doing here, lets finally return to the palace!'" << endl;
	cout << "2. 'Why would you want the amulet? You never cared for the kingdom.'" << endl;
	cout << "3. 'Give it over i need it to restore the standing of the kingdom!'" << endl;

	do {
		cin >> Action;
		if (Action == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02);
			cout << "'Well, what are we doing here, lets finally return to the palace!'" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
			EndlLoop = 2;
			EnemyMood = EnemyMood + 1;
		}
		else if (Action == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02);
			cout << "'Why would you want the amulet? You never cared for the kingdom.'" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
			EndlLoop = 2;
		}
		else if (Action == 3)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02);
			cout << "'Give it over i need it to restore the standing of the kingdom!'" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
			EndlLoop = 2;
			EnemyMood = EnemyMood - 1;
		}
		else
		{
			cout << "PLEASE ENTER A VALID OPTION" << endl;
		}
	} while (EndlLoop == 1);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 03);
	cout << "'Im gonna use the amulet to start a war with the kingdom of Rulanis," << endl;
	cout << "and you would only be in the way.'" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);

	cout << endl << "PRESS ENTER TO CONTINUE" << endl << endl << endl;

	cin.get();
	cin.get();
	cout << "CHOOSE SPEACH OPTION:" << endl << endl;

	cout << "1. 'Come on, we can talk about this on the way to the kingdom," << endl;
	cout << "  im sure we can figure something out without starting a war'" << endl;
	cout << "2. 'What do you mean start a war? We could never win a war on Rulanis.'" << endl;
	cout << "3. 'Are you stupid brother? You could never lead an army.'" << endl;

	EndlLoop = 1;
	do {
		cin >> Action;
		if (Action == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02);
			cout << "'Come on, we can talk about this on the way to the kingdom," << endl;
			cout << "im sure we can figure something out without starting a war'" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
			EndlLoop = 2;
			EnemyMood = EnemyMood + 1;
		}
		else if (Action == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02);
			cout << "'What do you mean start a war? We could never win a war on Rulanis.'" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
			EndlLoop = 2;
		}
		else if (Action == 3)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02);
			cout << "'Are you stupid brother? You could never lead an army.'" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
			EndlLoop = 2;
			EnemyMood = EnemyMood - 1;
		}
		else
		{
			cout << "PLEASE ENTER A VALID OPTION" << endl;
		}
	} while (EndlLoop == 1);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 03);
	cout << "'Have you forgotten what the king of Rulanis did to mother," << endl;
	cout << "she died because of him. And you just want to play with politics.'" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);

	cout << endl << "PRESS ENTER TO CONTINUE" << endl << endl << endl;

	cin.get();
	cin.get();
	cout << "CHOOSE SPEACH OPTION:" << endl << endl;

	cout << "1. 'I havent forgotten, we can claim his life together but " << endl;
	cout << "  we will need our kingdom united again.'" << endl;
	cout << "2. 'I havent forgotten, but this is not the way, he’s rule will end " << endl;
	cout << "  but he does not need to die.'" << endl;
	cout << "3. 'We wouldn't stand a chance give me the amulet, " << endl;
	cout << "  so I at least can heal the wounds of our kingdom.'" << endl;

	EndlLoop = 1;
	do {
		cin >> Action;
		if (Action == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02);
			cout << "'I havent forgotten, we can claim his life together but " << endl;
			cout << "we will need our kingdom united again.'" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
			EndlLoop = 2;
			EnemyMood = EnemyMood + 1;
		}
		else if (Action == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02);
			cout << "'I havent forgotten, but this is not the way, he’s rule will end " << endl;
			cout << "but he does not need to die.'" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
			EndlLoop = 2;
		}
		else if (Action == 3)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02);
			cout << "'We wouldn't stand a chance give me the amulet, " << endl;
			cout << "so I at least can heal the wounds of our kingdom.'" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);
			EndlLoop = 2;
			EnemyMood = EnemyMood - 1;
		}
		else
		{
			cout << "PLEASE ENTER A VALID OPTION" << endl;
		}
	} while (EndlLoop == 1);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 03);
	cout << "'Enough this is a journey i will do alone, DO NOT get in my way.'" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);

	cout << endl << "PRESS ENTER TO CONTINUE" << endl;

	cin.get();
	cin.get();
	system("cls");
	cout << "Enemy mood is: " << EnemyMood;
}

int main()
{
	srand(time(NULL));

	//Chancen for et critical hit i combat
	CriticalChance = rand() % 100 + 1;

	//Spørger efter spillerens navn
	cout << "What is your name stranger?" << endl;
	getline(cin, HeroName);
	cout << "Alright " << HeroName << ". Welcome to the land of kings and queens." << endl << endl << endl;

	cout << "PRESS ENTER TO CONTINUE" << endl;

	cin.get();
	cin.get();

	//Kører første del af historien
	Story1();

	cin.get();

	//Kører anden del af historien
	Story2();

	//Kører første møde med skurken
	LelandEncounter();

	ScriptedEncounter();
	cin.get();

	cin.get();
	return 0;
}