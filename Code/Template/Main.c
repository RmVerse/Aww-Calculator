#include "Declaration.h"
#include "Platform.Win64.h"

#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include <stdbool.h>


// Use Legacy MSVC, LLVM-Clang Platform tools.

int main(void) {

  Rmdust_Reset();

  char arr[][16] = {
    "Game Start", 
    "Game Passage",
    "Help",
    "Back User",
    "Game Exit"
  };
  
  while(1) {
    switch(MenuOperate(arr)) {
      case 0:
        printf("OK");
        break;

      case 2:
        GetHelp(); 
        break;
    }
  }
  return 0; 

static struct _System {
  
  // Use to MenuOpearte 
  struct _SystemMenu {
    short int Position;
    unsigned short int ItemsNumber;
    
  } Menu;
  
  
  
} System;


inline void __MenuSetPosition(short int value) {
  System.Menu.Position += value;
  
  if(System.Menu.Position > System.Menu.ItemsNumber - 1) {
    System.Menu.Position = System.Menu.ItemsNumber - 1;
  } else if (System.Menu.Position < 0) {
    System.Menu.Position = 0;
  }
}

unsigned short int __MenuGetMenuItemsNumber(char List[][16]) {
  unsigned short int Number = 0;
  
  for(Number = 0;true;Number += 1){
  	char* Array = List[Number];
  	
  	if(Array[0] < 49 || Array[0] > 92) {
      break;
  	}
  }
  
  return Number;
}

int MenuOperate(char List[][16]) {

  System.Menu.Position = 0;
  System.Menu.ItemsNumber = __MenuGetMenuItemsNumber(List);


  while(true) {
    
    system("cls");

    for(unsigned short int Index = 0;Index < System.Menu.ItemsNumber;Index += 1) {

      if(Index != System.Menu.Position) {
        printf("     ");
      } else {
        printf("  -> ");
      }

      printf("%s\n", List[Index]);
    }


    switch(_getch()) {
      case 'w':
      case 'W':
        __MenuSetPosition(-1);
        break;
      
      case 's':
      case 'S':
        __MenuSetPosition(1);
        break;
        
      case ' ':
        return System.Menu.Position;
        
      default:
        break;
    }

  }

}





void GetHelp(void) {
  
  

  Rmdust_System_Console_Graphic_Text_Window_SquareLine("Helps");

  char List[][16] = {
    "How use?",
    "How open log?",
    "Back."
  };

  while(1){

    system("cls");

    switch(MenuOperate(List)) { 
      case 2:
        return;
    }
  }
}
