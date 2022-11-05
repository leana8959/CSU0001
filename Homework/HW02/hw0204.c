#include <stdio.h>
#include <math.h>

int main(){
    int month = 0, year = 0, price = 0, term = 0, rate = 0, tax = 0, insurance = 0, addPay = 0;
    printf("Loan Date: ");
    scanf("%d.%d", &year, &month);
    printf("Loan Price: ");
    scanf("%d", &price);
    printf("Loan Term (yrs): ");
    scanf("%d", &term);
    printf("Interest Rate (%%): ");
    scanf("%d", &rate);
    printf("Property Tax (/m): ");
    scanf("%d", &tax);
    printf("Insurance (/m): ");
    scanf("%d", &insurance);
    printf("Additional Payment (/m): ");
    scanf("%d", &addPay);
    printf("--- Output ---\n");


    if(term!=10 && term!=15 && term!=20 && term!=30){
        printf("Invalid Loan Term.\n");
        return 1;
    }

    double r = (double)rate*0.01/12.0;
    double n = term*12;
    double additional = addPay + insurance + tax;

    double principal_interest = price * ((r*pow(1+r, n))/(pow(1+r, n) - 1));
    if(principal_interest-(principal_interest/1)>=0.5){
        principal_interest += 1;
    }
    int monthly = (int)principal_interest + additional;

    printf("Total Monthly Payment: %d\n", monthly);
    double remaining = price;
    for(int i=0; i<n; i++){
        if(month<12){
            month++;
            printf("%d.%02d) ", year, month);
        }
        else{
            month = 1;
            year++;
            printf("%d.%02d) ", year, month);
        }
        double principal = monthly - additional - (remaining*r);
        double interest = monthly - additional - principal;
        remaining -= principal;

        if(i==n-1){
            if(principal>=1000){
                printf("Principal = %d,%06.2lf, ", (int)(principal+remaining)/1000, principal+remaining - ((int)(principal+remaining)/1000*1000));
            }
            else{
                printf("Principal = %.2lf, ", principal);
            }
            if(interest>=1000){
                printf("Interest = %d,%06.2lf, ", (int)interest/1000, interest - ((int)interest/1000*1000));
            }
            else{
                printf("Interest = %.2lf, ", interest);
            }
            printf("Remaining = 0.00");
            printf("\n");
        }
        else{
            if(principal>=1000){
                printf("Principal = %d,%06.2lf, ", (int)principal/1000, principal - ((int)principal/1000*1000));
            }
            else{
                printf("Principal = %.2lf, ", principal);
            }
            if(interest>=1000){
                printf("Interest = %d,%06.2lf, ", (int)interest/1000, interest - ((int)interest/1000*1000));
            }
            else{
                printf("Interest = %.2lf, ", interest);
            }
            if(remaining>=1000){
                printf("Remaining = %d,%06.2lf", (int)remaining/1000, remaining - (int)remaining/1000*1000);
            }
            else{
                printf("Remaining = %.2lf", remaining);
            }
            //printf("Principal = %.2lf, Interest = %.2lf, Remaining = %.2lf", principal, interest, remaining);
            printf("\n");
        }
    }
    return 0;
}
