/*
    Copyright (C) 2022 Lubomir Bogdanov
    Contributor Lubomir Bogdanov <lbogdanov@tu-sofia.bg>
    This file is part of fifo_multi.
    fifo_multi is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    fifo_multi is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.
    You should have received a copy of the GNU Lesser General Public License
    along with fifo_multi.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * fifo_multi.c
 *
 *  Created on: Jun 18, 2020
 *      Author: lbogdanov
 */
#include "fifo_multi.h"

/*!
 * \struct fifo_buff_t
 *
 * \brief A structure describing
 * a FIFO buffer.
 *
 */
typedef struct {
	int8_t head_index;
	int8_t tail_index;
	uint8_t data[FIFO_SIZE];
}fifo_buff_t;

/*!
 * \var fifo_bf
 *
 * \brief A static array of FIFOs.
 * Change the number of FIFOs by modifying the
 * FIFO_NUMBERS macro according to your application
 * needs.
 */
fifo_buff_t fifo_bf[FIFO_NUMBERS];

/*!
 * \brief Initialize the FIFOs. No dynamic
 * allocation of memory is used to make it more
 * embedded system-friendly.
 *
 * \return None.
 */
void fifo_init(void){
	uint8_t i, j;

	for(i = 0; i < FIFO_NUMBERS; i++){	
		fifo_bf[i].head_index = FIFO_SIZE-1;
		fifo_bf[i].tail_index = fifo_bf[i].head_index;
		
		for(j = 0; j < FIFO_SIZE; j++){
			fifo_bf[i].data[j] = 0x00;
		}
	}	
}

/*!
 * \brief A function for pushing elements in a FIFO.
 *
 * \param fifo_number - a digit between 0 and FIFO_NUMBERS that 
 * denotes the FIFO channel currently being used.
 *
 * \param element - an 8-bit value to be pushed in the FIFO. 
 *
 * \return 0 - element pushed successfully, 1 - FIFO is full
 * and element was not pushed.
 */
uint8_t fifo_push(uint8_t fifo_number, uint8_t element){
	if(fifo_bf[fifo_number].tail_index < 0){
		return 1;
	}

	fifo_bf[fifo_number].data[fifo_bf[fifo_number].tail_index--] = element;

	return 0;
}

/*!
 * \brief A function for poping elements from a FIFO.
 *
 * \param fifo_number - a digit between 0 and FIFO_NUMBERS that 
 * denotes the FIFO channel currently being used.
 *
 * \param element - an 8-bit value that is popped from the FIFO. 
 *
 * \return 0 - element popped successfully, 1 - FIFO is
 * empty and element remains unchanged.
 */
uint8_t fifo_pop(uint8_t fifo_number, uint8_t *element){
	int i;

	if(fifo_bf[fifo_number].tail_index == fifo_bf[fifo_number].head_index){
		return 1;
	}

	*element = fifo_bf[fifo_number].data[fifo_bf[fifo_number].head_index];

	for(i = FIFO_SIZE-1; i > 0 ; i--){
		fifo_bf[fifo_number].data[i] = fifo_bf[fifo_number].data[i-1];
	}

	fifo_bf[fifo_number].tail_index++;

	return 0;
}

/*!
 * \brief A function for checking whether there are any elements
 * left before popping them. The FIFO remains unchanged by this
 * function.
 *
 * \param fifo_number - a digit between 0 and FIFO_NUMBERS that 
 * denotes the FIFO channel currently being used.
 * \param top_element - a pointer to an 8-bit variable that will
 * hold the top element of the FIFO, if it exists. If the FIFO
 * is empty, top_element remains unchanged.
 *
 * \return 0 - FIFO has elements, 1 - FIFO is empty.
 */
uint8_t fifo_peek(uint8_t fifo_number, uint8_t *top_element){
	if(fifo_bf[fifo_number].tail_index != fifo_bf[fifo_number].head_index){
		*top_element = fifo_bf[fifo_number].data[fifo_bf[fifo_number].head_index];
		return 0;
	}

	return 1;
}

/*!
 * \brief A function for checking whether there are any
 * elements left in the FIFO.
 *
 *\param fifo_number - a digit between 0 and FIFO_NUMBERS that
 * denotes the FIFO channel currently being used.
 *
 * \return 0 - buffer has elements, 1 - FIFO buffer is empty.
 */
uint8_t fifo_is_empty(uint8_t fifo_number){
	if(fifo_bf[fifo_number].tail_index != fifo_bf[fifo_number].head_index){
		return 0;
	}

	return 1;
}
