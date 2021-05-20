
#include <stdio.h>
#include <string.h>

#include "Report.h"
#include "Declaration.h"

struct Value {
  double InternalSurface_Num;
  char UserSurface_String[128];
}Set;


// 连续内部符号活动状态
int InternalSymbol_Active = 0; 



int main(void) {

  AwwCalculator();

  return 0;
}

// 启动序列  
int AwwCalculator() {
  // User Surface
  printf("Put in :");
  scanf("%s" , &Set.UserSurface_String);
  GetUserSurfaceValue(Set.UserSurface_String);
  
  // Internal Surface
  
  /*
   * 1. 验证数据合法性 
   * 2. 分析数据路径并转换 
   * 3. 计算并返回结果 
   */ 
   
  // 数据合法性验证 
  if (!VerifyDataRational(GetUserSurfaceValue())) {
    printf("?");
    
    return 0;
  }
  // 数据路径分析
   
  // 转换数据 


  // User Surface
  printf("%lf" , Set.InternalSurface_Num);
  

  return 1;
}

// 合法性验证 : 检查用户层 Set.UserSurface_String 每一位字符是否有效 
int VerifyDataRational() {
  int index = GetUserSurfaceValueStrlength();
  
  for (;index > 0;index --) {
    if (!VerifyDataRational_InternalSymbol(index)) {
      //return 0;
    }
    if (!VerifyDataRational_InternalSymbolContinuous(index)) {
      return 0;
    }
  }
  
  return 1; 
}
// 合法性验证分支 : 验证内部符号 
int VerifyDataRational_InternalSymbol(int index) {
  char message = GetUserSurfaceValue()[index];
  
  if (message == '+' || message == '-') {
    return 1;
  }
  
  if (message == '*' || message == '/' || message == '%') {
    return 1;
  }
  
  if (message ==  '!' || message == '&' || message == '|') {
    return 1;
  }
  
  if (message >= 0 && message <= 9) {
    return 1;
  }
  
  return 0;
}
// 合法性验证分支 : 验证定义符号 [未启用]
int VerifyDataRational_ExternalSymbol(int index) {
  char message = GetUserSurfaceValue()[index];
  
  if (message == '=' || message == ':') {
    return 1;
  }
  
  return 0; 
}
// 合法性验证分支 : 验证连续内部符号
int VerifyDataRational_InternalSymbolContinuous(int index) {
  if (InternalSymbol_Active == 1) {
    InternalSymbol_Active = 0;
    return 1;
  }
  
  char message = GetUserSurfaceValue()[index];
  
  if (!((message == '+' || message == '-') && VerifyDataRational_InternalSymbolContinuousNext(index + 1))) {
    InternalSymbol_Active = 1;
    return 0;
  }
  
  return 1; 
} 

inline int VerifyDataRational_InternalSymbolContinuousNext(int index) {
  char message = GetUserSurfaceValue()[index];
  
  if (message == '+' || message == '-') {
    return 1;
  }
  
  return 0;
}


// 路径分析 :  
int VerifyDataPath () {


}




// 路径验证 : 检查用户层 Set.UserSurface_String 符号是否有效 
void Verify(char* value) {
  
  int index = 0;
  char result;
  
  for(index = strlen(GetUserSurfaceValue());index > 0;index --) {
    if(!GetUserSurfaceValue()[index] > '0' && GetUserSurfaceValue()[index] < 'z') {
      SetValueResult(GetUserSurfaceValue()[index] - 32);    
      break;
    }
  
  }
  

} 



int GetUserSurfaceValueStrlength() { 
  return strlen(Set.UserSurface_String);
}

void SetValueResult(double value) {
  Set.InternalSurface_Num = value;
}

double GetValueResult() {
  return Set.InternalSurface_Num;
}

void SetValue(char value[128]) {
  int index = 0;
  for (index = strlen(Set.UserSurface_String);index > 0;index --) {
    Set.UserSurface_String[index] = value[index];
  }
}

char* GetUserSurfaceValue() {
  return Set.UserSurface_String;
}
