from math import sqrt
from heapq import *

NUMBER_MAX_VALUE=1<<32

# Given an unsorted array of numbers, find the ‘K’ largest numbers in it.
class TopKNumbers:
	def __init__(self, input, k):
		self.input = input
		self.k = k

	def solve(self):
		arr, k = self.input, self.k
		heap = []
		
		for val in arr:
			heappush(heap, -val)
			if len(heap) > k:
				heappop(heap)
		
		return heap * -1

# Given an unsorted array of numbers, find Kth smallest number in it.
class KSmallestNumbers:
	def __init__(self, input, k):
		self.input = input
		self.k = k

	def solve(self):
		arr, k = self.input, self.k
		heap = []
		
		for val in arr:
			heappush(heap, val)
			if len(heap) > k:
				heappop(heap)
		
		return heap

# Given an array of points in a 2D plane, find ‘K’ closest points to the origin.	
class Point:
	def __init__(self, point):
		self.point = point

	def calcTheDistance(self):
		return sqrt(sum([v**2 for v in self.point]))
	
	def __lt__(self, other):
		return self.calcTheDistance() > other.calcTheDistance()

class KClosestPointsToTheOrigin:
	def __init__(self, input, k):
		self.input = input
		self.k = k

	def solve(self):
		arr, k = self.input, self.k
		heap = []
				
		for val in arr:
			heappush(heap, Point(val))
			if len(heap) > k:
				heappop(heap)

		return [p.point for p in heap]

# Given ‘N’ ropes with different lengths, we need to connect these ropes into one big rope with minimum cost. 
# The cost of connecting two ropes is equal to the sum of their lengths.
class ConnectRopes:
	def __init__(self, input):
		self.input = input

	def solve(self):
		arr = self.input
		heapify(arr)
		temp, res = 0, 0
		while len(arr) > 1:
			temp = heappop(arr) + heappop(arr)
			heappush(arr, temp)
			res += temp

		return res

# Given a sorted number array and two integers ‘K’ and ‘X’, find ‘K’ closest numbers to ‘X’ in the array. 
# Return the numbers in the sorted order. ‘X’ is not necessarily present in the array.
class KClosestNumbers:
	def __init__(self, input, k, x):
		self.input = input
		self.k = k
		self.x = x

	def solve(self):
		return 0
  		
# Given an array of numbers and a number ‘K’, we need to remove 
# ‘K’ numbers from the array such that we are left with maximum distinct numbers.
class MaximumDistinctElements:
	def __init__(self, input, k):
		self.input = input
		self.k = k

	def solve(self):
		arr, k = self.input, self.k
		hmap = {}
		for i in arr:
			hmap[i] = hmap.get(i,0) + 1
		
		ans, minheap = 0, []
		for key in hmap:
			if hmap[key] > 1:
				heappush(minheap, (hmap[key], key))
			else:
				ans+=1

		while k>0 and len(minheap)>0:
			if minheap[0][0] <= k:
				ans+=1
				k-=heappop(minheap)[0]-1
			else:
				newFre = heappop(minheap)[0] - k
				if newFre == 1:
					ans+=1
				k = 0

		return max(0,ans-k)

if __name__ == "__main__":
	#print(ConnectRopes([1, 3, 11, 5]).solve())
	#print(KClosestNumbers([5, 6, 7, 8, 9], 3, 7).solve())
	print(MaximumDistinctElements([7, 3, 5, 8, 5, 3, 3], 2).solve())