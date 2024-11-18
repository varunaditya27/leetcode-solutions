class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        output_arr = []
        for i in range(1, n + 1):
            if i % 3 == 0 and i % 5 == 0:
                output_arr.append("FizzBuzz")
            elif i % 3 == 0:
                output_arr.append("Fizz")
            elif i % 5 == 0:
                output_arr.append("Buzz")
            else:
                output_arr.append(str(i))
        return output_arr
