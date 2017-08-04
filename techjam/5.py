def solution(s):
    s = s.lower()
    a = ["aaaaaa", "aaaaab", "bbbbbb", "cccccc", "dddddd", "eeeeee", "ffffff", "gggggg", "hhhhhh", "iiiiii", "jjjjjj", "kkkkkk", "llllll", "mmmmmm", "nnnnnn", "oooooo", "pppppp", "qqqqqq", "rrrrrr", "ssssss", "tttttt", "uuuuuu", "vvvvvv", "wwwwww", "yyyyyy", "zzzzzy", "zzzzzz"]
    blacklists = ["johndoe", "techjam", "kbtgtech", "ilovecoding", "thisiseasy", "letsgototraval", "afterfinish", "majhcet"]
    if s in a:
        return 0
    else:
        if len(s) <= 6 and len(s) >= 4:
            return 1
        return is_blacklist(s, blacklists)
 
def is_blacklist(customer, blacklists) :
    for blacklist in blacklists:
        if (is_typo(customer, blacklist)
            or is_miss(customer, blacklist)
            or is_miss(blacklist, customer)
            or is_swap(customer, blacklist)
            or customer == blacklist):
            return 1
    return 0
 
def find_mismatch(a, b):
    mismatchs = []
    for i in range(len(a)):
        if a[i] != b[i]:
            mismatchs.append((a[i], b[i]))
    return mismatchs
 
def is_typo(customer, blacklist):
    mismatchs = []
    if (len(customer) == len(blacklist)):
        mismatchs = find_mismatch(customer, blacklist)
    return (len(mismatchs) == 1)
 
def is_miss(customer, blacklist):
    is_miss = False
    miss_index = 0
    if len(customer) == len(blacklist) - 1:
        for i in range(0,len(blacklist)):
            miss_index = i
            if i != len(blacklist)-1:
                if customer[i] != blacklist[i]:
                    break
        #print miss_index
        blacklist = blacklist[:miss_index] + blacklist[miss_index+1:]
        return customer == blacklist
    else:
        return False
 
def is_swap(customer, blacklist):
    miss_tuple_list = []
    if len(customer) == len(blacklist):
        miss_tuple_list = find_mismatch(customer, blacklist)
    #print miss_tuple_list
    if len(miss_tuple_list) == 2 and miss_tuple_list[0][0] == miss_tuple_list[1][1] and miss_tuple_list[0][1] == miss_tuple_list[1][0] :
        return True
    return False

def main():
    print solution("a"), 0
    print solution("johnDoE"), 1
    print solution("johnDEO"), 1
    print solution("aaaaaa"), 0
    print solution("thisiseazy"), 1

if __name__ == "__main__":
    main()