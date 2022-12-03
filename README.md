# WASI Worker for Advent of Code 2022
Solves Advent of Code 2022 using Wasm written in C, running on Cloudflare Workers WASI.

## Usage
Visit the URL of the day you want to solve. Paste the input in the box. Click button.

## How to make it go
1. Install WASI-SDK (https://github.com/WebAssembly/wasi-sdk, I did the full build)
2. Clone repo
3. Edit makefiles to target your wasi-sdk directory
4. type "npm install"
5. type "npx wrangler dev -l" to test locally
