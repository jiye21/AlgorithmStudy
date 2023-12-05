T = int(input())

book_dict = {}

for i in range(T):
    name = str(input())
    if name not in book_dict.keys():
        book_dict[name] = 1
    else:
        book_dict[name] += 1

max_book_num = max(book_dict.values())
max_book_list = []
for key, value in book_dict.items():
    if value == max_book_num:
        max_book_list.append(key)


max_book_list.sort()
print(max_book_list[0])