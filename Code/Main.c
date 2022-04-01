
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "Platform.Win64.h"
#include "Descript.h"

#define and &&
#define or ||
#define in ==
#define is ==
#define not !

// only used at for( ...; ...; index step 2)
//              for( ...; ...; index += 2)
#define step +=


#define as(x) >=x
#define to(y) <=y

#define asWithout(x) >x
#define toWithout(y) <y

#define without(x) -x
#define with(y) +y



bool In(char s, char String[]) {
	
	for(size_t index = 0; index toWithout(strlen(String)); index step(1)) if(s is String[index]) return true;
	
	return false;
}

char* ReadLine(char String[]) {
	
	//scanf("%s", String);
	
	char c = 0;
	c = getchar();
	
	for(size_t index = 0; c != '\n'; c = getchar()) if(c != '\x20') {
                String[index] = c;
                index ++;
        }
	
	
	return String;
}

char* Format(char String[]) {

	for(size_t index = 0; index toWithout(strlen(String)); index step(1)) {
		
		if(!(String[index] as('0') and String[index] to('9'))) continue;
		if(!In(String[index],"+-*/")) continue;
		
	}


	return String;
}

int* WriteNums(char String[], int Index) {

	int* result = NULL;
	
	result = (int* )realloc(result, sizeof(int) * Index);
	
	memset(result, 0, sizeof(int) * Index);



	for(size_t index = 0, n = 0; index toWithout(strlen(String)); index step(1)) {
			
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
	
	memset(result, 0, sizeof(char) * Index);

	for(size_t index = 0,n = 0; index toWithout(strlen(String)); index step(1)) {
			
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


size_t CountNums(char String[]) {
	
	size_t Count = 0;
	
	for(size_t index = 0; index toWithout(strlen(String)); index step(1)) if(String[index] as('0') and String[index] to('9')) {
		Count ++;
	}
	
	return Count;
}

size_t CountSymbols(char String[]) {
	
	size_t Count = 0;
	
	for(size_t index = 0; index toWithout(strlen(String)); index step(1)) if(In(String[index], "+-*/")) {
		Count ++;
	}
	
	return Count;
}

int main(void) {
        
        
        SetWindowsSize(30, 120);
        system("color F0");
        
        
        
        
        
        
        
        
        
        
        
        
        
        

	char Formula[512] = "";
	
	strcpy(Formula, ReadLine(Formula));
	
        
        
        
        
        strcpy(Formula, Format(Formula));
	
	int* nums = NULL;
	char* symbols = NULL;

	size_t NumsLength = CountNums(Formula);
	size_t SymbolsLength = CountSymbols(Formula);

	nums = WriteNums(Formula, NumsLength);
	symbols = WriteSymbols(Formula, SymbolsLength);
	

	
	
	
	int r = 0;
	for(size_t SymbolsIndex = 0, NumsIndex = 1; SymbolsIndex toWithout(SymbolsLength); SymbolsIndex step(1), NumsIndex step(1)) {
		
		if(NumsIndex is NumsLength) {
			break;
		}
		
		if(NumsIndex is 1) {
			r = Computer(nums[NumsIndex - 1], nums[NumsIndex], symbols[SymbolsIndex]);
			continue;
		}

		r = Computer(r, nums[NumsIndex], symbols[SymbolsIndex]);		
	}
	
	printf("%d", r);
	
	
	
	
	return 0;
}
