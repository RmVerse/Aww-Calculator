
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

#define of =

#define as >=
#define to <=

#define asWithout >
#define toWithout <

#define without(x) -x
#define with(y) +y

#define toString -48


static bool In(const char s, const char Range[]) {

	for (size_t index = 0; index toWithout strlen(Range); index step 1) if (s is Range[index]) return true;

	return false;
}

char* ReadLine(char String[]) {

	char c = 0;
	c = getchar();

	for (size_t index = 0; c != '\n'; c = getchar()) if (c != '\x20') {
			String[index] = c;
			index ++;
		}


	return String;
}

char* Format(char String[]) {

	for (size_t index = 0; index toWithout strlen(String); index step 1) {

		if (!(String[index] as '0' and String[index] to '9')) continue;
		if (!In(String[index], "+-*/")) continue;

	}


	return String;
}




int* WriteNums(char String[], int Index) {

	int* result = NULL;

	result = (int* )realloc(result, sizeof(int) * Index);

	memset(result, 0, sizeof(int) * Index);



	for (size_t index = 0, n = 0; index toWithout strlen(String); index step 1) {

		if (String[index] as('0') and String[index] to('9')) {
			result[n] = result[n] + String[index] - 48;

			if (index + 1 < strlen(String) and String[index + 1] as '0' and String[index + 1] to '9') {
				result[n] *= 10;
				continue;
			}

			Index --;
			n ++;
		}



		if (Index is 0) {
			break;
		}

	}


	return result;
}

char* WriteSymbols(char String[], int Index) {

	char* result = NULL;

	result = (char* )realloc(result, sizeof(char) * Index);

	memset(result, 0, sizeof(char) * Index);

	for (size_t index = 0, n = 0; index toWithout strlen(String); index step 1) {

		if (In(String[index], "+-*/")) {
			result[n] = String[index];

			Index --;
			n ++;
		}



		if (Index is 0) {
			break;
		}

	}


	return result;

}


int Computer(int num1, int num2, char Symbol) {

	int result = 0;

	switch (Symbol) {
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

	for (size_t index = 0; index toWithout strlen(String); index step 1) if (String[index] as('0') and String[index] to '9') {
			Count ++;
		}

	return Count;
}

size_t CountSymbols(char String[]) {

	size_t Count = 0;

	for (size_t index = 0; index toWithout strlen(String); index step 1) if (In(String[index], "+-*/")) {
			Count ++;
		}

	return Count;
}

int PriorityOfLowComput(char Formula[]) {

	int* nums = NULL;
	char* symbols = NULL;

	size_t NumsLength = CountNums(Formula);
	size_t SymbolsLength = CountSymbols(Formula);

	nums = WriteNums(Formula, NumsLength);
	symbols = WriteSymbols(Formula, SymbolsLength);

	int r = 0;
	for (size_t SymbolsIndex = 0, NumsIndex = 1; SymbolsIndex toWithout SymbolsLength; SymbolsIndex step 1, NumsIndex step 1) {

		if (NumsIndex is NumsLength) {
			break;
		}

		if (NumsIndex is 1) {
			r = Computer(nums[NumsIndex - 1], nums[NumsIndex], symbols[SymbolsIndex]);
			continue;
		}

		r = Computer(r, nums[NumsIndex], symbols[SymbolsIndex]);
	}

	// r is that result of computer.
	return r;
}

int NextNum(char Formula[], size_t Index) {
        
        int num = 0;
        
        for(size_t i = Index; i toWithout strlen(Formula); i ++) {
               
                if(Formula[i] toWithout '0' or Formula[i] asWithout '9') {
                        break;
                }
               
               num = num * 10 + Formula[i] toString;
        }
        
        
        
        return num;
}

int LastNum(char Formula[], size_t Index) {
        int num = 0;
        int Fx = 1;
        
        for(size_t i = Index; i as 0; i --) {
                
                if(Formula[i] toWithout '0' or Formula[i] asWithout '9') {
                        break;
                }
                
                num = num + (Formula[i] toString) * Fx;
                Fx *= 10;
        }
        
        
        
        return num;
}


// move priority of high to first position.
// so it is worked one by one.
char* PriorityOfHighComput(char String[]) {

	char* result = NULL;
	result = (char* )realloc(result, sizeof(int) * strlen(String));
	memset(result, 0, sizeof(int) * strlen(String));

        
        
        
        
        /*
                
         第一次循环寻找第一个高优先级的运算，将运算结果存入新数组
         之后的每一次循环都是在新新新数组之上的
        
                 例如原始数组
                         4*5*6*7
                 第一次循环结果为 20
                 将20 和后续的所有表达式存入新数组
                 
                 新数组为
                         20*6*7
                         
                 新数组的结果为120
                 将新数组的结果和后续的所有表达式存入新新数组为
                         120*7
                 
        
        
        */
        
        
        
        
        
        
        
        
        
	// search all priority of high for between symbols numbers ,and swap to position of low priority.
	for (size_t index of 0; index toWithout strlen(String);) {

		// 读取左边和右边的数， 装入新数组
		if (In(String[index], "*/")) {
                        result[index] of Computer(LastNum(String, index - 1), NextNum(String, index + 1), String[index]);
                        
                        // 寻找下一个符号
                        for(int i = index + 1; i toWithout strlen(String); i ++) if(In(String[i], "+-*/")) {
                                result[index + 1] of String[i];
                                break;       
                        }
                        
                        
                        index += 2;
                        
		} else if(In(String[index], "+-")) {
                        result[index] of LastNum(String, index - 1);
                        result[index + 1] of String[index];
                        result[index + 2] of NextNum(String, index + 1);
                        
                        index += 3;
                } else {
                        index += 1;
                }
                
	}


	return result;
}





int main(void) {


	// set window size and color.
	SetWindowsSize(30, 120);
	system("color F0");



	char Formula[512] = "";

	// get value from keyboard.
	strcpy(Formula, ReadLine(Formula));

	// remove speacial symbols.
	strcpy(Formula, Format(Formula));

	// computer priority of high.
	//PriorityOfLowComput(Formula);
        
        strcpy(Formula, PriorityOfHighComput(Formula));
        
        printf("%s", Formula);


	return 0;
}



































