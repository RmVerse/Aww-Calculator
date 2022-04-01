
#include <direct.h>
#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdint.h>
#include <process.h>


#include "Platform.Win64.h"






////////////////////////////////////////////
//               New include              //
////////////////////////////////////////////


void SetWindowsSize(int Width, int Height) {
  
  char stCmd[128];
  sprintf(stCmd, "mode con cols=%d lines=%d", Height, Width);
  system(stCmd);
  
}

// Console pos direction
inline static void __SetPos(short int x, short int y) {
  COORD point = {
    x , y 
  };
    
  HANDLE HOutput = GetStdHandle( STD_OUTPUT_HANDLE );
  SetConsoleCursorPosition(HOutput, point);
}






////////////////////////////////////////////



static struct System {
  // Of Console ColorCode 
  struct SystemConsole {
    struct SystemConsoleColor {
      enum SystemConsoleColorList {
        Black,
        Blue,
        Green,
        GrayBlue,
        Red,
        Purple,
        GrayYellow,
        GrayWhite,
        GrayBlack,
        LightBlue,
        LightGreen,
        LightGrayBlue,
        LightRed,
        LightPurple,
        LightYellow,
        White
      } Background,Foreground;

      // Console-Color need this
      // Rmdust_System_Console_Color_Update() Use this


    } Color;

  } Console;



} System;


// Initialize
// Should use this in first
int Rmdust_Reset() {
  
  system("color F0");
  system("mode con cols=120 lines=30");




  return 1;
}


 void Rmdust_System_Console_Color_Update() {
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

  SetConsoleTextAttribute(handle,(WORD)System.Console.Color.Foreground + (WORD)System.Console.Color.Background * 0x10);
}




/*
 *    Writer Information :
 *      Google-Mail :    BY.SGATN3@Gmail.com
 *      GitHub-Name :    Bre97-web
 *    Writer Words :
 *      My Information is above this.
 *      You can give me with "Error Report"as I will Carefully.
 *      You can Upgrade this File,but you should have told me.
 *  About :
 *    Last Update date : 6.28.2021
 */
