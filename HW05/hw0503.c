#define NUM_STATES 8
#define NUM_INPUTS 11

#include <stdio.h>

typedef enum{
    START,
    S1,
    S2,
    S3,
    S4,
    S5,
    S6,
    FINAL
} State;

typedef enum{
    INPUT_OTHERS,
    INPUT10_35,
    INPUT_11,
    INPUT_20_78,
    INPUT_19,
    INPUT_12_36,
    INPUT_1,
    INPUT_2,
    INPUT_43,
    INPUT_99,
    INPUT_108
} Input;

State fsm_table[NUM_STATES][NUM_INPUTS] = {
        {START, S1,    S3,    S5,    START, START, START, START, START, START, START},
        {S1,    S1,    S1,    S1,    S2,    S6,    S1,    S1,    S1,    S1,    S1},
        {START, START, START, START, START, START, START, START, S2,    FINAL, START},
        {S4,    S4,    S4,    S4,    S4,    S4,    S4,    S4,    S4,    S4,    S4},
        {S6,    S6,    S6,    S6,    S6,    S6,    S6,    S6,    S6,    S6,    S6},
        {START, START, START, START, START, START, S4,    S6,    START, START, START},
        {S5,    S5,    S5,    S5,    S5,    S5,    S5,    S5,    S5,    S5,    FINAL},
        {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL,}
};

State current_state = START;

const char* state_names[NUM_STATES] = {
        "Start",
        "S1",
        "S2",
        "S3",
        "S4",
        "S5",
        "S6",
        "Final"
};

void process_input(int input){
    Input input_type;
    if(input == 10 || input == 35){
        input_type = INPUT10_35;
    }
    else if(input == 11){
        input_type = INPUT_11;
    }
    else if(input == 19){
        input_type = INPUT_19;
    }
    else if(input==20 || input==78){
        input_type = INPUT_20_78;
    }
    else if(input==12 || input==36){
        input_type = INPUT_12_36;
    }
    else if(input==1){
        input_type = INPUT_1;
    }
    else if(input==2){
        input_type = INPUT_2;
    }
    else if(input==43){
        input_type = INPUT_43;
    }
    else if(input==99){
        input_type = INPUT_99;
    }
    else if(input==108){
        input_type = INPUT_108;
    }
    else{
        input_type = INPUT_OTHERS;
    }
    current_state = fsm_table[current_state][input_type];
}


int main(void){
    int input=0;

    while(1){

        printf("%s\n", state_names[current_state]);
        if(current_state==FINAL){
            break;
        }
        printf("Please enter an integer: ");
        scanf("%d", &input);
        process_input(input);
    }

    return 0;
}