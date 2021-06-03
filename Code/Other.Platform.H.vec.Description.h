#pragma once

#ifndef vec_H_INCLUDED
#define vec_H_INCLUDED


int Rmdust_Reset();
void SetSystemMessage_Title_ToString(char Message[]);
char *GetSystemMessage_Title_ToString();

void SetSystemMessage_Addons_ToString(char Message[]);
char *GetSystemMessage_Addons_ToString();
void SetSystemMessage_MessageIndex(int Index);
int GetSystemMessage_MessageIndex();
void SetSystemMessage_Message_ToString(char Message[]);
char *GetSystemMessage_Message_ToString();
void SetSystemMessage_Message_ToChar(char Message);
char GetSystemMessage_Message_ToChar(int Index);
char *GetSystemMessage_Title_ToString();





void _Console_Write_WriteSleep(int sleepTime, char message[]);
void _Console_Write_Repeatedly(int sleepTime, char message[], char messageTwo[], char messageThree[]);
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

int Rmdust_System_IO_WriteFile_Logs_Reset();
// 写入日志
int Rmdust_System_IO_WriteFile_Logs();

// 创建文件夹
 int Rmdust_System_IO_Folder_Create(char FolderName[]);
//int _System_Time_GetDay();
//int _System_Time_GetMonth();

#endif
