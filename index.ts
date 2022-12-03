import { AoC } from "./aoc"
import { Base_html } from "./base_html"
import { Context } from "./Context"
import { Environment } from "./Environment"

import "./version"

export default {
	async fetch(request: Request, environment: Environment, ctx: ExecutionContext): Promise<Response> {
		const context = Context.open(environment)
		const url = request.url
		const day = parseInt(url.substring(url.length - 2))
		const x = url.substring(url.length - 1)
		let result: Response
		if (request.method == "POST")
			result = await AoC.day(day, x, request, context, ctx)
		else
			result = new Response(Base_html.get(day, x), { headers: { "Content-Type": "text/html" } })
		return result
	},
}
