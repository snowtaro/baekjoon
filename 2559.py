import heapq
import sys

n,k=map(int,sys.stdin.readline().split())

heap=[]

prefix=0

list1=list(map(int,sys.stdin.readline().split()))
for i in range(k):
    prefix+=list1[i]
heapq.heappush(heap,prefix*-1)

for i in range(n-k):
    prefix=prefix-list1[i]+list1[k+i]
    heapq.heappush(heap,prefix*-1)

print(heapq.heappop(heap)*(-1))