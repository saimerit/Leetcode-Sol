class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        count = (len(b) + len(a) - 1) // len(a)
        repeated = a * count
        if b in repeated:
            return count
        if b in repeated + a:
            return count + 1
        return -1