WASI_SDK_PATH = ../../../../../versioned/other/wasi-sdk/build/install/opt/wasi-sdk
CC = ${WASI_SDK_PATH}/bin/clang --sysroot=${WASI_SDK_PATH}/share/wasi-sysroot
LD = ${WASI_SDK_PATH}/bin/clang
CFLAGS = 
LDFLAGS = 
LIBS = 

OBJS = main.o
WASM = *.wasm


day_1: day_1.c
	$(CC) $(CFLAGS) day_1.c -o day_1.wasm

clean:
	rm -f $(EXECUTABLE) $(OBJS) $(WASM) *~
