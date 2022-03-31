
/*
 *  Writer : Bre 97
 *    Writer Information :
 *      Twitter-ID :     @Bre97_web
 *      Google-Mail :    BY.SGATN3@Gmail.com
 *      Outlook-Mail :   BY_SGATN3@Outlook.com
 *      GitHub-Name :    Bre97-web
 *    Writer Words :
 *      My Information above.
 *      You can give me "Error Report" as Carefully report.
 *      You can Upgrade this File.
 *  About :
 *    Last Update date : 9.28.2021
 */




#pragma once

#ifndef _PLATFORM_WIN64_C
#define _PLATFORM_WIN64_C

#include <stdio.h>
#include <stdint.h>
#include <process.h>
#include <windows.h>

#if _WIN32


// Unit : SystemIO
DWORD WINAPI SystemIOShortcutKey(LPVOID var);

inline int64_t     SystemIOWriteLog               (char Message[]);
inline int64_t     SystemIOFolderCreate           (char* FileName);
inline int64_t     SystemIOFileCreate             (char* FileName);
inline char*       SystemIOFileGetAllLine         (char* FileName);


// Unit : SystemConsole
       void        SystemConsoleWriteLineCutIn    (char Message[]);
inline void static __SetPos                       (short int x, short int y);
inline void static __Print                        ();
inline void static __Println                      ();
inline void static __Printf                       ();







// Old Code , Need to delete
void Rmdust_System_Console_Color_Update();
int Rmdust_Reset();

void Rmdust_System_Console_Graphic_Animation_BasicMessage(char* Message);
void Rmdust_System_Console_Graphic_Animation_LeaveMessage(char Message[]);
void Rmdust_System_Console_Graphic_Animation_Load();

void Rmdust_System_Console_Graphic_Text_Window(char* Message);
void Rmdust_System_Console_Graphic_Text_Window_SquareLine(char* Message);

#endif


#endif

