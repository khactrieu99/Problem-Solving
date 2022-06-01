from heapq import heappop, heappush
from re import I


NUMBER_MAX_VALUE=1<<32

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
		

if __name__ == "__main__":
	print(MergeKSortedList([[2, 6, 8], [3, 6, 7], [1, 3, 4]]).solve())