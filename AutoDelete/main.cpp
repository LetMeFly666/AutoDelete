/*
 * @Author: LetMeFly
 * @Date: 2022-08-11 21:29:48
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-08-11 21:48:27
 */
#include "AutoDelete.h"
//#pragma warning(disable : 4996)

bool runOnce = false;

int main(int argc, char** argv) {
    if (argc == 2) {
        runOnce = true;
        AutoDelete autoDelete;
        SetDelete setDelete(argv[1], getTempFilePath(autoDelete));
    }
    else {
        // AutoDelete autoDelete(5);
        AutoDelete autoDelete;
    }
    return 0;
}