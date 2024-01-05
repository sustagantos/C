#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include <string.h>

void readMap(map* m) {		//reads map from txt file, allocs and creates map in c
	FILE* f;
	f = fopen("map.txt", "r");
	if(f == 0) {
		printf("Couldn't read map.txt");
		exit(1);
	}

	fscanf(f, "%d %d", &(m->lines), &(m->columns));		//reads first line of map.txt, (quantity of lin. and col.)
	mapAlloc(m);
	
	for(int i = 0; i < m->lines; i++) {		//scans txt file and put in matrix
		fscanf(f, "%s", m->matrix[i]);
	}

	fclose(f);
}

void mapAlloc(map* m) {		//allocs the memory to the map, based on lines and columns it has
	m->matrix = malloc(sizeof(char*) * m->lines);

	for(int i = 0; i < m->lines; i++) {
		m->matrix[i] = malloc(sizeof(char) * m->columns + 1);
	}
}

void copyMap(map* destinyMap, map* originMap) {		//copy second to first map
	destinyMap->lines = originMap->lines;
	destinyMap->columns = originMap->columns;		//copy lines and columns

	mapAlloc(destinyMap);
	for(int i = 0; i < originMap->lines; i++) {
		strcpy(destinyMap->matrix[i], originMap->matrix[i]);
	}
}


void freeMap(map* m) {		//frees map memory
	for(int i = 0; i < m->lines; i++) {
		free(m->matrix[i]);
	}

	free(m->matrix);
}


int InMapFind(map* m, position* p, char c) {		//searches for a char in a map, if it is found,
													//returns its position inside p
	for(int i = 0; i < m->lines; i++) {
		for(int j = 0; j < m->columns; j++) {
			if(m->matrix[i][j] == c) {
				p->x = i;
				p->y = j;
				return 1;
			}
		}
	}

	return 0;
}

int canWalk(map* m, char character, int x, int y) {	//returns if hero can walk to that position
	return 
		isValidPosition(m, x, y) && 	//if index !out of range
		!isWall(m, x, y) &&	//if it's not wall
		!isCharacter(m, character, x, y);		//and if it's not character
}

int isValidPosition(map* m, int x, int y) {		//checks if parameter position is valid to move
	if(x >= m->lines) 
		return 0;
	if(y >= m->columns) 
		return 0;

	return 1;	
}

int isCharacter(map* m, char character, int x, int y) {		//returns if parameter character is in that position
	return m->matrix[x][y] == character;
}

int isWall(map* m, int x, int y) {		//returns if that position is or isn't wall
	return 
		m->matrix[x][y] == VERTICAL_WALL ||
		m->matrix[x][y] == HORIZONTAL_WALL;
}


void walk(map* m, int originX, int originY, 
	int destinyX, int destinyY) {		//walks to that position		

	char character = m->matrix[originX][originY];
	m->matrix[destinyX][destinyY] = character;
	m->matrix[originX][originY] = EMPTY;

}