#ifndef _HHEAD_DOCUMENTH_
#include"head_document.h"
#endif // !_Hͷ�ļ�H_

typedef pair<int, int> P;
static int dx[] = { 0,1,-1,0,0 };
static int dy[] = { 0,0,0,1,-1 };
list<P> que;

void creat_map(bool (*Map)[1000],int N,int M)//����N*M���Թ���ʹ��prim����
{
	memset(Map, 0, sizeof(Map));
	Map[1][1] = true;//Ĭ�������1��1��
	que.push_back(make_pair(1, 2));
	//que.push(make_pair(N - 1, M));
	que.push_back(make_pair(2, 1));
	//que.push(make_pair(1, 2));//�Ƚ�����±ߺ��ұ�����
	while (!que.empty())
	{
		srand((int)time(0));
		list<P>::iterator s;
		s = que.begin();
		int n = rand() % que.size();
		while (n--) s++;
		int flag = 0;
		
		for (int i = 1; i <= 4; i++)
			if ((*s).first + dx[i] >= 1 and (*s).first + dx[i] <= N)//x��Խ��
				if ((*s).second + dy[i] >= 1 and (*s).second + dy[i] <= M)//y��Խ��
					if (Map[(*s).first + dx[i]][(*s).second + dy[i]] == true)  flag++;
		if (flag <= 1)
		{
			Map[(*s).first][(*s).second] = true;//�������ͨ
			for (int i = 1; i <= 4; i++)
				if ((*s).first + dx[i] >= 1 and (*s).first + dx[i] <= N)//x��Խ��
					if ((*s).second + dy[i] >= 1 and (*s).second + dy[i] <= M)//y��Խ��
						if (Map[(*s).first + dx[i]][(*s).second + dy[i]] == false)//��ǽ�Ļ�
							que.push_back(make_pair((*s).first + dx[i], (*s).second + dy[i]));//�������
		}
		que.erase(s);
	}
}
queue <P> qu;
P find_end(bool (*Map)[1000],int M,int N)//��һ���յ�
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
