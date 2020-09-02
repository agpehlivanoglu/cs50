// Luhn’un Algoritmasý, CS50

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int x;
    int y = 0;
    int z = 0;
    long num = get_long("Credit Card Number: ");
//  Basamak sayýsýný buluyoruz
    int nDigits = floor(log10(num)) + 1;
//  printf("Basamak sayýsý: %i\n",nDigits);
    
//  sondan ikinci rakamdan baþlayýp ikiþer ikiþer rakamlarý belirlemek ve toplamak için
    for (int i = nDigits-1; i>0; i-=2 )
    {
        long a1 = pow(10,(nDigits-i)); // 10 üzeri ...
        x = (num/(a1) % 10);
        x = x*2; // kural gereði iki ile çarpýyoruz her rakamý
        if (x>=10)  // iki ile çarpýnca çýkan sonucu deðil sonucun rakamlarýný toplamak içim
        {
            x = 1 + (x%10);
        }
//        printf("%i\n",x);
        y = y + x;

    }
//    printf("%i\n",y);
     
//  sonuncu rakamdan baþlayýp ikiþer ikiþer rakamlarý belirlemek ve toplamak için
    for (int j=nDigits; j>0; j-=2 )
    {
        long a2 = pow(10,(nDigits-j));
            x = (num/(a2) % 10);
//        printf("%i\n",x);
        z = z + x;
    }
    
//   printf("%i\n",z);

//  bunlarý ilk ve ikinci rakamý belirlemek için kullanýyoruz
    long b = (pow(10,nDigits-1));
    long c = (pow(10,nDigits-2));

// Geçerli - Geçersiz olmasýný ve Hangi þirketin kartý olduðunu belirlemek için
    int sum = y + z;
    if (sum%10 == 0)
    {
        if (nDigits<15 || nDigits>16)
        {
            printf("INVALID\n");
        }
        if (nDigits==15)
        {
            if ((num/(b) % 10) == 3 && (num/(c) % 10) == 4)
            {
                printf("AMEX\n");
            }
            else if ((num/(b) % 10) == 3 && (num/(c) % 10) == 7)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        if (nDigits==16)
        {
            if ((num/(b) % 10) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                if ((num/(b) % 10) == 5)
                {
                    if ((num/(c) % 10)==1|| (num/(c)%10)==2|| (num/(c)%10)==3||(num/(c)%10)==4||(num/(c)%10)==5)
                    {
                        printf("MASTERCARD\n");
                    }
                    else
                    {
                         printf("INVALID\n"); 
                    }
                }
                else
                {
                   printf("INVALID\n"); 
                }
            }
        }        
    }
    else 
    {
        printf("INVALID\n");
    }
}

