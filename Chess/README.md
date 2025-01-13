#CHESS-CLI
##Overview
My implementation of chess was an attempt to self-evaluate my knowledge on C by making a more complicated board game (compared to say, tic-tac-toe or connect-four) without viewing other chess projects or viewing code that others have written.
Everything typed was purely created by my own thoughts and decisions with no outside influence. I wanted to see if I was given a problem, with absolutely no internet usage; Can I solve it and can I solve it well enough to be proud of it? How long will it take me to solve it?

Well this is WIP starting 01/12/25 and at the bottom of the readme will be a mock standup ever day of this week(with a time of how long i worked on it); Come hell or high waters, I will produce something of value. 




01/12/25: I created and initialized the board(put pieces on it via structs). I have made it so inputs are validated, the correct color pieces move based on the turn order, all pieces currently have the potental to move as they should, albeit some small bugs and validation is required
to help them move normally. currently rook moves as it should, pawn needs some more logic, queen needs one bug fixed before it moves correctly and then bishop will too. knight and king havent been implemented but i've set the foundation for making those functions.
I also desire to implement en passant, castling, and AI into this so my square structs contain additional info that i believe i want to capture for en passant and possibly for AI training (ambitious but given I have spent 5 hrs today and chess feels mostly done i'm gonna need more work) 
