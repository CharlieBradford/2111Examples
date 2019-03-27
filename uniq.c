#include <string.h>

typedef int bool;
#define TRUE 1
#define FALSE 0 /* I know fake booleans are gross but */ 
                /* I'm  trying to stick to the script */

int uniq(unsigned int n, char *a[], char *b[])            
{                                                        
    strcpy(b[0], a[0]);
    int i = 0;
    int k = 0;                                            
    while(i < n)                            
    {
        bool copy = FALSE;
        int j = 0;
        while (a[i][j] != '\0' && b[k][j] != '\0' && !copy)                     
        {
            if (a[i][j] != b[k][j])
            {
                copy = TRUE;
            }
            j = j + 1;
        }
        if (copy)
        {
            k = k + 1;
            strcpy(b[k], a[i]);
        }
        i = i + 1;
    }                                                    
    return k + 1;
}

