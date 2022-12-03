def doubles(path2):
	for i in path2:
		if i.islower():
			x = path2.count(i)
			if x == 2:
				return (True)
	return (False)
		

def find_options(input, currentCave, path, paths):
	path2 = path.copy()
	path2.append(currentCave)
	if (currentCave == 'end'):
		paths.append(path2)
		print("found one! ", path2)
		return

	for i in input[currentCave]:
		if (i.islower() and (i not in path2 or not doubles(path2))) or i.isupper():
			find_options(input, i, path2, paths)

input = {}
path = []

f = open("input3.txt", "r").read().splitlines()
print(f)

for i in f:
	print(i)
	a, b = i.split('-')
	if (a not in input):
		input[a] = []
	if (b not in input):
		input[b] = []

	if a != 'start' and b != 'end':
		input[b].append(a)
	if b != 'start' and a != 'end':
		input[a].append(b)

print(input)

paths = []
find_options(input, 'start', path, paths)
print(len(paths))
