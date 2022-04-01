
#include <stdio.h>
#include <string.h>
#include <stdbool.h>



#define and &
#define or ||
#define in ==
#define is ==


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


int main(void) {

	char Formula[512] = "";
	
	strcpy(Formula, ReadLine(Formula));
	
	strcpy(Formula, Format(Formula));
	printf("%s", Formula);
	
	return 0;
}
