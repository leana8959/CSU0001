#include <stdio.h>
#include <stdint.h>


int main(){
    int32_t choices = 0, credit = 0, grade = 0;
    int32_t total_credit = 0;
    int32_t total_grade = 0;
    int32_t remaining_credit = 0;
    double total_gpa = 0;
    double target_gpa = 0;
    double avg = 0;
    double gpa = 0;

    while(choices != 5){
        if(choices==0){
            printf("1) Input the course grade.\n"
                   "2) Remove the course grade.\n"
                   "3) GPA report.\n"
                   "4) Target GPA.\n"
                   "5) Exit.\n"
                   "Your Choice (1-5): ");
            scanf("%d", &choices);
        }
        else{
            if(choices == 1){
                int ok=0;
                while(ok!=1){
                    if(ok==0){
                        printf("Points (0-100): ");
                        scanf("%d", &grade);
                        printf("Credits (0-4): ");
                        scanf("%d", &credit);
                        if(grade>100 || grade<0 || credit>4 || credit<0){
                            ok=0;
                            printf("Invalid input\n");
                        }
                        else{
                            ok=1;
                        }
                    }
                }
                total_grade += grade;
                total_credit += credit;
                avg = (double)credit*grade/(double)credit;
                if(avg<50){
                    total_gpa += 0*credit;
                }
                else if(avg<60){
                    total_gpa += 1*credit;
                }
                else if(avg<63){
                    total_gpa += 1.7*credit;
                }
                else if(avg<67){
                    total_gpa += 2*credit;
                }
                else if(avg<70){
                    total_gpa += 2.3*credit;
                }
                else if(avg<73){
                    total_gpa += 2.7*credit;
                }
                else if(avg<77){
                    total_gpa += 3*credit;
                }
                else if(avg<80){
                    total_gpa += 3.3*credit;
                }
                else if(avg<85){
                    total_gpa += 3.7*credit;
                }
                else if(avg<90){
                    total_gpa += 4*credit;
                }
                else if(avg<=100){
                    total_gpa += 4.3*credit;
                }
            }
            else if(choices == 2){
                int ok=0;
                while(ok!=2){
                    if(ok==0){
                        printf("Points (0-100): ");
                        scanf("%d", &grade);
                        printf("Credits (0-4): ");
                        scanf("%d", &credit);
                        if(grade>100 || grade<0 || credit>4 || credit<0){
                            ok=0;
                            printf("Invalid input\n");
                        }
                        else{
                            ok=2;
                        }
                    }
                }
                total_credit -= credit;
                avg = (double)credit*grade/(double)credit;
                if(avg<50){
                    total_gpa -= 0*credit;
                }
                else if(avg<60){
                    total_gpa -= 1*credit;
                }
                else if(avg<63){
                    total_gpa -= 1.7*credit;
                }
                else if(avg<67){
                    total_gpa -= 2*credit;
                }
                else if(avg<70){
                    total_gpa -= 2.3*credit;
                }
                else if(avg<73){
                    total_gpa -= 2.7*credit;
                }
                else if(avg<77){
                    total_gpa -= 3*credit;
                }
                else if(avg<80){
                    total_gpa -= 3.3*credit;
                }
                else if(avg<85){
                    total_gpa -= 3.7*credit;
                }
                else if(avg<90){
                    total_gpa -= 4*credit;
                }
                else if(avg<=100){
                    total_gpa -= 4.3*credit;
                }
            }
            else if(choices == 3){
                printf("Total Credits: %d\n", total_credit);
                gpa = (double)total_gpa/(double)total_credit;
                printf("GPA: %.2lf\n", gpa);
            }
            else if(choices == 4){
                int ok = 0;
                while(ok!=1){
                    printf("Target GPA: ");
                    scanf("%lf", &target_gpa);
                    printf("Remaining Credits: ");
                    scanf("%d", &remaining_credit);
                    if(target_gpa>4.3 || target_gpa<0 || remaining_credit<0){
                        printf("Invalid input\n");
                        ok = 0;
                    }
                    else{
                        ok = 1;
                    }
                }
                double target_grade = (target_gpa*(total_credit+remaining_credit)-(gpa*total_credit))/remaining_credit;
                if(target_grade<1){
                    printf("You should get at least D on average for the remaining credits");
                }
                else if(target_grade<1.7){
                    printf("You should get at least C- on average for the remaining credits");
                }
                else if(target_grade<2){
                    printf("You should get at least C on average for the remaining credits");
                }
                else if(target_grade<2.3){
                    printf("You should get at least C+ on average for the remaining credits");
                }
                else if(target_grade<2.7){
                    printf("You should get at least B- on average for the remaining credits");
                }
                else if(target_grade<3.0){
                    printf("You should get at least B on average for the remaining credits");
                }
                else if(target_grade<3.3){
                    printf("You should get at least B+ on average for the remaining credits");
                }
                else if(target_grade<3.7){
                    printf("You should get at least A- on average for the remaining credits");
                }
                else if(target_grade<4.0){
                    printf("You should get at least A on average for the remaining credits");
                }
                else if(target_grade<=4.3){
                    printf("You should get at least A+ on average for the remaining credits");
                }
                printf("\n");
            }
            else if(choices == 5){
                return 0;
            }
            else{
                printf("Invalid Choice! Please enter numbers between 1-5.\n");
            }

            printf("\n"
                   "1) Add the course grade.\n"
                   "2) Remove the course grade.\n"
                   "3) GPA report.\n"
                   "4) Target GPA.\n"
                   "5) Exit.\n"
                   "Your Choice (1-5): ");
            scanf("%d", &choices);
        }
    }
}
