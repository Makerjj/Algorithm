#include <iostream>
#include <algorithm>
using namespace std;

struct bag{
	int v;//价值
	int w;//体积
}list[1001];

int dp[1001][1001];

int main(void){
	int V, N;//总体积和物品个数
	cin >> V >> N;
	for (int i = 0; i < N; ++i){
		cin >> list[i].w >> list[i].v;
	}
	//将没有物品时的价值设为0
	for (int i = 0; i <= V; ++i){
		dp[0][i] = 0;
	}

	for (int i = 1; i <= N; ++i){
		for (int j = list[i].w; j <= V; ++j){
			dp[i][j] = max(dp[i - 1][j] + list[i].v, dp[i - 1][j]);
		}
	}
	cout <<"最大价值为：" << dp[N][V] << endl;

	return 0;
}