#include <cs50.h>
#include <stdio.h>

bool isAmex(long n);
bool isMastercard(long n);
bool isVisa(long n);
bool hasValidChecksum(long n);

int main(void)
{
    long n = get_long("Number: ");
 
    hasValidChecksum(n);
    if (!isAmex(n) && !isMastercard(n) && !isVisa(n))
    {
        printf("INVALID\n");
    }
}

bool isAmex(long n)
{
    if (n == 1 && hasValidChecksum(n))
    {
        printf("AMEX\n");
        return true;
    }
    
    return false;
}

bool isMastercard(long n)
{
    if (n == 2 && hasValidChecksum(n))
    {
        printf("MASTERCARD\n");
        return true;
    }
    
    return false;    
}

bool isVisa(long n)
{
   if (n == 3 && hasValidChecksum(n))
    {
       printf("VISA\n");
       return true;
    }
    
    return false;
}

bool hasValidChecksum(long n)
{
    int i = 0;
    int sum = 0;
    while(n)
    {
        int digit = n % 10;
        if(i % 2 != 0)
        {
            if (digit >= 5)
            {
                sum += ((digit * 2) % 10) + 1;
            }
            else
            {
                sum += digit * 2;
            }
        }
        else
        {
            sum += digit;
        }
        n /= 10;
        
        i++;
    }

    if (sum % 10 == 0)
    {
        printf("Validated\n");
        return true;
    }

    return false;
}
