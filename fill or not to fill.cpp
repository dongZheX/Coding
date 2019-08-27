#include<stdio.h>
#include<algorithm>
using namespace std;
struct oa {
	double oil;
	double distance;
	bool operator < (const struct oa & A)const {
		return distance < A.distance;
	}
}oas[2000];
int main() {
	double maxo, dis, cdis;
	int n;
	int i, j;
	while (scanf("%lf%lf%lf%d", &maxo, &dis, &cdis, &n) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%lf%lf", &oas[i].oil, &oas[i].distance);
		}
		sort(oas, oas + n);
		if (oas[0].distance != 0) {
			printf("The maximum travel distance = %.2lf\n", 0);
		}
		if (dis == 0) {
			printf("0.0\n");
		}
		bool isArr = false;
		int cur = 0;
		double curOil = 0;
		double maxdis = maxo * cdis;
		double res = 0;		
		while (!isArr)
		{
			float min = 200000;
			int minNode;
			bool tag = false;;
			bool haveCheaper = false;
			for (i = cur+1;i < n;i++) 
			{
				if (maxdis >= (oas[i].distance - oas[cur].distance)) {
					tag = true;
					if (oas[i].oil < oas[cur].oil) {
						haveCheaper = true;
						res += ((oas[i].distance - oas[cur].distance) / cdis - curOil)*oas[cur].oil;
						curOil = 0;
						cur = i;
						break;
					}
					else if (oas[i].oil < min)
					{
						min = oas[i].oil;
						minNode = i;
					}
				}
				else
					break;
			}
			if (!haveCheaper && (maxdis >= (dis - oas[cur].distance))) {
				res += ((dis - oas[cur].distance) / cdis - curOil)*oas[cur].oil;
				printf("%.2lf\n", res);
				break;
			}
			if (tag && !haveCheaper) {
				res += (maxo - curOil)*oas[cur].oil;
				curOil = maxo - (oas[minNode].distance - oas[cur].distance) / cdis;
				cur = minNode;
			}
			else if (!tag) {
				printf("The maximum travel distance = %.2lf\n", oas[cur].distance + maxdis);
				break;
			}
		}
	}
}