/*
    Copyright (C) 2020 Lubomir Bogdanov
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
#include <stdio.h>
#include <stdint.h>
#include "fifo_multi.h"

int main(void) {
	uint8_t i, value;

	fifo_init();

	//Expected five 'e'
	printf("Pushing:\n");
	for(i = 0; i < 5; i++){
		if(fifo_push(0, i)){
			printf("f ");
			fflush(stdout);
		}
		else{
			printf("%d ", i);
			fflush(stdout);
		}
	}
	printf("\n");

	printf("Popping:\n");
	for(i = 0; i < 10; i++){
		if(fifo_pop(0, &value)){
			printf("e ");
			fflush(stdout);
		}
		else{
			printf("%d ", value);
			fflush(stdout);
		}
	}
	printf("\n");

	printf("==============================\n");

	//Expected 12 'f' and 12 'e'
	printf("Pushing:\n");
	for(i = 10; i < 30; i++){
		if(fifo_push(0, i)){
			printf("f ");
			fflush(stdout);
		}
		else{
			printf("%d ", i);
			fflush(stdout);
		}
	}
	printf("\n");

	printf("Popping:\n");
	for(i = 0; i < 20; i++){
		if(fifo_pop(0, &value)){
			printf("e ");
			fflush(stdout);
		}
		else{
			printf("%d ", value);
			fflush(stdout);
		}
	}
	printf("\n");

	printf("==============================\n");

	//Expected 22 'f' and 22 'e'
	printf("Pushing:\n");
	for(i = 50; i < 80; i++){
		if(fifo_push(0, i)){
			printf("f ");
			fflush(stdout);
		}
		else{
			printf("%d ", i);
			fflush(stdout);
		}
	}
	printf("\n");

	printf("Popping:\n");
	for(i = 0; i < 30; i++){
		if(fifo_pop(0, &value)){
			printf("e ");
			fflush(stdout);
		}
		else{
			printf("%d ", value);
			fflush(stdout);
		}
	}
	printf("\n");

	printf("==============================\n");
	//Expected one 'f'
	printf("Pushing:\n");
	for(i = 30; i < 34; i++){
		if(fifo_push(0, i)){
			printf("f ");
			fflush(stdout);
		}
		else{
			printf("%d ", i);
			fflush(stdout);
		}
	}
	printf("\n");

	printf("Popping:\n");
	for(i = 0; i < 2; i++){
		if(fifo_pop(0, &value)){
			printf("e ");
			fflush(stdout);
		}
		else{
			printf("%d ", value);
			fflush(stdout);
		}
	}
	printf("\n");

	printf("Pushing:\n");
	for(i = 40; i < 47; i++){
		if(fifo_push(0, i)){
			printf("f ");
			fflush(stdout);
		}
		else{
			printf("%d ", i);
			fflush(stdout);
		}
	}
	printf("\n");

	printf("==============================\n");
	if(fifo_peek(0)){
		printf("Fifo is empty!\n");
	}
	else{
		printf("Fifo has elements!\n");
	}

	printf("Popping:\n");
	for(i = 0; i < 10; i++){
		if(fifo_pop(0, &value)){
			printf("e ");
			fflush(stdout);
		}
		else{
			printf("%d ", value);
			fflush(stdout);
		}
	}
	printf("\n");

	if(fifo_peek(0)){
		printf("Fifo is empty!\n");
	}
	else{
		printf("Fifo has elements!\n");
	}



	return 0;
}
