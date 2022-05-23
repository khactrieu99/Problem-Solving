NUMBER_MAX_VALUE=1<<32

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
		

if __name__ == "__main__":
	print(CyclicSort([1, 5, 6, 4, 3, 2]).solve())