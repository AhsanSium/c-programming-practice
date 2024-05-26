num = 1

# Basic while Loop
while num <= 10:
    print(num)
    num += 1

# Break Continue Statement
while num <= 10:
    print(num)
    num += 1
    if num == 5:
        break

while num <= 10:
    if num == 5:
        num += 1
        print("skipping 5")
        continue
    print(num)
    num += 1

# For Loop in Range in python
numbers = [5, 10, 11, 14, 15, 25, 31, 39]

sum = 0
for num in numbers:
    print(num)
    sum += num

print("Sum is: ", sum)

# Get num with index i:
sum = 0
for i, num in enumerate(numbers):
    print(i, num)
    sum += num

print("Sum is: ", sum)

# print(range(1, 10))

# Range start inclusive stop exclusive, step
for i in range(1, 10, 2):
    print(i)

for i in range(len(numbers)):
    print(i, numbers[i])

friends = ['Aaa', 'Bbb', 'Ccc', 'Ddddd', 'Eeee', 'Ff', 'Ggggg', 'Hhhh']
for friend in friends:
    print(friend)

for i in range(len(friends)):
    print(i, friends[i])