NUMBER_MAX_VALUE=1<<32

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

if __name__ == "__main__":
	print(MergeIntervals([[1,4]]).solve())