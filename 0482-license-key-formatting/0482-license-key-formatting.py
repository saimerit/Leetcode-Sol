class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        s = s.replace('-', "")
        s = s.upper()
        if not s:
            return ""

        ls = []
        for i in range(len(s), 0, -k):
            ls.append(s[(max(0, i-k)) : i])
        return "-".join(ls[::-1])
        