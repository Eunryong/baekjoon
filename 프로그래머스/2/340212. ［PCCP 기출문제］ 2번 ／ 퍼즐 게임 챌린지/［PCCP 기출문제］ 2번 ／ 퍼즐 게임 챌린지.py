def solution(diffs, times, limit):
    answer = pow(10, 5)
    diffs = [0] + diffs
    times = [0] + times
    
    min_time = pow(10, 15)
    st, en = 1, max(diffs)
    total_time = sum(times)
    while st <= en:
        tmp = 0
        mid = (st + en) // 2
        for j in range(1, len(diffs)):
            if diffs[j] > mid:
                tmp += (diffs[j] - mid) * (times[j] + times[j - 1]) + times[j]
            else:
                tmp += times[j]
        
        if limit >= tmp:
            if min_time > tmp:
                answer = mid
            en = mid - 1
        else:
            st = mid + 1;
        

    return answer