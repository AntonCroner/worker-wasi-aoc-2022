import { Context } from "../Context"
import { day_1 } from "./day_1/day_1"

export namespace AoC {
	export async function day(
		day: number,
		x: string,
		request: Request,
		context: Context,
		ctx: ExecutionContext
	): Promise<Response> {
		let result: Response | undefined
		if (day == 1)
			result = await day_1(x, request, context, ctx)
		else
			result = new Response("Put /day_nx in the URL, where n∈{1, 2, 3..., 25}, and x∈{a, b}.")
		return result
	}
}
