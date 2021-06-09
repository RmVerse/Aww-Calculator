#include <direct.h>
#include <io.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

#include "Platform.C.Rmdust.Description.h"

/*
 * 标有 Rmdust 的函数均为新式函数
 * 剩余函数正在更新
 *
 * 标有 _Inline 的函数均为内部函数
 */

enum SystemMessageSurfaceIndexValueLableLevel { 
  Error, Warning, Non 
} SystemMessageLableLevel;

// 写入日志的原信息
struct SystemMessageSurfaceIndexValue {
  // 标题
  char Title[32];
  // 标题附加信息
  char TitleAddons[128];
  // 详细信息
  char Message[128];

  // 日志活动状态
  bool Active;

  // 日志错误等级
  int LableLevel;

  // Do NOT touch !
  // 用于定位 Message[MessageIndex]
  int MessageIndex;

} SystemMessage;

// 初始化
int Rmdust_Reset() {
  // 初始化文件夹
  Rmdust_System_IO_Folder_Create("C:\\Users\\Public\\Documents\\RMDUST");

  // 初始化日志活动状态
  Rmdust_SetLogsWriteActive(false);

  // 初始化日志错误等级
  SystemMessage.LableLevel = SystemMessageLableLevel = Non;

  // 初始化日志文件
  Rmdust_System_IO_Logs_Reset();

  Rmdust_SetSystemMessage_MessageIndex(0);

  return 1;
}

// +1 重载
int Rmdust_GetSystemMessage_LableLevel() {
  return SystemMessageLableLevel;
}
char* Rmdust_GetSystemMessage_LableLevel_ToString() {
  if (SystemMessage.LableLevel == 0) {
    return "Error";
  } else if (SystemMessage.LableLevel == 1) {
    return "Warning";
  } else if (SystemMessage.LableLevel == 2) {
    return "Non";
  }

  return 0;
}

void Rmdust_SetSystemMessage_LableLevel(char* Message) {
  // 毫无意义的转换
  if (!strcmp(Message,"Error")) {
    SystemMessageLableLevel = Error;
  } else if (!strcmp(Message, "Warning")) {
    SystemMessageLableLevel = Warning;
  } else if (!strcmp(Message, "Non")) {
    SystemMessageLableLevel = Non;
  }

  _Inline_SetSystemMessage_LableLevel();
}

inline static void _Inline_SetSystemMessage_LableLevel() {
  SystemMessage.LableLevel = SystemMessageLableLevel;
}


// 设置日志是否写入
void Rmdust_SetLogsWriteActive(bool Active) { SystemMessage.Active = Active; }
bool Rmdust_GetLogsWriteActive() { return SystemMessage.Active; }

//
void Rmdust_SetSystemMessage_Title_ToString(char Message[]) {
  strcpy_s(SystemMessage.Title, 32, Message);
}
char* Rmdust_GetSystemMessage_Title_ToString() { return SystemMessage.Title; }

void Rmdust_SetSystemMessage_TitleAddons_ToString(char Message[]) {
  strcpy_s(SystemMessage.TitleAddons, 128, Message);
}
char* Rmdust_GetSystemMessage_TitleAddons_ToString() {
  return SystemMessage.TitleAddons;
}

void Rmdust_SetSystemMessage_MessageIndex(int Index) {
  SystemMessage.MessageIndex = Index;
}
int Rmdust_GetSystemMessage_MessageIndex() {
  return SystemMessage.MessageIndex;
}

size_t Rmdust_GetSystemMessage_MessageStrlength() {
  return strlen(Rmdust_GetSystemMessage_Message_ToString());
}
unsigned int Rmdust_GetSystemMessage_MessageStrlength_ToIndex() {
  return (unsigned int)(Rmdust_GetSystemMessage_MessageStrlength() == 0
                            ? 0
                            : Rmdust_GetSystemMessage_MessageStrlength() - 1);
}

void Rmdust_SetSystemMessage_Message_ToString(char Message[]) {
  strcpy_s(SystemMessage.Message, 128, Message);
}
char* Rmdust_GetSystemMessage_Message_ToString() {
  return SystemMessage.Message;
}

void Rmdust_SetSystemMessage_Message_ToChar(char Message) {
  SystemMessage.Message[Rmdust_GetSystemMessage_MessageIndex()] = Message;
  Rmdust_SetSystemMessage_MessageIndex(Rmdust_GetSystemMessage_MessageIndex() +
                                       1);
}
char Rmdust_GetSystemMessage_Message_ToChar(int Index) {
  return SystemMessage.Message[Index];
}

void _Console_Write_CutToEnd(int startDelay, int endDelay, int whetherToEnd,
                             char message[]) {
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
void _Console_Write_CutToEndWithAscii(int startDelay, int endDelay,
                                      char message[]) {
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
        buff = ntemp;                        //	   0=1
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
void _Console_Write_Frame(char log[], char mark, unsigned int short titleMode) {
  for (int count = 0; count < 50; count++) {
    printf("%c", mark);
  }
  printf("\n");

  int logWidth = 0;
  for (unsigned int stTemp = 0; stTemp < strlen(log); stTemp++) {
    printf("%c", log[stTemp]);
    logWidth++;
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
  signed short int temp, tempTwo, count = 0;

  for (temp = 0; temp < 120; temp++) {
    temp <= 40 ? system("color f8")
               : temp <= 80 ? system("color f4") : system("color f6");
    for (tempTwo = 0; tempTwo < temp; tempTwo++) {
      printf("=");
    }
    printf(">\n");

    count <= 100 ? printf("%d%%", count++) : printf("Resource preparation");

    Sleep(temp);
    system("cls");
  }
  system("color f0");
}
void _Console_Write_LoadingAnimationSec(void) {
  unsigned short int temp;
  for (temp = 0; temp < 120; temp++) {
    temp <= 40 ? system("color f8")
               : temp <= 80 ? system("color f4") : system("color f6");
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
char* _Data_Convert_ArrayLinkBoth(char object[], char message[],
                                  char result[]) {
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
  FILE* fileAddress = NULL;
  fopen_s(&fileAddress, fileNameAddress, mode);
  if (fileAddress == NULL) {
    return -1;
  }
  fclose(fileAddress);
  return 1;
}
int _IO_File_Write(char fileNameAddress[], char mode[], char message[]) {
  FILE* fileAddress = NULL;
  fopen_s(&fileAddress, fileNameAddress, mode);
  if (fileAddress == NULL) {
    return -1;
  }
  fprintf(fileAddress, "%s", message);
  fclose(fileAddress);
  return 1;
}
int _IO_File_Read_State(char fileNameAddress[]) {
  FILE* fileAddress = NULL;
  fopen_s(&fileAddress, fileNameAddress, "r");
  if (fileAddress == NULL) {
    return -1;
  } else {
    fclose(fileAddress);
    return 1;
  }
}

int Rmdust_System_IO_Logs_Reset() {
  FILE* FilePath = NULL;
  fopen_s(&FilePath, "C:\\Users\\Public\\Documents\\RMDUST\\Log.txt", "w+");

  if (FilePath == NULL) {
    return -1;
  }

  fclose(FilePath);

  return 1;
}

/// +1 重载
int Rmdust_System_IO_Logs_Write() {
  if (Rmdust_GetLogsWriteActive() == false) {
    return 0;
  }

  FILE* FilePath = NULL;
  fopen_s(&FilePath, "C:\\Users\\Public\\Documents\\RMDUST\\Log.txt", "a+");

  if (FilePath == NULL) {
    return 0;
  }

  fprintf(FilePath, "-;\n-%d%s\n-5%s\n%s\n%s\n-;\n\n",
          Rmdust_GetSystemMessage_LableLevel(),
          Rmdust_GetSystemMessage_LableLevel_ToString(),
          Rmdust_GetSystemMessage_Title_ToString(),
          Rmdust_GetSystemMessage_TitleAddons_ToString(),
          Rmdust_GetSystemMessage_Message_ToString());

  fclose(FilePath);

  Rmdust_SetLogsWriteActive(false);

  return 1;
}

int Rmdust_System_IO_Logs_Write_ToMessage() {
  if (Rmdust_GetLogsWriteActive() == false) {
    return 0;
  }

  Rmdust_System_IO_Write("C:\\Users\\Public\\Documents\\RMDUST\\Log.txt",
                         Rmdust_GetSystemMessage_Message_ToString());

  Rmdust_SetLogsWriteActive(false);

  return 1;
}

int Rmdust_System_IO_Folder_Create(char FolderName[]) {
  if (!_access(FolderName, 0)) {
    return 0;
  }

  return _mkdir(FolderName);
}

inline int Rmdust_System_IO_Write(char Address[128], char Message[512]) {
  FILE* FilePath = NULL;
  fopen_s(&FilePath, Address, "r+");

  if (FilePath == NULL) {
    return 0;
  }

  fprintf(FilePath, "%s", Message);

  fclose(FilePath);

  return 1;
}

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
 *      You can give me with "Error Report"as I will Carefully.
 *      You can Upgrade this File,but you should have told me.
 *  About :
 *    Last Update date : 6-8-2021
 */
