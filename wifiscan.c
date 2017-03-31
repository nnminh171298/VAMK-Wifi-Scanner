#include "wifiscan.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int read_data(void){
	FILE *fp;
	char line[200];
	int c;
	WIFI_INFO wf;

	if((fp = fopen("scan.txt", "r"))==NULL){
		printf("Cannot open file %s\n", "scan.txt");
		return 1;
	}

	while(fgets(line, 200, fp)!=NULL){
		remove_spaces(line);
		if(strncmp(line, "Cell", 4) == 0){
			c = 0;
			get_MAC(line, wf.MAC);
#ifdef DEBUG
			printf("MAC: %x:%x:%x:%x:%x:%x\t\t", wf.MAC[0], wf.MAC[1], wf.MAC[2], wf.MAC[3], wf.MAC[4], wf.MAC[5]);
#endif
		}
		else{
			c++;
			if(c == 1){
				wf.frequency =  get_freq(line);
#ifdef DEBUG
				printf("Frequency: %.3f\t", wf.frequency);
#endif
			}
			if(c == 2){
				wf.slevel = get_slevel(line);
#ifdef DEBUG
				printf("Signal level: -%d\t", wf.slevel);
#endif
			}
			if(c == 3){
				get_essid(line, wf.essid);
#ifdef DEBUG
				printf("ESSID: %s\n", wf.essid);
#endif
			}
		}
	}
	printf("---------------End Of File--------------\n");
	fclose(fp);
}

void get_MAC(char s[], unsigned char mac[]){
	int i;
	char *token;
	strtok(s, " :");
	for(i=0; i<6; i++){
		token = strtok(NULL, ":");
		mac[i] = token[0] + token[1];
	}
}

double get_freq(char s[]){
	char *token;
	double temp;
	strtok(s, ":");
	token = strtok(NULL, " ");
	sscanf(token, "%lf", &temp);
	return temp;
}

int get_slevel(char s[]){
	char *token;
	strtok(s, "-");
	token = strtok(NULL, " ");
	return atoi(token);
}

void get_essid(char s[], char essid[]){
	char *token;
	strtok(s, "\"");
	token = strtok(NULL, "\"");
	// strtok treats 2 consecutive tokens as 1
	if(token[0] == '\n')
		essid[0] = '\0';
	else
		strcpy(essid, token);
}

void remove_spaces(char s[]){
	int i, len = strlen(s);
	for(i=0; i<len; i++)
		if(s[i]!=' ' && s[i]!='\n' && s[i]!='\t')
			break;
	strcpy(s, &s[i]);
}