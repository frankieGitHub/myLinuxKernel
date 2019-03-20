#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

unsigned char revertByte(unsigned char input) {
    unsigned char output = 0;

    int mask = 0;
    for(int i=0; i<8; i++) {
        mask = !!(input & (1<<i));
        if(mask == 1) output = output | (1 << (7-i));

        mask = 0;
    }

    return output;
}

int main()
{
    unsigned char test = 58;
    unsigned char result = revertByte(test);

    printf("result is %d\n", result);
    cout << result << endl;

    return 0;
}
