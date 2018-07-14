MININT=-99999

def maxSum(arr,size):
  max=MININT
  tempMax=0
  for i in range(size):
    tempMax=tempMax+arr[i]
    if(tempMax>max):
      max=tempMax
    if(tempMax<0):
      tempMax=0
  return max

def main():
  print("Enter number of test cases: ")
  t=int(input())
  for j in range(t):
    print("Enter number of integers: ")
    n=int(input())
    print("Enter integers: ")
    arr = [int(num) for num in input().split(' ')]
    res=maxSum(arr,n)
    print("Max contigious sum is ",res,"\n")

main()


