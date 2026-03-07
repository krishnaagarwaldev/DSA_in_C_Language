#include<stdio.h>
int main(){
    
    int gain[4][4] = {
    {25,5,12,11},
    {20,12,10,4},
    {10,4,9,2},
    {8,8,7,1}
    };
    
    int hours_used[4] = {0,0,0,0};
    int total_gain = 0;
    int total_hours = 4;
    
    for (int h=0; h<4 ; h++){
        int max_gain = -1;
        int best_course = -1;   
        
        for (int c=0; c<4; c++){
            if (hours_used[c] < 4){
                int current_gain = gain[hours_used[c]][c];
                
                if (current_gain > max_gain){
                    max_gain = current_gain;
                    best_course = c;
                }
            }
        }
        
        hours_used[best_course]++;
        total_gain += max_gain;
    }
    
    int base_marks = 20+40+40+80;
    int max_marks = base_marks + total_gain;
    printf("Max marks = %d\n", max_marks);
    return 0;
}