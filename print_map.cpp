#ifndef _HHEAD_DOCUMENTH_
#include"head_document.h"
#endif // !_Hͷ�ļ�H_
static int dx[] = { 0,-1,0,1,0 };
static int dy[] = { 0,0,1,0,-1 };
typedef pair<int, int> P;
void print(bool (*Map)[1000],P st, P ed,int N,int M)
{
	system("cls");
	cout << "˫��h������ʾ��ʾŶ��\n";
	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= M + 1; j++)
		{
			if (st.first == i and st.second == j) {
				cout << "��";
				continue;
			}
			if (ed.first == i and ed.second == j) {
				cout << "��";
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
	printf("����ʾ����\n");
	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= M + 1; j++)
		{
			if (st.first == i and st.second == j) {
				cout << "��";
				continue;
			}
			if (ed.first == i and ed.second == j) {
				cout << "��";
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