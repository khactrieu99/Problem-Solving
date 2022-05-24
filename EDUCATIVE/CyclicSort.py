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

if __name__ == "__main__":
	#print(CyclicSort([1, 5, 6, 4, 3, 2]).solve())
	print(FindTheMissingNumber([4, 0, 3, 1]).solve())