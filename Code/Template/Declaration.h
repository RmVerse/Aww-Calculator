#pragma once

#ifndef statement_H_INCLUDED
#define statement_H_INCLUDED

#include <stdbool.h>
#include <windows.h>

// Ep0.c
        int                   a                       ();
        void                  Init                    ();
        DWORD WINAPI        __MapsPut                 (LPVOID var);
        DWORD WINAPI        __MapsUpdate              (LPVOID var);
        DWORD WINAPI        __GetIn                   (LPVOID var);




// Main.c
inline  void                __MenuSetPosition         (short int value);
        unsigned short int  __MenuGetMenuItemsNumber  (char List[][16]);
        int                   MenuOperate             (char List[][16]);
        void                  GetHelp                 (void);


              
// UserGroup.c
void Set_SystemUserWindowsUserPath(char* Message);
char* Get_SystemUserWindowsUserPath();
void Set_SystemUserName(char* Message);
char* Get_SystemUserName();
void Set_SystemUserAllUserNumber(unsigned short int Number);
unsigned short int Get_SystemUserAllUserNumber();
void Set_SystemUserRegister(bool Active);
bool Get_SystemUserRegister();
char* Get_SystemUserWindowsUserPath();
void Set_SystemUserOnline(bool Active);
bool Get_SystemUserOnline();


int aaa();
inline static int __Register();
inline static int __Login();
inline static int __ReadLocalFile_UserList();
inline static int __WriteLocalFile_UserList(char* Message);
inline static int __InitLocalPath();
inline static char* __GetUserName();
inline static bool __IsLocalFileUser();


//inline static int __AddStringToLinkList(char* Message);
inline static void __LinkUserPath();

#endif
