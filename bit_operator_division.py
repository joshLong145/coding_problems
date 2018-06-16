num1 = 15
num2 = 5
rem = 0

def devide(num1, num2):
    quotient = 1
    if(num1 == num2):
        return 1
    elif num1 < num2:
        rem = num1

    while num1 <= num2:
        num = num2 << 1
        quotient = quotient << 1

    quotient = quotient + devide(num1 - num2 , num2)

    return quotient

print(devide(num1,num2))
