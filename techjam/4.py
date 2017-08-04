import re
from operator import itemgetter, attrgetter

def solution (s) :
  #Prepare data
  str_input = s
  call_list = []
  for call in str_input.split("|") :
    call_time, call_len = call.split(",")
    call_time_sum = 0
    call_len_sum = 0
    mul = 1
    for ct in reversed(call_time.split(":")) :
      call_time_sum = call_time_sum + int(ct) * mul 
      mul = mul * 60
    mul = 1
    for cl in reversed(call_len.split(":")) :
      call_len_sum =  call_len_sum + int(cl) * mul
      mul = mul * 60
    call_list.append( (call_time_sum ,call_len_sum) )
    call_list = sorted(call_list, key=itemgetter(0))
  
  # Solution
  max_call_center = 0
  calling_list = []

  for call_cal in call_list :
    #print call_cal
    #Check before add to list
    if len(calling_list) == 0 :
      calling_list.append(call_cal[0] + call_cal[1])

    else :
      reponse_time = 0
      #Determine real response time
      if calling_list[-1] - call_cal[0] > 60 :
        reponse_time = call_cal[0]
      else :
        reponse_time = calling_list[-1]

      #Delete finish call
      #print "response time", reponse_time
      for i in range(0,len(calling_list)) :
        if calling_list[i] <= reponse_time :
          calling_list[i] = -1
      calling_list = [e for e in calling_list if e != -1]
      calling_list.append(reponse_time + call_cal[1])
    #print calling_list
    max_call_center = max(max_call_center,len(calling_list))
  
  #This is solution !
  #print(max_call_center)
  return max_call_center

def main() :
  print solution("8:30:00,5:00|8:31:00,4:00|8:34:00,3:00|8:33:59,5")
if __name__ == "__main__" :
  main()


  aaaaa
  aaaab
  bbbbb
  ccccc
  ddddd
  eeeee
  fffff
  ggggg
  hhhhh
  iiiii
  jjjjj
  kkkkk
  lllll
  mmmmm
  nnnnn
  ooooo
  ppppp
  qqqqq
  rrrrr
  sssss
  ttttt
  uuuuu
  vvvvv
  wwwww
  xxxxy
  yyyyy
  zzzzy
  zzzzz