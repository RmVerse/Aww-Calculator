
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

  // �Ϸ�����֤
  if (!VerifyDataRational()) {
    printf("�Ϸ�����֤:�ַ�����");

    return 0;
  }

  // ����·������

  // ת������

  // User Surface

  return 1;
}

// �Ϸ�����֤ : ����û��� UserSurface.String ÿһλ�ַ��Ƿ���Ч���ұ��ʽ����
int VerifyDataRational() {
  if (!(VerifyDataRational_InternalSymbol() && VerifyDataRational_Monomial())) {
    // ��̎ݔ���e�`�б�
    return 0;
  }

  return 1;
}
// �Ϸ�����֤��֧ : ��֤�ڲ�����
int VerifyDataRational_InternalSymbol() {
  for (int Index = GetUserSurfaceValueStrlength_ToIndex(); Index >= 0;
       Index--) {
    // ����ȥ��Continuous
    if (!(VerifyDataRational_InternalSymbolContinuous_Arithmetic_Basic(Index) ||
          VerifyDataRational_InternalsymbolContinuous_Arithmetic_Pro(Index) ||
          VerifyDataRational_InternalSymbolContinuous_Logic(Index) ||
          VerifyDataRational_InternalSymbolContinuous_Number(Index))) {
      printf("�� %d λ�ַ� '%c' �e�` \n", Index, GetUserSurfaceValue()[Index]);
      SetLog(Char_ToString(&GetUserSurfaceValue()[Index]));

      // return 0;
    }
  }

  return 1;
}
// �Ϸ�����֤��֧ : ��֤������� [δ����]
int VerifyDataRational_ExternalSymbol(int index) {
  char message = GetUserSurfaceValue()[index];

  if (message == '=' || message == ':') {
    return 1;
  }

  return 0;
}
// �Ϸ�����֤��֧ : ��֤�����ڲ����� [δ����]
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
// �Ϸ�����֤��֧ : ��֤�����ڲ�������һλ [δ����]
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

// �Ϸ�����֤��֧ : ��֤���ʽ�Ϸ���
int VerifyDataRational_Monomial() {
  if (!VerifyDataRational_Monomial_FindInternalSymbol()) {

    return 0;
  }

  return 1;
}

// Ѱ���ڲ�����
int VerifyDataRational_Monomial_FindInternalSymbol() {
  if (VerifyDataPath_Monomial_FindInternalSymbol_FindStarIndexIsNumber() && VerifyDataPath_Monomial_FindInternalSymbol_FindNumber()) {
    return 1;
  }

  


  return 0;
}
// һ����ʽ�����������һ���ڲ�����
inline int VerifyDataPath_Monomial_FindInternalSymbol_FindNumber() {
  for (int Index = GetUserSurfaceValueStrlength_ToIndex(); Index >= 0;
       Index--) {
    if (VerifyDataRational_InternalSymbolContinuous_Number(Index)) {
      return 1;
    }
  }

  return 0;
}
// ��ʼ���ű��������ֻ��Ƕ������
inline int VerifyDataPath_Monomial_FindInternalSymbol_FindStarIndexIsNumber() {
  if (VerifyDataRational_InternalSymbolContinuous_Number(0)) {
    return 1;
  }
  return 0;
}

/*
// ·������ :
int VerifyDataPath() { VerifyDataPath_VerifyMultinomial(); }

// ·��������֧ : ��֤·���ܷ񱻷���Ϊ����ʽ
int VerifyDataPath_VerifyMultinomial() { VerifyDataPath();
  // Ѱ�����еļ����������
  
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

/// ���������ڲ����Ż״̬
void SetInternalSymbolActive(int Active) { InternalSymbol_Active = Active; }
/// ��ȡ�����ڲ����Ż״̬
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
