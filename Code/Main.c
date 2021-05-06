
#include <stdio.h>
#include <string.h>

#include "Report.h"
#include "Declaration.h"

struct Value {
  double result;
  char o[128];
}Set;




int main(void) {

  AwwCalculator();


  return REPORT_ACTIVE_FUNCTION_END;
}

int AwwCalculator() {
  printf("Put in :");
  
  scanf("%s" , &Set.o);
  SetValue(Set.o);
  
  Convert(GetValue());
  
  printf("%lf" , Set.result);
  

  return REPORT_ACTIVE_FUNCTION_END;
}

void Convert(char* value) {
  
  int index = 0;
  char result;
  
  for(index = strlen(GetValue());index > 0;index --) {
    if(!GetValue()[index] > '0' && GetValue()[index] < 'z') {
      SetValueResult(GetValue()[index] - 32);    
      break;
    }
  
  }
  

} 

void SetValueResult(double value) {
  Set.result = value;
}

double GetValueResult() {
  return Set.result;
}

void SetValue(char value[128]) {
  int index = 0;
  for (index = strlen(Set.o);index > 0;index --) {
    Set.o[index] = value[index];
  }
}

char* GetValue() {
  return Set.o;
}
