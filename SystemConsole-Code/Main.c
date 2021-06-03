
/////////////////////////////////////////////
//  此项目仅用作消息输出
/////////////////////////////////////////////

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "Declaration.h"

struct SystemSurfaceIndexValue {
  char Message[512];
} System;

int main(void) {

  SystemIO_ReadFile_ResetSystemMessage();
  SystemIO_Read_Form();

  system("pause");

  return 0;
}

void SetSystemMessage_ToChar(char Message) {
  System.Message[0] = Message;
}
void SetSystemMessage_ToString(char Message[]) {
  strcpy_s(System.Message,512,Message);
}

int SystemIO_ReadFile_ResetSystemMessage() {
  FILE* LocalFilePath = NULL;
  fopen_s(&LocalFilePath, "C:\\Users\\Public\\Documents\\RMDUST\\Log.txt", "r");

  if (LocalFilePath == NULL) {
    return 0;
  }

  char LocalFileText[512] = {0};
  for (int Index = 0;!feof(LocalFilePath);Index ++) {
    LocalFileText[Index] = (char)fgetc(LocalFilePath);
  }

  SetSystemMessage_ToString(LocalFileText);

  fclose(LocalFilePath);

  return 1;
}

int SystemIO_Read_Form() {
  FILE* LocalFilePath = NULL;
  fopen_s(&LocalFilePath, "C:\\Users\\Public\\Documents\\RMDUST\\Log.txt", "r");

  if (LocalFilePath == NULL) {
    return 0;
  }

  for (int Index = 0; Index < 512; Index++) {
    // Form Lable : Start
    if (System.Message[Index] == '-') {
      if (System.Message[Index + 1] == '1') {
        //system("color f4");

        SetColor(18,0);
      }

      Index++;
      continue;
    }

    // Form Lable : End
    if (System.Message[Index] == ';') {


      continue;
    }

    printf("%c", System.Message[Index]);
  }

  fclose(LocalFilePath);

  return 1;
}






VOID SetColor(UINT uFore, UINT uBack) {
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(handle, uFore + uBack * 0x10);
}

