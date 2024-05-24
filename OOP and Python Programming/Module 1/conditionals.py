"""  
in, not, not in, is, is not 
"""
a = 5

# IF Else Condition
if a > 5:
    print("Greater than 5")
else:
    print("Not Greater than 5")

if a > 5:
    print("Greater than 5")
elif a == 5:
    print("Equal to 5")
else:
    print("Not Greater than 5")

boss = False

if boss is True:
    print("Boss is Right")
else:
    print("Boss is wrong")

if boss is not True:
    print("Boss is Right")
else:
    print("Boss is wrong")

# Nested Condition
coin = "Head"

if coin == 'Head':
    if 1 :
        if 3 :
            if 4 % 2 == 0:
                if 8 / 3 == 2 or 10 + 3 == 13:
                    print("Nested Condition working")