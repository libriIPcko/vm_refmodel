#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "refModel.h"
#include <time.h>


char* path_i_nrst = "Q:/plsicik/Projekty/vm_refModel/ref_signals/i_nrst.hex";
char* path_i_sg0  = "Q:/plsicik/Projekty/vm_refModel/ref_signals/i_signal0.hex";
char* path_i_sg1  = "Q:/plsicik/Projekty/vm_refModel/ref_signals/i_signal1.hex";
char* path_i_sg2  = "Q:/plsicik/Projekty/vm_refModel/ref_signals/i_signal2.hex";

char* path_o_ctl0 = "Q:/plsicik/Projekty/vm_refModel/ref_signals/o_ctl0.hex";
char* path_o_ctl1 = "Q:/plsicik/Projekty/vm_refModel/ref_signals/o_ctl1.hex";
char* path_o_ctl2 = "Q:/plsicik/Projekty/vm_refModel/ref_signals/o_ctl2.hex";
char* path_o_sg   = "Q:/plsicik/Projekty/vm_refModel/ref_signals/o_signal.hex";

int endStep = 10;
//uint8_t i_sg[3, endStep];

bool compare(uint8_t i_sg[], uint8_t o_);
char* readHex(char* path);


int main(int argc, char** argv){
    int step = 0;
/*    
    while(step <= endStep){
        //uint8_t* evaluate_o_ctl(uint8_t i_nrst,uint8_t i_signal[3]);
        uint8_t temp_i_sg[];
        for(int i=0;i<3;i++){
             temp_i_sg[i] = i_sg[i,step]
        }
        evaluate_o_ctl(1,temp_i_sg);
        step++;
    }
*/    
    
    char* result = readHex(path_i_sg0);
    printf("%c\n", result[0]);
    printf("test");
    printf("\n%d\n", result[1]);

    /*
    int i = 0 ;
    while(result[i] != '1' || result[i] != '0'){
        *result++;
        printf("%d ---> %c",i, result[i]);
        i++;
    }
    */

    free(result);
    return 0;
}

bool compare(uint8_t i_sg[], uint8_t o_){
    //Load reference data
    //Take inputArr argument
    //In cycle compare booth    

}

char* readHex(char* path) {
    FILE *hexFile;
    int hexDigit;

    // Open the file
    hexFile = fopen(path, "r");

    // Check if the file was opened successfully
    if (hexFile == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Initialize variables for dynamic memory allocation
    size_t arraySize = 10; // Initial size, you can adjust it as needed
    char* hexArray = (char*)malloc(arraySize * sizeof(char));
    size_t currentIndex = 0;

    while ((hexDigit = fgetc(hexFile)) != 'x') {
        if(hexDigit == '1' || hexDigit == '0'){
            hexArray[currentIndex] = hexDigit;
            currentIndex++;
            //printf("%d", currentIndex);
            // Check if the array needs to be resized
            if (currentIndex == arraySize) {
                arraySize *= 2; // Double the size, you can adjust this strategy
                hexArray = (char*)realloc(hexArray, arraySize * sizeof(char));
                if (hexArray == NULL) {
                    perror("Error reallocating memory");
                    exit(EXIT_FAILURE);
                }
            }
        }
        else{
            //Nothing to do...
        }      
    }    
    //hexArray[currentIndex] = '\n';
    //hexArray[currentIndex] = currentIndex-2;
    // Close the file
    fclose(hexFile);
    return hexArray;
}



