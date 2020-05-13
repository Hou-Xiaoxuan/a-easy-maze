#ifndef _HHEAD_DOCUMENTH_
#include"head_document.h"
#endif // !_H头文件H_

//深搜找答案
int answer[1000][1000] = {0};
bool vis[1000][1000];
typedef pair<int, int> P;
static int dx[] = { 0,-1,0,1,0 };
static int dy[] = { 0,0,1,0,-1 };
void print(int(*answer)[1000], P st, P ed, int N, int M);//打印答案
stack <pair<int, int> > sta;
bool dfs(P ed, int N, int M)
{
	P s = sta.top();
	if (s == ed)
		return true;

	for (int i = 1; i <= 4; i++)
		if (s.first + dx[i] >= 1 and s.first + dx[i] <= N)//x不越界
			if (s.second + dy[i] >= 1 and s.second + dy[i] <= M)//y不越界
				if (vis[s.first + dx[i]][s.second + dy[i]] == false)
				{
					vis[s.first + dx[i]][s.second + dy[i]]=true;
					sta.push( make_pair(s.first + dx[i],s.second + dy[i]) );
					if (dfs(ed, N, M)==true) 
						return true;
					sta.pop();
					vis[s.first + dx[i]][s.second + dy[i]] = false;
				}
	return false;
}
void help(bool(*Map)[1000], P st, P ed, int N, int M)
{
	for (int i = 0; i <=N+1; i++)//拷贝地图 
		for (int j = 0; j <= M + 1; j++)
		{
			if (Map[i][j] == true) {
				vis[i][j] = false; answer[i][j] = 0;
			}
			else {
				vis[i][j] = true; answer[i][j] = 1;
			}

		}
	cout << "Map:\n";
	/*for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= M + 1; j++)
		{
			if (Map[i][j] == true) cout << "0 ";
			else cout << "1 ";
		}
		cout << endl;
	}
	cout << "Vis:\n";
	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= M + 1; j++)
		{
			if (vis[i][j] == true) cout << "0 ";
			else cout << "1 ";
		}
		cout << endl;
	}
	cout << "answer:\n";
	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= M + 1; j++)
		{
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}
	*/
	sta.push(st);
	dfs(ed, N, M);
	while(!sta.empty()) {
		P s = sta.top();
		answer[s.first][s.second] = 2;
		sta.pop();
	}
	print(answer, st, ed, N, M);
}

