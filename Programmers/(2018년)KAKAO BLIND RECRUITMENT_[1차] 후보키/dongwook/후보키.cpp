#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int countBits(int n) {
	int ret = 0;
	while (n) {
		if (n & 1) {
			ret++;
			n = n >> 1;//���������� �о� ��Ʈ�� �ϳ��� ����
		}
	}
	return ret;
}

bool cmp(int a, int b) {
	int x = countBits(a), y = countBits(b);
	return x > y;
}

bool check(vector<vector<string>> relation, int rowsize, int colsize, int subset) {
	for (int a = 0; a < rowsize - 1; a++) {
		for (int b = a + 1; b < rowsize; b++) {
			bool isSame = true;
			for (int k = 0; k < colsize; k++) {
				if ((subset & 1 << k) == 0) continue;
				if (relation[a][k] != relation[b][k]) {//���������� false
					isSame = false;
					break;
				}
			}
			if (isSame) {//�ϳ��� �ٸ��� ������ ->���ϼ��� �������� ����
				return false;
			}
		}
	}
	//2������ �ٵ��� ���ϼ� ������
	return true;
}

int solution(vector<vector<string>> relation) {
	int answer = 0;
	vector<int> candidates;

	for (int i = 1; i < (1 << relation[0].size()); i++) {
		if (check(relation, relation.size(), relation[0].size(), i)) {
			candidates.push_back(i);
		}
	}
	sort(candidates.begin(), candidates.end(), cmp);

	while (!candidates.empty()) {//candidates ���ִ°� ���ϼ��� �����ϴ� �͵�
		int n = candidates.back();//������������ ���� ���� ������

		candidates.pop_back();
		answer++;
		for (vector<int>::iterator it = candidates.begin(); it != candidates.end();) {
			if ((n & *it) == n)
				it = candidates.erase(it);
			else
				it++;
		}
	}

	return answer;
}

int main() {
	vector<vector<string>> input = { {"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"} };
	printf("%d\n", solution(input));
}