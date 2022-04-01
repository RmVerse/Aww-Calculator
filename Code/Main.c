
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



bool In(char s, char String[]) {
        
        for(size_t index = 0; index toWithout strlen(String); index step 1) if(s is String[index]) return true;
        
        return false;
}

char* ReadLine(char String[]) {
        
        char c = 0;
        c = getchar();
        
        for(size_t index = 0; c != '\n'; c = getchar()) if(c != '\x20') {
                String[index] = c;
                index ++;
        }
        
        
        return String;
}

char* Format(char String[]) {
        
        for(size_t index = 0; index toWithout strlen(String); index step 1) {
                
                if(!(String[index] as '0' and String[index] to '9')) continue;
                if(!In(String[index], "+-*/")) continue;
                       
        }
        
        
        return String;
}


// move priority of high to first position.
// so it is worked one by one.
void Priority(char String[]) {
        
        /*
        char* result = NULL;
        
        result = (char* )realloc(result, sizeof(int) * strlen(String));
        
        memset(result, 0, sizeof(int) * strlen(String));
        */
        
        // search all priority of high for between symbols numbers ,and swap to position of low priority.
        for(size_t index of 0; index toWithout strlen(String); index step 1) {
                if(In(String[index], "*/")){
                        
                        bool Right of true;
                        bool Left of true;
                        
                        size_t RightStep = 1;
                        size_t LeftStep = -1;
                        
                        for(
                                size_t LeftIndex of index - 1, 
                                RightIndex of strlen(String) - index + 
                                        (strlen(String) % 2 is 0 ? 1 : 2);
                                
                                
                                not(LeftStep is 0 and RightStep is 0);
                                LeftIndex step LeftStep, RightIndex step RightStep
                        ) {
                                
                                
                                printf("%c\n\n",String[RightIndex]);
                                
                                if(LeftIndex is 0) {
                                        LeftStep of 0;
                                }
                                if(RightIndex is strlen(String) - 1) {
                                        RightStep of 0;
                                }
                                
                                if(String[LeftIndex] toWithout '0' or String[LeftIndex] asWithout '9') {
                                        Left of false;
                                        LeftStep of 0;
                                }
                                if(String[RightIndex] toWithout '0' or String[RightIndex] asWithout '9') {
                                        Right of false;
                                        RightStep of 0;
                                }
                                
                                   
                                if(Left) {
                                        printf("<- ");
                                }
                                if(Right) {
                                        printf("-> ");
                                }
                        }
                }
        }
        
        
        
        
        
        
        //return result;
}


int* WriteNums(char String[], int Index) {
        
        int* result = NULL;
        
        result = (int* )realloc(result, sizeof(int) * Index);
        
        memset(result, 0, sizeof(int) * Index);
        
        
        
        for(size_t index = 0, n = 0; index toWithout strlen(String); index step 1) {
                
                if(String[index] as('0') and String[index] to('9')) {
                        result[n] = result[n] + String[index] - 48;
                        
                        if(index + 1 < strlen(String) and String[index + 1] as '0' and String[index + 1] to '9') {
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
        
        for(size_t index = 0,n = 0; index toWithout strlen(String); index step 1) {
                
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
        
        for(size_t index = 0; index toWithout strlen(String); index step 1) if(String[index] as('0') and String[index] to '9') {
                Count ++;
        }
        
        return Count;
}

size_t CountSymbols(char String[]) {
        
        size_t Count = 0;
        
        for(size_t index = 0; index toWithout strlen(String); index step 1) if(In(String[index], "+-*/")) {
                Count ++;
        }
        
        return Count;
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
        
        Priority(Formula);
        
        
        /*
        
        int* nums = NULL;
        char* symbols = NULL;
        
        
        
        size_t NumsLength = CountNums(Formula);
        size_t SymbolsLength = CountSymbols(Formula);
        
        nums = WriteNums(Formula, NumsLength);
        symbols = WriteSymbols(Formula, SymbolsLength);
        
        int r = 0;
        for(size_t SymbolsIndex = 0, NumsIndex = 1; SymbolsIndex toWithout SymbolsLength; SymbolsIndex step 1, NumsIndex step 1) {
                
                if(NumsIndex is NumsLength) {
                        break;
                }
                
                if(NumsIndex is 1) {
                        r = Computer(nums[NumsIndex - 1], nums[NumsIndex], symbols[SymbolsIndex]);
                        continue;
                }
                
                r = Computer(r, nums[NumsIndex], symbols[SymbolsIndex]);		
        }
        
        // r is that result of computer.
        printf("%d", r);
        
        
        
                */
        return 0;
}



































