#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(){
    u_int16_t n;
    double pi = 3.14159265358979323846;
    double ddd;
    printf("Please enter n (16-bits unsigned): ");
    scanf("%hd", &n);
    for(int i = 1; i <= n; i++){
        printf("n = %d:\n", i);
        double gregory = 0.0;
        for(int j = 1; j <= i; j++){
            if(j % 2 != 0){
                if(j == 1){
                    gregory += 4.0;
                }
                else{
                    gregory += (double)(4.0 / (j + (j-1))) ;
                }
            }
            else{
                gregory -= (double)(4.0 / (j + (j-1)));
            }
        }
        ddd = fabs(gregory - pi);
        printf("    Gregory-Leibniz series: %lf (%f)\n", gregory, ddd);

        double nilakantha = 0.0;
        for(int k = 1; k<=i; k++){
            if(k==1){
                nilakantha += 3.0;
            }
            else{
                if(k%2!=0){
                    nilakantha -= (double)(4.0 / (k * (k+1) * (k+2)));
                }
                else{
                    nilakantha += (double)(4.0 / (k * (k+1) * (k+2)));
                }
            }
        }
        ddd = fabs(nilakantha - pi);
        printf("    Nilakantha series: %lf (%f)\n", nilakantha, ddd);
    }
    return 0;
}