class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        ransom_note_dict = {}
        for char in ransomNote:
            ransom_note_dict[char] = ransom_note_dict.get(char, 0) + 1
        magazine_dict = {}
        for char in magazine:
            magazine_dict[char] = magazine_dict.get(char, 0) + 1
        for char in ransom_note_dict:
            if ransom_note_dict.get(char, 0) > magazine_dict.get(char, 0):
                return False
        return True 
