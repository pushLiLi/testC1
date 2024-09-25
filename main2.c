#include <stdio.h>

int arr[100];

void DeleteGivenValue (int *arr,int v) {
    int n = *arr / arr[0];
    int j = 0;
    for (int i = 0; i < n ; i++) {
        if (arr[i] != v) {
            arr[j] = arr[i];
            j++;
        }
    }
}

int main () {

}
