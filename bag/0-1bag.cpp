#include <iostream>
#include <algorithm>
using namespace std;

struct bag{
	int v;//��ֵ
	int w;//���
}list[1001];

int dp[1001][1001];

int main(void){
	int V, N;//���������Ʒ����
	cin >> V >> N;
	for (int i = 0; i < N; ++i){
		cin >> list[i].w >> list[i].v;
	}
	//��û����Ʒʱ�ļ�ֵ��Ϊ0
	for (int i = 0; i <= V; ++i){
		dp[0][i] = 0;
	}

	for (int i = 1; i <= N; ++i){
		for (int j = list[i].w; j <= V; ++j){
			dp[i][j] = max(dp[i - 1][j] + list[i].v, dp[i - 1][j]);
		}
	}
	cout <<"����ֵΪ��" << dp[N][V] << endl;

	return 0;
}