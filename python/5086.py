while True:
    str = input().split(' ')
    n1 = int(str[0])
    n2 = int(str[1])

    if n1 == 0 and n2 == 0:
        break

    if n2%n1 == 0:
        print("factor")
    elif n1%n2 == 0:
        print("multiple")
    else :
        print("neither")
