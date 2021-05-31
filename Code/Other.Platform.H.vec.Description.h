#pragma once

#ifndef vec_H_INCLUDED
#define vec_H_INCLUDED

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
int _IO_File_Log(char log[], char mark);
int _IO_Folder_Create(char folderNameAddress[]);
//int _System_Time_GetDay();
//int _System_Time_GetMonth();

#endif
