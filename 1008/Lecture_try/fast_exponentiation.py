def power(a,n):
    if n==0: return 1
    answer = power(a, (int) (n/2))
    if n%2==0:
        return answer*answer
    else:
        return answer*answer*a

print(power(4,8))