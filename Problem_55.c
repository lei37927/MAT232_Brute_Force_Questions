#include <stdio.h>

#define RANGE 100

int main() {
	// variable declaration
	char grid[RANGE][RANGE];
	int i,j;
	
	// initialization
	for(i = 0; i < RANGE; i++) {
		for(j = 0; j < RANGE; j++) {
			grid[i][j] = ' ';
		}
	}
	
	// set state
	grid[1][0] = '*';
	
	// calculate
	for(i = 0; i < RANGE; i++) {
		for(j = 0; j < RANGE; j++) {
			if(grid[i][j] == '*') {
				if(i+j < RANGE) {
					grid[i+j][j] = '*';
					grid[i][j+i] = '*';
				}
			}
		}
	}
	
	// print
	for(i = 0; i < RANGE; i++) {
		for(j = 0; j < RANGE; j++) {
			printf("%c",grid[i][j]);
		}
		printf("\n");
	}
	
	// end
	printf("\n");
	return 0;
}
