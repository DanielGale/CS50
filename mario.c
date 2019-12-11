#include <cs50.h>
#include <stdio.h>

void repeatChar(char c, int repetitions);

int main(void)
{
    int n;
    
    do
    {
        n = get_int("Height: ");
    }
    while(n < 1 || n > 8);
    
    for(int i = 1;i <= n;i++){
        repeatChar(' ',n-i);
        repeatChar('#',i);
        printf("  ");
        repeatChar('#',i);
        printf("\n");
    }
    
}

void repeatChar(char c, int repetitions){
    for(int i=0;i < repetitions;i++){
        printf("%c",c);
    }
}
