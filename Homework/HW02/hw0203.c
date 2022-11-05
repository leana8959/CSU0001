#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t number = 0;
    printf("Please enter a number: ");
    scanf("%d", &number);

    if(number<10){
        printf("%d + 0 = %d\n", number, number);
    }

    while(number>=10){
        int32_t sum = 0;
        int digits = 0;
        int temp = number;
        while(temp>0){
            temp = temp/10;
            digits++;
        }

        for(int i=digits; i>0; i--){
            if(i>1){
                int subtraction = 1;
                for(int j=1; j<i; j++){
                    subtraction*=10;
                }
                int add = number / subtraction;
                number = number % subtraction;
                sum += add;
                printf("%d + ", add);
            }
            else{
                int add = number % 10;
                sum += add;
                printf("%d ", add);
            }

        }
        printf("= %d\n", sum);
        number = sum;
    }
    return 0;
}