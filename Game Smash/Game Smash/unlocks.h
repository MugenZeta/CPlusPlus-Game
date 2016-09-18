#pragma once

/*
Use "get_C_UL;" to see if a character is unlocked and to update the unlock variable.

Use "get_L_UL;" to see if a level is unlocked and to update the unlock variable.

use "give_C_UL;" to unlock or lock character(s) and change the stored variabl.

use "give_C_UL;" to unlock or lock level(s) and change the stored variabl.
*/

void get_character_unlocks(bool &CharacterUnlock_ID00, bool &CharacterUnlock_ID01, bool &CharacterUnlock_ID02, bool &CharacterUnlock_ID03, bool &CharacterUnlock_ID04,
	bool &CharacterUnlock_ID05, bool &CharacterUnlock_ID06, bool &CharacterUnlock_ID07, bool &CharacterUnlock_ID08, bool &CharacterUnlock_ID09,
	bool &CharacterUnlock_ID10, bool &CharacterUnlock_ID11, bool &CharacterUnlock_ID12)
{
	std::ifstream ifile("char_unlocks.txt");
	ifile >> CharacterUnlock_ID00 &&
		ifile >> CharacterUnlock_ID01 &&
		ifile >> CharacterUnlock_ID02 &&
		ifile >> CharacterUnlock_ID03 &&
		ifile >> CharacterUnlock_ID04 &&
		ifile >> CharacterUnlock_ID05 &&
		ifile >> CharacterUnlock_ID06 &&
		ifile >> CharacterUnlock_ID07 &&
		ifile >> CharacterUnlock_ID08 &&
		ifile >> CharacterUnlock_ID09 &&
		ifile >> CharacterUnlock_ID10 &&
		ifile >> CharacterUnlock_ID11 &&
		ifile >> CharacterUnlock_ID12;
	ifile.close();
}

void get_level_unlocks(bool &LevelUnlock_ID00, bool &LevelUnlock_ID01, bool &LevelUnlock_ID02, bool &LevelUnlock_ID03, bool &LevelUnlock_ID04,
	bool &LevelUnlock_ID05, bool &LevelUnlock_ID06, bool &LevelUnlock_ID07)
{
	std::ifstream ifile("lvl_unlocks.txt");
	ifile >> LevelUnlock_ID00 &&
		ifile >> LevelUnlock_ID01 &&
		ifile >> LevelUnlock_ID02 &&
		ifile >> LevelUnlock_ID03 &&
		ifile >> LevelUnlock_ID04 &&
		ifile >> LevelUnlock_ID05 &&
		ifile >> LevelUnlock_ID06 &&
		ifile >> LevelUnlock_ID07;
	ifile.close();
}

void give_character_unlocks(bool &CharacterUnlock_ID00, bool &CharacterUnlock_ID01, bool &CharacterUnlock_ID02, bool &CharacterUnlock_ID03, bool &CharacterUnlock_ID04,
	bool &CharacterUnlock_ID05, bool &CharacterUnlock_ID06, bool &CharacterUnlock_ID07, bool &CharacterUnlock_ID08, bool &CharacterUnlock_ID09,
	bool &CharacterUnlock_ID10, bool &CharacterUnlock_ID11, bool &CharacterUnlock_ID12)
{
	std::ofstream ofile("char_unlocks.txt");
	ofile << CharacterUnlock_ID00 << "\n";
	ofile << CharacterUnlock_ID01 << "\n";
	ofile << CharacterUnlock_ID02 << "\n";
	ofile << CharacterUnlock_ID03 << "\n";
	ofile << CharacterUnlock_ID04 << "\n";
	ofile << CharacterUnlock_ID05 << "\n";
	ofile << CharacterUnlock_ID06 << "\n";
	ofile << CharacterUnlock_ID07 << "\n";
	ofile << CharacterUnlock_ID08 << "\n";
	ofile << CharacterUnlock_ID09 << "\n";
	ofile << CharacterUnlock_ID10 << "\n";
	ofile << CharacterUnlock_ID11 << "\n";
	ofile << CharacterUnlock_ID12;
	ofile.close();
}

void give_level_unlocks(bool &LevelUnlock_ID00, bool &LevelUnlock_ID01, bool &LevelUnlock_ID02, bool &LevelUnlock_ID03, bool &LevelUnlock_ID04,
	bool &LevelUnlock_ID05, bool &LevelUnlock_ID06, bool &LevelUnlock_ID07)
{
	std::ofstream ofile("lvl_unlocks.txt");
	ofile << LevelUnlock_ID00 << "\n";
	ofile << LevelUnlock_ID01 << "\n";
	ofile << LevelUnlock_ID02 << "\n";
	ofile << LevelUnlock_ID03 << "\n";
	ofile << LevelUnlock_ID04 << "\n";
	ofile << LevelUnlock_ID05 << "\n";
	ofile << LevelUnlock_ID06 << "\n";
	ofile << LevelUnlock_ID07;
	ofile.close();
}

#define getCharacterUnlocks get_character_unlocks(CharacterUnlock_ID00,CharacterUnlock_ID01,CharacterUnlock_ID02,CharacterUnlock_ID03,CharacterUnlock_ID04,CharacterUnlock_ID05,CharacterUnlock_ID06,CharacterUnlock_ID07,CharacterUnlock_ID08,CharacterUnlock_ID09,CharacterUnlock_ID10,CharacterUnlock_ID11,CharacterUnlock_ID12)
#define getLevelUnlocks get_level_unlocks(LevelUnlock_ID00,LevelUnlock_ID01,LevelUnlock_ID02,LevelUnlock_ID03,LevelUnlock_ID04,LevelUnlock_ID05,LevelUnlock_ID06,LevelUnlock_ID07)
#define giveCharacterUnlocks give_character_unlocks(CharacterUnlock_ID00,CharacterUnlock_ID01,CharacterUnlock_ID02,CharacterUnlock_ID03,CharacterUnlock_ID04,CharacterUnlock_ID05,CharacterUnlock_ID06,CharacterUnlock_ID07,CharacterUnlock_ID08,CharacterUnlock_ID09,CharacterUnlock_ID10,CharacterUnlock_ID11,CharacterUnlock_ID12)
#define giveLevelUnlocks give_level_unlocks(LevelUnlock_ID00,LevelUnlock_ID01,LevelUnlock_ID02,LevelUnlock_ID03,LevelUnlock_ID04,LevelUnlock_ID05,LevelUnlock_ID06,LevelUnlock_ID07)