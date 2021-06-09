
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <process.h>

#include "Platform.C.Rmdust.Description.h"
#include "Declaration.h"
#include "Report.h"

struct UserSurfaceIndexValue {
  char String[128];
} UserSurface;
struct InternalSurfaceIndexValue {
  double Result;
} InternalSurface;

int main(void) {

  Rmdust_Reset();
  
  // 创建线程
  CreateThread(0, 0, (LPTHREAD_START_ROUTINE)StartConsole, 0, 0, 0);

  AwwCalculator();
  
  //ExitThread((LPTHREAD_START_ROUTINE)StartConsole);

  return 0;
}

void StartConsole(void *a) { 
  system(
      "start C:\\Users\\YCJX\\Desktop\\bre97-web$AwwCalculator\\AwwCalculator\\Release\\SystemConsole.exe");
  ExitThread(0);
}

int AwwCalculator() {

  // User Surface
  printf("Put in :");
  SetUserSurfaceValue(gets_s(UserSurface.String, 128));
  printf("%s \n %d", GetUserSurfaceValue(),(int)GetUserSurfaceValueStrlength());

  // Internal Surface

  if (!VerifyDataRational()) {
    printf("合法性验证:错误");

    return 0;
  }

  // User Surface

  return 1;
}

int VerifyDataRational() {
  VerifyDataRational_Symbol();

  return 1;
}

int VerifyDataRational_Symbol() {
  if (!(VerifyDataRational_Symbol_InternalSymbol() && VerifyDataRational_Symbol_Monomial())) {
    return 0;
  }

  return 1;
}

int VerifyDataRational_Symbol_InternalSymbol() {
  
  for (int Index = GetUserSurfaceValueStrlength_ToIndex(); Index >= 0;Index--) {
    if (!(VerifyDataRational_Symbol_InternalSymbolContinuous_Arithmetic_Basic(Index) ||
          VerifyDataRational_Symbol_InternalsymbolContinuous_Arithmetic_Pro(Index) ||
          VerifyDataRational_Symbol_InternalSymbolContinuous_Logic(Index) ||
          VerifyDataRational_Symbol_InternalSymbolContinuous_Number(Index))) {
      

      Rmdust_SetLogsWriteActive(true);
      Rmdust_SetSystemMessage_Message_ToChar(GetUserSurfaceValue_ToIndex(Index));


    }
  }
  
  Rmdust_SetSystemMessage_LableLevel("Error");
  Rmdust_SetSystemMessage_Title_ToString("Text");
  Rmdust_SetSystemMessage_TitleAddons_ToString("From Function VerifyDataRational_Symbol_InternalSymbol()");

  Rmdust_System_IO_Logs_Write();

  return 1;
}

int VerifyDataRational_Symbol_ExternalSymbol(int index) {
  char message = GetUserSurfaceValue()[index];

  if (message == '=' || message == ':') {
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
