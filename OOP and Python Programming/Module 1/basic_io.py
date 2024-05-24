print("Now I need Money")
money1 = input("Give me some money: \n")
print("Thanks for " + money1 + " Taka\n")
print(type(money1))

money2 = input("Give me some more money: \n")
print("Thanks for " + money2 + " Taka\n")

# Python input default string so we need to convert if we want int
""" 
1. number to string: str
2. decimal to number: float
3. list, tuple, hex, oct
4. python int vs float
"""
total_money = int(money1) + int(money2)
print("Total Money: ", total_money, "\n")
print(type(total_money))