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
	int AttackDamage;
	int FightChance;
	int AttackMultiplier;
	int Agility;
	int Defence;
	int Strength;
	int Luck;

	Strength = 1;
	Agility = 1;
	Defence = 1;
	Luck = 1;
	
	FightChance = rand() % 100 + 1;

	if (FightChance >= 20 and FightChance <= 40) {

	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
