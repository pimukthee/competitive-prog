n = int(raw_input())
for i in range(n):
    str_input = raw_input()
    str_split = str_input.split('+')
    print int(str_split[0]) + int(str_split[1])
