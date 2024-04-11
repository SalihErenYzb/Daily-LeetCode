class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deque = collections.deque()
        for k in reversed(sorted(deck)):
            deque.appendleft(k)
            deque.appendleft(deque.pop())
        deque.append(deque.popleft())

        return list(deque)
        