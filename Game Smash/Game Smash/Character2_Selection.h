#pragma once

do{
	if (Character2_Selection == 0 && CharacterUnlock_ID00)
	{
		Character2_Sprite.setTexture(C_T_ID00);
		Character2_Selection_Repeat = 0;
	}
	else if (Character2_Selection == 1 && CharacterUnlock_ID01)
	{
		Character2_Sprite.setTexture(C_T_ID01);
		Character2_Selection_Repeat = 0;
	}
	else if (Character2_Selection == 2 && CharacterUnlock_ID02)
	{
		Character2_Sprite.setTexture(C_T_ID02);
		Character2_Selection_Repeat = 0;
	}
	else if (Character2_Selection == 3 && CharacterUnlock_ID03)
	{
		Character2_Sprite.setTexture(C_T_ID03);
		Character2_Selection_Repeat = 0;
	}
	else if (Character2_Selection == 4 && CharacterUnlock_ID04)
	{
		Character2_Sprite.setTexture(C_T_ID04);
		Character2_Selection_Repeat = 0;
	}
	else if (Character2_Selection == 5 && CharacterUnlock_ID05)
	{
		Character2_Sprite.setTexture(C_T_ID05);
		Character2_Selection_Repeat = 0;
	}
	else if (Character2_Selection == 6 && CharacterUnlock_ID06)
	{
		Character2_Sprite.setTexture(C_T_ID06);
		Character2_Selection_Repeat = 0;
	}
	else if (Character2_Selection == 7 && CharacterUnlock_ID07)
	{
		Character2_Sprite.setTexture(C_T_ID07);
		Character2_Selection_Repeat = 0;
	}
	else if (Character2_Selection == 8 && CharacterUnlock_ID08)
	{
		Character2_Sprite.setTexture(C_T_ID08);
		Character2_Selection_Repeat = 0;
	}
	else if (Character2_Selection == 9 && CharacterUnlock_ID09)
	{
		Character2_Sprite.setTexture(C_T_ID09);
		Character2_Selection_Repeat = 0;
	}
	else if (Character2_Selection == 10 && CharacterUnlock_ID10)
	{
		Character2_Sprite.setTexture(C_T_ID10);
		Character2_Selection_Repeat = 0;
	}
	else if (Character2_Selection == 11 && CharacterUnlock_ID11)
	{
		Character2_Sprite.setTexture(C_T_ID11);
		Character2_Selection_Repeat = 0;
	}
	else if (Character2_Selection == 12 && CharacterUnlock_ID12)
	{
		Character2_Sprite.setTexture(C_T_ID12);
		Character2_Selection_Repeat = 0;
	}
	else
	{
		Character2_Selection_Repeat = 1;
	}
} while (Character2_Selection_Repeat);