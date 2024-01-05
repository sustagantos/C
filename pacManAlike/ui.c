#include <stdio.h>
#include "map.h"

char wallDraw[4][7] = {
	{"......" },
	{"......" },
	{"......" },
	{"......" }
};

char ghostDraw[4][7] = {
	{" .-.  " },
	{"| OO| " },
	{"|   | " },
	{"'^^^' " }
};

char heroDraw[4][7] = {
	{" .--. "  },
	{"/ _.-'"  },
	{"\\  '-." },
	{" '--' "  }
};

char pillDraw[4][7] = {
	{"      "},
	{" .-.  "},
	{" '-'  "},
	{"      "}
};

char emptyDraw[4][7] = {
	{"      "},
	{"      "},
	{"      "},
	{"      "}
};

void printPart(char draw[4][7], int part) {		//prints a part of the draw, only a row
	printf("%s", draw[part]);
}

void printMap(map* m) {		//prints the whole wide map
	for(int i = 0; i < m->lines; i++) {

		for(int part = 0; part < 4; part++) {
			for(int j = 0; j < m->columns; j++) {

				switch(m->matrix[i][j]) {
					case GHOST:
						printPart(ghostDraw, part);
						break;
					case HERO:
						printPart(heroDraw, part);
						break;
					case PILL:
						printPart(pillDraw, part);
						break;
					case VERTICAL_WALL:
					case HORIZONTAL_WALL:
						printPart(wallDraw, part);
						break;
					case EMPTY:
						printPart(emptyDraw, part);
						break;
				}
				
			}
			printf("\n");
		}

	}
}