// Luhn�un Algoritmas�, CS50

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int x;
    int y = 0;
    int z = 0;
    long num = get_long("Credit Card Number: ");
//  Basamak say�s�n� buluyoruz
    int nDigits = floor(log10(num)) + 1;
//  printf("Basamak say�s�: %i\n",nDigits);
    
//  sondan ikinci rakamdan ba�lay�p iki�er iki�er rakamlar� belirlemek ve toplamak i�in
    for (int i = nDigits-1; i>0; i-=2 )
    {
        long a1 = pow(10,(nDigits-i)); // 10 �zeri ...
        x = (num/(a1) % 10);
        x = x*2; // kural gere�i iki ile �arp�yoruz her rakam�
        if (x>=10)  // iki ile �arp�nca ��kan sonucu de�il sonucun rakamlar�n� toplamak i�im
        {
            x = 1 + (x%10);
        }
//        printf("%i\n",x);
        y = y + x;

    }
//    printf("%i\n",y);
     
//  sonuncu rakamdan ba�lay�p iki�er iki�er rakamlar� belirlemek ve toplamak i�in
    for (int j=nDigits; j>0; j-=2 )
    {
        long a2 = pow(10,(nDigits-j));
            x = (num/(a2) % 10);
//        printf("%i\n",x);
        z = z + x;
    }
    
//   printf("%i\n",z);

//  bunlar� ilk ve ikinci rakam� belirlemek i�in kullan�yoruz
    long b = (pow(10,nDigits-1));
    long c = (pow(10,nDigits-2));

// Ge�erli - Ge�ersiz olmas�n� ve Hangi �irketin kart� oldu�unu belirlemek i�in
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

