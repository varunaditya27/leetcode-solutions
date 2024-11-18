class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = {'a', 'e', 'i', 'o', 'u'}
        vowel_indices = [i for i in range(len(s)) if s[i].lower() in vowels]
        vowel_values = [s[i] for i in range(len(s)) if s[i].lower() in vowels]
        char_list = list(s)
        for j in range(len(vowel_indices)):
            char_list[vowel_indices[j]] = vowel_values[-1 - j]
        reversed_string = ''.join(char_list)
        return reversed_string
