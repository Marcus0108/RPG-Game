#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <stdio.h>
#include <Windows.h>

using namespace std;

//Spillerens navn samt stats
char HeroName[50];
int * PlayerStats;

//Weapon stats
int Sword = 7;

//Mob stats
struct mobs {
	int damage = 5;
	int health = 22;
}wolf;

// Stats på modstanderne i combat systemet
int Hitchance;
int EnemyMood = 0;

//Tale sekvens variable
int Action;//Brugt til alle interections mugligheder
int EndLoop = 1;//Bruges til at stoppe nogle loop
int GentagelsesForhindring = 0;//Bruges til kun at vise nogle ting første gang en loop køre

//Stats som kan bruges og endres til kampe, uden at endre på derres uprindelse
struct CurrentStats {
	int health;
	int damage;
	int weapon;
}CurrentMobA, CurrentMobB, Currentplayer;

//En måde hvor vi definere 3 variabler, som vi kan slette helt fra hukomelsen, hvis vi kan ville bruge dem i halvdellen af programmet
void PonitersAndDynamicMemoryB()
{
	PlayerStats = new (nothrow) int[3];
	if (PlayerStats == nullptr)
		cout << "Error: memory could not be allocated";
	else
	{
		PlayerStats[0] = 4;//damage
		PlayerStats[1] = 100;//health
		PlayerStats[2] = 0;//deaths
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

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02);//Endre text farven, så vi kan vise hvem der taler, (i dette tilfælde, spilleren)
	cout << "'Go on Nix, faster!'";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);//Endre det tilbage til standart farven
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

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02); //Ændre tekst farven til spillerens farve
	cout << "'Swim Nix'";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07); //Ændre tekst farven til standard farve
	cout << " you whisper, while pointing at the rock. The bird carefully felt the" << endl;
	cout << "water before swimming towards the rock. You patt the bird on his head, before" << endl;
	cout << "dismounting to go checkout the stone. Legend has it that the stone will be" << endl;
	cout << "laying in a small out carveing in a stone. Upon looking in the stone you" << endl;
	cout << "find that it is empty. Surprised, you let out a deep sigh of disappointment." << endl;
	cout << "Suddenly, from the banks of the lake, you hear a familiar voice." << endl << endl;

	cout << endl << "PRESS ENTER TO CONTINUE" << endl;

	cin.get();
}

//Første møde med Leland, som sætter Lelands humør og bestæmmer hvilken kamp man skal imod
void LelandEncounter()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 03); //Endre texten til Lelands tale farve
	cout << "'Took you long enough..." << endl << "...Little brother.'" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02);  //Ændre tekst farven til spillerens farve
	cout << "'Leland? How... When...'" << endl;
	cout << " 'You... Youre alive!?!'" << endl;
	cout << " 'I thought the rebels got to you! What are you doing here?'" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 03); //Endre texten til Lelands tale farve
	cout << "'The same reason as you, I went to get the amulet.'" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07); //Ændre tekst farven til standard farve
	cout << "Leland reached into his clothes, and pulled out the amulet from under his shirt," << endl;
	cout << " revealing a small golden skull dangling from his neck." << endl << endl;

	cout << endl << "PRESS ENTER TO CONTINUE" << endl << endl << endl;

	cin.get();

	cout << "CHOOSE SPEACH OPTION:" << endl << endl;

	cout << "1. 'Well, what are we doing here, lets finally return to the palace!'" << endl;
	cout << "2. 'Why would you want the amulet? You never cared for the kingdom.'" << endl;
	cout << "3. 'Give it over i need it to restore the standing of the kingdom!'" << endl;

	//Spørger efter hvilken action man vil tage, hvis men så skriver noget andet end de 3 mugligheder spøger den igen
	do {
		cin >> Action;
		if (Action == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02); //Ændre tekst farven til spillerens farve
			cout << "'Well, what are we doing here, lets finally return to the palace!'" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07); //Ændre tekst farven til standard farve
			EndLoop = 2;
			EnemyMood = EnemyMood + 1;
		}
		else if (Action == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02); //Ændre tekst farven til spillerens farve
			cout << "'Why would you want the amulet? You never cared for the kingdom.'" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07); //Ændre tekst farven til standard farve
			EndLoop = 2;
		}
		else if (Action == 3)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02); //Ændre tekst farven til spillerens farve
			cout << "'Give it over i need it to restore the standing of the kingdom!'" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07); //Ændre tekst farven til standard farve
			EndLoop = 2;
			EnemyMood = EnemyMood - 1;
		}
		else
		{
			cout << "PLEASE ENTER A VALID OPTION" << endl;
		}
	} while (EndLoop == 1);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 03); //Endre texten til Lelands tale farve
	cout << "'Im gonna use the amulet to start a war with the kingdom of Rulanis," << endl;
	cout << "and you would only be in the way.'" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07); //Ændre tekst farven til standard farve

	cout << endl << "PRESS ENTER TO CONTINUE" << endl << endl << endl;

	cin.get();
	cin.get();
	cout << "CHOOSE SPEACH OPTION:" << endl << endl;

	cout << "1. 'Come on, we can talk about this on the way to the kingdom," << endl;
	cout << "  im sure we can figure something out without starting a war'" << endl;
	cout << "2. 'What do you mean start a war? We could never win a war on Rulanis.'" << endl;
	cout << "3. 'Are you stupid brother? You could never lead an army.'" << endl;

	EndLoop = 1;
	do {
		cin >> Action;
		if (Action == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02); //Ændre tekst farven til spillerens farve
			cout << "'Come on, we can talk about this on the way to the kingdom," << endl;
			cout << "im sure we can figure something out without starting a war'" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07); //Ændre tekst farven til standard farve
			EndLoop = 2;
			EnemyMood = EnemyMood + 1;
		}
		else if (Action == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02); //Ændre tekst farven til spillerens farve
			cout << "'What do you mean start a war? We could never win a war on Rulanis.'" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07); //Ændre tekst farven til standard farve
			EndLoop = 2;
		}
		else if (Action == 3)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02); //Ændre tekst farven til spillerens farve
			cout << "'Are you stupid brother? You could never lead an army.'" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07); //Ændre tekst farven til standard farve
			EndLoop = 2;
			EnemyMood = EnemyMood - 1;
		}
		else
		{
			cout << "PLEASE ENTER A VALID OPTION" << endl;
		}
	} while (EndLoop == 1);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 03); //Endre texten til Lelands tale farve
	cout << "'Have you forgotten what the king of Rulanis did to mother," << endl;
	cout << "she died because of him. And you just want to play with politics.'" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07); //Ændre tekst farven til standard farve

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

	EndLoop = 1;
	do {
		cin >> Action;
		if (Action == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02); //Ændre tekst farven til spillerens farve
			cout << "'I havent forgotten, we can claim his life together but " << endl;
			cout << "we will need our kingdom united again.'" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07); //Ændre tekst farven til standard farve
			EndLoop = 2;
			EnemyMood = EnemyMood + 1;
		}
		else if (Action == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02); //Ændre tekst farven til spillerens farve
			cout << "'I havent forgotten, but this is not the way, he’s rule will end " << endl;
			cout << "but he does not need to die.'" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07); //Ændre tekst farven til standard farve
			EndLoop = 2;
		}
		else if (Action == 3)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02); //Ændre tekst farven til spillerens farve
			cout << "'We wouldn't stand a chance give me the amulet, " << endl;
			cout << "so I at least can heal the wounds of our kingdom.'" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07); //Ændre tekst farven til standard farve
			EndLoop = 2;
			EnemyMood = EnemyMood - 1;
		}
		else
		{
			cout << "PLEASE ENTER A VALID OPTION" << endl;
		}
	} while (EndLoop == 1);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 03); //Endre texten til Lelands tale farve
	cout << "'Enough this is a journey i will do alone, DO NOT get in my way.'" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07); //Ændre tekst farven til standard farve

	cout << endl << "PRESS ENTER TO CONTINUE" << endl;

	cin.get();
	cin.get();
	system("cls");
}

//De 3 muglige kampe du kan spille afhængig af sammentallen
void ScriptedEncounter()
{
	system("cls");
	EndLoop = 1;

	if (EnemyMood > 0)//scenen der sker når Leland er i godt humør
	{
		cout << "Leland hands starts glowing, and he send a spell right by nix." << endl;
		cout << "Nix set off runing wildly around, you strugle to get the bird" << endl;
		cout << "under control, but you ultimately fail. You feal the bird loseing" << endl;
		cout << "its grip, as it backs into a ravine. Last thing you see before passing" << endl;
		cout << "out, is the trees getting smaller as you keep falling." << endl;
	}
	else if (EnemyMood == 0)//scenen der sker når Leland er i middel humør
	{
		CurrentMobA.health = wolf.health; //health
		CurrentMobA.damage = wolf.damage; //damage
		CurrentMobB.health = wolf.health; //health
		CurrentMobB.damage = wolf.damage; //damage

		Currentplayer.health = PlayerStats[1]; //health
		Currentplayer.damage = PlayerStats[0]; //base damage
		Currentplayer.weapon = Sword; //sword damage
		do
		{
			if (GentagelsesForhindring == 0)
			{
				cout << "Leland summons two undead wolfs the wolfs rushes towards you." << endl;
			}
			cout << endl << "Take action:" << endl;
			cout << "1. Attack" << endl;
			cout << "2. Try to flee" << endl;
			cout << "3. Try to disarm the situation" << endl;

			cin >> Action;
			if (Action == 1)
			{
				if (CurrentMobA.health >= 0)
				{
					CurrentMobA.health = CurrentMobA.health - ((Currentplayer.damage + Currentplayer.weapon) / 2);
					cout << "You feel your sword slice through the rotten flesh of the first wolf." << endl;
					cout << "Doing " << ((Currentplayer.damage + Currentplayer.weapon) / 2) << " damage." << endl;
					cin.get();
					if (CurrentMobA.health <= 0)
					{
						cout << "The mutalated body of the rotten remains of the first wolf falls" << endl;
						cout << "limp to the ground." << endl;
					}
				}
				else if (CurrentMobA.health <= 0)
				{
					CurrentMobB.health = CurrentMobB.health - ((Currentplayer.damage + Currentplayer.weapon) / 2);
					cout << "You feel your sword slice through the rotten flesh of the second wolf." << endl;
					cout << "Doing " << ((Currentplayer.damage + Currentplayer.weapon) / 2) << " damage." << endl;
					cin.get();
					if (CurrentMobB.health <= 0)
					{
						cout << "The mutalated body of the rotten remains of the second wolf falls" << endl;
						cout << "limp to the ground." << endl;
					}
				}

				cin.get();
				if (CurrentMobA.health >= 1)
				{
					cout << "The two wolfs attempt to bite you:" << endl;
				}
				else if (CurrentMobB.health >= 1)
				{
					cout << "The last wolf attempt to bite you:" << endl;
				}

				if (CurrentMobA.health >= 1)
				{
					Hitchance = rand() % 100 + 1;
					if (Hitchance <= 75 && Hitchance != 1)
					{
						Currentplayer.health = Currentplayer.health - CurrentMobA.damage;
						cout << "The first wolfs jaws latches into your flesh." << endl;
						cout << "Dealing " << CurrentMobA.damage << " damage." << endl;
					}
					else if (Hitchance == 1)
					{
						Currentplayer.health = Currentplayer.health - (CurrentMobA.damage * 1.5);
						cout << "The first wolf jaws latches onto your leg riping a piece off." << endl;
						cout << "Dealing a critical " << (CurrentMobA.damage * 1.5) << " damage." << endl;
					}
					else if (Hitchance >= 76)
					{
						cout << "You see the first wolf prepare to bite you and you dodge out of the way." << endl;
					}
				}

				if (CurrentMobB.health >= 1)
				{
					Hitchance = rand() % 100 + 1;
					if (Hitchance <= 75 && Hitchance != 1)
					{
						Currentplayer.health = Currentplayer.health - CurrentMobB.damage;
						cout << "The second wolf jaws latches into your flesh." << endl;
						cout << "Dealing " << CurrentMobB.damage << " damage." << endl;
					}
					else if (Hitchance == 1)
					{
						Currentplayer.health = Currentplayer.health - (CurrentMobB.damage * 1.5);
						cout << "The second wolf jaws latches onto your leg riping a piece off." << endl;
						cout << "Dealing a critical " << (CurrentMobB.damage * 1.5) << " damage." << endl;
					}
					else if (Hitchance >= 76)
					{
						cout << "You see the second wolf prepare to bite you and you dodge out of the way." << endl;
					}
				}
				cin.get();

				if (Currentplayer.health >= 1)
				{
					cout << "You have " << Currentplayer.health << " health left." << endl;
				}
				else if (Currentplayer.health <= 0)
				{
					cout << "You colapse too the ground. YOU ARE DEAD." << endl;
					EndLoop = 0;
				}
				cin.get();

				if (CurrentMobB.health <= 0)
				{
					cout << "You gather you self and call for Nix, but nothing happens..." << endl;
				}

				GentagelsesForhindring = 1;
				if (CurrentMobB.health <= 0)
				{
					GentagelsesForhindring = 0;
					EndLoop = 0;
				}
			}
			else if (Action == 2)
			{
				cout << "You start backing away from the wolves, while keeping them in sight." << endl;
				cout << "Sadly you don't notice the ravine behind you, so you fall to you lonely death." << endl << endl;
				cout << HeroName << "'s journey sadly ends here.";
				PlayerStats[2] = 1;

				EndLoop = 2;
			}
			else if (Action == 3)
			{
				cout << "You try and calm the two wolfs, but as you look into their eyes you see nothing." << endl;
				cout << "The two seemingly mindless wolfs keep rushing at you." << endl << endl;

				if (CurrentMobA.health >= 1)
				{
					cout << "The two wolfs attempt to bite you:" << endl;
				}
				else if (CurrentMobB.health >= 1)
				{
					cout << "The last wolf attempt to bite you:" << endl;
				}

				if (CurrentMobA.health >= 1)
				{
					Hitchance = rand() % 100 + 1;
					if (Hitchance <= 75 && Hitchance != 1)
					{
						Currentplayer.health = Currentplayer.health - CurrentMobA.damage;
						cout << "The first wolfs jaws latches into your flesh." << endl;
						cout << "Dealing " << CurrentMobA.damage << " damage." << endl;
					}
					else if (Hitchance == 1)
					{
						Currentplayer.health = Currentplayer.health - (CurrentMobA.damage * 1.5);
						cout << "The first wolf jaws latches onto your leg riping a piece off." << endl;
						cout << "Dealing a critical " << (CurrentMobA.damage * 1.5) << " damage." << endl;
					}
					else if (Hitchance >= 76)
					{
						cout << "You see the first wolf prepare to bite you and you dodge out of the way." << endl;
					}
				}

				if (CurrentMobB.health >= 1)
				{
					Hitchance = rand() % 100 + 1;
					if (Hitchance <= 75 && Hitchance != 1)
					{
						Currentplayer.health = Currentplayer.health - CurrentMobB.damage;
						cout << "The second wolf jaws latches into your flesh." << endl;
						cout << "Dealing " << CurrentMobB.damage << " damage." << endl;
					}
					else if (Hitchance == 1)
					{
						Currentplayer.health = Currentplayer.health - (CurrentMobB.damage * 1.5);
						cout << "The second wolf jaws latches onto your leg riping a piece off." << endl;
						cout << "Dealing a critical " << (CurrentMobB.damage * 1.5) << " damage." << endl;
					}
					else if (Hitchance >= 76)
					{
						cout << "You see the second wolf prepare to bite you and you dodge out of the way." << endl;
					}
				}
				cin.get();

				if (Currentplayer.health >= 1)
				{
					cout << "You have " << Currentplayer.health << " health left." << endl;
				}
				else if (Currentplayer.health <= 0)
				{
					cout << "You colapse too the ground. YOU ARE DEAD." << endl;
					EndLoop = 0;
				}
				GentagelsesForhindring = 1;
			}
			else
			{
				cout << "PLEASE ENTER A VALID OPTION" << endl;
			}
		} while (EndLoop == 1);
	}
	else if (EnemyMood < 0)//scenen der sker når Leland er i dårligt humør
	{
		do
		{
			if (GentagelsesForhindring == 0)
			{
				cout << "You feal a dark power swamming around Leland." << endl;
			}
			cout << endl << "Take action:" << endl;
			cout << "1. Attack" << endl;
			cout << "2. Try to flee" << endl;
			cout << "3. Try to disarm the situation" << endl;

			cin >> Action;
			if (Action == 1)
			{
				cout << "As you draw your sword as you see Leland rush toward you." << endl;
				cout << "Sudenly a powerfull force rips the sword out of your hand." << endl;
				cout << "You stand still in a shock as he places his fingers on your chest." << endl;
				cout << "You feal a explosive wave of energy surge though your chest." << endl;
				cout << "You fly backwards into a tree, knocking you out cold." << endl;
				EndLoop = 0;
			}
			else if (Action == 2)
			{
				cout << "You start backing away from Leland, while keeping him in sight." << endl;
				cout << "As he rushes towards you trip and fall into a ravine," << endl;
				cout << "and you fall to you lonely death." << endl << endl;
				cout << HeroName << "'s journey sadly ends here.";
				PlayerStats[2] = 1;

				EndLoop = 0;
			}
			else if (Action == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 02); //Ændre tekst farven til spillerens farve
				cout << "'Stop this foolishness brother!'" << endl << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07); //Ændre tekst farven til standard farve
				cout << "As you say this you see a crackeling blue ball form over you." << endl;
				cout << "A lightning strikes down on you, knocking you out cold." << endl;
				EndLoop = 0;
			}
			else
			{
				cout << "PLEASE ENTER A VALID OPTION" << endl;
			}
		} while (EndLoop == 1);
	}
}

int main()
{
	srand(time(NULL));

	//Definere nogle variabler
	PonitersAndDynamicMemoryB();

	//Spørger efter spillerens navn
	cout << "What is your name stranger?" << endl;
	cin.get(HeroName, 50);
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

	//Køre kampen mod skurken eller 2 ulve
	ScriptedEncounter();
	cin.get();

	//slætter 3 stats fra hukommelsen
	if (PlayerStats != nullptr)
	{
		delete[] PlayerStats;
	}

	cin.get();
	return 0;
}