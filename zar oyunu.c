#include<stdio.h>
#include<stdlib.h>
#include<time.h>

enum status {CONTINUE, WON, LOST};

int rolldice (void);

int main () {
	
	int sum, mypoint;
	enum status gamestatus;
	
	srand(time(NULL));
	sum = rolldice();
	
	switch (sum) {
		
		case 7:
		case 11:
			gamestatus = WON;
			break;
			
		case 2:
		case 3:
		case 12:
			gamestatus = LOST;
			break;
			
		default:
			mypoint = sum;
			gamestatus = CONTINUE;
			printf("My point is %d\n", mypoint);
			break;
	}
	
	while (gamestatus == CONTINUE) {
		
		sum = rolldice();
		
		if (sum == mypoint) {
			
			gamestatus = WON;
		}
		
		else {
			
			if (sum == 7) {
				
				gamestatus = LOST;
			}
		}
	}
	
	if (gamestatus == WON) {
		
		puts("player wins");
	}
	
	else {
		
		puts("player loses");
	}
}

int rolldice (void) {
	
	int dice1, dice2, worksum;
	
	dice1 = 1 + (rand() %6);
	dice2 = 1 + (rand() %6);
	worksum = dice1 + dice2;
	
	printf("player rolled %d + %d = %d\n", dice1, dice2, worksum);
	
	return worksum;
}
