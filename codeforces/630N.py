def main():  
    from math import sqrt
    a, b, c = map(float, input().split())
    b = b / a
    c = c / a
    r = sqrt(b**2  - 4*c)
    print(str((-b+r) / 2) + "\n" + str((-b-r) / 2))

if __name__ == '__main__':
    main()