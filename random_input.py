from random import randint
num = int(input("Input point(s) number: "))
print("Input area: [x, y]")
x = int(input("x = "))
y = int(input("y = "))

f = open("input.txt", "w")
f.write(str(num)+"\n")

for i in range(num):
    f.write(str(randint(x, y))+" "+str(randint(x, y))+"\n")

f.write("\n")

f.close()
print("Finished")
