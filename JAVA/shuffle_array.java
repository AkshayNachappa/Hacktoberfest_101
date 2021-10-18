class shuffle_array{
    public static void main(String[] args){
    int[] nums={2,5,1,3,4,7};
    int n=3;
    int[] ans= shuffle(nums,n);
    for(int j=0;j<2*n;j++){
    System.out.print(ans[j]+" ");}
  }
  static int[] shuffle(int[] nums,int n){
    int[] ans= new int[2*n];
    int g=0;
    for(int i=0;i<2*n;i++){
      if(i%2==0){
        ans[i] = nums[g++];}
      else{ ans[i]=nums[g+n-1];}
    }
    return ans;
  }
}
