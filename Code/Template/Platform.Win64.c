?

/*
 * To Do list
 *  From Bre97
 *   
 *    2021.10.1次更新
 *      1. 关于快捷键的功能更新
 *      2. 修整代码  
 */







#include <direct.h>
#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdint.h>
#include <process.h>


#include "Platform.Win64.h"
#include "ShortcutKey.h"






////////////////////////////////////////////
//               New include              //
////////////////////////////////////////////

// Use Thread, Get key of user's.
DWORD WINAPI SystemIOShortcutKey() {

  struct _PutIn {
    int HeadCode;
    int MainCode;
  } PutIn;

  // Get double key.
  PutIn.HeadCode = _getch();
  PutIn.MainCode = _getch();

  while(true) { 

    PutIn.HeadCode = _getch();
    PutIn.MainCode = _getch();

    switch(PutIn.HeadCode) {
      case Key_HeadCode_Function :
        goto Function;
        break;
      
      case Key_HeadCode_Control :
        goto Control;
        break;
  
      case Key_HeadCode_IndependentControl :
        goto IndependentControl;
        break;
  
  
  
      default :
        break;
    }
  
  
    switch(getch()) {
      
      Function:
      // This insert GetHelper() function.
      case Key_F1 : 
        puts("Test F1");
        break;  
    
        
      Control :
      case Key_Home : 
        puts("Test Home");
        break;
  
        
        
      IndependentControl :
      case Key_Esc : 
      
        exit(0);
      
    }
  }

}




struct WindowsSize {
  
  unsigned short int WindowsHeight;
  unsigned short int WindowsWidth;
  
};

void SetWindowsSize(struct WindowsSize Windows) {
  
  char stCmd[128];
  sprintf(stCmd, "mode con cols=%d lines=%d", Windows.WindowsHeight, Windows.WindowsWidth);
  system(stCmd);
  
}




inline void Initialize() {



}


////////////////////////////////////////////
//               Wait to Add              //
////////////////////////////////////////////

// Use Thread, Get key of user's.
DWORD WINAPI SystemIOShortcutKey(LPVOID var) {

  struct _PutIn {
    int HeadCode;
    int MainCode;
  } PutIn;

  // Get double key.
  PutIn.HeadCode = _getch();
  PutIn.MainCode = _getch();

  switch(PutIn.HeadCode) {
    case Key_HeadCode_Function :
      goto Function;
      break;
    
    case Key_HeadCode_Control :
      goto Control;
      break;

    case Key_HeadCode_IndependentControl :
      goto IndependentControl;
      break;



    default :
      break;
  }



  Function :
  switch(PutIn.MainCode) {
    // This insert GetHelper() function.
    case Key_F1 : 
      break;

  }
  goto Done;

  Control :
  switch(PutIn.MainCode) {        
    case Key_Home : 
      puts("gets");    
      break;

  }
  goto Done;


  IndependentControl :
  switch(PutIn.MainCode) {
    case Key_Esc : 
      exit(0);

  }





  Done :
  return 1;
}




////////////////////////////////////////////
//               Wait to Test             //
////////////////////////////////////////////
inline int64_t SystemIOWriteLog(char Message[]) {

  FILE* Path = NULL;
  fopen_s(&Path, "C:\\Users\\Public\\RMDUST\\Share\\Log.txt", "a+");
  
  if(Path == NULL) {
    return FAIL;
  }


  fprintf(Path, "%s", Message);

  return DONE;
}

inline int64_t SystemIOFolderCreate(char* FolderName) {
  if (!_access(FolderName, 0)) {
    return DONE;
  }

  return _mkdir(FolderName);
}

inline int64_t SystemIOFileCreate(char* FileName) {
  FILE* Path = NULL;
  fopen_s(&Path, FileName, "a+");

  if (Path == NULL) {
    return FAIL;
  }


  fclose(Path);

  return DONE;
}

inline char* SystemIOFileGetAllLine(char* FileName) {

  FILE* Path = NULL;
  fopen_s(&Path, FileName, "r");

  if(Path == NULL) {
    return FAIL;
  }


  char Result[2048] = {0};

  while(!feof(Path)){
    strcat_s(Result, (char)fgetc(Path));
  }

  return Result;
}


// It printf to end and leave screeen
void SystemConsoleWriteLineCutIn(char Message[]) {
  size_t MessageLength = strlen(Message);
  
  system("cls");
  Rmdust_System_Console_Graphic_Animation_BasicMessage(Message);

  // This Use 
  for (size_t Index = 0;Index < MessageLength;Index += 1) {
    size_t MessageIndexTemp = Index;


    system("cls");
    for (size_t InternalIndex = 0;InternalIndex < MessageLength;InternalIndex += 1) {
      if (Message[Index] < Message[InternalIndex]) {
        MessageIndexTemp = InternalIndex;
      }
    }

    if (MessageIndexTemp != Index) {
      Message[MessageIndexTemp] = ' ';
    }

    printf("%s", Message);
    Sleep(Graphic_Animation_Transition_Time);
  }
}


////////////////////////////////////////////
//             Wait to Delete             //
////////////////////////////////////////////

// use it that Need Create Thraed
int ConsoleGraphicLoadingAnimation() {
  for (int Count = 5;Count > 0;Count--) {
    __SetPos(60,20);
    printf("|");
    Sleep(100);

    __SetPos(60,20);
    printf("/");
    Sleep(100);

    __SetPos(60,20);
    printf("-");
    Sleep(200);

    __SetPos(60,20);
    printf("\\");
    Sleep(100);
  }
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


// New

#define Graphic_Animation_Transition_Time 50

static char __Text = '=';
static char __Space = ' ';
//static unsigned short int __WindowsHeight = 40;
static unsigned short int __WindowsWidth = 120;

static unsigned short int __WindowWidthCenter = 60;
static size_t __WindowWidthEnd = 57;


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


// Use this Before : Change struct -> System.Console.Color.Background
//                                    System.Console.Color.Foreground



// Initialize
// Should use this in first
int Rmdust_Reset() {
  
  system("color F0");
  system("mode con cols=120 lines=30");


  Rmdust_System_IO_Folder_Create("C:\\Users\\Public\\Documents\\RMDUST");
  


  return 1;
}


void Rmdust_System_Console_Color_Update() {
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

  SetConsoleTextAttribute(handle,(WORD)System.Console.Color.Foreground + (WORD)System.Console.Color.Background * 0x10);
}


// It printf to end 
void Rmdust_System_Console_Graphic_Animation_BasicMessage(char* Message) {
  size_t MessageLength = strlen(Message);

  for (size_t Index = 0;Index < MessageLength;Index += 1) {
    Sleep(Graphic_Animation_Transition_Time);
    printf("%c", *(Message + Index));
  }
}








// Text Window
void Rmdust_System_Console_Graphic_Text_Window(char* Message) {
  __Println();
  printf("%s" , Message);
  __Printf();
}

// Text Window
// Support English/Chinese/Number In Windows 7
//         English/       /Number In Windows 10
void Rmdust_System_Console_Graphic_Text_Window_SquareLine(char* Message) {
  size_t MessageLength = strlen(Message);

  __Println();
  printf("%c" , __Text);
  for (size_t Count = __WindowWidthCenter - MessageLength/2;Count > 0;Count -= 1) {
    printf("%c" , __Space);
  }
  
  printf("%s" , Message);
  for (size_t Count = __WindowWidthEnd - 1 - (MessageLength % 2 == 0 ? MessageLength / 2 - 1 : MessageLength / 2);Count > 0 ;Count -= 1) {
    printf("%c" , __Space);
  }
  printf("%c" , __Text);
  __Printf();
}










inline void static __Print() {
  for (unsigned short int Count = __WindowsWidth - 1;Count > 0 ;Count -= 1) {
    printf("%c" , __Text);
  }
}
inline void static __Println() {
  __Print();
  printf("\n");
}
inline void static __Printf() {
  printf("\n");
  __Print();
}







/*
int _System_Time_GetDay() {
  time_t systemTime;
  struct tm *systemTimeAddress;
  time(&systemTime);
  gmtime_s(&systemTime, systemTimeAddress);
  return systemTimeAddress->tm_mday;
}
int _System_Time_GetMonth() {
  time_t systemTime;
  struct tm *systemTimeAddress;
  time(&systemTime);
  gmtime_s(&systemTime, systemTimeAddress);
  return systemTimeAddress->tm_mon;
}
*/

/*
 *  Writer : Bre 97
 *    Writer Information :
 *      Twitter-ID :     @Bre97_web
 *      Google-Mail :    BY.SGATN3@Gmail.com
 *      Outlook-Mail :   BY_SGATN3@Outlook.com
 *      GitHub-Name :    Bre97-web
 *    Writer Words :
 *      My Information is above this.
 *      You can give me with "Error Report"as I will Carefully.
 *      You can Upgrade this File,but you should have told me.
 *  About :
 *    Last Update date : 6.28.2021
 */
