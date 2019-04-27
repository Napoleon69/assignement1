#include <stdio.h>
int main()
{
    printf("Enter the number of task to perform:\n1:Encrypt a message with rotational cypher with key.\n2:Decrypt rotational cypher with key.\n3:Encrypt a message with substitution cypher with key.\n4:Decrypt substitution cypher with key.\n");   
    int option = 1;
    switch (option)
    {
        case 1:
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
            printf("%s\n", encryption);
            break;
        }
        case 2:
        {
            char encryption[] = "AFCSB";
            int length = 1;
            while (encryption[length])
                length++;
            char message[length];
            int key = 1;
            if (key > 0)
                key = key - 26;
            for (int index = 0; index < length; index++)
                {
                    message[index] = encryption[index];
                    if (message[index] > 96 && message[index] < 123)
                        message[index] = message[index] - 32;
                    if (message[index] > 64 && message[index] < 91)
                        {
                            message[index] = message[index] - 65;
                            message[index] = (message[index] - key) % 26 + 65;
                        }
                }
                printf("%s\n", message);
        }
    }

    return 0;
}
