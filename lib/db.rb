#!/usr/bin/env ruby

require 'net/http'
require 'json'

# TODO don't keep these as globals
fen	= "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
moves = "e2e4"

def database(fen, moves)
<<-DOC
`database` is just a simple request to the lichess database
	to pull a list of moves played from various games as a json body.
	DOC

	uri = URI("https://explorer.lichess.ovh/lichess?variant=standard&speeds[]" +
				"=bullet&speeds[]=blitz&speeds[]=rapid&speeds[]=classical&ratings[]" +
				"=1600&ratings[]=1800&ratings[]=2000&ratings[]=2200&ratings[]=2500&moves=50" +
				"&play=" + moves + 
				"&fen=" + fen.gsub(" ", "%20"))
	 
	Net::HTTP.get(uri)
	res = Net::HTTP.get_response(uri)

	# puts res.code, res.class.name
	# puts res.body

	response = res.body

	# Net::HTTP.start("localhost", 1234) do |http|
	#	request = Net::HTTP::Get.new uri
	#	respone = http.request request
	# end

	return response
end

def parse(fen, moves)
<<-DOC
	`parse` takes the json body from `database` and returns the moves
	for white, black & moves that result in draws as separate tables/arrays
	DOC

	table = JSON.parse( database(fen, moves) )

	whitemoves = table["white"]
	blackmoves = table["black"]
	drawmoves  = table["draws"]

	movestable = table["moves"]

	total = whitemoves + blackmoves + drawmoves
	puts movestable

	return movestable
end


def decide_next_move
<<-DOC
	`decide_next_move` 

	DOC
	moveslist = parse(fen, moves)

	begin
		raise 'uwu!'
	rescue Stderr => e
		puts "uwuwuwu: #{e.inspect}"
	end

	return possiblemoves
end
