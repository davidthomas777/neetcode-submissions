class Solution:
    def isPalindrome(self, s: str) -> bool:
        alphabet_list = list("abcdefghijklmnopqrstuvwxyz0123456789")
        new_str = s.replace(" ", "").lower()
        chr_list = []
        reverse_list = []
        for char in new_str:
            if char.lower() in alphabet_list:
                chr_list.append(char)

        for char in chr_list[::-1]:
            reverse_list.append(char)
        
        if chr_list == reverse_list:
            return True
        elif chr_list != reverse_list:
            return False
