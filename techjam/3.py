def solution(s):
    times = s
    number_of_customer = len(times)
    total_time = 5
    is_subset_sum = find_all_subset_sum(times, number_of_customer, total_time)
    waiting_time = minimum_waiting_time(is_subset_sum, number_of_customer, total_time // 2, total_time)
    return waiting_time  

def find_all_subset_sum(times, number_of_customer, total_time):
    #dynamic programming subset sum
    is_subset_sum = []
    for i in range(0, number_of_customer + 1):
        is_subset_sum.append([False] * (total_time + 1))
    for i in range(0, number_of_customer + 1):
        is_subset_sum[i][0] = True
    for i in range(1, number_of_customer + 1):
        for j in range(1, total_time + 1):
            is_subset_sum[i][j] = is_subset_sum[i - 1][j]
            print i
            print is_subset_sum
            print
            if j >= times[i-1]:
                print "edit ", i, j
                is_subset_sum[i][j] = is_subset_sum[i][j] | is_subset_sum[i-1][j-times[i-1]]
            print is_subset_sum
            print
    return is_subset_sum
 
def minimum_waiting_time(is_subset_sum, number_of_customer, average_time, total_time):
    waiting_time = 1000
    for time in range(average_time, total_time + 1):
        if is_subset_sum[number_of_customer][time]:
            first_queue = time
            second_queue = total_time - first_queue
            waiting_time = min(waiting_time, max(first_queue, second_queue))
    return waiting_time

def main():
    print solution([1])

if __name__ == '__main__':
    main()