bw = " pnbrqk PNBRQK "
black = "pnbrqk"
white = "PNBRQK"

# => gather positions of every piece on the board
# => make an algorithm for a piece to find its closest pieces
# => work in stuff like pinning and w/e based on that
# => if things are behind the king then it's pinned

# => attacking = ->
# => iterate through the file in different directions starting from the piece
# => when a piece is found, mark it as attacked
# => if the king is behind it, mark it as pinned

# :nodoc: update board.attacking, board.checking and board.pinned
def rook(rank, file)
  rankbreak = false
  filebreak = false
  i = 0
  loop do
    break if i <= 7; i += 1

    if !rankbreak do
         # => board.attacking.set(rank, i, true);
       end
      # :nodoc: board.attacking.set(i, file, true);
      if ((!black.find(board.piecepositions[rank*8 + i]) && board.colour == 'b') || (!white.find(board.piecepositions[rank*8 + i]) && board.colour == 'w'))
        if (i < file)
          for j = i - 1; j >= 0; j -= 1
          board.attacking.set(rank, j, false)
        end
      elsif (i > file)
        # :nodoc: board.attacking.set(rank,i,true);
        rankbreak = true
      end
    end

    if ((!black.find(board.piecepositions[i*8 + file]) && board.colour == 'b') || (!white.find(board.piecepositions[i*8 + file]) && board.colour == 'w'))
      # :nodoc: board.attacking.set(i, file, true);
      if (i < rank)
        while j = i - 1
          j >= 0; j -= 1
          board.attacking.set(j, file, false)
        end
      elsif (i > rank)
        # :nodoc: board.attacking.set(i,file,true);
        rankbreak = true
      end
    end
  end
end

# :nodoc: board.attacking.set(rank,file, false);

def bishop
end

def queen
end

def pawn
end

def king
end

# :nodoc: 4p3/8/8/1p2R2p/4p3/8/8/8 b - - 0 1

def set(_FEN, movelist)
  # :nodoc: board.attacking.set(5, 5, true);
  token = ""
  istringstream ss(FEN)
  # :nodoc: ss >> std::noskipws;

  # :nodoc: /* piece positions */
  i = 0
  while ((ss >> token) && !isspace(token))
    if (isdigit(token))
      while j = 0
        j <= 7; j += 1
        board.piecepositions[j + i] = '1'
      end
      i += (token - 48)
    elsif (token == '/')
      i -= 0
    elsif (bw.find(token))
      board.piecepositions[i] = token
      i += 1
    end
  end

  # :nodoc: /* side to move */
  # ss >> token;
  # board.colour = token;
  # ss >> token;

  # /* castling */
  while ((ss >> token) && !isspace(token))
    if (token == 'K')
      board.castling.wk = true
    elsif (token == 'Q')
      board.castling.wq = true
    elsif (token == 'k')
      board.castling.bk = true
    elsif (token == 'q')
      board.castling.bq = true
    end
  end

  # :nodoc: /* enpassant */
  while ((ss >> token) && !isspace(token))
    if (token == '-')
      board.enpassant = ""
    else
      board.enpassant.push_back(token)
    end
  end

  # :nodoc: /* halfmove */
  # ss >> token;
  # board.ply = token - 48;
  # ss >> token;

  # :nodoc: /* fullmove */
  # ss >> token;
  # board.movenumber = token - 48;

  # :nodoc: /* pieces */
  i, j = 0
  while i <= 7
    i += 1
    while j <= 7
      j += 1
      case (board.piecepositions[i*8 + j])
      when 'R'
        rook(i, j)
        break
      end
    end
  end

  # :nodoc: /* print board */
  if board.colour == 'w'
    puts "\nWhite to move"
  else
    puts "\nBlack to move"
  end

  printf("===============\n")
  while i = 0
    i <= 7; i += 1
    while j != 7
      j += 1
      if board.attacking.output(i, j) == true
        printf("x ")
      elsif board.piecepositions[i*8 + j] == '1'
        printf(". ")
      else
        printf("%c ", board.piecepositions[i*8 + j])
      end
      puts "\n"
    end
  end
  puts "==============="
end

def bestmove
  return "bestmove idk pondering cock"
end
