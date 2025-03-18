In the Department of CSIE, there is a Probability Laboratory located in the basement. Some dedicated students burn the midnight oil to conduct research on probability in the lab. One day, the members are investigating the probabilities in Texas Hold'em, a popular poker game.  

As an enthusiastic member of the lab, you are tasked with determining the winning probability of your current hand. Given two Texas Hold'em starting hands (one for yourself and one for your opponent), you need to calculate your chances of winning.  

### Texas Hold'em Rules (Simplified)  

For this problem, we assume the following conditions to make the problem simpler:  

- The game consists of only two players.  
- No blinds or betting rules are considered.
- Each player is initially dealt two cards.  
- The deck consists of 52 standard playing cards (no jokers).
- If two players have the cards of the same rank, it's considered a draw.
- When there's a draw, you win.

### Hand Rankings (From Highest to Lowest Priority)  

Note that in the following examples, in the suits part, S stands for spade, H for Heart, D for Diamond and C for club. For example, S5 means spade with number 5. The order of cards is independent of the suits, only dependent on the number. A is the largest, and K is the second, ..., and 2 is the smallest.

1. Royal Flush:  
   - Five highest-ranking consecutive cards (10, J, Q, K, A) of the same suit.  
   - Example:  
     - S10, SJ, SQ, SK, SA  
     - C10, CJ, CQ, CK, CA  
   <!-- - If both players have a Royal Flush, the game is a draw.  -->

2. Straight Flush:  
   - Any five consecutive cards of the same suit.  
   - Example:  
     - SA, S2, S3, S4, S5 (in this case, S5 is top)
     - H5, H6, H7, H8, H9
     - SJ, SQ, SK, SA, S2 is not a Straight Flush  
   <!-- - If both players have a Straight Flush, the one with the higher top card wins. If tied, the game is a draw. -->

3. Four of a Kind:  
   - Four cards with the same rank, plus any fifth card.  
   - Example:  
     - SA, HA, DA, CA, CK
     - S10, H10, D10, C10, HQ
   <!-- - If both players have Four of a Kind, the one with the higher four cards wins. If tied, the game is a draw. -->

4. Full House:  
   - A combination of three of a kind plus a pair.
   - Example:
     - S9, H9, D9, C5, S5
     - SQ, HQ, DQ, C4, S4
   <!-- - If both players have a Full House, the one with the higher three of a kind wins. If tied, the game is a draw. -->

5. Flush:  
   - Any five cards of the same suit, not necessarily consecutive.  
   - Example:  
     - H2, H4, H6, H8, HJ
     - C3, C7, C9, CJ, CK
   <!-- - If both players have a Flush, the one with the highest card wins. If tied, compare the next highest card. If still tied, the game is a draw. -->

6. Straight:  
   - Any five consecutive cards, not necessarily the same suit.  
   - Example:  
     - S4, D5, H6, C7, S8  
     - H10, SJ, DQ, CK, SA (in this case, SA is top)
     - HA, S2, D3, C4, S5 (in this case, S5 is top)
     - SJ, CQ, HK, DA, S2 is not a Straight  
   <!-- - If both players have a Straight, the one with the higher top card wins. If tied, the game is a draw. -->

7. Three of a Kind:
   - Three cards with the same rank, plus two other unrelated cards.
   - Example:  
     - S6, H6, D6, C9, S10
     - SQ, HQ, DQ, C2, H4  
   <!-- - If both players have Three of a Kind, the one with the higher three cards wins. If tied, the game is a draw.  -->

8. Two Pair:  
   - Two different pairs, plus any fifth card.
   - Example:  
     - S5, H5, D8, C8, SA  
     - H3, D3, C7, S7, D9  
   <!-- - If both players have Two Pair, the one with the higher highest pair wins. If tied, the second pair is compared. If still tied, the game is a draw. -->

9. One Pair:  
   - One pair, plus three unrelated cards.  
   - Example:  
     - S2, H2, D4, C7, S10
     - H9, D9, C5, S6, DK
   <!-- - If both players have One Pair, the one with the higher pair wins. If tied, the highest kicker card determines the winner. If still tied, the game is a draw. -->

10. High Card:  
   - If no players have any valid combinations, the winner is determined by the highest card in their hand.  
   - Example:  
     - S10, H3, D6, C8, SA
     - H5, D2, C9, SJ, QD
   <!-- - If both players have the same high card, compare the second highest card, and so on. If all five cards are equal, the game is a draw. -->

---  

Your goal is to calculate the winning probability based on the two starting hands. The probabilities should be derived considering all possible board outcomes (community cards). Your answer is considered correct if the error is smaller than \(10^(-5)\).
