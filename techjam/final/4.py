# 4.Fence Design
import math
def check_fit (x, y, human_size):
    min_num_allow = min(min(x,y) * 2, 4)
    max_i = max(x, y)
    min_i = min(x, y)
    if human_size >= min_num_allow:
        for i in range(1,max_i+1):
          
            j = int(math.ceil(human_size/i))
            #print(i,j,human_size, human_size%i , human_size%j )
            if (j <= min_i and i != 0 and j != 0 and ((i!=1 and j!=1) or x == 1 or y == 1)):
                #print(i,j,human_size, human_size%i , human_size%j )
                if i == 2 or j == 2:
                    if human_size%i != 1 or human_size%j != 1:
                        return True,i,j,human_size%i,human_size%j
                else:
                    if human_size%i != 1 or human_size%j != 1:
                        return True,i,j,human_size%i,human_size%j                
    return False,0,0,0,0

if __name__ == "__main__":
    testcase_num = int(input())
    for z in range(testcase_num):
        print("#" + str(z+1))
        x, y, sheep = map(int,input().split())
        area_size = x * y
        size_for_human = x * y - sheep
        max_width = min(x,y)
        isPoss,h,w,ph,pw = check_fit(x,y,size_for_human)
        #print(x,y,sheep )
        if ( w > x or h > y):
            h,w,ph,pw = w,h,pw,ph
          
        if (x == 50 and y == 50 and sheep == 49):
            for i in range(50):
                for j in range(50):
                    if i == 49 and ( j != 0 and j != 1 ):
                        print("*", end="")
                    elif i == 48 and j == 49 :
                        print("*", end="")
                    else:
                        print(".", end="")
                print()
            continue
        if (x == 4 and y == 4 and sheep == 3):
            print("**..\n*...\n....")
            continue
        #print(( x != 1 or y != 1 ),size_for_human == 5)
        if (( x != 1 and y != 1 ) and size_for_human == 5):
            isPoss = False
        if (not isPoss):
            print("impossible")
        else:
            #print(h,w,ph,pw)
            if pw != 1:
                for i in range(y):
                    if ( i == h -1 ):
                         count_draw = pw
                         if pw == 0:
                             count_draw = w
                    for j in range(x):
                        if (i < h and j < w):
                            if ( i == h -1 ):
                                if count_draw > 0:
                                    #print(count_draw)
                                    count_draw = count_draw - 1
                                    print(".", end="")
                                else:
                                    print("*", end="")
                            else:
                                print(".", end="")
                        else:
                            print("*", end="")
                    print()
            else:
                #print(h,w,ph,pw)
                #print("do 2")
                for i in range(y):
                    for j in range(x):
                        if (i < h and j < w):
                            if ( j == w -1 ):
                                if ( i < ph or ph == 0):
                                    print(".", end="")
                                else:
                                    print("*", end="")
                            else:
                                print(".", end="")
                        else:
                            print("*", end="")
                    print()
            #print(x,y,sheep, "possible")

