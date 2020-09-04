#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("Height: ");
    while (height>8 || height<1){
        height = get_int("Height: ");
    }

    for (int i = 1; i<height+1; i++){
        for(int k=height-i; k>0; k--){
            printf(" ");
        }
        for(int j = 1; j<i+1; j++){
            printf("#");
        }
        printf("\n");
    }
}

