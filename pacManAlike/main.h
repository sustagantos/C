#ifndef _MAIN_H_
#define _MAIN_H_

#define UP 'w'
#define DOWN 's'
#define RIGHT 'd'
#define LEFT 'a'
#define BOMB 'b'

int result();
void move(char direction);
int ghostMove(int originX, int originY, 
	int* destinyX, int* destinyY);
int isValidDirection(char direction);
void ghosts();
void explodePill();
void explodePill02(int x, int y, int sumX, int sumY, int quantity);


#endif