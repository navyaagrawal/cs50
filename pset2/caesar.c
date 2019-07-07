#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc!=2)
    {
        printf("Error!\n");
        return 1;
    }
    else 
    {
        int k = atoi(argv[1]);
        char s[1000], p[1000];
        printf("plaintext: ");
        gets(s);
        int i,n;
        for (i=0, n=strlen(s); i<n; i++)
        {
            if (isupper(s[i]))
            {
                p[i]=((s[i]-65+k)%26)+65;
            }
            else if (islower(s[i]))
            {
                p[i]=((s[i]-97+k)%26)+97;
            }
            else
            {
                p[i]=s[i];
            }
        }
        p[i]='\0';
        printf("ciphertext: ");
        puts(p);
    }
}