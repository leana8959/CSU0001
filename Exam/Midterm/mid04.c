#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
    double tort_speed = 0.3;
    double hare_speed, nap_prob;
    double tort_dist = 0, hare_dist = 0;
    int winning = 0, turn = 0;
    printf("The Hare Speed (m/turn): ");
    scanf("%lf", &hare_speed);
    printf("The Nap Probability (0-1): ");
    scanf("%lf", &nap_prob);

    while(winning != 1){
        tort_dist += tort_speed;
        if(tort_dist<=12.3){
            printf("Turn %d) Tortoise: %.6lf, ", turn, tort_dist);
        }
        else{
            printf("Turn %d) Tortoise: %.6lf (Winner), ", turn, tort_dist);
            winning = 1;
        }
        double nap = rand() / (double) RAND_MAX;
        if(nap >= nap_prob){
            hare_dist += hare_speed;
            if(hare_dist<=12.3){
                printf("Hare = %.6lf\n", hare_dist);
            }
            else{
                printf("Hare = %.6lf (Winner)\n", hare_dist);
                winning = 1;
            }
        }
        else{
            hare_dist += 0;
            printf("Hare = %.6lf (NAP)\n", hare_dist);
        }
        turn++;
    }
    return 0;
}
