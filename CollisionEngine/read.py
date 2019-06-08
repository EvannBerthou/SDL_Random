import matplotlib.pyplot as plt
import csv

x = []
y = []

with open("values.txt", 'r') as f:
    plots = csv.reader(f, delimiter=',')
    i = 0
    for row in plots:
        x.append(int(row[0]))
        y.append(i)
        i += 1
plt.plot(x,y)
plt.xlabel("time")
plt.ylabel("values")
plt.title("t")
plt.show()
