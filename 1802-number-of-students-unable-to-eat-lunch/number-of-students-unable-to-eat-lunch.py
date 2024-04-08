class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        n = len(students)
        while students:
            if students[0] == sandwiches[0]:
                students.pop(0)
                sandwiches.pop(0)

            else:
                if sandwiches[0] in students:
                    students.append(students.pop(0))
                else:
                    break

        return len(students)