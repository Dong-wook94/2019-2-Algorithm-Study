# [D5] 4112 이상한 피라미드 탐험

## 아이디어
상대적으로 피라미드의 높은곳에 있는 지점 기준으로 삼각형이 만들어진다면 
level 만큼 이동하여 탐색이 가능하다. 

각지점을 level 과 index를 통해 표현하여 **level이 index 보다 큰경우 
작은경우** 그리고 이로 확인할수 없는 범위인 경우를 **추가적으로 
고려**하여야 했다.

~~~ c
int search_treasure(int i_pos, int t_pos) {
	int time;
	int level_gap, index_gap;
	if (i_pos < t_pos) { //상대적으로 높은곳을 시작지점으로 잡기위예
		source = get_pos(i_pos);
		destination = get_pos(t_pos);
	}
	else {
		destination = get_pos(i_pos);
		source = get_pos(t_pos);
	}
	level_gap = destination.level - source.level;
	index_gap = abs(source.index - destination.index);
	if (level_gap <= index_gap) {
		time = index_gap;
		if (source.index > destination.index)//예외
			time += (destination.level - source.level);
	}
	else {
		time = level_gap;
		if (source.index > destination.index)//예외
			time += (source.index - destination.index);
	}
	return time;
}
~~~

최초 접근은 BFS를 통한 탐색을 시도하였으나 시간과 메모리를 많이 소모하게 
되어 알고리즘을 변경하여 풀었다.


