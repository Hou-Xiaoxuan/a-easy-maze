#ifndef _HHEAD_DOCUMENTH_
#include"head_document.h"
#endif // !_Hͷ�ļ�H_
/*#include"map_create.cpp" 
#include"move.cpp"
#include"print_map.cpp"*/
bool Map[1000][1000];
typedef pair<int, int> P;

void creat_map(bool(*Map)[1000], int N, int M);//����N*M���Թ���ʹ��prim����
P find_end(bool(*Map)[1000], int M, int N);//Ѱ���յ�
void print(bool(*Map)[1000], P st, P ed, int N, int M);//��ӡ��ͼ
int move(bool(*Map)[1000], P& st);
void help(bool(*Map)[1000], P st, P ed, int N, int M);//��������
int main()
{
	int n, m;
	n = 30, m = 50;
	creat_map(Map,n,m);
	P st = make_pair(1, 1);
	P ed = find_end(Map, n, m);
	print(Map, st, ed, n, m);
	while (st != ed) { 
		int k=move(Map, st);
		if (k == 1) help(Map, st, ed, n, m);
		print(Map, st, ed, n, m);
	}
	cout << "You Win!!\n";
	getch();
	return 0;
}
