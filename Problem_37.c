#include <stdio.h>

// change iterations number if you need
#define ITERATION 20

#define CAPACITY 16
#define SIZE 15

int main() {
	
	// initialize piles here
	int piles[CAPACITY] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0};
	
	int count;
	int index;
	
	// I'm using single-letter variable here~
	int i;
	
	for(index = 0; index < ITERATION; index++) {
		
		// print piles
		for(i = 0; i < SIZE; i++) {
			printf("%4d", piles[i]);
		}
		
		printf("\n\n");
		
		// arrange piles to ensure no empty place
		for(i = 0; i < SIZE; i++) {
			if(piles[i] == 0) {
				while(i < SIZE) {
					piles[i] = piles[i + 1];
					i++;
				}
			}
		}
		
		// count the number of piles
		count = 0;
		for(i = 0; i < SIZE; i++) {
			if(piles[i] != 0) {
				count++;
			}
		}
		
		// move each pile back and make a new one at 0
		int temp = count;
		while(count > 0) {
			piles[count] = piles[count - 1];
			count--;
		}
		for(i = 1; i < CAPACITY; i++) {
			if(piles[i] > 0) {
				piles[i]--;
			}
		}
		count = temp;
		piles[0] = count;
	}
	
	return 0;
}
