class Solution:
    def maxFreqSum(self, s: str) -> int:
        freq = dict()
        max_vowel = 0
        max_consonant = 0

        for c in s:
            freq[c] = freq.get(c, 0) + 1

            if c in ['a', 'e', 'i', 'o', 'u']:
                # print(f'DEBUG: vowel, {c}, freq: {freq[c]}')
                max_vowel = max(max_vowel, freq[c])
            else:
                # print(f'DEBUG: consonant, {c}, freq: {freq[c]}')
                max_consonant = max(max_consonant, freq[c])

        return max_vowel + max_consonant