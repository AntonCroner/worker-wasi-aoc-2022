WASI_SDK_PATH = ../../../../../versioned/other/wasi-sdk/build/install/opt/wasi-sdk
CC = ${WASI_SDK_PATH}/bin/clang --sysroot=${WASI_SDK_PATH}/share/wasi-sysroot
LD = ${WASI_SDK_PATH}/bin/clang
CFLAGS = -std=c11
LDFLAGS = 
LIBS = 

OBJS = main.o
WASM = *.wasm

day_2: day_2a day_2b

day_2a: day_2a.c
	$(CC) $(CFLAGS) day_2a.c -o day_2a.wasm

day_2b: day_2b.c
	$(CC) $(CFLAGS) day_2b.c -o day_2b.wasm

clean:
	rm -f $(EXECUTABLE) $(OBJS) $(WASM) *~
