// RPG-Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <stdio.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int BaseAttckDamage = 3;
	double AttackDamage;
	int FightChance;
	int AttackMultiplier;
	double CriticalChance;
	int CriticalValue;
	int Agility;
	int Defence;
	int Strength;
	int Luck;

	Strength = 1;
	Agility = 1;
	Defence = 1;
	Luck = 1;
	AttackMultiplier = 1;
	
	CriticalChance = rand() % 100 + 1;
	FightChance = rand() % 100 + 1;

	if (CriticalChance >= 20 and CriticalChance <= 40) {
		CriticalValue = BaseAttckDamage * AttackMultiplier * 20 / 100;
	}

	cout << "The valley of souls, if anything, was a place of silence. From time to time," << endl;
	cout << "you could hear gas escaping from the bog, or the sound of falling rocks would" << endl;
	cout <<	"disturb the silence, but the sound of living things was almost never heard." << endl;
	cout << "It's not like anything could live there, the fog that covered the valley was a" << endl;

	cout << "very dangerous toxic gas. Still, that didn't stop you from crossing through it." << endl;
	cout << "A search of many years dove you here and you aren't planning to turn back" << endl;
	cout << "because of a little bit of air." << endl << endl;

	cout << "'Go on Nix, faster!' You mutter from under the scarf, you use to cover mouth" << endl;
	cout << "and nose. It isn't the best protection against the gas, but it allows you to" << endl;
	cout << "stay in the fog, for now. Nix, the large, bright blue bipedal bird you are" << endl;
	cout << "riding on, followed your command and fastened his pace." << endl << endl;

	cout << "You come upon an illuminated lake. The gas around it appears to be gone, and you" << endl;
	cout << "lower the scarf to catch some fresh air. In the middle of the lake you notice" << endl;
	cout << "a small rock sticking out above the water. Your face lights up in a smile when" << endl;
	cout << "when you realize that this could be the end of your journey.The necromancer’s" << endl;
	cout << "amulet, a magical necklace that had been passed down in his family for ages," << endl;
	cout << "until it disappeared during the war of Havenport. This would proof your royal" << endl;
	cout << "blood and allow you to retake the throne and restore order to the kingdom." << endl << endl << endl;

	cout << "PRESS ENTER TO CONTINUE" << endl;
	
	cin.get();
	system("cls");

	cout << "'Swim Nix' you whisper, while pointing at the rock. The bird carefully felt the" << endl;
	cout << "water before swimming towards the rock. You patt the bird on his head, before" << endl;
	cout << "dismounting to go checkout the stone. Legend has it that the stone will be" << endl;
	cout << "laying in a small out carveing in the stone. Upon looking in the stone you" << endl;
	cout << "find that it is empty. Surprised, you let out a deep sigh of disappointment." << endl;

	cin.get();


	if (FightChance >= 20 and FightChance <= 40) {

	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
