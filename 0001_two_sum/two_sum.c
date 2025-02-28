#include <stdio.h>
#include <stdlib.h>


struct object {
    int val;
    int index;
};//定义一个结构体

static int compare(const void *a, const void *b)
{
    return ((struct object *) a)->val - ((struct object *) b)->val;
}//定义比较函数

int * twosum(int *nums, int numsSize, int target, int *returnSize)
{
    int i, j;
    struct object *objs = (object*)malloc(numsSize * sizeof(*objs));//malloc返回值是int型
    for (i = 0; i < numsSize; i++) {
        objs[i].val = nums[i];
        objs[i].index = i;
    }
    qsort(objs, numsSize, sizeof(*objs), compare);//排序之后，只按照数组中值的大小排序，val和index值跟着变
    for (i = 0; i < numsSize; i++) {
        printf("objs[i].val = %d\n",objs[i].val);
        printf("objs[i].index = %d\n",objs[i].index);
    }
    int *results = (int*)malloc(2 * sizeof(int));
    i = 0;
    j = numsSize - 1;
    while (i < j) {
        int sum = objs[i].val + objs[j].val;
        if (sum < target) {
            i++;
        } else if (sum > target) {
            j--;
        } else {
            results[0] = objs[i].index;
            results[1] = objs[j].index;
            *returnSize = 2;
            return results;
        }
    }
    return NULL;
}

int main(void)
{
    //int nums[] = {-1, -2, -3, -4, -5};
    //int target = -8;
    //int nums[] = {0,4,3,0};
    //int target = 0;
    int nums[] = { 3, 2, 3 };
    int size = sizeof(nums) / sizeof(*nums);
    int target = 6;
    int count = 0;
    int *indexes = twosum(nums, size, target, &count);
    if (indexes != NULL) {
        printf("%d %d\n", indexes[0], indexes[1]);
    } else {
        printf("Not found\n");
    }

    return 0;
}
