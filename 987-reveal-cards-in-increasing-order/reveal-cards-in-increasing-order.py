class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deque = collections.deque()
        for k in reversed(sorted(deck)):
            if deque:
                deque.appendleft(deque.pop())
            deque.appendleft(k)
        return list(deque)
        