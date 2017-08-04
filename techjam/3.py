possible_way = [[-1] * 305] * 15

def main():
    times = map(int, raw_input().split())
    number_of_customer = len(times)
    total_time = sum(times)
    is_subset_sum = find_all_subset_sum(times, number_of_customer, total_time)
    waiting_time = minimum_waiting_time(is_subset_sum, number_of_customer, total_time // 2, total_time)
    print waiting_time

def find_all_subset_sum(times, customer, total_time):
    """dynamic programming subset sum"""
    if possible_way[customer][total_time] >= 0:
        return possible_way[customer][total_time]
    if total_time == 0:
        return 1
    if customer == 0:
        return 0
    if total_time >= times[customer - 1]


def minimum_waiting_time(is_subset_sum, number_of_customer, average_time, total_time):
    waiting_time = 1000
    for time in range(average_time, total_time + 1):
        if is_subset_sum[number_of_customer][time]:
            first_queue = time
            second_queue = total_time - first_queue
            waiting_time = min(waiting_time, max(first_queue, second_queue))
    return waiting_time

if __name__ == '__main__':
    main()