#pragma once

#ifndef statement_H_INCLUDED
#define statement_H_INCLUDED

int AwwCalculator();

int VerifyDataRational();
int VerifyDataRational_InternalSymbol();
int VerifyDataRational_InternalSymbolContinuous();
inline int VerifyDataRational_InternalSymbolContinuousNext(int Index);
inline int VerifyDataRational_InternalSymbolContinuous_Logic(int Index);
inline int VerifyDataRational_InternalsymbolContinuous_Arithmetic_Pro(int Index);
inline int VerifyDataRational_InternalSymbolContinuous_Arithmetic_Basic(int Index);
inline int VerifyDataRational_InternalSymbolContinuous_Number(int Index);

int VerifyDataRational_Monomial();
int VerifyDataRational_Monomial_FindInternalSymbol();
inline int VerifyDataPath_Monomial_FindInternalSymbol_FindStarIndexIsNumber();
inline int VerifyDataPath_Monomial_FindInternalSymbol_FindNumber();





void SetValueResult(double value);
double GetValueResult();
void SetValue(char value[128]);

size_t GetUserSurfaceValueStrlength();
unsigned int GetUserSurfaceValueStrlength_ToIndex();
void SetUserSurfaceValue(char* Message);
char* GetUserSurfaceValue();

void SetInternalSymbolActive(int Active);
int GetInternalSymbolActive();

int SetLog(char* Message);
int SystemIO_Write(char* Message);

char* Char_ToString(char* Message);
#endif
