import { WASI } from "@cloudflare/workers-wasi"
import { Context } from "../../Context"
import day_1_wasm from "./day_1.wasm"

export async function day_1(request: Request, context: Context, ctx: ExecutionContext): Promise<Response> {
	console.log("test 1")

	const stdout = new TransformStream()
	console.log("test 2")

	const wasi = new WASI({
		args: [],
		stdin: request.body ? request.body : undefined,
		stdout: stdout.writable,
	})
	console.log("test 3")
	const instance = new WebAssembly.Instance(day_1_wasm, {
		wasi_snapshot_preview1: wasi.wasiImport,
	})
	console.log("test 4")
	ctx.waitUntil(wasi.start(instance))
	console.log("test 5")
	return new Response(stdout.readable)
}
