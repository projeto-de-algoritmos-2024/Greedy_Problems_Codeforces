x = int(input())
s = list(input())
ant = s.copy()
lis1 = []
cnt = 0
for i in range(x-1):
     if s[i] != "W":
        if s[i+1]!= "W":
            s[i] = "W"
            s[i+1] = "W"
            cnt += 1
            lis1.append(i)
        else:
            s[i] = "W"
            s[i+1] = "B"
            cnt += 1
            lis1.append(i)
if "B" in s:
    cnt = 1000000
cnt2 = 0
lis2 =[]
for i in range(x-1):
     if ant[i] != "B":
        if ant[i+1]!= "B":
            ant[i] = "B"
            ant[i+1] = "B"
            cnt2 += 1
            lis2.append(i)
        else:
            ant[i] = "B"
            ant[i+1] = "W"
            cnt2 += 1
            lis2.append(i)
if "W" in ant:
    cnt2 = 1000000
if cnt == 1000000 and cnt2 == 1000000:
    print(-1)
    exit()
print(min(cnt,cnt2))

if cnt < cnt2:
    for i in lis1:
        print(i+1,end=" ")
    print()
else:
    for i in lis2:
        print(i+1,end=" ")
    print()