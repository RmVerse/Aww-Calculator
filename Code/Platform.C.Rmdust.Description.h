#pragma once

#ifndef Rmdust_H_INCLUDED
#define Rmdust_H_INCLUDED


int Rmdust_Reset();

int Rmdust_GetSystemMessage_LableLevel();
char* Rmdust_GetSystemMessage_LableLevel_ToString();

inline static void _Inline_SetSystemMessage_LableLevel();

void Rmdust_SetSystemMessage_LableLevel(char* Message);


void Rmdust_SetLogsWriteActive(
    bool Active);
bool Rmdust_GetLogsWriteActive();

void Rmdust_SetSystemMessage_Title_ToString(char Message[]);
char* Rmdust_GetSystemMessage_Title_ToString();
void Rmdust_SetSystemMessage_TitleAddons_ToString(char Message[]);
char* Rmdust_GetSystemMessage_TitleAddons_ToString();
void Rmdust_SetSystemMessage_MessageIndex(int Index);
int Rmdust_GetSystemMessage_MessageIndex();
void Rmdust_SetSystemMessage_Message_ToString(char Message[]);
char* Rmdust_GetSystemMessage_Message_ToString();
void Rmdust_SetSystemMessage_Message_ToChar(char Message);
char Rmdust_GetSystemMessage_Message_ToChar(int Index);
char* Rmdust_GetSystemMessage_Title_ToString();

void _Console_Write_CutToEnd(int startDelay, int endDelay, int whetherToEnd, char message[]);
void _Console_Write_CutToEndWithAscii(int startDelay, int endDelay, char message[]);
void _Console_Write_Frame(char log[], char mark, unsigned int short titleMode);
void _Console_Write_LoadingAnimation(void);
void _Console_Write_LoadingAnimationSec(void);
int _Data_Convert_AsciiToNum(int ascii);
char *_Data_Convert_ArrayLinkBoth(char object[], char message[], char result[]);
int _IO_File_Create(char fileNameAddress[], char mode[]);
int _IO_File_Write(char fileNameAddress[], char mode[], char message[]);
int _IO_File_Read_State(char fileNameAddress[]);

int Rmdust_System_IO_Logs_Reset();
int Rmdust_System_IO_Logs_Write();
inline int Rmdust_System_IO_Write(char Address[128], char Message[512]);

// 创建文件夹
 int Rmdust_System_IO_Folder_Create(char FolderName[]);

 
 //int _System_Time_GetDay();
//int _System_Time_GetMonth();

#endif
