#include <stdio.h>

void palindrome(int x, int y, int z){
    if(x/10==z%10){
        if(x%10==(z/10)%10){
            if(y/10==(z/100)%10){
                if(y%10==z/1000){
                    printf("%02d-%02d-%04d\n", x,y,z);
                }
            }
        }
    }
}

int main(){
    int32_t sDay, sMonth, sYear;
    printf("Start Date: ");
    scanf("%d-%d-%d", &sMonth, &sDay, &sYear);
    int32_t eDay, eMonth, eYear;
    printf("End Date: ");
    scanf("%d-%d-%d", &eMonth, &eDay, &eYear);

    if(sDay > 31 || sDay < 1 || eDay > 31 || eDay < 1){
        printf("Invalid number.");
        return 1;
    }
    if(sMonth < 1 || eMonth < 1 || eMonth > 12 || sMonth > 12){
        printf("Invalid number.");
        return 1;
    }


    for(int year = sYear; year <= eYear; year++){
        if(year < eYear){
            for(int month = sMonth; month <= 12; month++){
                if(year == sYear && month == sMonth){
                    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 ||
                       month == 12){
                        for(int day = sDay; day <= 31; day++){
                            palindrome(month, day, year);
                        }
                    }
                    else if(month == 4 || month == 6 || month == 9 || month == 11){
                        for(int day = sDay; day <= 30; day++){
                            palindrome(month, day, year);
                        }
                    }
                    else{
                        if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
                            for(int day = sDay; day <= 29; day++){
                                palindrome(month, day, year);
                            }
                        }
                        else{
                            for(int day = 1; day <= 28; day++){
                                palindrome(month, day, year);
                            }
                        }
                    }
                }
                else{
                    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 ||
                       month == 12){
                        for(int day = 1; day <= 31; day++){
                            palindrome(month, day, year);
                        }
                    }
                    else if(month == 4 || month == 6 || month == 9 || month == 11){
                        for(int day = 1; day <= 30; day++){
                            palindrome(month, day, year);
                        }
                    }
                    else{
                        if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
                            for(int day = 1; day <= 29; day++){
                                palindrome(month, day, year);
                            }
                        }
                        else{
                            for(int day = 1; day <= 28; day++){
                                palindrome(month, day, year);
                            }
                        }
                    }
                }
            }
        }
        else if(year == eYear){
            for(int month = 1; month <= eMonth; month++){
                if(month == eMonth){
                    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 ||
                       month == 12){
                        for(int day = 1; day <= eDay; day++){
                            palindrome(month, day, year);
                        }
                    }
                    else if(month == 4 || month == 6 || month == 9 || month == 11){
                        for(int day = 1; day <= eDay; day++){
                            palindrome(month, day, year);
                        }
                    }
                    else{
                        if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
                            for(int day = 1; day <= eDay; day++){
                                palindrome(month, day, year);
                            }
                        }
                        else{
                            for(int day = 1; day <= 28; day++){
                                palindrome(month, day, year);
                            }
                        }
                    }
                }
                else{
                    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 ||
                       month == 12){
                        for(int day = 1; day <= 31; day++){
                            palindrome(month, day, year);
                        }
                    }
                    else if(month == 4 || month == 6 || month == 9 || month == 11){
                        for(int day = 1; day <= 30; day++){
                            palindrome(month, day, year);
                        }
                    }
                    else{
                        if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
                            for(int day = 1; day <= 29; day++){
                                palindrome(month, day, year);
                            }
                        }
                        else{
                            for(int day = 1; day <= 28; day++){
                                palindrome(month, day, year);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
