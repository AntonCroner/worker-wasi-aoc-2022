import { day_1 } from "./aoc/day_1/day_1"
import { Context } from "./Context"
import { Environment } from "./Environment"

import "./item"
import "./aoc"
import "./version"

export default {
	async fetch(request: Request, environment: Environment, ctx: ExecutionContext): Promise<Response> {
		const context = Context.open(environment)
		const url = request.url
		const day = url.substring(url.length)
		console.log(day)
		const result = await day_1(request, context, ctx)
		return result
	},
}
