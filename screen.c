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
	ch = (int)((freq-2.412)*1000)/5+1;		// calculate the channel
	setFGcolor(31+ch%7);
	for(i=0; i<33-level/3; i++){
		gotoXY(34-i, ch*6+26);
		printf("%s", VER);
		gotoXY(34-i, ch*6+2);
		printf("%s", VER);
	}
	for(k=0; k<25; k++){
		gotoXY(34-i, ch*6+2+k);
		if(k==0 || k==24)						// 2 corners
			printf("%s", COR);
		else if(k>1 && k<23 && k<strlen(id)+2)	// from k=2, end when k=23 or string ends
			printf("%c", id[k-2]);
		else									// the rest of the cases
			printf("%s", HOR);
	}
	fflush(stdout);
}

void displayBack(void){
	int i, k;
	for(i=0; i<34; i+=2){				// print the y-axis
		gotoXY(i+1, 1);
		printf("-%2d", i*3);
/*		if(i!=0 & !(i%5))
			for(k=4; k<110; k++){		// print the horizontal lines each 15dB
				gotoXY(i+1, k);
				printf("-");
			}
*/	}
	k=0;
	for(i=0; i<=96; i++){				// print the x-axis
		if(i%6 == 0){
			k++;
			if(k>2 && k<16){
				gotoXY(36, i+8);
				printf("%d", k-2);
			}
		}
		gotoXY(35, i+8);
		printf("%s", HOR);
	}
	fflush(stdout);
}