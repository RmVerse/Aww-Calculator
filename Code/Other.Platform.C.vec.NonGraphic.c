#include <direct.h>
#include <io.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>

#include "Other.Platform.H.vec.Description.h"

void _Console_Write_WriteSleep(int sleepTime,char message[]) {
  Sleep(sleepTime);
  message != 0 ? printf("%s", message) : 0;
}
void _Console_Write_Repeatedly(int sleepTime,char message[], char messageTwo[], char messageThree[]) {
  message != 0 ? printf("%s", message) : printf(" ");
  Sleep(sleepTime);
  messageTwo != 0 ? printf("%s", messageTwo) : printf(" ");
  Sleep(sleepTime);
  messageThree != 0 ? printf("%s", messageThree) : printf(" ");
  Sleep(sleepTime);
}       
void _Console_Write_CutToEnd(int startDelay, int endDelay, int whetherToEnd, char message[]) {
  size_t TEMP;
  size_t callWidth = strlen(message);
  for (TEMP = 0; TEMP < callWidth; TEMP++) {
    Sleep(startDelay);
    printf("%c", message[TEMP]);
  }
  if (whetherToEnd == 1) {
    Sleep(endDelay);
    for (TEMP = 0; TEMP < callWidth; TEMP++) {
      message[TEMP] = ' ';
      system("cls");
      printf("%s", message);
      Sleep(endDelay);
    }
  }
}
void _Console_Write_CutToEndWithAscii( int startDelay, int endDelay, char message[]) {
  unsigned int buff;
  unsigned int TEMP = 0;
  unsigned int ntemp = 0;
  system("cls");
  for (TEMP = 0; TEMP < strlen(message); TEMP++) {
    Sleep(startDelay);
    printf("%c", message[TEMP]);
  }
  system("cls");
  for (TEMP = 0; TEMP < strlen(message); TEMP++) {
    buff = TEMP;
    for (ntemp = 0; ntemp < strlen(message); ntemp++) {
      if (message[ntemp] > message[buff]) {  // T>T h>T a>T
        buff = ntemp;                  //	   0=1
      }
    }
    if (buff != TEMP) {
      message[buff] = ' ';
    }
    printf("%s", message);
    Sleep(endDelay);
    system("cls");
  }
}
void _Console_Write_Frame(char log[],char mark,unsigned int short titleMode) {
  for (int count = 0; count < 50;count ++) {
    printf("%c",mark);
  }
  printf("\n");

  int logWidth = 0;
  for (unsigned int stTemp = 0; stTemp < strlen(log); stTemp++) {
    printf("%c", log[stTemp]);
    logWidth ++;
    if (logWidth == 48) {
      printf("\n\x20\x20");
      logWidth = 0;
    }
  }

  printf("\n");
  if (titleMode == 1) {
    for (int count = 0; count < 50; count++) {
      printf("%c", mark);
    }
    printf("\n");
  }
}
void _Console_Write_LoadingAnimation(void) {
  signed short int temp , tempTwo , count = 0;

  for (temp = 0; temp < 120; temp++) {
    temp <= 40 ? system("color f8") : temp <= 80 ? system("color f4") : system("color f6");
    for (tempTwo = 0; tempTwo < temp; tempTwo++) {
      printf("=");
    }
    printf(">\n");

    count <= 100 ? printf("%d%%", count ++) : printf("Resource preparation");

    Sleep(temp);
    system("cls");
  }
  system("color f0");
}
void _Console_Write_LoadingAnimationSec(void) {
  unsigned short int temp;
  for (temp = 0; temp < 120; temp++) {
    temp <= 40 ? system("color f8") : temp <= 80 ? system("color f4") : system("color f6");
    printf("=");
  }
  system("color f0");
  system("cls");
}
                   
int _Data_Convert_AsciiToNum(int ascii) {
  if (ascii >= 48 && ascii <= 57) {
    ascii -= 48;
    return ascii;
  }
  return -1;
}
char *_Data_Convert_ArrayLinkBoth(char object[], char message[], char result[]) {
  size_t callWidth = strlen(message);
  size_t toCallWidth = strlen(object);
  size_t temp = 0;
  for (temp = 0; temp < toCallWidth; temp++) {
    result[temp] = object[temp];
  }
  for (temp = 0; temp < callWidth; temp++) {
    result[toCallWidth + temp] = message[temp];
  }
  return result;
}

int _IO_File_Create(char fileNameAddress[], char mode[]) {
  FILE *fileAddress = NULL;
  fopen_s(&fileAddress, fileNameAddress, mode);
  if (fileAddress == NULL) {
    return -1;
  }
  fclose(fileAddress);
  return 1;
}
int _IO_File_Write(char fileNameAddress[], char mode[], char message[]) {
  FILE *fileAddress = NULL;
  fopen_s(&fileAddress, fileNameAddress, mode);
  if (fileAddress == NULL) {
    return -1;
  }
  fprintf(fileAddress , "%s" , message);
  fclose(fileAddress);
  return 1;
}
int _IO_File_Read_State(char fileNameAddress[]) {
  FILE *fileAddress = NULL;
  fopen_s(&fileAddress, fileNameAddress, "r");
  if (fileAddress == NULL) {
    return -1;
  } else {
    fclose(fileAddress);
    return 1;
  }
}
int _IO_File_Log(char log[] , char mark) {
  FILE *logWrite = NULL;
  fopen_s(&logWrite, "./resource/core/log.txt", "a+");
  if (logWrite == NULL) {
    return -1;
  }

  for (int count = 0; count < 50; count ++) {
    fprintf(logWrite , "%c", mark);
  }
  fprintf(logWrite , "\n");

  int logWidth = 0;
  for (unsigned int stTemp = 0;stTemp < strlen(log);stTemp ++) {
    fprintf(logWrite, "%c" , log[stTemp]);
    logWidth ++;
    if (logWidth == 48) {
      fprintf(logWrite , "\n\x20\x20");
      logWidth = 0;
    }
  }
  fprintf(logWrite, "\n");
  for (int newcount = 0; newcount < 50; newcount++) {
    fprintf(logWrite, "%c", mark);
  }
  fprintf(logWrite, "\n");

  fclose(logWrite);
  return 1;
}
int _IO_Folder_Create(char fileNameAddress[]) {
  if (_access(fileNameAddress, 0)) {
    
    return _mkdir(fileNameAddress);;
  }
  return -1;
}
/*
void _Square_puts_(int padding,int width,int height,char message) {
  char arr[2][2];
  int countOutside,countInside;
  switch(padding) {
    case 0:
      for(countOutside = 0;countOutside < height;countOutside ++) {
        for(countInside = 0;countInside < width;countInside ++) {
          if(countOutside != 0 && countOutside != (height-1)) {
            arr[countInside+1][countOutside] = ' ';
            if((countInside+1) == width || countInside == 0) {
              arr[countInside][countOutside] = message;
            }
          } else {
            arr[countInside][countOutside] = message;  
          }
        }
      }
      break;
    case 1:
      for(countOutside = 0;countOutside < height;countOutside ++) {
        for(countInside = 0;countInside < width;countInside ++) {
          arr[countInside][countOutside] = message;
        } 
      }
      break;
    default :
      break;
  }
  for(countOutside = 0;countOutside < height;countOutside ++) {
    for(countInside = 0;countInside < width;countInside ++) {
      printf("%c", arr[countInside][countOutside]);      
    }
    puts("");     
  }
}

void _Triangle_puts_(int height){
  int heightWidth = height;
  int countOutside,countInside;
  int i = 0;

  s:;  
  for(countOutside = 0;countOutside < heightWidth;countOutside ++) {
    printf("  ");
  }
  printf("+");
  for(countInside = 0;countInside < i;countInside ++) {
    printf("+");
  }
  i += 2;
  if(i != 0) {
    printf("+");
  }
  printf("\n");
  heightWidth = heightWidth - 1;
  if(heightWidth != 0) {
    goto s;
  }
  
}
*/

/*
int _System_Time_GetDay() {
  time_t systemTime;
  struct tm *systemTimeAddress;
  time(&systemTime);
  gmtime_s(&systemTime, systemTimeAddress);
  return systemTimeAddress->tm_mday;
}
int _System_Time_GetMonth() {
  time_t systemTime;
  struct tm *systemTimeAddress;
  time(&systemTime);
  gmtime_s(&systemTime, systemTimeAddress);
  return systemTimeAddress->tm_mon;
}
*/

/*
 *  Writer : Bre 97
 *    Writer Information :
 *      Twitter-ID :     @Tisnlu
 *      Google-Mail :    BY.SGATN3@Gmail.com
 *      Outlook-Mail :   BY_SGATN3@Outlook.com
 *      GitHub-Name :    Bre 97
 *    Writer Words :
 *      My Information is above this.
 *      You can give me with "Error Report",I will look Carefully.
 *      You can Upgrade the "this.h" File,but you should have told me.
 *  About :
 *    Last Update date : 12-25-2020
 */
