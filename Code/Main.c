
#include "Descript.h"
#include "ShortcutKey.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>




















int main(void) {

        Putin();




        return 0;

}


void Putin() {

        char List[256 + 1];

        struct _PutIn {
                int HeadCode;
                int MainCode;
        } PutIn;

        for(size_t Index = 0; Index < 256; Index ++) {

                

                PutIn.HeadCode = _getch();
                PutIn.MainCode = _getch();

                
                switch (PutIn.HeadCode) {
                        case Key_HeadCode_IndependentControl :
                                goto IndependentControl;
                                break;

                        default :
                                goto Others;
                                break; 
                                
                }

                IndependentControl :
                if(PutIn.MainCode == Key_Esc) {
                        exit(0);
                }

                Others:
                List[Index] = PutIn.MainCode;

                system("cls");

                printf("%s\n", List);
                for(size_t i = 0; i < strlen(List); i ++) {
                        printf("%c", '\x20');

                }
                printf("%c", '`');

                
        }


}


void PutPosition() {


}
