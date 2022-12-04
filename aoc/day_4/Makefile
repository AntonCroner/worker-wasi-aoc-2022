WASI_SDK_PATH = ../../../../../versioned/other/wasi-sdk/build/install/opt/wasi-sdk
CC = ${WASI_SDK_PATH}/bin/clang --sysroot=${WASI_SDK_PATH}/share/wasi-sysroot
LD = ${WASI_SDK_PATH}/bin/clang
CFLAGS = -std=c11
LDFLAGS = 
LIBS = 

OBJS = main.o
WASM = *.wasm

day_4: day_4a day_4b

day_4a: day_4a.c
	$(CC) $(CFLAGS) day_4a.c -o day_4a.wasm

day_4b: day_4b.c
	$(CC) $(CFLAGS) day_4b.c -o day_4b.wasm

clean:
	rm -f $(EXECUTABLE) $(OBJS) $(WASM) *~
