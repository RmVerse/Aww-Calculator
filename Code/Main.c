
#include <stdio.h>
#include <string.h>

#include "Report.h"
#include "Declaration.h"

struct Value {
  double InternalSurface_Num;
  char UserSurface_String[128];
}Set;


// �����ڲ����Ż״̬
int InternalSymbol_Active = 0; 



int main(void) {

  AwwCalculator();

  return 0;
}

// ��������  
int AwwCalculator() {
  // User Surface
  printf("Put in :");
  scanf("%s" , &Set.UserSurface_String);
  GetUserSurfaceValue(Set.UserSurface_String);
  
  // Internal Surface
  
  /*
   * 1. ��֤���ݺϷ��� 
   * 2. ��������·����ת�� 
   * 3. ���㲢���ؽ�� 
   */ 
   
  // ���ݺϷ�����֤ 
  if (!VerifyDataRational(GetUserSurfaceValue())) {
    printf("?");
    
    return 0;
  }
  // ����·������
   
  // ת������ 


  // User Surface
  printf("%lf" , Set.InternalSurface_Num);
  

  return 1;
}

// �Ϸ�����֤ : ����û��� Set.UserSurface_String ÿһλ�ַ��Ƿ���Ч 
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
// �Ϸ�����֤��֧ : ��֤�ڲ����� 
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
// �Ϸ�����֤��֧ : ��֤������� [δ����]
int VerifyDataRational_ExternalSymbol(int index) {
  char message = GetUserSurfaceValue()[index];
  
  if (message == '=' || message == ':') {
    return 1;
  }
  
  return 0; 
}
// �Ϸ�����֤��֧ : ��֤�����ڲ�����
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


// ·������ :  
int VerifyDataPath () {


}




// ·����֤ : ����û��� Set.UserSurface_String �����Ƿ���Ч 
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
