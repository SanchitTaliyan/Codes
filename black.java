public class BlackJackHand extends Hand<BlackJackCard> {
2 /* There are multiple possible scores for a blackjack hand,
3 * since aces have multiple values. Return the highest possible
4 * score that's under 21, or the lowest score that's over. */
5 public int score() {
6 ArrayList<Integer> scores = possibleScores();
7 int maxUnder = Integer.MIN_VALUE;
8 int minOver = Integer.MAX_VALUE;
9 for (int score : scores) {
10 if (score > 21 && score < minOver) {
11 minOver = score;
12 } else if (score <= 21 && score > maxUnder) {
13 maxUnder = score;
14 }
15 }
16 return maxUnder == Integer.MIN_VALUE ? minOver : maxUnder;
17 }
18
19 /* return a list of all possible scores this hand could have
20 * (evaluating each ace as both 1 and 11 */
21 private ArrayList<Integer> possibleScores() { … }
22
23 public boolean busted() { return score() > 21; }
24 public boolean is21() { return score() == 21; }
25 public boolean isBlackJack() { ... }
26 }
27
28 public class BlackJackCard extends Card {
29 public BlackDackCard(int c, Suit s) { super(c, s); }
30 public int value() {
31 if (isAce()) return 1;
32 else if (faceValue >= 11 && faceValue <= 13) return 10;
33 else return faceValue;
}
public int minValue() {
37 if (isAce()) return 1;
38 else return value();
39 }
40
41 public int maxValue() {
42 if (IsAceQ) return 11;
43 else return value();
44 }
45
46 public boolean isAce() {
47 return faceValue == 1;
48 }
49
50 public boolean isFaceCard() {
51 return faceValue >= 11 && faceValue <= 13;
52 }
53 } 
