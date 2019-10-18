#include <stdio.h>
#include <algorithm>

using namespace std;

int D, W, K;//�β�, ���α���, �԰ݱ���


int result;
int min_cnt;
int visited[15];
int film[14][21];
//��ǰ�� �����ϴ� ����츦 ����Ѵ� -> 
bool check() {
	for (int i = 0; i < W; i++) {
		bool flag1 = false;//col�� üũ
		for (int j = 0; j <= D - K; j++) {
			int cnt = 0;
			for (int p = j; p < j + K; p++) {//�հݱ��� ������ŭ ������
				if (film[j][i] != film[p][i]) {//3�� üũ�ϴٰ� �ٸ���
					break;
				}
				cnt++;
			}
			if (cnt==K) {//3���� ������
				flag1 = true;
				break;
			}
		}
		if (!flag1)//col ���
			return false;
	}
	return true;
}

void dfs(int row,int cnt) {
	int temp[21];
	if (cnt >= result)
		return;
	if (cnt >K || row >D) {
		return;
	}
	if (check()) {//��������
		result = min(result, cnt);
		return;
	}


	for (int i = 0; i < W; i++) {//���������س���
		temp[i] = film[row][i];
	}
	for (int c = 0; c < W; c++) {
		film[row][c] = 0;
	}
	dfs(row + 1, cnt + 1);
	for (int c = 0; c < W; c++) {
		film[row][c] = 1;
	}
	dfs(row + 1, cnt + 1);

	for (int i = 0; i < W; i++) {//�ǵ�����
		film[row][i] = temp[i];
	}
	dfs(row + 1,cnt);


}

void Testcase() {

	scanf("%d %d %d", &D, &W, &K);
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &film[i][j]);
		}
	}

	for (int i = 0; i < D; i++)
		visited[i] = 0;
	dfs(0,0);


}

int main() {
	int testcase;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int i = 1; i <= testcase; i++) {
		result = 15;
		Testcase();
		printf("#%d %d\n", i, result);
	}
}