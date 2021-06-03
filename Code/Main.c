
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Other.Platform.H.vec.Description.h"
#include "Declaration.h"
#include "Report.h"

struct UserSurfaceIndexValue {
  char String[128];
} UserSurface;
struct InternalSurfaceIndexValue {
  double Result;

} InternalSurface;
//struct SystemSurfaceIndexValue {
//  char Message[128];
//} System;

int InternalSymbol_Active = 0;

int main(void) {

  Rmdust_Reset();
  Rmdust_System_IO_Folder_Create("C:\\Users\\Public\\Documents\\RMDUST");





  AwwCalculator();

  system("start C:\\Users\\YCJX\\Desktop\\bre97-web$AwwCalculator\\AwwCalculator-C\\Release\\SystemConsole.exe");

  return 0;
}

int AwwCalculator() {
  // User Surface
  printf("Put in :");
  SetUserSurfaceValue(gets_s(UserSurface.String, 128));
  printf("%s \n %d", GetUserSurfaceValue(),
         (int)GetUserSurfaceValueStrlength());

  // Internal Surface

  // 合法性验证
  if (!VerifyDataRational()) {
    printf("合法性验证:字符错误");

    return 0;
  }

  // 数据路径分析

  // 转换数据

  // User Surface

  return 1;
}


int VerifyDataRational() {
  if (!(VerifyDataRational_Symbol_InternalSymbol() && VerifyDataRational_Symbol_Monomial())) {
    // 此處輸出錯誤列表
    return 0;
  }

  return 1;
}

int VerifyDataRational_Symbol_InternalSymbol() {
  SetSystemMessage_Title_ToString("1");
  SetSystemMessage_Addons_ToString("Error : From Function VerifyDataRational_Symbol_InternalSymbol\n");

  for (int Index = GetUserSurfaceValueStrlength_ToIndex(); Index >= 0;Index--) {
    if (!(VerifyDataRational_Symbol_InternalSymbolContinuous_Arithmetic_Basic(Index) ||
          VerifyDataRational_Symbol_InternalsymbolContinuous_Arithmetic_Pro(Index) ||
          VerifyDataRational_Symbol_InternalSymbolContinuous_Logic(Index) ||
          VerifyDataRational_Symbol_InternalSymbolContinuous_Number(Index))) {
      
      SetSystemMessage_Message_ToChar(GetUserSurfaceValue_ToIndex(Index));

    }
  }

  Rmdust_System_IO_WriteFile_Logs();

  return 1;
}

int VerifyDataRational_Symbol_ExternalSymbol(int index) {
  char message = GetUserSurfaceValue()[index];

  if (message == '=' || message == ':') {
    return 1;
  }

  return 0;
}

int VerifyDataRational_Symbol_InternalSymbolContinuous() {
  for (int Index = GetUserSurfaceValueStrlength_ToIndex(); Index >= 0;
       Index--) {
    if (VerifyDataRational_Symbol_InternalSymbolContinuousNext(Index) &&
        VerifyDataRational_Symbol_InternalSymbolContinuousNext(Index - 1)) {
      return 0;
    }
  }

  return 1;
}

inline int VerifyDataRational_Symbol_InternalSymbolContinuousNext(int Index) {
  char message = GetUserSurfaceValue()[Index];
  if (message == '+' || message == '-') {
    return 1;
  }

  return 0;
}

inline int VerifyDataRational_Symbol_InternalSymbolContinuous_Logic(int Index) {
  char Message = GetUserSurfaceValue()[Index];
  if (Message == '&' || Message == '|' || Message == ' ' || Message == '\0') {
    return 1;
  }
  return 0;
}
inline int VerifyDataRational_Symbol_InternalsymbolContinuous_Arithmetic_Pro(
    int Index) {
  char Message = GetUserSurfaceValue()[Index];
  if (Message == '!' || Message == '*' || Message == '/' || Message == '%') {
    return 1;
  }
  return 0;
}
inline int VerifyDataRational_Symbol_InternalSymbolContinuous_Arithmetic_Basic(
    int Index) {
  char Message = GetUserSurfaceValue()[Index];
  if (Message == '+' || Message == '-') {
    return 1;
  }
  return 0;
}
inline int VerifyDataRational_Symbol_InternalSymbolContinuous_Number(int Index) {
  char Message = GetUserSurfaceValue()[Index];
  if (Message >= '0' && Message <= '9') {
    return 1;
  }
  return 0;
}


int VerifyDataRational_Symbol_Monomial() {
  if (!VerifyDataRational_Symbol_Monomial_FindInternalSymbol()) {

    return 0;
  }

  return 1;
}

// 寻找内部符号
int VerifyDataRational_Symbol_Monomial_FindInternalSymbol() {
  if (VerifyDataPath_Monomial_FindInternalSymbol_FindStarIndexIsNumber() && VerifyDataPath_Monomial_FindInternalSymbol_FindNumber()) {
    return 1;
  }

  


  return 0;
}
// 一句表达式必须包含至少一个内部数字
inline int VerifyDataPath_Monomial_FindInternalSymbol_FindNumber() {
  for (int Index = GetUserSurfaceValueStrlength_ToIndex(); Index >= 0;
       Index--) {
    if (VerifyDataRational_Symbol_InternalSymbolContinuous_Number(Index)) {
      return 1;
    }
  }

  return 0;
}
// 起始符号必须是数字或是定义符号
inline int VerifyDataPath_Monomial_FindInternalSymbol_FindStarIndexIsNumber() {
  if (VerifyDataRational_Symbol_InternalSymbolContinuous_Number(0)) {
    return 1;
  }
  return 0;
}

/*
// 路径分析 :
int VerifyDataPath() { VerifyDataPath_VerifyMultinomial(); }

// 路径分析分支 : 验证路径能否被分组为多项式
int VerifyDataPath_VerifyMultinomial() { VerifyDataPath();
  // 寻找所有的计算符号坐标
  

}

inline int VerifyDataPath_() {
  


}

*/

size_t GetUserSurfaceValueStrlength() { return strlen(UserSurface.String); }
unsigned int GetUserSurfaceValueStrlength_ToIndex() {
  return (unsigned int)(GetUserSurfaceValueStrlength() == 0
                            ? 0
                            : GetUserSurfaceValueStrlength() - 1);
}

void SetUserSurfaceValue(char* Message) { *UserSurface.String = *Message; }
char* GetUserSurfaceValue() { return UserSurface.String; }

char GetUserSurfaceValue_ToIndex(int Index) {
  //return GetUserSurfaceValue()[Index];
  return UserSurface.String[Index];
}


void SetInternalSymbolActive(int Active) { InternalSymbol_Active = Active; }

int GetInternalSymbolActive() { return InternalSymbol_Active; }

//int SetLog(char* Message) {
//  SystemIO_Write(Message);
//
//  return 1;
//}
//
//int SystemIO_Write(char* Message) {
//  FILE* LocalFilePath = NULL;
//  fopen_s(&LocalFilePath, "C:/Users/Public/Documents/RMDUST/Log.txt", "a+");
//
//  if (LocalFilePath == NULL) {
//    return 0;
//  }
//
//  fprintf_s(LocalFilePath, Message);
//
//  fclose(LocalFilePath);
//  return 1;
//}



char* Char_ToString(char* Message) {
  return Message;
}
