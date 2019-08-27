#include<stdio.h>
#include<algorithm>
using namespace std;
int bina_search(int a[], int, int);
int main() {
	int a[1000];
	int n;
	int x;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		scanf("%d", &x);
		printf("%d\n", lower_bound(a,a+n,x)-a);
	}
	
}
int bina_search(int a[], int key,int n) {
	int low = 0, high = n - 1;
	int mid;
	while (low <= high) {
		
		mid =  (low + high) / 2;
		if (a[mid] == key)
		{
			return mid+1;
		}
		if (a[mid] > key) {
			high = mid - 1;		
		}
		if(a[mid] < key)
		{
			low = mid + 1;
		}
	}
	return -1;
}