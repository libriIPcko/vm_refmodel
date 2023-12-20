#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "refModel.h"

int endStep = 10;
uint8_t i_sg[3, endStep];

int main(int argc, char** argv){
    int step = 0;
    
    while(step <= endStep){
        //uint8_t* evaluate_o_ctl(uint8_t i_nrst,uint8_t i_signal[3]);
        uint8_t temp_i_sg[];
        for(int i=0;i<3;i++){
             temp_i_sg[i] = i_sg[i,step]
        }
        evaluate_o_ctl(1,temp_i_sg);
        step++;
    }

    return 0;
}

bool compare(uint8_t inputArr[]){
    //Load reference data
    //Take inputArr argument
    //In cycle compare booth
    

}

