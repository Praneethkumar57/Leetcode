class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        lsum = sum(cardPoints[0:k])
        rsum =0
        maxsum = lsum
        count = 0
        r = len(cardPoints)-1
        while(count<k):
            val = cardPoints[k-(count+1)]
            lsum = lsum - val
            rsum = rsum + cardPoints[r]
            maxsum = max(maxsum, (lsum+rsum))
            r = r-1
            count = count+1
        return(maxsum)