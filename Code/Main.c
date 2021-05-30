
#include <stdio.h>
#include <string.h>

#include "Declaration.h"
#include "Report.h"

struct UserSurfaceIndexValue {
  char String[128];
} UserSurface;
struct InternalSurfaceIndexValue {
  double Result;

} InternalSurface;
struct SystemSurfaceIndexValue {
  char* Message;
} System;

int InternalSymbol_Active = 0;

int main(void) {
  AwwCalculator();

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

// 合法性验证 : 检查用户层 UserSurface.String 每一位字符是否有效并且表达式无误
int VerifyDataRational() {
  if (!(VerifyDataRational_InternalSymbol() && VerifyDataRational_Monomial())) {
    // 此處輸出錯誤列表
    return 0;
  }

  return 1;
}
// 合法性验证分支 : 验证内部符号
int VerifyDataRational_InternalSymbol() {
  for (int Index = GetUserSurfaceValueStrlength_ToIndex(); Index >= 0;
       Index--) {
    // 名字去掉Continuous
    if (!(VerifyDataRational_InternalSymbolContinuous_Arithmetic_Basic(Index) ||
          VerifyDataRational_InternalsymbolContinuous_Arithmetic_Pro(Index) ||
          VerifyDataRational_InternalSymbolContinuous_Logic(Index) ||
          VerifyDataRational_InternalSymbolContinuous_Number(Index))) {
      printf("第 %d 位字符 '%c' 錯誤 \n", Index, GetUserSurfaceValue()[Index]);
      SetLog(Char_ToString(&GetUserSurfaceValue()[Index]));

      // return 0;
    }
  }

  return 1;
}
// 合法性验证分支 : 验证定义符号 [未启用]
int VerifyDataRational_ExternalSymbol(int index) {
  char message = GetUserSurfaceValue()[index];

  if (message == '=' || message == ':') {
    return 1;
  }

  return 0;
}
// 合法性验证分支 : 验证连续内部符号 [未启用]
int VerifyDataRational_InternalSymbolContinuous() {
  for (int Index = GetUserSurfaceValueStrlength_ToIndex(); Index >= 0;
       Index--) {
    if (VerifyDataRational_InternalSymbolContinuousNext(Index) &&
        VerifyDataRational_InternalSymbolContinuousNext(Index - 1)) {
      return 0;
    }
  }

  return 1;
}
// 合法性验证分支 : 验证连续内部符号下一位 [未启用]
inline int VerifyDataRational_InternalSymbolContinuousNext(int Index) {
  char message = GetUserSurfaceValue()[Index];
  if (message == '+' || message == '-') {
    return 1;
  }

  return 0;
}

inline int VerifyDataRational_InternalSymbolContinuous_Logic(int Index) {
  char Message = GetUserSurfaceValue()[Index];
  if (Message == '&' || Message == '|' || Message == ' ' || Message == '\0') {
    return 1;
  }
  return 0;
}
inline int VerifyDataRational_InternalsymbolContinuous_Arithmetic_Pro(
    int Index) {
  char Message = GetUserSurfaceValue()[Index];
  if (Message == '!' || Message == '*' || Message == '/' || Message == '%') {
    return 1;
  }
  return 0;
}
inline int VerifyDataRational_InternalSymbolContinuous_Arithmetic_Basic(
    int Index) {
  char Message = GetUserSurfaceValue()[Index];
  if (Message == '+' || Message == '-') {
    return 1;
  }
  return 0;
}
inline int VerifyDataRational_InternalSymbolContinuous_Number(int Index) {
  char Message = GetUserSurfaceValue()[Index];
  if (Message >= '0' && Message <= '9') {
    return 1;
  }
  return 0;
}

// 合法性验证分支 : 验证表达式合法性
int VerifyDataRational_Monomial() {
  if (!VerifyDataRational_Monomial_FindInternalSymbol()) {

    return 0;
  }

  return 1;
}

// 寻找内部符号
int VerifyDataRational_Monomial_FindInternalSymbol() {
  if (VerifyDataPath_Monomial_FindInternalSymbol_FindStarIndexIsNumber() && VerifyDataPath_Monomial_FindInternalSymbol_FindNumber()) {
    return 1;
  }

  


  return 0;
}
// 一句表达式必须包含至少一个内部数字
inline int VerifyDataPath_Monomial_FindInternalSymbol_FindNumber() {
  for (int Index = GetUserSurfaceValueStrlength_ToIndex(); Index >= 0;
       Index--) {
    if (VerifyDataRational_InternalSymbolContinuous_Number(Index)) {
      return 1;
    }
  }

  return 0;
}
// 起始符号必须是数字或是定义符号
inline int VerifyDataPath_Monomial_FindInternalSymbol_FindStarIndexIsNumber() {
  if (VerifyDataRational_InternalSymbolContinuous_Number(0)) {
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

/// 设置连续内部符号活动状态
void SetInternalSymbolActive(int Active) { InternalSymbol_Active = Active; }
/// 获取连续内部符号活动状态
int GetInternalSymbolActive() { return InternalSymbol_Active; }

int SetLog(char* Message) {
  SystemIO_Write(Message);

  return 1;
}

int SystemIO_Write(char* Message) {
  FILE* LocalFilePath = NULL;
  fopen_s(&LocalFilePath, "Log.txt", "a+");

  if (LocalFilePath == NULL) {
    return 0;
  }

  fprintf_s(LocalFilePath, Message, "\n");

  fclose(LocalFilePath);
  return 1;
}

char* Char_ToString(char* Message) {
  char Result[2] = " ";
  Result[0] = *Message;
  return Message;
}
