#include <stdio.h>

#define ARRAY_SIZE 100

void DeleteGivenValue(int *arr, int size, int v) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != v) {
            arr[j] = arr[i];
            j++;
        }
    }
    // 填充剩余的元素为0，表示删除了元素
    for (int i = j; i < size; i++) {
        arr[i] = 0;
    }
}

int main() {
    int arr[ARRAY_SIZE];
    int size = ARRAY_SIZE;
    
    // 初始化数组
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    
    // 在数组中插入一些需要删除的值
    arr[10] = 5;
    arr[20] = 5;
    arr[30] = 5;
    
    // 调用函数删除值为5的元素
    DeleteGivenValue(arr, size, 5);
    
    // 打印修改后的数组
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    
    return 0;
}
