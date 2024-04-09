def solution(A):
  count = {}
  max_segments = 0
  max_segments = calc(count, max_segments, A)
  if len(A) % 2 == 1:
    A = A[1:]
    max_segments = calc(count, max_segments, A)
    A = A[:-2]
    max_segments = calc(count, max_segments, A)
  return max_segments

def calc(count, max_segments, A):
    for i in range(len(A) - 1):
        segment_sum = A[i] + A[i+1]
        if segment_sum in count:
            count[segment_sum] += 1
        else:
            count[segment_sum] = 1
        max_segments = max(max_segments, count[segment_sum])


# テストケース
A = [1, 0, 1, 3, 1, 2, 2, 1, 0, 4]
print(solution(A))  # 出力: 3

A = [5, 3, 1, 3, 2, 3]
print(solution(A))  # 出力: 1

A = [9, 9, 9, 9, 9]
print(solution(A))  # 出力: 2

A = [1, 5, 2, 4, 3, 3]
print(solution(A))  # 出力: 3
