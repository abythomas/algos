 class BinarySearch{
  int binarysearch(int []arr,int l,int r,int x)
  {
    
    if(r>=l)
    {
      int mid=l + (r-l)/2;
      if(arr[mid]==x)
      {
        return mid;
      }
      if(arr[mid]<x)
      {
        return binarysearch(arr,mid+1,r,x);
      }
      else
      {
        return binarysearch(arr,l,mid-1,x);
      }
    }
    return -1;
    
  }
  
}
class Main {
  
  public static void main(String[] args) {
    BinarySearch bin=new BinarySearch();
    int arr[]={2,4,6,12,56,244,897};
    int l=0;
    int r=arr.length;
    r--;
    System.out.println(bin.binarysearch(arr,l,r,12));
  }
}
