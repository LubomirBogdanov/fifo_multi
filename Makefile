#    Copyright (C) 2020 Lubomir Bogdanov
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

PROJECT			= main
#Add additional files here. The ${PROJECT}.c should be at the end.
SRC			= fifo_multi.c main.c   

INDIR			= src
OUTDIR			= gcc
OBJ			= ${SRC:%.c=${OUTDIR}/%.o}

CPU			= cortex-m0
INSTRSET		= thumb
CC              	= gcc
LD			= ld
OBJCOPY			= objcopy
OBJDUMP			= objdump
SIZE			= size
PREPROCESSOR		= 
IPATH			= 
OPTFLAGS		= -O0 -fno-common -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"${@:${OUTDIR}/%.o=${OUTDIR}/%.d}" -MT"${@:${OUTDIR}/%.o=${OUTDIR}/%.o}" -MT"${@:${OUTDIR}/%.o=${OUTDIR}/%.d}"
DEBUGFLAGS		= -g3
CFLAGS          	= ${PREPROCESSOR} -I${IPATH} ${OPTFLAGS} ${DEBUGFLAGS}
LINKER_FILE		= 
LDFLAGS			= -Xlinker --gc-sections -Xlinker -print-memory-usage
OBJDUMPFLAGS		= -D -S
SIZEFLAGS		= -d
 

.PHONY: ${OUTDIR}/${PROJECT} ${OBJ}
all: ${OUTDIR} ${OUTDIR}/${PROJECT} size

${OUTDIR}:
	@mkdir -p ${OUTDIR}
	
${OUTDIR}/${PROJECT}: ${OBJ}
	@echo 'Building target: $@'
	@echo 'Invoking: Linker'
	${CC} ${LDFLAGS} -o "${OUTDIR}/${PROJECT}" ${SRC:%.c=${OUTDIR}/%.o} 
	@echo ' '

${OBJ}: ${SRC:${INDIR}/%.c}
	@echo 'Building file: $@'
	@echo 'Invoking: C Compiler'
	${CC} ${CFLAGS} -o ${@} ${@:${OUTDIR}/%.o=${INDIR}/%.c}
	@echo ' '
	
${OUTDIR}/${PROJECT}.lst: 
	${OBJDUMP} ${OBJDUMPFLAGS} ${OUTDIR}/${PROJECT}_${MCU_INDEX}.axf > ${OUTDIR}/${PROJECT}.lst

size:
	${SIZE} ${SIZEFLAGS} ${OUTDIR}/${PROJECT}

clean:
	@echo 'Removing directory: ${OUTDIR}'
	rm -r ${OUTDIR} 
	@echo ' '
