#include <stdio.h>
#include <stdlib.h>
  
int main()
{
    FILE *fptr1, *fptr2;
    char filename[100], c;
  
    // Open one file for reading
    fptr1 = fopen("input.txt", "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", "input.txt");
        exit(0);
    }
  
    // Open another file for writing
    fptr2 = fopen("output.txt", "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s \n", "output.txt");
        exit(0);
    }
  
    // Read contents from file
    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
  
    printf("\nContents copied to %s", "output.txt");
  
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}