require "option_parser"
require "http/server"

# :nodoc:
#
#          http://wbec-ridderkerk.nl/html/UCIProtocol.html
#
#   Description of the universal chess interface (UCI)    April 2004
#   ================================================================
#
# The specification is independent of the operating system. For Windows,
# the engine is a normal exe file, either a console or "real" windows application.
#
# all communication is done via standard input and output with text commands,
#
# The engine should boot and wait for input from the GUI,
# the engine should wait for the "isready" or "setoption" command to set up its internal parameters
# as the boot process should be as quick as possible.
#
# the engine must always be able to process input from stdin, even while thinking.
#
# all command strings the engine receives will end with `\n`,
# also all commands the GUI receives should end with `\n`,
# Note: `\n` can be `0x0c` or `0x0a0c` or any combination depending on your OS.
# If you use Engine und GUI in the same OS this should be no problem if you cummunicate in text mode,
# but be aware of this when for example running a Linux engine in a Windows GUI.
#
# The engine will always be in forced mode which means it should never start calculating
# or pondering without receiving a "go" command first.

# Before the engine is asked to search on a position, there will always be a position command
# to tell the engine about the current position.

# by default all the opening book handling is done by the GUI,
# *but there is an option for the engine to use its own book ("OwnBook" option, see below)*

# if the engine or the GUI receives an unknown command or token it should just ignore it and try to
# parse the rest of the string.

# if the engine receives a command which is not supposed to come, for example "stop" when the engine is
# not calculating, it should also just ignore it.

# TODO: Write documentation for `Amethyst`
module Amethyst
  VERSION = "0.1.0"

  server = HTTP::Server.new do |context|
    context.response.content_type = "text/plain"
    context.response.print "Hello world! The time is #{Time.local}"
  end

  address = server.bind_tcp 8080
  puts "Listening on http://#{address}"
  server.listen

  # /* IO service */

  # /* Store position from FEN and moves in bitboards */

  # /* Valid move finder */

  # /* Search, decides which moves look most promising to calculate first */

  # /* Evaluator */
  # Position::set("4p3/8/8/1p2R2p/4p3/8/8/8 b - - 0 1", "");

  # puts Position::bestmove()

  # UCI::loop(argc, argv);

  puts "hiiii izzy <3"
end
