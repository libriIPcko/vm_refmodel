#include <stdio.h>
#include <stdint.h>

//Input signals
uint8_t i_clk;
uint8_t i_nrst;
uint8_t i_signal[3];
//Output signals
uint8_t o_ctl [3];
uint8_t o_signal;
//Internal signals
uint8_t ctl_mask[3];
uint8_t l_err;
uint8_t f_err;
uint8_t l_err_counter;
uint8_t f_err_counter;
uint8_t l_recovery_counter;
uint8_t f_recovery_counter;

//Definitions
#define L_ERROR_ASSERT_CYCLES
#define F_ERROR_ASSERT_CYCLES
#define L_RECOVERY_CYCLES
#define F_RECOVERY_CYCLES

uint8_t get_l_err();
uint8_t get_f_err();
uint8_t get_l_err_counter();
uint8_t get_f_err_counter();
uint8_t get_l_recovery_counter();
uint8_t get_f_recovery_counter();
uint8_t gen_o_signal();
uint8_t* evaluate_o_ctl();
int calc(int a, int b);

uint8_t get_l_err(){
	return l_err;
}
uint8_t get_f_err(){
	return f_err;
}
uint8_t get_l_err_counter(){
	return l_err;
}
uint8_t get_f_err_counter(){
	return f_err_counter;
}
uint8_t get_l_recovery_counter(){
	return l_recovery_counter;
}
uint8_t get_f_recovery_counter(){
	return f_err_counter;
}

uint8_t gen_o_signal(){
	o_signal =  (!o_ctl[2] & i_signal[2]) | (!o_ctl[1] & i_signal[1]) | (!o_ctl[0] & i_signal[0]);
}

uint8_t* evaluate_o_ctl(){
	
	return  o_ctl;	//Return a pointer to the first element of the array
}

int calc(int a, int b){
	return a-b;
}