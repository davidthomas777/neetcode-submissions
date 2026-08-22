class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        l1 = []
        l2 = []
        for char in s:
            l1.append(char)
        for char in t:
            l2.append(char)
        l1.sort()
        l2.sort()
        if l1 == l2:
            return True
        else:
            return False