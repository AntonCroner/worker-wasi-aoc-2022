WASI_SDK_PATH = ../../../../../versioned/other/wasi-sdk/build/install/opt/wasi-sdk
CC = ${WASI_SDK_PATH}/bin/clang --sysroot=${WASI_SDK_PATH}/share/wasi-sysroot
LD = ${WASI_SDK_PATH}/bin/clang
CFLAGS = -std=c11
LDFLAGS = 
LIBS = 

OBJS = main.o
WASM = *.wasm


day_1a: day_1a.c
	$(CC) $(CFLAGS) day_1a.c -o day_1a.wasm

day_1b: day_1b.c
	$(CC) $(CFLAGS) day_1b.c -o day_1b.wasm

clean:
	rm -f $(EXECUTABLE) $(OBJS) $(WASM) *~
