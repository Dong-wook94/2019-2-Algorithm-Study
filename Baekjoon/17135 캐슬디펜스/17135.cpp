#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>

typedef struct Enemy {

	int row;
	int col;
	int distance;
	int choice;

	Enemy(){}
	Enemy(int r, int c) {
		row = r;
		col = c;
	}
}Enemy;

int row_size;
int col_size;
int attack_range;
int max_kill=0;
using namespace std;


int row_dir = {};
int row_col = {};
bool cmp(Enemy e1, Enemy e2);
int Game(int Map[][16], vector<Enemy> enemys, vector<int> Archer_pos);
void combination(int map[][16], vector<Enemy> enemys);
int main() {
	vector<Enemy> enemys;
	int Map[16][16];
	cin >> row_size>>col_size>>attack_range;

	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < col_size; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 1) {
				enemys.push_back(Enemy(i,j));
				enemys[enemys.size() - 1].choice = 0;
			}
		}
	}
	combination(Map, enemys);
}

bool cmp(Enemy e1, Enemy e2) {
	if (e1.distance == e2.distance)
		return e1.col < e2.col;
	return e1.distance < e2.distance;
}
int Game(int Map[][16], vector<Enemy> enemys,vector<int> Archer_pos) {
	int kill = 0;
	int castle_line = row_size;
	//for (int i = 0; i < enemys.size(); i++)//�ߺ������ ���� üũ���� �ʱ�ȭ
	//	enemys[i].choice = 0;
	while (1) {
		
		if ( enemys.size()<= 0)//��������
			break;
		
		for (int i = 0; i < col_size; i++) {//�ü����� ���� ������ ����
			if (Archer_pos[i] == 1) {//�ü��� �ִ°�
				for (int j = 0; j < enemys.size(); j++) {//�� �Ÿ����ϱ�
					enemys[j].distance = abs(castle_line - enemys[j].row) + abs(i - enemys[j].col);				
				}
				sort(enemys.begin(), enemys.end(), cmp);
				if(enemys[0].distance<=attack_range)
					enemys[0].choice = 1;
			}
		}
		for (vector<Enemy>::iterator iter = enemys.begin(); iter != enemys.end();) {
			if (iter->choice == 1) {
				iter = enemys.erase(iter);
				kill++;
			}
			else if (iter->choice == 0 && iter->row == castle_line - 1) {//t���̶� ����
				iter = enemys.erase(iter);
			}
			else {
				iter++;
			}
		}
		castle_line--;
	}
	return kill;
}
//3��̸��� ȣ������ ����ó������
void combination(int map[][16], vector<Enemy> enemys) {//������ ����Ͽ� ��� ��ġ�� �ٵ����� 3���̻��϶��� ���ư����ϱ�
	vector<int> Archer_pos;
	for (int i = 0; i < 3; i++) {
		Archer_pos.push_back(1);
	}
	for (int i = 0; i < (col_size - 3); i++) {
		Archer_pos.push_back(0);
	}
	sort(Archer_pos.begin(), Archer_pos.end());
	do {
		//�ü���ġ���� ��������
		max_kill=max(max_kill,Game(map, enemys,Archer_pos));
		
	} while (next_permutation(Archer_pos.begin(), Archer_pos.end()));

	printf("%d\n", max_kill);
	return;
}