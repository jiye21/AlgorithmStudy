import random

T = int(input())   # 테스트 케이스 개수 T

for test_case in range(T):
    k = int(input())
    word_list = []
    for i in range(k):
        word_list.append(input())
    p_list = []
    for i in range(k):
        for j in range(i+1, k):
            p_list.append(word_list[i] + word_list[j])
            p_list.append(word_list[j] + word_list[i])

    answer = []
    for p in p_list:
        p_split = " ".join(p).split()         # str형인 단어(p)를 list로 변환
        p_split_r = list(reversed(p_split))   # 변환한 list를 reverse

        if len(p_split) % 2 == 0:
            if p_split[:len(p_split) // 2] == p_split_r[:len(p_split)//2]:  #펠린드롬인지 검사
                answer.append(p)
        else:
            if p_split[:len(p_split) // 2] == p_split_r[:len(p_split)//2]:  #펠린드롬이면인지 검사
                answer.append(p)

    if len(answer) == 0:
        print('0')
    elif len(answer) == 1:
        print(answer[0])
    else:
        print(answer[random.randrange(0, len(answer)-1)])


