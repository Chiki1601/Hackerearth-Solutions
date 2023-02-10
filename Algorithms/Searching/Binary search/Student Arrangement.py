# Write your code here
n, m, k = list(map(int, input().split()))
a = map(int, input().split())
remain_seats = [k] * m
seats = [i for i in range(m)]
non_preferred_count = 0
total_student = 0
 
 
def find_seat(num):
    if seats[num] == num:
        return num
    seats[num] = find_seat(seats[num])
    return seats[num]
 
 
for i in a:
    seat_num = i - 1
    total_student += 1
 
    if total_student > m * k:
        non_preferred_count += n - total_student + 1
        break
 
    assigned_seat = find_seat(seat_num)
    if seat_num != assigned_seat:
        non_preferred_count += 1
    remain_seats[assigned_seat] -= 1
    if not remain_seats[assigned_seat]:
        seats[assigned_seat] = find_seat((assigned_seat + 1) % m)
print(non_preferred_count)
