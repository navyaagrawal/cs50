#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, int argv[])
{
    char g[1000];
    strcpy(g,argv[1]);
    if (argc!=2)
    {
        printf("Oops!\n");
        return 1;
    }
    else
    {
        for (int j=0, n=strlen(g) ; j<n ; j++)
        {
            if (!isalpha(g[j]))
            {
                 printf("Oops!\n");
                 return 1;
            }
        }
            printf("plaintext: ");
            char s[1000],p[1000];
            gets(s);
            int i, h=strlen(s), f=0,l;
            for (i=0;i<h;i++)
            {
                if (islower(s[i]))
                {
                    l = f%strlen(g);
                    if (islower(g[l]))
                    p[i]=((s[i]-97+g[l]-97)%26)+97;
                    else 
                     p[i]=((s[i]-97+g[l]-65)%26)+97;
                    f++;
                }
                else if (isupper(s[i]))
                {
                    l = f%strlen(g);
                    if (isupper(g[l]))
                    p[i]=((s[i]-65+g[l]-65)%26)+65;
                    else
                    p[i]=((s[i]-65+g[l]-97)%26)+65;
                    f++;
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