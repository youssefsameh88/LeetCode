class Solution(object):
    def fizzBuzz(self, n):
        answer =[]
        i = 1
        while i <= n:
            if not (i % 3 or i % 5):
                 answer.append("FizzBuzz")
            elif not i % 3:
                answer.append("Fizz")
            elif not i % 5:
                answer.append("Buzz")
            else:
               answer.append(str(i))
            i+=1
        return answer
               
print(Solution().fizzBuzz(15))