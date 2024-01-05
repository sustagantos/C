#ifndef _MAP_H_
#define _MAP_H_


#define HERO '@'
#define EMPTY '.'
#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL '-'
#define GHOST 'G'
#define PILL 'P'


typedef struct MAP{
	char** matrix;
	int lines;
	int columns; 
} map;

typedef struct POSITION{
	int x;
	int y;
} position;


void mapAlloc(map* m);

void readMap(map* m);

void freeMap(map* m);

int InMapFind(map* m, position* p, char c);

int isValidPosition(map* m, int x, int y);

void copyMap(map* destinyMap, map* originMap);

int isCharacter(map* m, char character, int x, int y);

int isWall(map* m, int x, int y);

void walk(map* m, int originX, int originY, 
	int destinyX, int destinyY);
	
int canWalk(map* m, char character, int x, int y);


#endif