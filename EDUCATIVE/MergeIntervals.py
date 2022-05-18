from math import fabs


NUMBER_MAX_VALUE=1<<32

# Given a list of intervals, 
# merge all the overlapping intervals to produce a list that has only mutually exclusive intervals.
class MergeIntervals:
	def __init__(self, input):
  		self.input = input

	def solve(self):
		lst, res = self.input, []
		lst.sort(key = lambda sublist: sublist[0])

		i, j = 0, 0
		while j<len(lst):
			maxVal=lst[j][1]
			while j<len(lst) and maxVal >= lst[j][0]:
				maxVal=max(maxVal,lst[j][1])
				j+=1	
			res.append([lst[i][0], maxVal])
			i=j
			
		return res

# Given a list of non-overlapping intervals sorted by their start time, 
# insert a given interval at the correct position and merge all necessary intervals to produce a list that has only mutually exclusive intervals.
class InvertIntervals:
	def __init__(self, intervals, newIntervals):
  		self.intervals, self.newIntervals = intervals, newIntervals

	def solve(self):
		intervals, newIntervals, res = self.intervals, self.newIntervals, []
		ind=0
		while intervals[ind][0]<newIntervals[0]:
			ind+=1
		intervals.insert(ind, newIntervals)

		i, j = 0, 0
		while j<len(intervals):
			maxVal=intervals[j][1]
			while j<len(intervals) and maxVal >= intervals[j][0]:
				maxVal=max(maxVal,intervals[j][1])
				j+=1	
			res.append([intervals[i][0], maxVal])
			i=j
		return res

# Given two lists of intervals, find the intersection of these two lists. 
# Each list consists of disjoint intervals sorted on their start time.
class IntervalsIntersection:
	def __init__(self, array1, array2):
  		self.array1, self.array2 = array1, array2

	def solve(self):
		arr1, arr2, res = self.array1, self.array2, []
		i, j = 0, 0

		def isOverlap(a,b):
			return (a[0]<=b[0] and b[0]<=a[1]) or (b[0]<=a[0] and a[0]<=b[1])

		while i<len(arr1) and j<len(arr2):
			if isOverlap(arr1[i],arr2[j]):
				start = max(arr1[i][0], arr2[j][0])
				end = min(arr1[i][1], arr2[j][1])
				res.append([start,end])	
			if arr1[i][1]<arr2[j][1]:
				i+=1
			else:
				j+=1
		return res

# Given an array of intervals representing ‘N’ appointments, 
# find out if a person can attend all the appointments.
class ConflictingAppointments:
	def __init__(self, arr):
  		self.input = arr
	
	def solve(self):
		arr = self.input
		arr.sort(key= lambda x: x[0])

		for i in range(1,len(arr)):
			if arr[i][0] <= arr[i-1][1]:
				return False

		return True

if __name__ == "__main__":
	#print(MergeIntervals([[1,4]]).solve())
	#print(InvertIntervals([[2,3],[5,7]], [1,4]).solve())
	#print(IntervalsIntersection([[1, 3], [5, 7], [9, 12]], [[5, 10]]).solve())
	print(ConflictingAppointments([[4,5], [2,3], [3,6]]).solve())