def solution (s) :
    blacklists, customers = s.split("#")
    customers = customers.split("|")
    blacklists = blacklists.split("|")
    answers = [0] * len(customers)
    customer_count = 0
    for customer in customers:
        customer = customer.lower()
        for blacklist in blacklists:
            blacklist = blacklist.lower()
            if (is_typo(customer, blacklist)
                or is_miss(customer, blacklist)
                or is_miss(blacklist, customer)
                or is_swap(customer, blacklist)
                or customer == blacklist):
                    answers[customer_count] = 1
        customer_count = customer_count + 1
    return answers

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

def main() :

    # Swap test
    print "swap test"
    print is_swap("JohnDoe".lower(),"JohnDoe".lower()), False
    print is_swap("JonDoe".lower(),"JohDo".lower()), False
    print is_swap("Johndoe".lower(),"JohnEod".lower()), True 
    print is_swap("JohnDoe".lower(),"EohnDoJ".lower()), True
    print is_swap("JohnDoe".lower(),"eohnDoj".lower()), True
    print is_swap("JohnDoe".lower(),"JohoDne".lower()), True
    print is_swap("JohnDoe".lower(),"JohoDN".lower()), True

    # Miss test
    print "\nmiss 1 test"
    print is_miss("JonDoe".lower(),"JohnDoe".lower()), True
    print is_miss("JohnDo".lower(),"JohnDoe".lower()), True
    print is_miss("Johndoe".lower(),"JohnDoe".lower()), False 
    print is_miss("JhnDoe".lower(),"JohnDoe".lower()), True
    print is_miss("Johne".lower(),"JohnDoe".lower()), False
    print is_miss("JohDo".lower(),"JohnDoe".lower()), False
    print is_miss("JohnDoe".lower(),"JohnDoee".lower()), True

    # Typo test
    print "\nTypo 1 test"
    print is_typo("JohnDoe".lower(),"JohnDoe".lower()), False
    print is_typo("JohnDxe".lower(),"JohnDoe".lower()), True
    print is_typo("zohnDoe".lower(),"JohnDoe".lower()), True
    print is_typo("JohnDol".lower(),"JohnDoe".lower()), True
    
    print solution("JohnDoe|Somchai|Tawatchai#Johdnoe|Somying|Thawatchai|Thawatcai|JohnDoe|JPHNDOE")

if __name__ == "__main__" :
  main()
