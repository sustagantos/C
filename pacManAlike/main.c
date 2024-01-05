#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "main.h"
#include "map.h"
#include "ui.h"

map m;
position hero;
int hasPill = 0;

int result() {		//checks if it's over
	position pos;

	int lost = !InMapFind(&m, &pos, HERO);
	int won = !InMapFind(&m, &pos, GHOST);

	return won || lost;
		
}

int isValidDirection(char direction) {		//checks if it's a valid direction
	return
		direction == LEFT || 
		direction == UP ||
		direction == DOWN ||
		direction == RIGHT;
}

void movesHero(char direction) {		//moves hero

	int nextX = hero.x;
	int nextY = hero.y;

	switch(direction) {
		case LEFT:
			nextY--;
			break;
		case UP:
			nextX--;
			break;
		case DOWN:
			nextX++;
			break;
		case RIGHT:
			nextY++;
			break;
	}

	if(!canWalk(&m, HERO, nextX, nextY))
		return;

	if(isCharacter(&m, PILL, nextX, nextY)) {
		hasPill=1;
	}

	walk(&m, hero.x, hero.y, nextX, nextY);
	hero.x = nextX;
	hero.y = nextY;
}

int ghostMove(int originX, int originY, 
	int* destinyX, int* destinyY) {		//moves randomly each ghost

	int options[4][2] = { 	//available move options (w,a,s,d)
		{ originX   , originY+1 }, 
		{ originX+1 , originY   },  
		{ originX   , originY-1 }, 
		{ originX-1 , originY   }
	};

	srand(time(0));

	for(int i = 0; i < 10; i++) {
		int position = rand() % 4;

		if(canWalk(&m, GHOST, options[position][0], options[position][1])) {
			*destinyX = options[position][0];
			*destinyY = options[position][1];
			return 1;
		}
	}

	return 0;
}

void ghosts() {		//copies the map, makes the ghosts walk, erase previous map
	map mapCopy;

	copyMap(&mapCopy, &m);

	for(int i = 0; i < mapCopy.lines; i++) {
		for(int j = 0; j < mapCopy.columns; j++) {
			if(mapCopy.matrix[i][j] == GHOST) {

				int destinyX;
				int destinyY;

				int isFound = ghostMove(i, j, &destinyX, &destinyY);

				if(isFound) {
					walk(&m, i, j, destinyX, destinyY);
				}
			}
		}
	}

	freeMap(&mapCopy);
}

void explodePill02(int x, int y, int sumX, int sumY, int quantity) {	//explode pills, if there is

	if(quantity == 0){
		return;
	}

	int newX = x+sumX;
	int newY = y+sumY;

	if(!isValidPosition(&m, newX, newY)){
		return;
	}

	if(isWall(&m, newX, newY)){
		return;
	}

	m.matrix[newX][newY] = EMPTY;
	explodePill02(newX, newY, sumX, sumY, quantity-1);
}

void explodePill() {	//explode pill in all directions
	if(!hasPill){
		return;
	}
	explodePill02(hero.x, hero.y, 0, 1, 3);
	explodePill02(hero.x, hero.y, 0, -1, 3);
	explodePill02(hero.x, hero.y, 1, 0, 3);
	explodePill02(hero.x, hero.y, -1, 0, 3);
	
	hasPill -= 1;
}

int main() {
	
	readMap(&m);
	InMapFind(&m, &hero, HERO);

	do {
		printf("PILL: %s\n", (hasPill ? "Y" : "N"));
		printMap(&m);

		char command;
		scanf(" %c", &command);

		if(isValidDirection(command)){
			movesHero(command);
		}	
		
		if(command == BOMB){
			explodePill();
		}

		ghosts();

	} while (!result());

	freeMap(&m);
}