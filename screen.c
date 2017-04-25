#include "screen.h"
#include "wifiscan.h"
#include <string.h>
#include <stdio.h>

void setFGcolor(int fg){
	printf("\033[%d;1m", fg);
	fflush(stdout);
}

void resetColors(void){
	printf("\033[0m");
	fflush(stdout);
}

void gotoXY(int row, int col){
	printf("\033[%d;%dH", row, col);
	fflush(stdout);
}

void clearScreen(void){
	printf("\033[2J");
	fflush(stdout);
}

void displayBar(char *id, double freq, int level){
	int i, k, ch;
	ch = (((int)(freq-2.412))*1000)%5+1;		// calculate the channel
	printf("\n%d", ch);
	for(i=0; i>level; i-=3){
		setFGcolor(31-i%7);
		gotoXY(30+i/3, ch*6+18);
		printf("%s", VER);
		gotoXY(30+i/3, -6+ch*6);
		printf("%s", VER);
	}
/*	for(k=0; k<13; k++){
		gotoXY(30+i, -6+ch*6+k);
		if(k==0 || k==12)						// 2 corners
			printf("%s", COR);
		else if(k>1 && strlen(id)>k && k<11)	// from k=2, end when k=10 or string ends
			printf("%s", id[k-2]);
		else									// the rest of the cases
			printf("%s", HOR);
	}
*/	fflush(stdout);
}

void displayBack(void){
	int i, k;
	for(i=0; i<34; i++){
		gotoXY(i+1, 1);
		printf("-%2d", i*3);
		if(i!=0 & !(i%5))
			for(k=4; k<110; k++){
				gotoXY(i+1, k);
				printf("-");
			}
	}
	k=0;
	for(i=0; i<96; i++){
		if(i%6 == 0){
			k++;
			if(k>2 && k<16){
				gotoXY(36, i+8);
				printf("%d", k-2);
			}
			i++;
		}
		gotoXY(35, i+8);
		printf("%c", 'i');
	}
	fflush(stdout);
}