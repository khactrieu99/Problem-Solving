NUMBER_MAX_VALUE=1<<32

# Given an array of sorted numbers and a target sum, 
# find a pair in the array whose sum is equal to the given target.
class PairWithTargetSum:
    def __init__(self, input, target):
        self.input = input
        self.target = target

    def solve(self):
        arr, tg = self.input, self.target
            

if __name__ == "__main__":
    print(PairWithTargetSum([1,2,3,4,6], 6).solve())