T = int(input())  # 우선 3을 받아본다 == 테스트 케이스 숫자!

for test_case in range(1, T+1):
    N, M = map(int, input().split())  # 각자의 테스트 케이스 안에서의 숫자 갯수
    a = list(map(int, input().split()))
    test_list = [0 for i in range(N-M+1)]
    for i in range(N-M+1):  # i, 0부터 N-M까지 순회
        for j in range(M):  # j, 0부터 M-1까지 순회
            test_list[i] += a[i+j]

    answer = max(test_list) - min(test_list)
    print(f'#{test_case} {answer}')