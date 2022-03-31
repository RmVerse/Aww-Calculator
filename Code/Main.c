
#include "Descript.h"
#include "ShortcutKey.h"

#include "Platform.Win64.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>





















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
                                List[Index] = PutIn.HeadCode;
                                continue;
                }


                switch (getch()) {
                        IndependentControl :
                        case Key_Esc :
                                exit(0);

                }
        }


}


void PutPosition() {


}