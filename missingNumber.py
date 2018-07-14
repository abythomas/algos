def missingNumber():
    print("Enter value of n: ")
    n=int(input())
    print("Enter the n-1 integers: ")
    sum=0
    for num in input().split(' '):
      sum=sum+int(num)
    print("Missing number is ",int(n*(n+1)/2-sum),"\n")

missingNumber()
