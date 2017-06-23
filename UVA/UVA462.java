import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		LinkedList<Card> arr = null;

		// read in the input
		while(in.hasNext()) {
			arr = new LinkedList<Card>();
			for(int i = 0; i < 13; i++) {
				String s = in.next();
				arr.add(new Card(s.substring(0,1),s.substring(1,2)));
			}
			Solution sl = new Solution(arr);
			System.out.println(sl.bid());
		}
	}
}

class Solution {
	// Define the object attributes
	private LinkedList<Card> _cards = new LinkedList<Card>();
	private HashMap<String,Integer> _suitCount = new HashMap<String,Integer>();
	private HashMap<String,HashMap<String,Integer>> _special = new HashMap<String,HashMap<String,Integer>>();
	private int _points;

	// Constructor
	Solution(LinkedList<Card> arr) {
		// Intialize all the attributes
		_cards = arr;
		_suitCount = new HashMap<>();
		_special   = new HashMap<>();

		// Award the initial points
		for(Card c : _cards) {

			// Track the number of cards for each suit
			String rank = c.getRank();
			String suit = c.getSuit();

			_suitCount.put(suit,(_suitCount.containsKey(suit)) ? _suitCount.get(suit)+1 : 1);

			// Record the special cards for each suit
			if(!_special.containsKey(suit)) {
				_special.put(suit,new HashMap<String,Integer>());
			}

			// Award initial points
			switch(rank) {
				case "A":
					_special.get(suit).put("A",1);
					_points += 4;
					break;
				case "K":
					_special.get(suit).put("K",1);
					_points += 3;
					break;
				case "Q":
					_special.get(suit).put("Q",1);
					_points += 2;
					break;
				case "J":
					_special.get(suit).put("J",1);
					_points += 1;
			}
		}
	}

	void deductPoints() {
		for(String s : _special.keySet()) {
			// foreach suit, check for conditions to
			// deduct points
			HashMap<String,HashMap<String,Integer>> suitData = new HashMap<>();
			if(_special.get(s).containsKey("K") &&
					(_suitCount.get(s) == 1)) {
				_points -= 1;
					}
			if(_special.get(s).containsKey("Q") &&
					(_suitCount.get(s) <= 2)) {
				_points -= 1;
					}
			if(_special.get(s).containsKey("J") &&
					(_suitCount.get(s) <= 3)) {
				_points -= 1;
					}
		}
	}

	int getPoints() {
		return _points;
	}

	void addPoints() {

		// Add 2 points for each suit not owned
		_points += 2 * (4 - _special.size());

		for(String s : _suitCount.keySet()) {
			// Check for conditions to add points

			if(_suitCount.get(s) == 2) {
				_points += 1;
			} else if(_suitCount.get(s) == 1) {
				_points += 2;
			}
		}
	}

	boolean isStoppedSuit(String suit) {
		return 
			_special.get(suit).containsKey("A") ||
			(_special.get(suit).containsKey("K") && _suitCount.get(suit) >= 2) ||
			(_special.get(suit).containsKey("Q") && _suitCount.get(suit) >= 3);
	}

	String bid() {
		deductPoints();
		int trumpPnt = _points;
		addPoints();

		if(_points < 14) {
			return "PASS";
		} else if(trumpPnt >= 16 && canTrump()) {
			return "BID NO-TRUMP";
		} else {
			return "BID "+maxSuit();
		}
	}

	boolean canTrump() {
		if(_special.size() != 4) return false;
		for(String suit : _special.keySet()) {
			if(!isStoppedSuit(suit)) {
				return false;
			}
		}
		return true;
	}

	String maxSuit() {

		int max =  0;
		String maxSuit = "";

		for(String suit : _special.keySet()) {
			if(max == Math.max(max,_suitCount.get(suit))) {
				if(max == _suitCount.get(suit) && precedence(maxSuit) < precedence(suit)) {
					maxSuit = suit;
				}
			} else {
				maxSuit = suit;
			}
			max = Math.max(max,_suitCount.get(suit));
		}
		return maxSuit;
	}

	int precedence(String suit) {
		switch(suit) {
			case "S":
				return 4;
			case "H":
				return 3;
			case "D":
				return 2;
			case "C":
				return 1;
		}
		return -1;
	}

}

class Card {
	private String _rank;
	private String _suit;

	Card(String r, String s) {
		_rank = r;
		_suit = s;
	}

	String getSuit() {
		return _suit;
	}

	String getRank() {
		return _rank;
	}

	public String toString() {
		return "Card:" + " Rank => "+ _rank + " Suit => " + _suit;
	}
}
