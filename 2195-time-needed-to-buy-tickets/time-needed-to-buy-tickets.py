
class Solution:
    def timeRequiredToBuy(self, tickets, k: int) -> int:
        ans = k+1
        oldk = tickets[k]-1
        for i in range(k+1):
            tickets[i] -=1
        tickets = [num for num in tickets if num != 0]
        tickets.sort()
        tickets = list(reversed(tickets))
        k = 0

        while oldk > k:
            k +=1
            ans += len(tickets)
            while tickets and tickets[-1] == k:
                tickets.pop()
        return ans

