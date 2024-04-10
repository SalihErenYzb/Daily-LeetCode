class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        stack = list((range(len(deck))))
        indexes = []
        while stack:
            indexes.append(stack.pop(0))
            if stack:
                stack.append(stack.pop(0))
        deck.sort()
        out = []
        print(indexes)
        for z in zip(indexes,deck):
            out.append(z)
        out.sort()
        out = [k[1] for k in out]
        return out
        