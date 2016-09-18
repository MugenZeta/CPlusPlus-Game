#pragma once

do{
	if (Level_Selection == 0 && LevelUnlock_ID00)
	{
		Level_Sprite.setTexture(L_T_ID00);
		LevelBackground_Sprite.setTexture(LB_T_ID00);
		Ground_Origin = sf::Vector2f(0, 570);
		Ground_Size = sf::Vector2f(800, 70);
		Character1_Origin = sf::Vector2f(0, 0);
		Character2_Origin = sf::Vector2f(704, 0);
		Level_Selection_Repeat = 0;
	}
	else if (Level_Selection == 1 && LevelUnlock_ID01)
	{
		Level_Sprite.setTexture(L_T_ID01);
		LevelBackground_Sprite.setTexture(LB_T_ID01);
		Level_Selection_Repeat = 0;
	}
	else if (Level_Selection == 2 && LevelUnlock_ID02)
	{
		Level_Sprite.setTexture(L_T_ID02);
		LevelBackground_Sprite.setTexture(LB_T_ID02);
		Level_Selection_Repeat = 0;
	}
	else if (Level_Selection == 3 && LevelUnlock_ID03)
	{
		Level_Sprite.setTexture(L_T_ID03);
		LevelBackground_Sprite.setTexture(LB_T_ID03);
		Level_Selection_Repeat = 0;
	}
	else if (Level_Selection == 4 && LevelUnlock_ID04)
	{
		Level_Sprite.setTexture(L_T_ID04);
		LevelBackground_Sprite.setTexture(LB_T_ID04);
		Level_Selection_Repeat = 0;
	}
	else if (Level_Selection == 5 && LevelUnlock_ID05)
	{
		Level_Sprite.setTexture(L_T_ID05);
		LevelBackground_Sprite.setTexture(LB_T_ID05);
		Level_Selection_Repeat = 0;
	}
	else if (Level_Selection == 6 && LevelUnlock_ID06)
	{
		Level_Sprite.setTexture(L_T_ID06);
		LevelBackground_Sprite.setTexture(LB_T_ID06);
		Level_Selection_Repeat = 0;
	}
	else if (Level_Selection == 7 && LevelUnlock_ID07)
	{
		Level_Sprite.setTexture(L_T_ID07);
		LevelBackground_Sprite.setTexture(LB_T_ID07);
		Level_Selection_Repeat = 0;
	}
	else
	{
		Level_Selection_Repeat = 1;
	}
} while (Level_Selection_Repeat);