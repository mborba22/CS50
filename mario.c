#include <cs50.h>
#include <stdio.h>

void pyramid(int n);

int main(void)
{
    int i = get_int("Select the height of your pyramid between 1 and 8: ");   
    if(i>0 & i<9)
    {
        pyramid(i);
    }
    else
    {
        while(i<1 || i>8)
        {
            i = get_int("Incorrect, please enter a number between 1-8: ");
        }
        pyramid(i);
    }
}

void pyramid(int n)
{
   for(int i=0;i<n;i++)
   {
       for(int l=((n-1)-i);l>0;l--)
       {
           printf(" ");
       }
       for(int k=0;k<=i;k++)
       {
           printf("#");
       }
       printf("  ");
       for(int j=0;j<=i;j++)
       {
           printf("#");
       }
       printf("\n");
   }
}
