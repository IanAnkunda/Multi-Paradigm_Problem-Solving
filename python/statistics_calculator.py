"""
statistics_calculator.py
Object-oriented version of mean, median, and mode.
"""

class StatisticsCalculator:
    def __init__(self, numbers):
        self.numbers = numbers

    def mean(self):
        return sum(self.numbers) / len(self.numbers)

    def median(self):
        nums = sorted(self.numbers)
        n = len(nums)
        mid = n // 2

        if n % 2 == 0:
            return (nums[mid - 1] + nums[mid]) / 2
        return nums[mid]

    def mode(self):
        freq = {}
        for num in self.numbers:
            freq[num] = freq.get(num, 0) + 1
        return max(freq, key=freq.get)


if __name__ == "__main__":
    data = [1, 2, 2, 3, 4, 5, 5, 5]
    calc = StatisticsCalculator(data)

    print("Input:", data)
    print("Mean:", calc.mean())
    print("Median:", calc.median())
    print("Mode:", calc.mode())
