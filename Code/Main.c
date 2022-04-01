
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

int* WriteNums(char String[], int Index) {

	int* result = NULL;
	
	result = (int* )realloc(result, sizeof(int) * Index);
	
	memset(result, 0, sizeof(int) * Index);

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

char* WriteSymbols(char String[], int Index) {
	
	char* result = NULL;
	
	result = (char* )realloc(result, sizeof(char) * Index);
	
	memset(result, 0, sizeof(String));

	for(size_t index = 0,n = 0; index < strlen(String); index ++) {
			
		if(In(String[index], "+-*/")) {
			result[n] = String[index];
			
			Index --;
			n ++;
		}
		
		
		
		if(Index is 0) {
			break;
		}
		
	}


	return result;	
	
}


int Computer(int num1, int num2, char Symbol) {

	int result = 0;

	switch(Symbol) {
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			result = num1 / num2;
			break;
		
		default:
			break;
	}


	return result;
}




int main(void) {

	char Formula[512] = "";
	
	strcpy(Formula, ReadLine(Formula));
	strcpy(Formula, Format(Formula));
	
	int* nums = WriteNums(Formula,3);
	char* symbols = WriteSymbols(Formula,10);
	
	
	for(int i = 0; i to(sizeof(nums) / sizeof(nums[0])) - 1; i ++) {
		printf("%d - ", nums[i]);
	}
	
	
	
	
	
	
	int r = 0;
	for(size_t SymbolsIndex = 0, NumsIndex = 0; SymbolsIndex <= strlen(symbols); SymbolsIndex ++, NumsIndex += 2) {
		
		if((NumsIndex + 1) as(sizeof(nums) / sizeof(nums[0]))) {
			
			r = r + Computer(nums[NumsIndex], 0, symbols[SymbolsIndex]);
			printf("r + Êý×Ö%d  = %d",nums[NumsIndex], r);
			
			break;
		}
		r = r + Computer(nums[NumsIndex], nums[NumsIndex + 1], symbols[SymbolsIndex]);
		
		printf("Êý×Ö%d Óë %d = %d",nums[NumsIndex], nums[NumsIndex+1], r);
	
	}
	

	
	
	
	
	
	return 0;
}
