

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 */
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l_index = 0;
        int r_index = n;

        while (l_index <= r_index) {
            int mid_index = l_index + (r_index - l_index) / 2;
            int myGuess = guess(mid_index);

            if (myGuess == 1) {
                l_index = mid_index + 1;
            }
            else if (myGuess == -1) {
                r_index = mid_index - 1;
            }
            else {
                return (mid_index);
            }
        }
        return (-1);
    }
};