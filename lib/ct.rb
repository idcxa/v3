require 'net/http'
require 'json'

class Die
	@@whatthefuck = 0
	def initialize(nameu, uwu)
		@nameuwu = nameu
		@fuckuwu = uwu
	end

	def sayhi
		puts "hiiiii #{@nameuwu},,, #{@uwu}"
	end
end

die = Die.new("cass", "uwu fuck you")
# die.sayhi

def database(fen, moves)
	uri = "https://explorer.lichess.ovh/lichess?variant=standard&speeds[]
			=bullet&speeds[]=blitz&speeds[]=rapid&speeds[]=classical&ratings[]
			=1600&ratings[]=1800&ratings[]=2000&ratings[]=2200&ratings[]=2500&moves=50
			&play=" + moves + "&fen=" + fen.gsub(" ", "%20")
	 
	Net::HTTP.get(uri)
	puts uri
end

database("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", "e2e4")
