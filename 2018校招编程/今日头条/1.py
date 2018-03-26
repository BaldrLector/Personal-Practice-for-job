n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
a.sort()



def diff_of_list(lst, k):
    netList = [i + k for i in lst]
    return len(set(lst) & set(netList))


# for i in range(n):
#     for j in range(i, n):
#         if a[j] - a[i] == k:
#             st.add((a[i], a[j]))

print(diff_of_list(a, k))
