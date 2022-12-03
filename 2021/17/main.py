def find_velocity(x, y, xvel, yvel, xmin, xmax, ymin, ymax, orxvel, oryvel, top):
    x += xvel
    y += yvel
    if (xvel > 0):
        xvel -= 1
    elif xvel < 0:
        xvel += 1
    yvel -= 1
    if y > top[0]:
        top[0] = y
    if x > xmax or y < ymax:
        return
    if x >= xmin and x <= xmax and y <= ymin and y >= ymax:
        print("possible! x: ", orxvel, " y: ", oryvel, "top: ", top[0])
        return
    find_velocity(x, y, xvel, yvel, xmin, xmax, ymin, ymax, orxvel, oryvel, top)


f = open("input.txt", "r").read().splitlines()

xmin = int(f[0])
xmax = int(f[1])
ymin = int(f[2])
ymax = int(f[3])

top = [1]
top[0] = 0
for j in range (-200, 200):
    for i in range (-20, 200):
        find_velocity(0, 0, i, j, xmin, xmax, ymin, ymax, i, j, top)
