#include "wifiscan.h"
#include "screen.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void){
	while(1){
		system(CMD);
		clearScreen();
		read_display();
		sleep(5);
	}
}