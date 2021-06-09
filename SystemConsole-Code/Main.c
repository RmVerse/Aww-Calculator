
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

  // Error : Red+7
  // Warning : 
  // Non : 

  while(1){

    memset(System.Message, 0, sizeof System.Message); 

    Sleep(1000);
    system("cls");

    SystemIO_ReadFile_ResetSystemMessage();
    SystemIO_Read_Form();
  }

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

/*
 * 关于文本内格式说明
 * 
 *  -;
 *  -0Title-5
 *  Addons
 *  Message
 *  -;
 */

int SystemIO_Read_Form() {

  system("color f4");

  for (int Index = 0; Index < 512; Index++) {
    
    // Form Lable : Start
    if (System.Message[Index] == '-') {
      
      /* Lable Level
       *  0 : Error
       *  1 : Warning
       *  2 : Non
       */

      Index ++;

      if (System.Message[Index] == '0') {
        SetColor(FOREGROUND_RED, 0);
      } else if (System.Message[Index] == '1') {
        SetColor(FOREGROUND_RED, 0);
      } else if (System.Message[Index] == '2') {
      }

      // Form Lable : End
      if (System.Message[Index] == ';') {
        SetColor(FOREGROUND_RED, 2);
        printf("\n--------------------------------------\n");
      } else if (0) {
      }

      continue;
    }
    
    printf("%c", System.Message[Index]);
  }

  return 1;
}



// 颜色转换器



VOID SetColor(WORD uFore, WORD uBack) {
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(handle, uFore + uBack * 0x10);
}

