#pragma once

#ifndef statement_H_INCLUDED
#define statement_H_INCLUDED

int AwwCalculator();

// 合法性验证 : 检查用户层 UserSurface.String 每一位字符是否有效并且表达式无误
int VerifyDataRational();
// 合法性验证分支 : 验证内部符号
int VerifyDataRational_Symbol_InternalSymbol();
// 合法性验证分支 : 验证连续内部符号 [未启用]
int VerifyDataRational_Symbol_InternalSymbolContinuous();
// 合法性验证分支 : 验证连续内部符号下一位 [未启用]
inline int VerifyDataRational_Symbol_InternalSymbolContinuousNext(int Index);
inline int VerifyDataRational_Symbol_InternalSymbolContinuous_Logic(int Index);
inline int VerifyDataRational_Symbol_InternalsymbolContinuous_Arithmetic_Pro(int Index);
inline int VerifyDataRational_Symbol_InternalSymbolContinuous_Arithmetic_Basic(int Index);
inline int VerifyDataRational_Symbol_InternalSymbolContinuous_Number(int Index);

// 合法性验证分支 : 验证表达式合法性
int VerifyDataRational_Symbol_Monomial();
// 寻找内部符号
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

// 写入日志
int SetLog(char Message[100]);
int SystemIO_Write(char* Message);
inline int SystemIO_Folder_Create(char fileNameAddress[]);

char* Char_ToString(char* Message);
#endif
