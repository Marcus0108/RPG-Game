// RPG-Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <stdio.h>


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
	int PlayerName;

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

	if (FightChance >= 20 and FightChance <= 40) {

	}

	cin.ignore();
	cin.get();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
