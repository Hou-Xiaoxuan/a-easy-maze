#ifndef _HHEAD_DOCUMENTH_
#include"head_document.h"
#endif // !_H头文件H_

typedef pair<int, int> P;
static int dx[] = { 0,1,-1,0,0 };
static int dy[] = { 0,0,0,1,-1 };
list<P> que;

void creat_map(bool (*Map)[1000],int N,int M)//生成N*M的迷宫，使用prim方法
{
	memset(Map, 0, sizeof(Map));
	Map[1][1] = true;//默认起点是1，1；
	que.push_back(make_pair(1, 2));
	//que.push(make_pair(N - 1, M));
	que.push_back(make_pair(2, 1));
	//que.push(make_pair(1, 2));//先将起点下边和右边入列
	while (!que.empty())
	{
		srand((int)time(0));
		list<P>::iterator s;
		s = que.begin();
		int n = rand() % que.size();
		while (n--) s++;
		int flag = 0;
		
		for (int i = 1; i <= 4; i++)
			if ((*s).first + dx[i] >= 1 and (*s).first + dx[i] <= N)//x不越界
				if ((*s).second + dy[i] >= 1 and (*s).second + dy[i] <= M)//y不越界
					if (Map[(*s).first + dx[i]][(*s).second + dy[i]] == true)  flag++;
		if (flag <= 1)
		{
			Map[(*s).first][(*s).second] = true;//把这里打通
			for (int i = 1; i <= 4; i++)
				if ((*s).first + dx[i] >= 1 and (*s).first + dx[i] <= N)//x不越界
					if ((*s).second + dy[i] >= 1 and (*s).second + dy[i] <= M)//y不越界
						if (Map[(*s).first + dx[i]][(*s).second + dy[i]] == false)//是墙的话
							que.push_back(make_pair((*s).first + dx[i], (*s).second + dy[i]));//放入队列
		}
		que.erase(s);
	}
}
queue <P> qu;
P find_end(bool (*Map)[1000],int M,int N)//找一个终点
{
	P a = make_pair(M, N);
	qu.push(a);
	while (1)
	{
		P s = qu.front();
		if (Map[s.first][s.second] == true) return s;
		else{
			qu.push(make_pair(s.first - 1, s.second));
			qu.push(make_pair(s.first, s.second - 1));
		}
		qu.pop();
	}
}
