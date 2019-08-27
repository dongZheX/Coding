#include<algorithm>
#include<set>
using namespace std;
int main() {
	int n;
	set<int> s;
	int i;
	scanf("%d", &n);
	for (i = 0;i<n;i++) {
		int temp;
		scanf("%d", &temp);
		s.insert(temp);
	}
	set<int>::iterator iter = s.begin();
	//×Ô¶¯ÅÅĞò
	while (iter != s.end()) {
		printf("%d\n", *iter);
		iter++;
	}
}