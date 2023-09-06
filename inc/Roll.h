#ifndef ROLL_H
#define ROLL_H

#include <cstdlib>

struct Dice
{
	unsigned int ROLLS;
	unsigned int FACES;
	int MOD;
};

int roll(unsigned int rolls,unsigned int faces,int mod);
int roll(Dice d);

#endif
