#include <stdio.h>

int main(){
    //setup
    int c1, c2, c3, c4, c5, p1, p2, p3, p4, p5;
    printf("Please enter 5 cards: ");
    scanf("%d %d %d %d %d", &c1, &c2, &c3, &c4, &c5);

    //determine invalid input
    if(c1 > 52 || c2 > 52 || c3 > 52 || c4 > 52 || c5 > 52){
        printf("Invalid input! Exceeds the max card number");
        return 1;
    }
    if(c1 == c2 || c1 == c3 || c1 == c4 || c1 == c5){
        printf("Invalid input! Two or more identical cards entered");
        return 1;
    }
    else if(c2 == c3 || c2 == c4 || c2 == c5){
        printf("Invalid input! Two or more identical cards entered");
        return 1;
    }
    else if(c3 == c4 || c3 == c5){
        printf("Invalid input! Two or more identical cards entered");
        return 1;
    }
    else if(c4 == c5){
        printf("Invalid input! Two or more identical cards entered");
        return 1;
    }

    //check pattern and number
    if(c1 > 39){
        p1 = 1;
        c1 = c1 - 39;
    }
    else if(c1 > 26){
        p1 = 2;
        c1 = c1 - 26;
    }
    else if(c1 > 13){
        p1 = 3;
        c1 = c1 - 13;
    }
    else{
        p1 = 4;
    }

    if(c2 > 39){
        p2 = 1;
        c2 = c2 - 39;
    }
    else if(c2 > 26){
        p2 = 2;
        c2 = c2 - 26;
    }
    else if(c2 > 13){
        p2 = 3;
        c2 = c2 - 13;
    }
    else{
        p2 = 4;
    }

    if(c3 > 39){
        p3 = 1;
        c3 = c3 - 39;
    }
    else if(c3 > 26){
        p3 = 2;
        c3 = c3 - 26;
    }
    else if(c3 > 13){
        p3 = 3;
        c3 = c3 - 13;
    }
    else{
        p3 = 4;
    }

    if(c4 > 39){
        p4 = 1;
        c4 = c4 - 39;
    }
    else if(c4 > 26){
        p4 = 2;
        c4 = c4 - 26;
    }
    else if(c4 > 13){
        p4 = 3;
        c4 = c4 - 13;
    }
    else{
        p4 = 4;
    }

    if(c5 > 39){
        p5 = 1;
        c5 = c5 - 39;
    }
    else if(c5 > 26){
        p5 = 2;
        c5 = c5 - 26;
    }
    else if(c5 > 13){
        p5 = 3;
        c5 = c5 - 13;
    }
    else{
        p5 = 4;
    }

    //sorting algorithm
    if(c1 > c2){
        int temp = c1;
        c1 = c2;
        c2 = temp;

        temp = p1;
        p1 = p2;
        p2 = temp;

    }
    if(c3 > c4){
        int temp = c3;
        c3 = c4;
        c4 = temp;

        temp = p3;
        p3 = p4;
        p4 = temp;
    }
    if(c1 > c3){
        int temp = c1;
        c1 = c3;
        c3 = temp;

        temp = p1;
        p1 = p3;
        p3 = temp;
    }
    if(c2 > c4){
        int temp = c2;
        c2 = c4;
        c4 = temp;

        temp = p2;
        p2 = p4;
        p4 = temp;
    }
    if(c2 > c3){
        int temp = c2;
        c2 = c3;
        c3 = temp;

        temp = p2;
        p2 = p3;
        p3 = temp;
    }
    if(c5 <= c1){
        int temp = c5;
        c5 = c4;
        c4 = c3;
        c3 = c2;
        c2 = c1;
        c1 = temp;

        temp = p5;
        p5 = p4;
        p4 = p3;
        p3 = p2;
        p2 = p1;
        p1 = temp;
    }
    else if(c5 <= c2){
        int temp = c5;
        c5 = c4;
        c4 = c3;
        c3 = c2;
        c2 = temp;

        temp = p5;
        p5 = p4;
        p4 = p3;
        p3 = p2;
        p2 = temp;
    }
    else if(c5 <= c3){
        int temp = c5;
        c5 = c4;
        c4 = c3;
        c3 = temp;

        temp = p5;
        p5 = p4;
        p4 = p3;
        p3 = temp;
    }
    else if(c5 <= c4){
        int temp = c5;
        c5 = c4;
        c4 = temp;

        temp = p5;
        p5 = p4;
        p4 = temp;
    }
    else{
        c5 = c5;
    }

    //recognition
    if(p1 == p2 && p2 == p3 && p3 == p4 && p4 == p5){
        if(c1 + 1 == c2 && c2 + 1 == c3 && c3 + 1 == c4 && c4 + 1 == c5){
            printf("Straight flush");
        }
        else{
            printf("Flush");
        }
    }
    else{
        if(c1 + 1 == c2 && c2 + 1 == c3 && c3 + 1 == c4 && c4 + 1 == c5){
            printf("Straight");
        }
        else if(c1 == c2 && c2 == c3 && c3 == c4 || c2 == c3 && c3 == c4 && c4 == c5){
            printf("Four of a kind");
        }
        else if(c1 == c2 && c2 == c3){
            if(c4 == c5){
                printf("Full house");
            }
            else{
                printf("Three of a kind");
            }
        }
        else if(c3 == c4 && c4 == c5){
            if(c1 == c2){
                printf("Full house");
            }
            else{
                printf("Three of a kind");
            }
        }
        else if(c2 == c3 && c3 == c4){
            printf("Three of a kind");
        }
        else if(c1 == c2){
            if(c3 == c4 || c4 == c5){
                printf("Two pair");
            }
            else{
                printf("One pair");
            }
        }
        else if(c3 == c4){
            if(c1 == c2){
                printf("Two pair");
            }
            else{
                printf("One pair");
            }
        }
        else if(c4 == c5){
            if(c1 == c2 || c2 == c3){
                printf("Two pair");
            }
            else{
                printf("One pair");
            }
        }
        else{
            if(c1==1 && c2==10 && c3==11 && c4==12 && c5==13){
                if(p1==p2 && p2==p3 && p3==p4 && p4==p5){
                    printf("Straight flush");
                }
                else{
                    printf("Straight");
                }
            }
            else{
                printf("High card");
            }
        }
    }
    return 0;
}
