import { WASI } from "@cloudflare/workers-wasi"
import { Context } from "../../Context"
import day_2a_wasm from "./day_2a.wasm"
import day_2b_wasm from "./day_2b.wasm"

export async function day_2(x: string, request: Request, context: Context, ctx: ExecutionContext): Promise<Response> {
	const stdout = new TransformStream()
	const wasi = new WASI({
		args: [],
		stdin: request.body ? request.body : undefined,
		stdout: stdout.writable,
	})
	let instance: WebAssembly.Instance
	if (x == "a") {
		instance = new WebAssembly.Instance(day_2a_wasm, {
			wasi_snapshot_preview1: wasi.wasiImport,
		})
	} else {
		instance = new WebAssembly.Instance(day_2b_wasm, {
			wasi_snapshot_preview1: wasi.wasiImport,
		})
	}
	ctx.waitUntil(wasi.start(instance))
	return new Response(stdout.readable)
}
