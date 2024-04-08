class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        ssum = sum(students)
        zerosum = len(students)-ssum
        for c in sandwiches:
            if c and ssum:
                ssum -=1
            elif zerosum and not c:
                zerosum -=1
            else:
                return ssum+zerosum
        return 0
        