#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "refModel.h"


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


uint8_t* evaluate_o_ctl(uint8_t i_nrst,uint8_t i_signal[3]){
	if(i_nrst == 1){
		//Check match of signal_0
	if(i_signal[0] == i_signal[1] && i_signal[0] == i_signal[2]){
		o_ctl[0] = 0;
		type_err[0] = 0;
	}
	else{
		if(i_signal[0] != i_signal[1]){
			l_err = true;
			type_err[0] = 1;
		}
		if(i_signal[0] != i_signal[2]){
			if(l_err == false){
				l_err = true;
				type_err[0] = 1;
			}
			else{
				l_err = false;
				f_err = true;
				type_err[0] = 2;
			}
		}
		type_err[0] = 1;
		o_ctl[0] = 1;
	}
	//Check match of signal_1
	if(i_signal[1] == i_signal[0] && i_signal[1] == i_signal[2]){
		o_ctl[1] = 0;
		type_err[0] = 0;
	}
	else{
		if(i_signal[1] != i_signal[0]){
			l_err = true;
			type_err[1] = 1;
		}
		if(i_signal[1] != i_signal[2]){
			if(l_err == false){
				l_err = true;
				type_err[1] = 1;
			}
			else{
				l_err = false;
				f_err = true;
				type_err[1] = 2;
			}
		}
		type_err[1] = 0;
		o_ctl[1] = 1;
	}
	//Check match of signal_2
	if(i_signal[2] == i_signal[0] && i_signal[2] == i_signal[1]){
		o_ctl[2] = 0;
		type_err[0] = 0;
	}
	else{
		if(i_signal[2] != i_signal[0]){
			l_err = true;
			type_err[2] = 1;
		}
		if(i_signal[2] != i_signal[1]){
			if(l_err == false){
				l_err = true;
				type_err[2] = 1;
			}
			else{
				l_err = false;
				f_err = true;
				type_err[2] = 2;
			}
		}
		type_err[2] = 0;
		o_ctl[2] = 1;
	}

	return  o_ctl;	//Return a pointer to the first element of the array
	}
	//Reset case
	else{
		o_ctl[0] = 1;
		o_ctl[1] = 1;
		o_ctl[2] = 1;

		type_err[2] = 3;
		type_err[2] = 3;
		type_err[2] = 3;
	}
}
