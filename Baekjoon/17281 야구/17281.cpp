#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n_inning;
int Select[10];
int score[51][10];
int order[10];
vector<int> perm;
int base[5];
int total_score=0;
int max_score = -1;

void advance();
void Game();
void permutation(int cnt);
int main() {

	//freopen("input.txt", "r", stdin);
	scanf("%d", &n_inning);
	for (int i = 1; i <=n_inning; i++) {
		for (int j = 1; j <=9; j++) {
			scanf("%d", &score[i][j]);
		}
	}
	Select[4] = 1;
	order[4] = 1;
	permutation(2);
	printf("%d\n", max_score);
	
}
void advance() {
	for (int i = 3; i >= 0; i--) {
		base[i + 1] = base[i];
	}
	if (base[4] == 1) {
		base[4] = 0;
		total_score++;
	}
	base[0] = 0;
}
void Game() {
	int inning = 1;
	int out_cnt = 0;
	int play_order = 1;
	memset(base, 0, sizeof(base));
	while (1) {
		//printf("%3d�̴� %3d �ƿ� ��������(%3d) %3d��Ÿ�� (���ȣ%3d):",inning,out_cnt,total_score, play_order, order[play_order], score[inning][order[play_order]]);
		if (inning > 9) {
			//��������
		//	printf("score : %d\n", total_score);
			return;
		}
		int player_score = score[inning][order[play_order]];
		if (player_score == 0) {
		//	printf("�ƿ�\n");
			out_cnt++;

		}
		else if (player_score == 1) {
			base[0] = 1;//���̽��� ����Ѹ����
			advance();
		}
		else if (player_score == 2) {
			base[0] = 1;//���̽��� ����Ѹ����
			advance();
			advance();
		}
		else if (player_score == 3) {
			base[0] = 1;//���̽��� ����Ѹ����
			advance();
			advance();
			advance();
		}
		else {
			base[0] = 1;
			advance();
			advance();
			advance();
			advance();
		}

		////	printf("%d��Ÿ\n", score[inning][order[play_order]]);
		//	base[0] = 1;//���̽��� ����Ѹ����
		//	for (int i = 0; i < player_score; i++) {
		//		//����
		//	}
		//	//base[score[inning][order[play_order]]] = 1;
		//}
		if (out_cnt == 3) {//�����ƿ�.
			out_cnt = 0;
			inning++;
			memset(base, 0, sizeof(base));
		}
		play_order = play_order % 9 + 1;//��������

	}

}
void permutation(int cnt) {
	if (cnt == 10) {
		total_score = 0;
		Game();
		max_score = max(max_score, total_score);
		return;
	}
	for (int i = 1; i < 10; i++) {
		if (Select[i] == 1)
			continue;
		Select[i] = 1;
		order[i] = cnt;
		permutation(cnt + 1);
		Select[i] = 0;
	}
}