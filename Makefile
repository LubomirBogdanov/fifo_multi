#    Copyright (C) 2022 Lubomir Bogdanov
#    Contributor Lubomir Bogdanov <lbogdanov@tu-sofia.bg>
#    This file is part of fifo_multi.
#    fifo_multi is free software: you can redistribute it and/or modify
#    it under the terms of the GNU Lesser General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#    fifo_multi is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU Lesser General Public License for more details.
#    You should have received a copy of the GNU Lesser General Public License
#    along with fifo_multi.  If not, see <http://www.gnu.org/licenses/>.

OUTDIR	= debug
SRCDIR	= src
BINNAME	= main
INC		= ${wildcard ${SRCDIR}/*.h}
SRC		= ${wildcard ${SRCDIR}/*.c} 
CC		= gcc
SIZE	= size
CLAGS	= -Wall -Werror -O0 -g3 -I.

all: ${OUTDIR} ${OUTDIR}/${BINNAME} bin_size

${OUTDIR}:
	mkdir -p ${OUTDIR}
	
${OUTDIR}/${BINNAME}: ${SRC} ${INC}
	${CC} ${CFLAGS} ${SRC} -o ${OUTDIR}/${BINNAME}

bin_size:
	${SIZE} ${OUTDIR}/${BINNAME}
	
run:
	./${OUTDIR}/${BINNAME}

clean:
	@echo 'Removing directory: ${OUTDIR}'
	rm -r ${OUTDIR} 
