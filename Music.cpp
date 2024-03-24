#include "function.h"

void playMusicBackground(bool sound)
{
	if (sound)
	{
		PlaySound(TEXT("NoiNhoTuaThienHa.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
	else
	{
		PlaySound(0, 0, 0);
	}
}

//void playMusicEffect()
//{
//
//}