 #include<stdio.h>

int main()
{

int nums[] = {10,1,10,10,10};
int numsSize = 5;

 int l = 0;
    int r = numsSize - 1;
    
    while(l<r)
    {
        int mid = (l+r)/2;
        
        if(nums[mid] == nums[r])
            r = r-1;
        else if(nums[mid] > nums[r])
            l = mid+1;
        else
        {
            r = mid;
        }
    }
    printf("%d ", nums[r]);

}