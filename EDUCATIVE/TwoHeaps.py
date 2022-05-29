from heapq import *


NUMBER_MAX_VALUE=1<<32

class FindTheMediumOfNumberStream:
	def __init__(self):
		self.index = 0
		self.maxHeap = []
		self.minHeap = []

	def insert_num(self, num):
		self.index += 1
		heappush(self.minHeap, num)

		if len(self.minHeap) - len(self.maxHeap) > 1:
			heappush(self.maxHeap, -heappop(self.minHeap))

	def find_median(self):
		if self.index % 2 != 0:
			return self.minHeap[0]
		return (-self.maxHeap[0] + self.minHeap[0])/2

	def processing(self):
		self.insert_num(3)
		print("The median is: " + str(self.find_median()))
		self.insert_num(1)
		print("The median is: " + str(self.find_median()))
		self.insert_num(5)
		print("The median is: " + str(self.find_median()))
		self.insert_num(4)
		print("The median is: " + str(self.find_median()))

if __name__ == "__main__":
	#print(FindTheMediumOfNumberStream().processing())
	print(SlidingWindowMedian([1, 2, -1, 3, 5], 2).solve())