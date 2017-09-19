#include <iostream>
using namespace std;

int puzzle[6][8], press[6][8];

bool guess(){
    for(int r = 1; r <= 4; ++r){
        for(int c = 1; c <= 6; ++c){
            press[r + 1][c] = (puzzle[r][c]
                    + press[r][c] + press[r - 1][c] + press[r][c - 1] + press[r][c + 1]) % 2;
        }
    }
    for(int c = 1; c <= 6; ++c){
        if((press[5][c - 1] + press[5][c] + press[5][c + 1] + press[4][c]) % 2 != puzzle[5][c])
            return false;
    }
    return true;
}

int main(){
    int n, i;
    cin>>n;
    for(int r = 1; r <= 5; ++r){
        for(int c = 1; r <= 6; ++c){
            cin>>puzzle[r][c]<<endl;
        }
    }



    // Tranversal the row 1, from 000000 to 111111
    // When it can be the answer
    for(int c = 1; c <= 5; ++c){
        press[1][c] = 0;
    }
    while(1){

        if(guess()){
            break;
        }

        // Normal Form, from 000000-111111
        // 000000
        // 100000
        // 010000
        // 110000
        // 001000
        // 101000
        // 011000
        // 111000
        // ......
        press[1][1]++;
        int c = 1;
        while(press[1][c] > 1){
            press[1][c] = 0;
            c++;
            press[1][c]++;
        }
    }


}
