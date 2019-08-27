#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef struct Student {
	char id[10];
	char name[20];
	char sex[3];
	int val;
}stu;
bool cmp(stu a, stu b) {
	return strcmp(a.id, b.id)<0?true:false;
}
int main() {
	int n;
	int m;
	char key[5];
	scanf("%d", &n);
	stu stus[1001];
	for(int i = 0;i<n;i++) {
		scanf("%s%s%s%d", stus[i].id, stus[i].name, stus[i].sex, &stus[i].val);
	}
	sort(stus, stus + n, cmp);
	scanf("%d", &m);
	while (m--) {
		scanf("%s", key);
		int low = 0, high = n - 1;
		int mid;
		while (low <= high) {
			mid = (low + high) / 2;
			if (strcmp(stus[mid].id, key) == 0) {
				printf("%s %s %s %d\n", stus[mid].id, stus[mid].name, stus[mid].sex, stus[mid].val);
				break;
			}
			else if (strcmp(stus[mid].id, key) < 0) {
				low = mid + 1;
			}
			else if (strcmp(stus[mid].id, key) > 0) {
				high = high - 1;
			}
		}
		if (m < 0)
			printf("No Answer!");
	}
	
	
}