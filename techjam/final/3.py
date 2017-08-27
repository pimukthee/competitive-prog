
# 3.Walk around
import operator as op
from functools import reduce

def nCr(n, r):
    r = min(r, n-r)
    if r == 0: 
        return 1
    return reduce(op.mul, range(n, n-r, -1))//reduce(op.mul, range(1, r+1))

if __name__ == "__main__":
    testcase_num = int(input())
    for i in range(testcase_num):
        x, y = map(int,input().split())
        print(nCr((x + y),(min(x,y))))



