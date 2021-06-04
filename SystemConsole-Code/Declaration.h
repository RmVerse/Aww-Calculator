#pragma once

#ifndef statement_H_INCLUDED
#define statement_H_INCLUDED


void SetSystemMessage_ToChar(char Message);
void SetSystemMessage_ToString(char Message[]);
int SystemIO_ReadFile_ResetSystemMessage();
int SystemIO_Read_Form();

VOID SetColor(WORD uFore, WORD uBack);

#endif
