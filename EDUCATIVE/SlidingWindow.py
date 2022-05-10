NUMBER_MAX_VALUE=1<<32

# Given an array of positive numbers and a positive number ‘k’, 
# find the maximum sum of any contiguous subarray of size ‘k
class MaxSumSubArrayOfSizeK:
    def __init__(self, input):
        self.input = input

    # time complexity: O(n)
    # space complexity: O(1)
    def solve(self, k):
        arr, curSum = self.input, 0
        for i in range(min(k,len(arr))):
          curSum=curSum+arr[i]
        if len(arr)<=k:
            return curSum
        res, curIndex = curSum, k
        while curIndex < len(arr):
            curSum=curSum+arr[curIndex]-arr[curIndex-k]
            res = max(res,curSum)
            curIndex=curIndex+1
        return res

# Given an array of positive numbers and a positive number ‘S’, 
# find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. 
# Return 0 if no such subarray exists.
class SmallestSubArrayWithAGreaterSum:
    def __init__(self, input):
        self.input = input

    # time complexity O(n)
    # space complexity O(1)
    def solve(self, s):
        arr, i, j, curSum, res = self.input, 0, 0, 0, NUMBER_MAX_VALUE 
        while i<len(arr):
            curSum=curSum+arr[i]
            while curSum>=s:
                res=min(res,i-j+1)
                curSum=curSum-arr[j]
                j+=1
            i+=1

        if res == NUMBER_MAX_VALUE:
            res = 0
        return res

# Given a string, find the length of the longest substring in it with no more than K distinct characters.
class LongestSubStringWithMaximumKDistinctCharacters:
    def __init__(self, input):
        self.input = input
    
    # time complexity O(n)
    # space complexity O(k)
    def solve(self, k):
        s,i,j,res = self.input,0,0,0
        _map={}
        while i<len(s):
            _map[s[i]]=_map.get(s[i],0)+1
            if len(_map)<=k:
                res=max(res,i-j+1)
            else:
                while len(_map)>k:
                    _map[s[j]]-=1
                    if _map[s[j]]==0:
                        del _map[s[j]]
                    j+=1
            i+=1
        return res

# Similar to Longest SubString With Maximum K Distinct Characters, with K=2
class FruitsIntoBaskets:
    def __init__(self, input):
        self.input = input

    def solve(self):
        arr, i, j, res = self.input, 0, 0, 0
        _map = {}
        while i<len(arr):
            _map[arr[i]]=_map.get(arr[i],0)+1
            if len(_map)<=2:
                res=max(res,i-j+1)
            else:
                while len(_map)>2:
                    _map[arr[j]]-=1
                    if _map[arr[j]]==0:
                        del _map[arr[j]]
                    j+=1
            i+=1
        return res

# Given a string, find the length of the longest substring, which has all distinct characters.
class LongestSubStringWithDistinctCharacters:
    def __init__(self, input):
        self.input = input
    
    # Time complexity O(n)
    # Space complexity O(26) <=> O(1)
    def solve(self):
        s, i, j, res = self.input, 0, 0, 0
        hmap = {}

        while i<len(s):
            if s[i] in hmap:
                if hmap[s[i]]>=j:
                    j=i
            res=max(res,i-j+1)
            hmap[s[i]]=i
            i+=1
        return res

# Given a string with lowercase letters only, if you are allowed to replace no more than k letters with any letter, 
# find the length of the longest substring having the same letters after replacement.
class LongestSubStringWithSameLettersAfterReplacement:
    def __init__(self, input):
        self.input = input
    
    def solve(self, k):
        s, i, j, curMax, res = self.input, 0, 0, 0, 0
        hmap = {}
        while i<len(s):
            hmap[s[i]]=hmap.get(s[i],0)+1
            curMax = max(curMax, hmap[s[i]])

            if i-j+1-curMax > k:
                hmap[s[j]]-=1
                j+=1
            
            res = max(res, i-j+1)
            i+=1
        return res

class LongestSubArrayWithOnesAfterReplacement:
    def __init__(self, input):
        self.input = input
    
    def solve(self, k):
        arr, i, j, res= self.input, 0, 0, 0
        hmap = {}
        while i<len(arr):  
            hmap[arr[i]]=hmap.get(arr[i],0)+1     
            maxInSlice = max(hmap.get(0,0), hmap.get(1,0))

            if i-j+1-maxInSlice > k:
                hmap[arr[j]]-=1
                j+=1

            res=max(res,i-j+1)
            i+=1
        return res
            

if __name__ == "__main__":
    # print(MaxSumSubArrayOfSizeK([2,3,4,1,5]).solve(2))
    # print(SmallestSubArrayWithAGreaterSum([3,4,1,1,6]).solve(8))
    # print(LongestSubStringWithMaximumKDistinctCharacters("cbbebi").solve(10))
    # print(FruitsIntoBaskets(['A','B','C','B','B','C']).solve())
    # print(LongestSubStringWithDistinctCharacters("abccde").solve())
    # print(LongestSubStringWithSameLettersAfterReplacement("abccde").solve(1))
    print(LongestSubArrayWithOnesAfterReplacement([0,1,0,0,1,1,0,1,1,0,0,1,1]).solve(3))
