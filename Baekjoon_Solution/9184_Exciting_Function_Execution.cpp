#include <iostream>
using namespace std;

int inputA, inputB, inputC;
int table[21][21][21];

int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0){
        return 1;
    }
    else if(a > 20 || b > 20 || c > 20){
        return w(20, 20, 20);
    }
    else if(table[a][b][c]){
        return table[a][b][c];
    }
    else if(a < b && b < c){
        return table[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    }
    else{
        return table[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
}

int main(){
    while(true){
        scanf("%d %d %d", &inputA, &inputB, &inputC);
        if(inputA == -1 && inputB == -1 && inputC == -1)
            break;
        printf("w(%d, %d, %d) = %d\n", inputA, inputB, inputC, w(inputA, inputB, inputC));
    }
}

/* 
///////////////// bottom-up 8ms /////////////////

#include <iostream>
using namespace std;

int inputA, inputB, inputC;
int table[21][21][21];

int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0){
        return 1;
    }
    else if(a > 20 || b > 20 || c > 20){
        return w(20, 20, 20);
    }
    else if(table[a][b][c]){
        return table[a][b][c];
    }
    else if(a < b && b < c){
        return w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    }
    else{
        return w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
}

int main(){
    for(int countA = 0; countA <= 20; countA++){
        for(int countB = 0; countB <= 20; countB++){
            for(int countC = 0; countC <= 20; countC++){
                table[countA][countB][countC] = w(countA, countB, countC);
            }
        }
    }

    while(true){
        scanf("%d %d %d", &inputA, &inputB, &inputC);
        if(inputA == -1 && inputB == -1 && inputC == -1)
            break;
        printf("w(%d, %d, %d) = %d\n", inputA, inputB, inputC, w(inputA, inputB, inputC));
    }
}
*/