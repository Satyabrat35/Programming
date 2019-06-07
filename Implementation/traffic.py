n,k=map(int,input().split())
arr = [x for x in input().split()]
a=[0]*100005
for i in range(0,n):
	if arr[i]=='R':
		a[i]=1
	elif arr[i]=='Y':
		a[i]=2
	else:
		a[i]=0
ans = 0
x = 0
b = [0]*100005
for i in range(0,n):
	x+=b[i]
	y = (3-(a[i]+x)%3)%3
	ans+=y
	x+=y
	if k+i<n:
		b[i+k]-=y
print(ans)
