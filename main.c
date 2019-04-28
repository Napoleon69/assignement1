
//This program can encrypt a message using rotational or substitution cipers as long as it is given a key and message. 
//It can decrypt a rotational or substitution cipher when it is provided the key used to encrypt them in the first place. 
//A rotational cipher can also be decrypted without a key if provided user input. 
//The messages must be hardcoded to the respective strings and are not read from a file. The keys must also be hardcoded to their respective 'key' variables with the exception of the first two cases, dealing with the rotation cypher.

#include <stdio.h>
int main()
{
    char didntWork; //Variable initialised now so its out of the do while loop in case 5. Used to determine whether case 5 successfully decipherd the message
    int option;     //Variable initialised now so it is out of the first do while loop.
    char aCommonLetter[] = "ETAOINSRHLDCUMFPGWYBVKXJQ"; // This string displays the most frequently used letters in the english languare. It will be used in case 5 to dictate the order in which letters are tested for being the most frequent in a string. 
    unsigned char letter = 0;   // This is the variable that is incremented when case 5 incorrectly decrypts a message, causing the next element of aCommonLetter to become the letter assumed to be the most frequent in a given string.
    do //This do-while function repeats the prompt for a case to be selected after a given input does not correctly identify a case to run.
    {  //The printf function prompts the user to select a case.
    printf("Enter the number of task to perform:\n1:Encrypt a message with rotational cipher with key.\n2:Decrypt rotational cipher with key.\n3:Encrypt a message with substitution cipher with key.\n4:Decrypt substitution cipher with key.\n5:Decrypt rotation cipher without key.\n");   
    scanf("%d", &option);   // This reads the chosed case and assigns it to the 'option' variable.
    }
    while(option > 5 && option < 1);    //This is the requirement for the user prompt to repeat.

    switch (option) //The start of the switch statement using the variable 'option' which has been assigned by the user.
    {
        case 1: //Case 1 encrypts a message with a rotational cipher when given a key and message.
        {
            char message[] = "ZEBRA";   //The message to be encrypted will be stored in this string. To be typed between the double apostrophes.
            int length = 1; //This assigns makes sure the while loop activates as it needs a non-zero value to be true. As the given strings will have at least one element there is no issue.
            while (message[length]) //This while loop counts the number of elements by incrementing the variable 'length' as long as the element does't store a NULL.
            length ++;  
            char encryption[length];  //This is the string that will have its elements edited as the 'message' string cannot be edited due to their method of initialisation and will cause a segmentatin fault.  
            int key;
            printf("Please enter the key to encrypt the rotational cipher:\n"); //Prompts the user to input the key.
            scanf("%d", &key);  //Reads the user input and stores the integer in the variable 'key'.
            if (key < 0)    //This if statement takes negative keys and transforms them into their positive counterparts. This is to avoid a negative number before the modulus in the encryption equation which will not work as intended.
                key = 26 + key;
            for (int index = 0; index < length; index ++)   //This for statement activates for all elements of the given message string individually.
            {
                encryption[index] = message[index]; //The 'encryption' element is made equal to the 'message' element of the same position, allowing it to be edited, since the 'message' string cannot.
                if (encryption[index] > 96 && encryption[index] < 123) //This if statement turns any lower case letters to higher case.
                    encryption[index] = encryption[index] - 32;
                if (encryption[index] > 64 && encryption[index] < 91) //This if statement only works on higher case letters, since lower case letters were turned into higher case, only symbols and numbers are left alone.
                {    
                    encryption[index] = encryption[index] - 65; //The numerals that represent ASCII characters are made to symbolise each letter. A being 0 and Z being 25. This makes it much easier to change the letters.
                    encryption[index] = (encryption[index] + key) % 26 + 65; //The key is added to the number symbolising the letter. The modulus acts as the wrap around so that for example if a key is added to it wraps around to the start of the alphabet.
                }                                                            //The new number symbolising the letter is then turned back into a number that represents its ASCII character.
            }                                                                //This is then stored in the respective index of the 'encryption' string.
            printf("This is the encrypted message: %s\n", encryption);
            break;
        }
        case 2: //Case 2 decrypts a rotational cipher when given a message and the key used to encrypt it.
        {
            char encryption[] = "DBOBEJBO NPPTF"; //The message to decrypt is stored here.
            int length = 1; //As seen in case 1, these lines measure the length of the string.
            while (encryption[length])
                length++;
            char message[length]; //The string which will stored the decrypted message is initialised as the same length as the encrypted message.
            int key;
            printf("Please enter the key that was used to encrypt the rotational cipher:\n"); 
            scanf("%d", &key); //The key is stored as an integer in 'key'.
            if (key > 0) // Since this is decryption, positive keys are turned into their negative counterparts so as not to make a the modulus operate on a negative.
                key = key - 26; 
            for (int index = 0; index < length; index++) //The for loop makes sure all elements of the message are acted on.
            {
                    message[index] = encryption[index]; //The corresponding elements in the strings are made equal so that the elements can be edited.
                    if (message[index] > 96 && message[index] < 123) //Lower case are turned to upper case.
                        message[index] = message[index] - 32;
                    if (message[index] > 64 && message[index] < 91) //Only upper case characters are encrypted.
                    {
                            message[index] = message[index] - 65;   //The stored numbers are made to symbolise a letter of the alphabet.
                            message[index] = (message[index] - key) % 26 + 65;  //The key is removed from this letter and the modulus is taken to make sure the letters wrap around.
                    }                                                           //The numbers are then transformed back into numerals that represent its ASCII character.
            }                                                                   //The number is stored in the respective element of the 'message' string.
                printf("This is the decrypted message: %s\n", message);
                break;
        }
        case 3:
        {
            char message[] = "BANANABREAD"; //The message to encrypt is placed in this string.
            char key[] = "XTSAUFBJZQLEHGMYCNVPDWORIK"; //The substitution key is placed in this string.
            int length = 1; //The length of the message is taken.
            while (message[length])
                length++;
            char encryption[length]; //The string where the encrypted message will be stored is initialised with the same length.
            for (int index = 0; index < length; index++) //This for loop works on all the elements one at a time in the original message.
            {
                    encryption[index] = message[index]; //The value of the element in the original message is copied into the corresponding element in the 'encryption' string so it can be edited.
                    if (encryption[index] < 123 && encryption[index] > 96) //Lower case become upper case.
                        encryption[index] = encryption[index] - 32;        
                    if (encryption[index] > 64 && encryption[index] < 91)  //Only upper case letters are encrypted, symbols and numbers are copied over unchanged.
                        encryption[index] = key[message[index] - 65];   //The value of the numeral representing its respective ASCII character in the original message is reduced to symbolise the position of a letter in the alphabet.E.g. A as 0, Z as 25.  
            }                                                           //This number is used to find its encoded counterpart by taking the value of the ASCII character at its positional value in the 'key' string.  
            printf("This is the encrypted message: %s\n", encryption);  //This new value is stored in the its respective position in the 'encryption' string.  
            break;
        }
        case 4: //Case 4 decrypts a message encoded with substitution cipher.
        {
            char encryption[] = "TXGXGXTNUXA";  // The message to decrypt is placed int this string.
            char key[] = "XTSAUFBJZQLEHGMYCNVPDWORIK";  //The decryption key is placed in this string.
            int length = 1; //The length of the message is calculated.
            while (encryption[length])
                length++;
            char message[length]; //The string which will hold the deciphered string is initialised here with the same length.
            for ( int index = 0; index < length; index++)   //This for loop will act on every element of the string one by one.
            {
                message[index] = encryption[index]; //The value of the elements in the encrypted message are copied to the respective element of the 'message' string.
                if (message[index] < 123 && message[index] > 96) //Characters representing lower case numerals are made upper case.
                    message[index] = message[index] - 32;         
                if (message[index] > 64 && message[index] < 91) //Only uppercase letters are encrypted.
                {
                    int letterPlace;    //This variable is made to help find the corresponding element number in the key for each encrypted element in the encrypted message.
                    letterPlace = 0;    //It is initialised to 0 as 0 is the first element in the 'key' string.
                    while (encryption[index] != key[letterPlace]) //This while loop finds the position in the 'key' string where the numerical value of the element from the key and the element from the encrypted message match. 
                        letterPlace++;
                    message[index] = letterPlace + 65; //Once the position of the respective character is foun it is turned into a numerical value representing its ASCII code and it is stored in the respective index in the 'message' string.
                }   
            }
            printf("This is the decrypted message: %s\n", message);
            break;
        }
        case 5: //Case 5 decrypts a rotational cipher without a key. It does this by counting the most used letter and assigning it to the most used english letter. If this does not decrypt the message, it assignes it the second most used english letter and so on until a solution is found.
        {
           do   //This block of code will be repeated until the message is successfully decrypted, each time, the letter assumed to be the most used letter in the message will change. 
           {    //The message is to decrypt it written here in 'encryption'.
                char encryption[] = "TVU TVAOTH: AOL KHAH IYVBNOA AV BZ IF AOL IVAOHU ZWPLZ WPUWVPUAZ AOL LEHJA SVJHAPVU VM AOL LTWLYVY'Z ULD IHAASL ZAHAPVU. DL HSZV RUVD AOHA AOL DLHWVU ZFZALTZ VM AOPZ KLHAO ZAHY HYL UVA FLA VWLYHAPVUHS. DPAO AOL PTWLYPHS MSLLA ZWYLHK AOYVBNOVBA AOL NHSHEF PU H CHPU LMMVYA AV LUNHNL BZ, PA PZ YLSHAPCLSF BUWYVALJALK. IBA TVZA PTWVYAHUA VM HSS, DL'CL SLHYULK AOHA AOL LTWLYVY OPTZLSM PZ WLYZVUHSSF VCLYZLLPUN AOL MPUHS ZAHNLZ VM AOL JVUZAYBJAPVU VM AOPZ KLHAO ZAHY. THUF IVAOHUZ KPLK AV IYPUN BZ AOPZ PUMVYTHAPVU.";            
                int length = 1; //First the length of the string is calculated.
                while (encryption[length])
                    length++;
                char message[length];   //The string which will hold the decrypted message is initialised with the same length.
                int currentCount = 0;   //This variable will count the number of times each letter is used in the encrypted message.
                int highestCount = 0;   //This variable will remember the highest count of a letter so far.
                int letterCounted = 0;  //This variable will remember the ASCII value of the most frequent letter.
                for (int index = 0; index < length; index++) //This for loop will act on every element in the string one by one. Counting how many times the letter stored in each element appears and remembering the most frequent one.
                {
                    if (encryption[index] > 96 && encryption[index] < 123)  //If a lower case letter is stored, it becomes upper case.
                        encryption[index] = encryption[index] - 32;
                    if (encryption[index] > 64 && encryption[index] < 91)   //Only upper case letters are acted upon, other characters pass through untouched.
                    {                                                       
                        if (currentCount > highestCount) //If last letter counted is of a higher frequency than the current most common letter, the letter is remembered as being the most frequent so far, and its frequency becomes the highest count.
                        {    
                            letterCounted = encryption[index - 1];
                            highestCount = currentCount;
                        }
                        currentCount = 0;   //Current count must be reset.
                        for (int count = 0; count < length; count++)    //This for loop takes a letter stored inside an element of the encrypted message and counts how many times the same letter shows up in the rest of the message.
                        {
                            if (encryption[count] == encryption[index])
                            currentCount++;
                        }
                    }
                }
                int key = letterCounted - aCommonLetter[letter];    //The most common letter in the string is then reduced by the letter assumed to be most common to find the expectec deviance from the normal assignment, of A as 0 through Z as 25, which is the key.
                if (key > 0)    //The code block continues as if it were a decryption where the key is known.
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
                printf("Is this the decrypted message?: %s\na) Yes\nb) No\n" , message);    //The message is displayed to the user, and prompted to answer whether the output looks correct.
                char temporary;     //This variable is used to store the answer of the user.
                scanf("\n%c", &temporary);  
                if (temporary == 'a')   
                    didntWork = 0;
                else
                    didntWork = 1;
                if (didntWork)      //If the message displayed was wrong, the letter assumed to be most common will change.
                    letter++;
            }
            while(didntWork);   //As long as the message doesn't produce the correct output the case will repeat with a new letter assumed to be most common until all letters are checked and the output message is verified as being correct.
            break;
        }
        default: printf("Command not recognised.\n");
    }
    return 0;
}
