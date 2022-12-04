WASI_SDK_PATH = ../../../../../versioned/other/wasi-sdk/build/install/opt/wasi-sdk
CC = ${WASI_SDK_PATH}/bin/clang --sysroot=${WASI_SDK_PATH}/share/wasi-sysroot
LD = ${WASI_SDK_PATH}/bin/clang
CFLAGS = -std=c11
LDFLAGS = 
LIBS = 

OBJS = main.o
WASM = *.wasm

day_3: day_3a day_3b

day_3a: day_3a.c
	$(CC) $(CFLAGS) day_3a.c -o day_3a.wasm

day_3b: day_3b.c
	$(CC) $(CFLAGS) day_3b.c -o day_3b.wasm

clean:
	rm -f $(EXECUTABLE) $(OBJS) $(WASM) *~
