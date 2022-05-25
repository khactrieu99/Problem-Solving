NUMBER_MAX_VALUE=1<<32

# Write a function to sort the objects in-place on their creation sequence number in O(n)
# and without using any extra space
class CyclicSort:
	def __init__(self, input):
		self.input = input

	def solve(self):
		arr = self.input
		def swap(arr, a, b):
			arr[a], arr[b] = arr[b], arr[a]
		for i in range(len(arr)):
			while arr[i] != i+1:
				swap(arr, i, arr[i]-1)
		return arr
		
# We are given an array containing n distinct numbers taken from the range 0 to n.
# Since the array has only n numbers out of the total n+1 numbers, find the missing number.
class FindTheMissingNumber:
	def __init__(self, input):
		self.input = input	

	def solve(self):
		arr, ans = self.input, 0
		def swap(arr, a, b):	
			arr[a], arr[b] = arr[b], arr[a]

		for i in range(len(arr)):
			while arr[i]<len(arr) and arr[i] != i:
				swap(arr, i, arr[i])
		
		for i in range(len(arr)):	
			if arr[i] != i:
				ans = i
				break

		return ans	

# We are given an unsorted array containing numbers taken from the range 1 to ‘n’. 
# The array can have duplicates, which means some numbers will be missing. Find all those missing numbers.
class FindAllMissingNumbers:
	def __init__(self, input):
  		self.input = input

	def solve(self):	
		arr, res = self.input, []
		i = 0
		while i < len(arr):
			j = arr[i] - 1
			if arr[i] != i+1 and arr[i] != arr[j]:
				arr[i], arr[j] = arr[j], arr[i]
			else:
				i+=1

		for i in range(len(arr)):
			if arr[i] != i+1:
				res.append(i+1)

		return res

# Find that duplicate number without using any extra space
class FindTheDuplicateNumber:
	def __init__(self, input):
  		self.input = input

	def solve(self):
		arr, i = self.input, 0
		while i<len(arr):
			j = arr[i]-1
			if arr[i] != i+1:
				if arr[i] == arr[j]:
					return arr[i]
				arr[i], arr[j] = arr[j], arr[i]
			else:
				i+=1
		return -1

# We are given an unsorted array containing n numbers taken from the range 1 to n. 
# The array has some numbers appearing twice, find all these duplicate numbers using constant space.
class FindAllDuplicateNumbers:
	def __init__(self, input):
  		self.input = input

	def solve(self):
		arr, res = self.input, []
		i = 0
		while i<len(arr):
			j = arr[i]-1
			if arr[i] != i+1:
				if arr[i] == arr[j]:
					res.append(arr[i])
					i+=1
				else:
					arr[i], arr[j] = arr[j], arr[i]
			else:
				i+=1
		return res

if __name__ == "__main__":
	#print(CyclicSort([1, 5, 6, 4, 3, 2]).solve())
	#print(FindTheMissingNumber([4, 0, 3, 1]).solve())
	#print(FindAllMissingNumbers([2, 3, 2, 1]).solve())
	#print(FindTheDuplicateNumber([2, 4, 1, 4, 4]).solve())
	print(FindAllDuplicateNumbers([5, 4, 7, 2, 3, 5, 3]).solve())