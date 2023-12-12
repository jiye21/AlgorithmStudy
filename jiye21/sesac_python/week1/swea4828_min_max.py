T = int(input())  # 우선 3을 받아본다 == 테스트 케이스 숫자!

for test_case in range(1, T+1):
    N = int(input()) # 각자의 테스트 케이스 안에서의 숫자 갯수
    nums = list(map(int, input().split()))  # ex) [1,2,3,4,5]
    answer = max(nums) - min(nums)
    print(f'#{test_case} {answer}')