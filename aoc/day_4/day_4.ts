import { WASI } from "@cloudflare/workers-wasi"
import { Context } from "../../Context"
import day_4a_wasm from "./day_4a.wasm"
import day_4b_wasm from "./day_4b.wasm"

export async function day_4(x: string, request: Request, context: Context, ctx: ExecutionContext): Promise<Response> {
	const stdout = new TransformStream()
	const wasi = new WASI({
		args: [],
		stdin: request.body ? request.body : undefined,
		stdout: stdout.writable,
	})
	let instance: WebAssembly.Instance
	if (x == "a") {
		instance = new WebAssembly.Instance(day_4a_wasm, {
			wasi_snapshot_preview1: wasi.wasiImport,
		})
	} else {
		instance = new WebAssembly.Instance(day_4b_wasm, {
			wasi_snapshot_preview1: wasi.wasiImport,
		})
	}
	ctx.waitUntil(wasi.start(instance))
	return new Response(stdout.readable)
}
