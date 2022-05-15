NUMBER_MAX_VALUE=1<<32

# Given an array of sorted numbers and a target sum, 
# find a pair in the array whose sum is equal to the given target.
class PairWithTargetSum:
    def __init__(self, input, target):
        self.input = input
        self.target = target

    def solve(self):
        arr, tg = self.input, self.target
        i, j = 0, len(arr)-1

        while i<j:
            if arr[i]+arr[j] == tg:
                break;
            if arr[i]+arr[j] < tg:
                i+=1
            else:
                j-=1;
        return [i,j]

# Given an array of sorted numbers, remove all duplicates from it
class RemoveDuplicates:
    def __init__(self, input):
        self.input = input
    
    def solve(self):
        arr, i, j, res = self.input, 0, 0, 0
        
        while i<len(arr):
            while i<len(arr) and arr[i]==arr[j]:
                i+=1
            res+=1
            j=i
        return res

# Given a sorted array, create a new array containing squares of all the numbers of the input array in the sorted order.
class SquaringASortesArray:
    def __init__(self, input):
        self.input = input

    def solve(self):
        arr, i, j = self.input, 0, 0, 
        res = []
        for idx, v in enumerate(arr):
            if v>=0:
                i = idx
                j = idx-1
                break
        while i<len(arr) or j>=0:
            if i==len(arr):
                res.append(arr[j]**2)
                j-=1
            elif j==-1:
                res.append(arr[i]**2)
                i+=1
            else:
                if arr[i]**2 <= arr[j]**2:
                    res.append(arr[i]**2)
                    i+=1
                else:
                    res.append(arr[j]**2)
                    j-=1
        return res

# Given an array of unsorted numbers, find all unique triplets in it that add up to zero.
class TripletSumToZero:
    def __init__(self, input):
        self.input = input
    
    def solve(self):
        arr = self.input
        res = []
        arr.sort()

        for i in range(len(arr)):
            if i>0 and arr[i]==arr[i-1]:
                continue
            self.findPair(arr,-arr[i],i+1,res)

        return res

    def findPair(self, arr, target, start, res):
        end = len(arr)-1
        while start < end:
            if arr[start]+arr[end]==target:
                res.append([arr[start],arr[end],-target])
                start+=1
                end-=1
                while start<end and arr[start]==arr[start-1]:
                    start+=1
                while end>start and arr[end]==arr[end+1]:
                    end-=1
            elif arr[start]+arr[end]>target:
                end-=1
            else:
                start+=1

# Given an array arr of unsorted numbers and a target sum, count all triplets in it such that arr[i] + arr[j] + arr[k] < target 
# where i, j, and k are three different indices. Write a function to return the count of such triplets.
class TripletWithSmallestSum:
    def __init__(self, input, target):
        self.input, self.target = input, target

    def solve(self):
        arr, target, res = self.input, self.target, 0

        arr.sort()

        for k in range(len(arr)):
            newTarget = target - arr[k]
            i, j = k+1, len(arr)-1
            while i<j:
                if arr[i]+arr[j]<newTarget:
                    res += j-i
                    i += 1
                else:
                    j -= 1
        return res

if __name__ == "__main__":
    #print(PairWithTargetSum([2, 5, 9, 11], 11).solve())
    #print(RemoveDuplicates([2, 2, 2, 11]).solve())
    #print(SquaringASortesArray([4,6,8,9]).solve())
    #print(TripletSumToZero([-3, 0, 1, 2, -1, 1, -2]).solve())
    print(TripletWithSmallestSum([-1, 4, 2, 1, 3], 5).solve())