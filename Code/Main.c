
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "Descript.h"

#define and &&
#define or ||
#define in ==
#define is ==



#define as(x) >=x
#define to(y) <=y


bool In(char s, char String[]) {
	
	for(size_t index = 0; index < strlen(String); index ++) if(s == String[index]) return true;
	
	return false;
}


char* ReadLine(char String[]) {
	
	scanf("%s", String);
	
	return String;
}

char* Format(char String[]) {

	for(size_t index = 0; index < strlen(String); index ++) {
		
		if(String[index] >= '0' and String[index] <= '9') continue;
		if(In(String[index],"+-*/")) continue;
		
		String[index] = '\x20';
	}


	return String;
}

int* Write(char String[], int Index) {

	int* result = NULL;
	
	result = (int* )realloc(result, sizeof(int) * Index);
	
	memset(result, 0, sizeof(String));

	for(size_t index = 0,n = 0; index < strlen(String); index ++) {
			
		if(String[index] as('0') and String[index] to('9')) {
			result[n] = result[n] + String[index] - 48;
			
			if(index + 1 < strlen(String) and String[index + 1] as('0') and String[index + 1] to('9')) {
				result[n] *= 10;
				continue;
			}
			
			Index --;
			n ++;
		}
		
		
		
		if(Index is 0) {
			break;
		}
		
	}


	return result;
}

int main(void) {

	char Formula[512] = "";
	
	strcpy(Formula, ReadLine(Formula));
	
	strcpy(Formula, Format(Formula));
	
	printf("%d", Write(Formula,2)[1]);
	
	
	
	
	
	return 0;
}
