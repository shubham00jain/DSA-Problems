/*
Some ways to do this:
1. brute force. Check elements in 2 loops -> n^2.
2. if the elements are consecutive then return (sumofarray - sumof(n-1) numbers). -> O(n) Time Constant Space.
3. If array has only 1 duplicate element then do XOR. -> O(n) Time Constant Space
4. Go to the element and change its value to -ve of that element. If you find a -ve value then return that element. -> O(n) and constant space but destroys the array.
5. Use fast and slow pointer method.
*/


//method 3
int findDuplicate(vector<int>& nums) {
  int i;
  int dupe = 0;
  for(i = 0; i < N; i++) {
    dupe = dupe ^ arr[i] ^ i;
 }

}



//method 4
int findDuplicate(vector<int>& nums) {
    int res = 0;
    for(int i=0;i<nums.size();i++){
        if( nums[ abs(nums[i]) ]>0 ){
            nums[abs(nums[i])] = - nums[abs(nums[i])];
        }
        else{
            res = nums[i];
        }
    }
    return abs(res);

}

