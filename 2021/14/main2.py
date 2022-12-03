from string import ascii_uppercase

f = open("input2.txt", "r").read().splitlines()
input = {}
counts = {}
newcounts = {}
check = [] 
last = "a"
new = "a"
formula = f[0]
total = 0
print(formula)

for i in f:
	if i != f[0]:
		a, b = i.split('-')
		input[a] = b
		counts[a] = 0
		newcounts[a] = 0

for val in formula:
	if last != "a":
		check = last + val
		counts[check] += 1
	last = val
print(counts)
print(formula)

for k in range(40):
	for i in counts:
		if counts[i] > 0:
			new = input[i]
			newcounts[i[0] + new] += counts[i]
			newcounts[new + i[1]] += counts[i]
			counts[i] = 0
	counts = newcounts.copy()
	for j in newcounts:
	 	newcounts[j] = 0
	print("counts: ", counts)

lowest = 50000000000000
highest = 0
for c in ascii_uppercase:
	total = 0
	if c == 'N':
		total += 1
	for i in counts:
		if i[1] == c and counts[i] > 0:
			total += counts[i]
	if (total != 0):
		print("count of ", c, ": ", total)
	if total > highest:
		highest = total
	if total < lowest and total > 0:
		lowest = total

print(highest, "-", lowest, "=", highest - lowest)
