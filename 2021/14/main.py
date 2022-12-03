from string import ascii_uppercase

f = open("input2.txt", "r").read().splitlines()
input = {}
check = [] 
formula = f[0]

print(formula)

for i in f:
	if i != f[0]:
		a, b = i.split('-')
		input[a] = b

for k in range(10):
	newformula = []
	last = "a"
	for i in formula:
		if last != "a":
			check = last + i
			newformula += input[check]
			
		newformula += i
		last = i
	formula = newformula

lowest = 5000
highest = 0
for c in ascii_uppercase:
	count = formula.count(c)
	if count > highest:
		highest = count
	elif count < lowest and count != 0:
		lowest = count

print(highest, "-", lowest, "=", highest - lowest)
