#pragma once

do{
	if (Character1_Selection == 0 && CharacterUnlock_ID00)
	{
		Character1_Sprite.setTexture(C_T_ID00);
		Character1_Selection_Repeat = 0;
	}
	else if (Character1_Selection == 1 && CharacterUnlock_ID01)
	{
		Character1_Sprite.setTexture(C_T_ID01);
		Character1_Selection_Repeat = 0;
	}
	else if (Character1_Selection == 2 && CharacterUnlock_ID02)
	{
		Character1_Sprite.setTexture(C_T_ID02);
		Character1_Selection_Repeat = 0;
	}
	else if (Character1_Selection == 3 && CharacterUnlock_ID03)
	{
		Character1_Sprite.setTexture(C_T_ID03);
		Character1_Selection_Repeat = 0;
	}
	else if (Character1_Selection == 4 && CharacterUnlock_ID04)
	{
		Character1_Sprite.setTexture(C_T_ID04);
		Character1_Selection_Repeat = 0;
	}
	else if (Character1_Selection == 5 && CharacterUnlock_ID05)
	{
		Character1_Sprite.setTexture(C_T_ID05);
		Character1_Selection_Repeat = 0;
	}
	else if (Character1_Selection == 6 && CharacterUnlock_ID06)
	{
		Character1_Sprite.setTexture(C_T_ID06);
		Character1_Selection_Repeat = 0;
	}
	else if (Character1_Selection == 7 && CharacterUnlock_ID07)
	{
		Character1_Sprite.setTexture(C_T_ID07);
		Character1_Selection_Repeat = 0;
	}
	else if (Character1_Selection == 8 && CharacterUnlock_ID08)
	{
		Character1_Sprite.setTexture(C_T_ID08);
		Character1_Selection_Repeat = 0;
	}
	else if (Character1_Selection == 9 && CharacterUnlock_ID09)
	{
		Character1_Sprite.setTexture(C_T_ID09);
		Character1_Selection_Repeat = 0;
	}
	else if (Character1_Selection == 10 && CharacterUnlock_ID10)
	{
		Character1_Sprite.setTexture(C_T_ID10);
		Character1_Selection_Repeat = 0;
	}
	else if (Character1_Selection == 11 && CharacterUnlock_ID11)
	{
		Character1_Sprite.setTexture(C_T_ID11);
		Character1_Selection_Repeat = 0;
	}
	else if (Character1_Selection == 12 && CharacterUnlock_ID12)
	{
		Character1_Sprite.setTexture(C_T_ID12);
		Character1_Selection_Repeat = 0;
	}
	else
	{
		Character1_Selection_Repeat = 1;
	}
} while (Character1_Selection_Repeat);