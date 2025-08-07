def solution(video_len, pos, op_start, op_end, commands):
    video_len = video_len.split(':')
    
    total_len = int(video_len[0]) * 60 + int(video_len[1])
    pos = pos.split(':')
    
    time = int(pos[0]) * 60 + int(pos[1])
    
    op_start = op_start.split(':')
    op_end = op_end.split(':')
    
    start = int(op_start[0]) * 60 + int(op_start[1])
    end = int(op_end[0]) * 60 + int(op_end[1])
    
    
    for cmd in commands:
        if start <= time and time <= end:
            time = end
            
        if cmd == 'prev':
            time -= 10
            if time < 0:
                time = 0
        elif cmd == 'next':
            time += 10
            if time > total_len:
                time = total_len
        
    if start <= time and time <= end:
        time = end
            
    print(time)
    minute = time // 60
    second = time % 60
    
    answer = f"{minute:02d}:{second:02d}"
    return answer