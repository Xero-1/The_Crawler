#ifndef MAP_H
#define MAP_H

enum class LAYERS
{
	TERRAIN=0,
	ITEMS,
	CREATURES
};

class Map
{
public:
	Map();
	~Map();
	inline char getTerrain(unsigned int y,unsigned int x){return this->cCanvas[y][x];}
private:
	char cCanvas[30][80];
};

#endif
