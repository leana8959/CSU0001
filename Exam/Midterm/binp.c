#include "binp.h"

#include <stdio.h>
#include <stdint.h>
#include <math.h>

int32_t isBinaryPalindrome(int32_t x){
    int32_t runtime = 0;
    int32_t remainder = 0;
    int32_t binary1 = 0;
    int32_t binary2 = 0;
    int32_t binary3 = 0;
    int32_t binary4 = 0;
    int32_t palindrome = 0;
    while(x > 0){
        for(int i=0; i<8; i++){
            remainder = x % 2;
            x /= 2;
            binary1 += remainder * pow(10, i);
            runtime++;
        }
        for(int i=0; i<8; i++){
            remainder = x % 2;
            x /= 2;
            binary2 += remainder * pow(10, i);
            runtime++;
        }
        for(int i=0; i<8; i++){
            remainder = x % 2;
            x /= 2;
            binary3 += remainder * pow(10, i);
            runtime++;
        }
        for(int i=0; i<8; i++){
            remainder = x % 2;
            x /= 2;
            binary4 += remainder * pow(10, i);
        }
    }
    for(int i = 0; i < 8; i++){
        int32_t second_half = (int)(binary1/pow(10, i)) % 10;
        int32_t first_half = (int)(binary4/pow(10, 7-i))%10;
        if(first_half==second_half){
            palindrome += 1;
        }
    }
    for(int i = 0; i < 8; i++){
        int32_t second_half = (int)(binary2/pow(10, i)) % 10;
        int32_t first_half = (int)(binary3/pow(10, 7-i))%10;
        if(first_half==second_half){
            palindrome += 1;
        }
    }
    if(palindrome==16){
        return 1;
    }
    else{
        return 0;
    }
}