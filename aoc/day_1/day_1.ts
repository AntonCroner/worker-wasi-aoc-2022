import { WASI } from "@cloudflare/workers-wasi"
import { Context } from "../../Context"
import day_1a_wasm from "./day_1a.wasm"
import day_1b_wasm from "./day_1b.wasm"

export async function day_1(x: string, request: Request, context: Context, ctx: ExecutionContext): Promise<Response> {
	const stdout = new TransformStream()
	const wasi = new WASI({
		args: [],
		stdin: request.body ? request.body : undefined,
		stdout: stdout.writable,
	})
	let instance: WebAssembly.Instance
	if (x == "a") {
		instance = new WebAssembly.Instance(day_1a_wasm, {
			wasi_snapshot_preview1: wasi.wasiImport,
		})
	} else {
		instance = new WebAssembly.Instance(day_1b_wasm, {
			wasi_snapshot_preview1: wasi.wasiImport,
		})
	}
	ctx.waitUntil(wasi.start(instance))
	return new Response(stdout.readable)
}
