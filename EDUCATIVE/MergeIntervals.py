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

if __name__ == "__main__":
	#print(MergeIntervals([[1,4]]).solve())
	print(InvertIntervals([[2,3],[5,7]], [1,4]).solve())