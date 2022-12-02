#include "mine.h"

int find_good_cells(const int32_t board[16][30], int32_t row[480], int32_t col[480]){

    int32_t count = 0;

    for(int i=0; i<480; i++){
        row[i] = -1;
        col[i] = -1;
    }

    for(int i=0; i<16; i++){
        for(int j=0; j<30; j++){
            if(i!=0 && i!=15){
                if(j!=0 && j!=29){
                    if(board[i][j]==0){
                        if(board[i + 1][j] == 0 && board[i - 1][j] == 0 && board[i][j + 1] == 0 && board[i][j - 1] == 0 &&
                           board[i + 1][j + 1] == 0 && board[i + 1][j - 1] == 0 && board[i - 1][j - 1] == 0 && board[i - 1][j + 1] == 0){
                            row[count] = i;
                            col[count] = j;
                        }
                    }
                }
            }
            count++;
        }
    }
    return 0;
}