#include "functions.h" 
/* Write your implementations of the functions in this source file.
 * Skeleton versions of the functions already appear below. 
 */ 
int area_of_rectangle(int x1, int y1, int x2, int y2){
    int area = 0;
    if ( x1<x2){
        if (y1<y2){
            area =(x2-x1)*(y2-y1);
        }
        else{
            area =(x2-x1)*(y1-y2);
        }
    }else{
        if (y1 < y2){
            area =(x1-x2)*(y2-y1);
        }
        else{
            area =(x1-x2)*(y1-y2);
        }
    }
        return area;
}

int smallest_prime_between(int x, int y){
    int i, j, a;
    if (x>y || (x<0 && y<0)||(y<2)){
        return -1;
    }
    if (x%2 == 0){
        x++;
    }
    for (i = x; i <= y; i = i + 2){
        a = 0;
        for(j = 2; j <= i / 2; j++){
            if (i % j == 0){
                a = 1;
            }
        }
        if (a == 0){
            return i;
        }
    }

    return -1;
}

