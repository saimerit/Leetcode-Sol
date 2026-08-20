class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s = s.split()
        if len(s) != len(pattern):
            return False
        m = {}
        o = []
        for i in range(len(pattern)):
            if not m.get(pattern[i]):
                if s[i] not in o:
                    m[pattern[i]] = s[i]
                    o.append(s[i])
                else:
                    return False
            else:
                if pattern[i] in m and m.get(pattern[i]) != s[i]:
                    return False
        
        return True
        