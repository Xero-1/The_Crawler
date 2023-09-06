#include "Roll.h"

int roll(unsigned rolls,unsigned int faces,int mod)
{
	int result=0;
	for(int i=0;i<rolls;i++)
		result+=rand()%faces+1;
	return result+mod;
}
int roll(Dice d)
{
	return roll(d.ROLLS,d.FACES,d.MOD);
}
