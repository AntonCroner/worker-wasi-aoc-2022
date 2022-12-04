import { Context } from "../Context"
import { day_1 } from "./day_1/day_1"
import { day_2 } from "./day_2/day_2"
import { day_3 } from "./day_3/day_3"
import { day_4 } from "./day_4/day_4"

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
		else if (day == 2)
			result = await day_2(x, request, context, ctx)
		else if (day == 3)
			result = await day_3(x, request, context, ctx)
		else if (day == 4)
			result = await day_4(x, request, context, ctx)
		else
			result = new Response("Put /day_nx in the URL, where n∈{1, 2, 3..., 25}, and x∈{a, b}.")
		return result
	}
}
