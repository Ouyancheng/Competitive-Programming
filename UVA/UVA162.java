import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
	Card[] cards = new Card[52];
	
	String token;
	
	while(!((token = in.next())).equals("#")) {
	  cards[0] = new Card(token.charAt(0)+"",token.charAt(1)+"");
	  for(int i = 1; i < cards.length; i++) {
	    token = in.next();
	    cards[i] = new Card(token.charAt(0)+"",token.charAt(1)+"");
	  }
	  Game g = new Game(cards);;
	  int winner = g.play();
	  System.out.printf("%d%3s\n",g.getPlayerCode(winner),g.playerDeckSize(winner));
	}
  }
}

class Game {
  // Array containing player's decks
  // Player 0 is non-dealer
  // Player 1 is dealer
  private Stack<Card>[] _players;
  private Stack<Card> _played;
  private int _currPlayer;
  private int _fcPlayer;
  private int[] _playerCode = { 2, 1 };
  
  Game(Card[] cards) {
    _players = (Stack<Card>[]) new Stack[2];
	for(int i = 0; i < _players.length; i++) {
	  _players[i] = new Stack<Card>();
	}
	_played  = new Stack<Card>();
	_currPlayer = 0; // Let the non-dealer be the first player
	_fcPlayer   = -1;
	
	// deal cards
	for(Card c : cards) {
	  _players[_currPlayer].push(c);
	  switchPlayer();
	}
  }
  
  void switchPlayer() {
    _currPlayer = (_currPlayer + 1) % _players.length;
  }
  
  int setN(Card c) {
    switch(c.getRank()) {
	  case "J": return 1;
	  case "Q": return 2;
	  case "K": return 3;
	  case "A": return 4;
	  default:  return 0;
	}
  }
  
  boolean nextRound() {
	
	do {
	  // Check if the current player's hand is empty
	  if(_players[_currPlayer].isEmpty()) {
	    return true;
	  }
	  // play card
	  Card playCard = _players[_currPlayer].pop();
	  _played.push(playCard);
	  
	  if(_played.peek().isFaceCard()) {
	    _fcPlayer = _currPlayer;
	  }
	  switchPlayer();
  } while(!_played.peek().isFaceCard());

  int N = setN(_played.peek());
  
  do {
      // Check if the current player's hand is empty
	  if(_players[_currPlayer].isEmpty()) {
	    return true;
	  }
	  // play card
	  Card playCard = _players[_currPlayer].pop();
	  _played.push(playCard);
	  
	  // Check if any of the N cards is face card
	  if(_played.peek().isFaceCard()) {
	    _fcPlayer = _currPlayer;
	    switchPlayer();
		N = setN(_played.peek());
	  } else {
	    N--;
	  }
	} while(N != 0);
	return false; // return false if the game has not ended
  }
  
  int play() {
	Stack<Card> tmp = new Stack<Card>();
	// Keep going until game ends
    while(!nextRound()) {
	  // Add played cards to bottom of fcp deck
	  while(_players[_fcPlayer].size() != 0) { 
	    tmp.push(_players[_fcPlayer].pop()); 
	  }
	  while(_played.size() != 0) {
	    _players[_fcPlayer].push(_played.pop());
	  }
	  while(tmp.size() != 0) {
	    _players[_fcPlayer].push(tmp.pop());
	  }
	  _currPlayer = _fcPlayer;
	}
	return (_currPlayer == 0) ? _players.length - 1 : _currPlayer - 1 ;
  }
  
  int playerDeckSize(int index) {
    if(index < 0 || index >= _players.length) return -1;
    return _players[index].size();
  }
  
  int getPlayerCode(int index) {
    return _playerCode[index];
  }
}

class Card {
  private String _suit;
  private String _rank;

  Card(String s,String r) {
    _suit = s;
	_rank = r;
  }
  
  boolean isFaceCard() {
    return _rank.matches("[AKQJ]");
  }
  
  String getRank() {
    return _rank;
  }
}