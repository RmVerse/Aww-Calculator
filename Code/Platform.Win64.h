
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

// Unit : SystemConsole
inline void static __SetPos                       (short int x, short int y);
inline void static __Print                        ();
inline void static __Println                      ();
inline void static __Printf                       ();



void SetWindowsSize(int Height, int Width);



// Old Code , Need to delete
void Rmdust_System_Console_Color_Update();
int Rmdust_Reset();

#endif


#endif
