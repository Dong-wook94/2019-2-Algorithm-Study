# [백준] 17140 이차원 배열과 연산

> 삼성알고리즘 기출문제

실제 시험장에서 풀었던 문제이다.
실제 시험장에서는 stable_sort를 두번 이용한 radix_sort 를 사용하였는데 
이번에는 pair클래스를 이용하여 sort한번으로 이용하였다.

진행과정은 다음과같다.
1. 각행에서 존재하는 숫자의 갯수를 센다.
2. 카운트한 pair<숫자개수, 숫자>로 이루어진 vector에 넣기.
3. Sort 후 차례로 map에 입력.
4. max_row or max_col 갱신 


## pair 클래스 정리
* pair클래스는 stl에서 데이터 쌍을 표현할때 사용.
* pair<[type1],[type2]> p : 사용할 데이터 타입 1,2를 넣고 그타입의 pair 
클래스인 p를 만든다.
* p.first : 첫번째 인자를 반환해 준다.
* p.second : p의 두번째 인자를 반환해 준다.
* make_pair(변수1,변수2) : 변수1과 변수2가 들어간 pair를 만들어줍니다.
* sort를 알고르즘에 의해 정렬이 가능하다. : 대소 비교및 sort에의한 
정렬에서 첫번째 인자 기준, 전번째가 같으면 두번째인자로 판단.


