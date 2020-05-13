#ifndef _HHEAD_DOCUMENTH_
#include"head_document.h"
#endif // !_H头文件H_
static int dx[] = { 0,-1,0,1,0 };
static int dy[] = { 0,0,1,0,-1 };
typedef pair<int, int> P;
void print(bool (*Map)[1000],P st, P ed,int N,int M)
{
	system("cls");
	cout << "双击h可以显示提示哦。\n";
	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= M + 1; j++)
		{
			if (st.first == i and st.second == j) {
				cout << "个";
				continue;
			}
			if (ed.first == i and ed.second == j) {
				cout << "终";
				continue;
			}
			if (Map[i][j] == true)  cout << "  ";
			else printf("%c%c", 0xa8, 0x80);
		}
		cout << endl;
	}


}
void print(int(*answer)[1000], P st, P ed, int N, int M)
{
	system("cls");
	printf("答案显示三秒\n");
	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= M + 1; j++)
		{
			if (st.first == i and st.second == j) {
				cout << "个";
				continue;
			}
			if (ed.first == i and ed.second == j) {
				cout << "终";
				continue;
			}
			if (answer[i][j] == 0)  cout << "  ";
			else if (answer[i][j] == 1)printf("%c%c", 0xa8, 0x80);
			else if (answer[i][j] == 2)printf("%2c",'*');
		}
		cout << endl;
	}
	Sleep(3000);
	system("cls");
}