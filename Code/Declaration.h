#pragma once

#ifndef statement_H_INCLUDED
#define statement_H_INCLUDED

int AwwCalculator();

// �Ϸ�����֤ : ����û��� UserSurface.String ÿһλ�ַ��Ƿ���Ч���ұ��ʽ����
int VerifyDataRational();
// �Ϸ�����֤��֧ : ��֤�ڲ�����
int VerifyDataRational_Symbol_InternalSymbol();
// �Ϸ�����֤��֧ : ��֤�����ڲ����� [δ����]
int VerifyDataRational_Symbol_InternalSymbolContinuous();
// �Ϸ�����֤��֧ : ��֤�����ڲ�������һλ [δ����]
inline int VerifyDataRational_Symbol_InternalSymbolContinuousNext(int Index);
inline int VerifyDataRational_Symbol_InternalSymbolContinuous_Logic(int Index);
inline int VerifyDataRational_Symbol_InternalsymbolContinuous_Arithmetic_Pro(int Index);
inline int VerifyDataRational_Symbol_InternalSymbolContinuous_Arithmetic_Basic(int Index);
inline int VerifyDataRational_Symbol_InternalSymbolContinuous_Number(int Index);

// �Ϸ�����֤��֧ : ��֤���ʽ�Ϸ���
int VerifyDataRational_Symbol_Monomial();
// Ѱ���ڲ�����
int VerifyDataRational_Symbol_Monomial_FindInternalSymbol();
// 
inline int VerifyDataPath_Monomial_FindInternalSymbol_FindStarIndexIsNumber();
inline int VerifyDataPath_Monomial_FindInternalSymbol_FindNumber();

size_t GetUserSurfaceValueStrlength();
unsigned int GetUserSurfaceValueStrlength_ToIndex();
void SetUserSurfaceValue(char* Message);
char* GetUserSurfaceValue();
char GetUserSurfaceValue_ToIndex(int Index);



void SetInternalSymbolActive(int Active);
int GetInternalSymbolActive();

// д����־
int SetLog(char Message[100]);
int SystemIO_Write(char* Message);
inline int SystemIO_Folder_Create(char fileNameAddress[]);

char* Char_ToString(char* Message);
#endif
