#include <stdio.h>
int main()
{
    char message[] = "ZEBRA";
    int length = 1;
    while (message[length])
        length ++;
    char encryption[length];    
    int key = 1;
    if (key < 0)
     key = 26 + key;
    for (int index = 0; index < length; index ++)
    {
        encryption[index] = message[index];
        if (encryption[index] > 96 && encryption[index] < 123)
            encryption[index] = encryption[index] - 32;
        if (encryption[index] > 64 && encryption[index] < 91)
        {    
            encryption[index] = encryption[index] - 65;
            encryption[index] = (encryption[index] + key) % 26 + 65;
        }    
    }
    printf("%s", encryption);
    return 0;
}
