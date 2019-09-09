#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<set>
#include<vector>

#define MAX_N 5000005
using namespace std;

int first[10000], second[10000];
int v[MAX_N];

int main() {
	int n; scanf("%d", &n);
	set<int> key;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		key.insert(v[i]);
	}
	int num = key.size();
	//���
	int i = 0, j = 0;
	int count = 0;
    map<int, int> appear;

	while (i <= j && j <= n) {
		//����������
		if (appear.size() == num) {
			//��һ�γ���ȫ�����֣����߳��ֵ����ֵ����������С������
			if (count == 0 || second[count - 1] - first[count - 1] == j - i - 1) {
				//�����Ŵ�1��N
				first[count] = i + 1;
				second[count++] = j;
			}
			//�и�С��������֣����¸�ֵ����
			else if (second[count - 1] - first[count - 1] > j - i - 1) {
				count = 0;
				first[count] = i + 1;
				second[count++] = j;
			}
			//������һ����������i��ǰ�ƶ��������Ѿ����ֵ�map�м�ȥ
			if (appear[v[i]] == 1)
				appear.erase(v[i]);
			else
				appear[v[i]] --;
			i++;
		}
		//û�����룬������������
		else
			appear[v[j++]] ++;
	}

	printf("%d %d\n", second[0] - first[0] + 1, count);
	for (int i = 0; i < count; i++)
		printf("[%d,%d]%c", first[i], second[i], i == count - 1 ? '\n' : ' ');

	return 0;
}