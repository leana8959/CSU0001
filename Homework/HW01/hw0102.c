#include <stdio.h>

int main() {
    int valueA, valueB, product;
    int digitA1, digitA2, digitA3;
    int digitB1, digitB2, digitB3;
    int digitP1, digitP2, digitP3;
    printf("Please enter the first number: ");
    scanf("%d", &valueA);
    printf("Please enter the second number: ");
    scanf("%d", &valueB);

    if(valueA<0 || valueB<0){
        printf("Error! Only three digit non-negative integers allowed");
        return 1;
    }

    if(valueA/100==0 || valueB/100==0 || valueA/100>=10 || valueB/100>=10){
        printf("Error! Only three digit non-negative integers allowed");
        return 1;
    }

    product = valueA - valueB;

    digitA1 = valueA%10;
    digitA2 = valueA%100/10;
    digitA3 = valueA/100;

    digitB1 = valueB%10;
    digitB2 = valueB%100/10;
    digitB3 = valueB/100;


    if(product>=0){

        digitP1 = product%10;
        digitP2 = product%100/10;
        digitP3 = product/100;

        if(digitP3==0){
            if(digitP2==0){
                printf("   %d %d %d\n", digitA3,digitA2,digitA1);
                printf("-) %d %d %d\n", digitB3,digitB2,digitB1);
                printf("-----------\n");
                printf("       %d\n", digitP1);
            }
            else{
                printf("   %d %d %d\n", digitA3,digitA2,digitA1);
                printf("-) %d %d %d\n", digitB3,digitB2,digitB1);
                printf("-----------\n");
                printf("     %d %d\n", digitP2, digitP1);
            }
        }
        else{
            printf("   %d %d %d\n", digitA3,digitA2,digitA1);
            printf("-) %d %d %d\n", digitB3,digitB2,digitB1);
            printf("-----------\n");
            printf("   %d %d %d\n", digitP3,digitP2,digitP1);
        }

    }
    else if(product<0){

        digitP1 = product%10*-1;
        digitP2 = product%100/10*-1;
        digitP3 = product/100*-1;

        if(digitP3==0){
            if(digitP2==0){
                printf("   %d %d %d\n", digitA3,digitA2,digitA1);
                printf("-) %d %d %d\n", digitB3,digitB2,digitB1);
                printf("-----------\n");
                printf("     - %d\n", digitP1);
            }
            else{
                printf("   %d %d %d\n", digitA3,digitA2,digitA1);
                printf("-) %d %d %d\n", digitB3,digitB2,digitB1);
                printf("-----------\n");
                printf("   - %d %d\n", digitP2,digitP1);
            }
        }
        else{
            printf("   %d %d %d\n", digitA3,digitA2,digitA1);
            printf("-) %d %d %d\n", digitB3,digitB2,digitB1);
            printf("-----------\n");
            printf(" - %d %d %d\n", digitP3,digitP2,digitP1);
        }
    }

    return 0;
}
