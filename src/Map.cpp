#include "Map.h"

Map::Map()
{
	for(int i=0;i<30;i++)
	{
		for(int j=0;j<80;j++)
		{
			this->cCanvas[i][j]='#';
		}
	}
}
Map::~Map(){}
