require "option_parser"

startpos = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
VERS = 0.1

def position
  while line = STDIN.raw &.gets
    if (token == "startpos")
      fen = startpos
      is >> token
    elsif (token == "fen")
      # while the token isn't anything about moves,
      # keep adding the fen onto the stream
      while (is >> token && token != "moves")
        fen += token + " "
      end
    else
      return
    end

    puts line
  end
end

def loop(argc, argv)
  OptionParser.parse do |parser|
    parser.banner = "CTEngine\n ==========\n Author: Izzy Cassell\n"

    parser.on "-v", "--version", "Show version" do
      puts VERS
      exit
    end
    parser.on "uci", "UCI" do
      puts "id name CTEngine #{VERS} \n
                id author Izzy Cassell\n
                uciok"
      exit
    end
    parser.on "isready", "Is Ready?" do
      puts "readyok"
      exit
    end
    parser.on "quit", "stop" do
      puts "byyeee <3"
      return
    end
    parser.on "position" do
      puts "byyeee <3"
      return
    end
    parser.on "go", "Lesss gooooooo" do
      puts "mmmmm cock.."
      exit
    end
  end
end
