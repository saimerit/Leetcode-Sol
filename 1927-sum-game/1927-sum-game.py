class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num)
        l = int(n/2)
        qLeft = 0
        qRight = 0
        lsum = 0
        rsum = 0
        for i in range(l):
            if num[i] == '?':
                qLeft+=1
            else:
                lsum += ord(num[i]) - ord('0')
        
        for i in range(l, n):
            if num[i] == '?':
                qRight +=1
            else:
                rsum += ord(num[i]) - ord('0')
        
        diff = lsum - rsum
        return 2 * diff != 9 * ( - qLeft + qRight)

        