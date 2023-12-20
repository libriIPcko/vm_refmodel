#ifndef REFMODEL_H
#define REFMODEL_H

#include <stdint.h>
#include <stdbool.h>

//Input signals
uint8_t i_clk;
uint8_t i_nrst;
uint8_t i_signal[3];
//Output signals
uint8_t o_ctl [3];
uint8_t o_signal;
//Internal signals
uint8_t ctl_mask[3];
//type_err values:
//0 - without err; 
//1 - l_err; 
//2 - f_err
//3 - reset
uint8_t type_err[3];	
uint8_t l_err;
uint8_t f_err;
uint8_t l_err_counter;
uint8_t f_err_counter;
uint8_t l_recovery_counter;
uint8_t f_recovery_counter;

//Definitions
bool L_ERROR_ASSERT_CYCLES;
bool F_ERROR_ASSERT_CYCLES;
bool L_RECOVERY_CYCLES;
bool F_RECOVERY_CYCLES;

uint8_t get_l_err();
uint8_t get_f_err();
uint8_t get_l_err_counter();
uint8_t get_f_err_counter();
uint8_t get_l_recovery_counter();
uint8_t get_f_recovery_counter();
uint8_t gen_o_signal();
uint8_t* evaluate_o_ctl(uint8_t i_nrst,uint8_t i_signal[3]);


#endif //REFMODEL.H