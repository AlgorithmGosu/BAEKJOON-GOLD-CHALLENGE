# 보통 이렇게 시간 or day를 기준으로 최대치를 구하라고 할 때,
# 오늘 기점으로 최대가 진짜 최대잖아. => 이게 가능한 이유가, 이 문제 기준으로 오늘 회의(act)를 하면 +1임. 즉 가중치가 존재하지 않기 때문에
# 현재의 최대가 진짜 최대인거야.
# 반대로 퇴사문제있잖아. 거기서는 언제 하느냐에 따라 얻는 점수가(가중치가) 다르기 때문에 그리디가 아니라 dp 문제로 풀어야 해.
# 이 문제에서 알 수 있듯이, n(즉 복잡도)이 되는 변수가 뭔지를 잘 파악하면 쉽게 문제 유형을 알 수 있을 거 같아.
# 왜냐하면 이 문제는 시간이 2^31-1 이었는데 dp면 시간 기준으로 설정을 해야해서 불가능하거든.
# 이 문제는 회의 수가 100000개로 딱봐도, 회의 수를 O(n)이내로 구현해내야 하는 문제였어. 그래서 dp는 불가능하고, 그럼 가능한게 거의 그리디나 정렬O(nlogn)정도밖에 안돼.
n = int(input())
data =[]
for _ in range(n):
    data.append(list(map(int,input().split())))
data.sort(key=lambda x:[x[1],x[0]])
now = 0
count = 0
for i in range(n):  
    s,e = data[i]
    if s >= now:
        count+=1
        now = e
print(count)