#include <stdio.h>
int main()
{
    int option;
    int didItWork;
    char aCommonLetter[] = "ETAOINSRHLDCUMFPGWYBVKXJQ";
    char letter = 0;
    do 
    {
    printf("Enter the number of task to perform:\n1:Encrypt a message with rotational cypher with key.\n2:Decrypt rotational cypher with key.\n3:Encrypt a message with substitution cypher with key.\n4:Decrypt substitution cypher with key.\n5:Decrypt rotation cypher without key.\n");   
    scanf("%d", &option);
    //option = 5;
    }
    while(option > 5 || option < 1);

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
            printf("This is the encrypted message: %s\n", encryption);
            break;
        }
        case 2:
        {
            char encryption[] = "DBOBEJBO NPPTF";
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
                printf("This is the decrypted message: %s\n", message);
                break;
        }
        case 3:
        {
            char message[] = "BANANABREAD";
            char key[] = "XTSAUFBJZQLEHGMYCNVPDWORIK";
            int length = 1;
            while (message[length])
                length++;
            char encryption[length];
            for (int index = 0; index < length; index++)
            {
                    encryption[index] = message[index];
                    if (encryption[index] < 123 && encryption[index] > 96)
                        encryption[index] = encryption[index] - 32;         
                    if (encryption[index] > 64 && encryption[index] < 91)
                        encryption[index] = key[message[index] - 65];

            }
            printf("This is the encrypted message: %s\n", encryption);    
            break;
        }
        case 4:
        {
            char encryption[] = "TXGXGXTNUXA";
            char key[] = "XTSAUFBJZQLEHGMYCNVPDWORIK";
            int length = 1;
            while (encryption[length])
                length++;
            char message[length];
            for ( int index = 0; index < length; index++)
            {
                message[index] = encryption[index];
                if (message[index] < 123 && message[index] > 96)
                    message[index] = message[index] - 32;         
                if (message[index] > 64 && message[index] < 91)
                {
                    int letterPlace;
                    letterPlace = 0;
                    while (encryption[index] != key[letterPlace])
                        letterPlace++;
                    message[index] = letterPlace + 65;
                }   
            }
            printf("This is the decrypted message: %s\n", message);
            break;
        }
        case 5:
        {
           do
           {
                char encryption[] = "GEBGOC";            
                int length = 1;
                while (encryption[length])
                    length++;
                char message[length];
                int currentCount = 0;
                int highestCount = 0;
                int letterCounted = 0;
                for (int index = 0; index < length; index++)
                {
                    if (encryption[index] > 96 && encryption[index] < 123)
                        encryption[index] = encryption[index] - 32;
                    if (encryption[index] > 64 && encryption[index] < 91)
                    {        
                        if (currentCount > highestCount)
                        {    
                            letterCounted = encryption[index - 1];
                            highestCount = currentCount;
                        }
                        currentCount = 0;
                        for (int count = 0; count < length; count++)
                        {
                            if (encryption[count] == encryption[index])
                            currentCount++;
                        }
                    }

                }
                int key = letterCounted - aCommonLetter[letter];
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
                printf("Is this the decrypted message?: %s\na) Yes\nb) No" , message);
                scanf("%c", &didItWork - 97);
                if (didItWork)
                    ++;
            }
            while(didItWork);
            break;
        }
        default: printf("Command not recognised.");
    }
    return 0;
}
