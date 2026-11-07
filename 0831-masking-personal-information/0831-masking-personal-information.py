class Solution:
    def maskPII(self, s: str) -> str:
        if '@' in s:
            for i in range(len(s)):
                if s[i] == '@':
                    return (str(s[0]) + "*****" + str(s[i-1]) + s[i:]).lower()
        else:
            dig = [c for c in s if c.isdigit()]
            last4 = "".join(dig[-4:])
            local = f"***-***-{last4}"
            cul = len(dig) - 10
            if cul == 0: return local
            return f"+{'*' * cul}-{local}"