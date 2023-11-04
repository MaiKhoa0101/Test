#include<iostream>

using namespace std;

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void merge(int arr[], int l, int m, int r) {
    int i = l;
    int u = m + 1;
    while (i < m + 1 && u < r) {
        if (arr[i] >= arr[u]) {
            int temp = arr[u];
            for (int b = u; b > i; b--) {
                arr[b] = arr[b - 1];
            }
            arr[i] = temp;
            i++;
        }
        else {
            u++;
        }
    }
}
void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int mid = (l + (r - 1)) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

void Insertion_sort(int a[], int n) {
    int pos,x;
    for (int i = 1; i < n; i++) {
        pos = i - 1;
        if (a[pos] > a[i]) {
            x = a[i];
            a[i] = a[pos];
            while (a[pos] > x && pos>=0) {
                a[pos+1]=a[pos];
                pos--;
            }
            a[pos + 1] = x;
        }
    }
}

void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n; j > i; j--) {
            if (a[j] < a[j - 1]) {
                int temp = a[j-1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void quick_sort(int a[], int left, int right) {
    int x = a[(left + right) / 2];
    int i = left, j=right;

    do {
        while (a[i] < x) {
            i++;
        }
        while (a[j] > x) {
            j--;
        }
        if (i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
        printArray(a, 8);
    } while (i<j);

    if (left < j) {
        quick_sort(a, left, j);
    }
    if (right > i) {
        quick_sort(a, i, right);
    }
}

void heapify(int a[],int n,int indx) {
    int max = 0;
    for (int i = 0; i <= n; i++) {
        if (a[i] > a[max]) {
            max = i;
        }
    }
    if (a[max] != a[0]) {
        int temp = a[max];
        a[max] = a[0];
        a[0] = temp;
    }
}
void swap(int a[], int n, int indx) {
    int temp = a[0];
    a[0] = a[n];
    a[n] = temp;

}

void heap_sort(int a[], int n, int indx) {
    int i = indx * 2 + 1;
    int j = indx * 2 + 2;
    heapify(a,n,indx);
    swap(a,n,indx);
    n--;
    printArray(a, 8);
    if (n > 1) {
        heap_sort(a, n, indx);
    }
}

void ShellSort(int a[], int n) {
    int i, j, x, khoanginterval = 1;
    while (khoanginterval <= n / 3)
        khoanginterval = khoanginterval * 3 + 1;
    while (khoanginterval > 0) {
        for (i = khoanginterval; i < n; i++) {
            x = a[i];
            j = i - khoanginterval;
            printArray(a, n);
            while ((x < a[j]) && (j >= 0)) {
                a[j + khoanginterval] = a[j];
                j = j - khoanginterval;
                printArray(a, n);
            }
            a[j + khoanginterval] = x;
            printArray(a, n);
        }
        khoanginterval = (khoanginterval - 1) / 3;
        printArray(a, n);
    }
}







int a[100001] = { 5,1,6,8,3,9,0,11,14,10,15 };
int main() {
    int n=11;

    printArray(a, n);
    cout << endl << "Heap sort:" << endl;
    ShellSort(a, n);
    //heap_sort(a, n - 1,0);
    /*
    * cout << endl<<"Insertion sort:"<<endl;
    Insertion_sort(a, n);

    cout << endl<<"Bubble sort:"<<endl;
    bubble_sort(a, n - 1);

    cout << endl<<"Merge sort:"<<endl;
    mergeSort(a, 0, n - 1);

    cout << endl << "Quick sort:" << endl;
    quick_sort(a, 0, n - 1);
    */

    printArray(a, n);
    cout << endl<<endl;

    /*
    mergeSort(a, 0, n - 1);
    */


    return 0;
}
