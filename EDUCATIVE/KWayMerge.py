from heapq import heappop, heappush
from re import I


NUMBER_MAX_VALUE=1<<32

# Given an array of ‘K’ sorted LinkedLists, merge them into one sorted list.
class MergeKSortedList:
	def __init__(self, llist):
  		self.llist = llist

	def solve(self):
		llist = self.llist
		minheap, ans = [], []
		for i,l in enumerate(llist):
			heappush(minheap, (l.pop(0), i))

		while minheap:
			val, i = heappop(minheap)
			ans.append(val)
			if llist[i]:
				heappush(minheap, (llist[i].pop(0), i))
		return ans

# Given ‘M’ sorted arrays, find the K’th smallest number among all the arrays.
class KthSmallestNumberInMSortedLists:
	def __init__(self, llist, k):
		self.llist = llist
		self.k = k

	def solve(self):
		llist, k = self.llist, self.k
		minheap = []		
		for i,l in enumerate(llist):
			heappush(minheap, (l.pop(0), i))
		
		while minheap:
			k-=1
			val, i = heappop(minheap)

			if k == 0:
				return val
			
			if llist[i]:
				heappush(minheap, (llist[i].pop(0), i))

		return -1

# Given an N∗N matrix where each row and column is sorted in ascending order, 
# find the Kth smallest element in the matrix.
class KthSmallestNumberInASortedMatrix:
	def __init__(self, matrix, k):
		self.matrix = matrix
		self.k = k

	def solve(self):
		matrix, k = self.matrix, self.k
		minheap = []		
		for i,l in enumerate(matrix):
			heappush(minheap, (l.pop(0), i))
		
		while minheap:
			k-=1
			val, i = heappop(minheap)

			if k == 0:
				return val
			
			if matrix[i]:
				heappush(minheap, (matrix[i].pop(0), i))

		return -1

# Given ‘M’ sorted arrays, find the smallest range that includes 
# at least one number from each of the ‘M’ lists.
class SmallestNumberRange:
	def __init__(self, llist):
  		self.llist = llist

	def solve(self):
		llist = self.llist
		maxheap, minval, mrange, ans = [], NUMBER_MAX_VALUE, NUMBER_MAX_VALUE, []

		for i,l in enumerate(llist):
			val = l.pop()
			minval = min(minval, val)
			heappush(maxheap, (-val, i))
	
		mrange = -maxheap[0][0] - minval

		while maxheap:
			l, i = heappop(maxheap)
			if -l - minval < mrange:
				mrange = -l - minval
				ans = [minval, -l]
			if llist[i]:
				val = llist[i].pop()
				minval = min(minval, val)
				heappush(maxheap, (-val, i))
			else:
				break

		return ans

if __name__ == "__main__":
	#print(MergeKSortedList([[2, 6, 8], [3, 6, 7], [1, 3, 4]]).solve())
	#print(KthSmallestNumberInMSortedLists([[5, 8, 9],[1, 7]], 3).solve())
	#print(KthSmallestNumberInASortedMatrix([
		# 	[2, 6, 8], 
		# 	[3, 7, 10],	
		# 	[5, 8, 11]
		# ], 5).solve())
	print(SmallestNumberRange([[1, 5, 8],[4, 12],[7, 8, 10]]).solve())
