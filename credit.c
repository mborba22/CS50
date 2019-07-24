#include <stdio.h>
#include <cs50.h>

int count(long long n);
int getsum1(long long n);
int getsum2(long long n);
bool isvalid(int n);
void getcard(long long n);

int main(void)
{
    long long cc = get_long("Number: ");
    int digits = count(cc), total=0;
    if(digits==13 || digits==15 || digits==16)
    {
       total = getsum1(cc)+getsum2(cc);
        
       if(isvalid(total)==true)
       {
           getcard(cc);
       }
    }
    else
    {
       printf("INVALID\n");
    }    
}

//Gets the length of the card number
int count(long long n)
{
    int count = 0;
    while(n != 0)
    {
        n=n/10;
        count++;
    }
    return count;
}

//Gets the sum of the product of every other number times 2.
int getsum1(long long n)
{
    int number[16], sum=0, digits;
    long long product = 0;
    n=n/10;
    for(int i=0;n>0;i++)
    {
        number[i] = n%10;
        product = number[i]*2;
        digits = count(product);
        if(digits>1)
        {
            for(int j=0;product>0;j++)
            {
                number[j] = product%10;
                sum += number[j];
                product /= 10;
            }
        }
        else
        {
           sum += product;
        }
        n /= 100;
    }
    return sum;
}

//Gets the sum of all other numbers
int getsum2(long long n)
{
    int number[16], sum=0;
    for(int i=0;n>0;i++)
    {
        number[i] = n%10;
        sum+=number[i];
        n/=100;
    }
    return sum;
}

//Divides the total of the two sums by 10 to validate the card number
bool isvalid(int n)
{
    if(n%10==0)
    {
       return true; 
    }
    else
    {
        printf("INVALID\n");
        return false;
    }
}

//Conmpares the beginning values and prints the corresponding card maker
void getcard(long long n)
{
    while(count(n)>2)
    {
        n/=10;
    }

   if(n>39 && n<50)
   {
       printf("VISA\n");
   }
   else if(n>50 && n<56)
   {
       printf("MASTERCARD\n");
   }
   else if(n==34 || n==37)
   {
       printf("AMEX\n");
   }
   else
   {
       printf("INVALID\n");
   }
}
