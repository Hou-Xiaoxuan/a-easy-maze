#ifndef _HHEAD_DOCUMENTH_
#include"head_document.h"
#endif // !_Hͷ�ļ�H_
//#include"map_create.cpp"
static int dx[] = { 0,-1,0,1,0 };
static int dy[] = { 0,0,1,0,-1 };
typedef pair<int, int> P;
int move(bool (*Map)[1000],P& st)
{
	bool flag = false;
	while (!flag) 
	{
		int direction=0;
		if (getch() == 224)//�ɼ��̿��Ʒ���
			switch (getch())
			{
			case 72:
				direction = 1;
				break;
			case 77:
				direction = 2;
				break;
			case 80:
				direction = 3;
				break;
			case 75:
				direction = 4;
				break;
			}
		else if (getch() == 'h')
			return 1;
		if (direction == 0) {
			while (_kbhit())//������������룬��գ�
			{
				getch();//�������
			}
			cout << " invalid!\n";
			continue;
		}
		//��ʽ��ʼ���ߣ�
		if (Map[st.first + dx[direction]][st.second + dy[direction]] == false) {
			while (_kbhit())//������������룬��գ�
			{
				getch();//�������
			}
			//cout << " can't move!";
			continue;
		}
		else 
		{
			st = make_pair(st.first + dx[direction], st.second + dy[direction]);
			return 0;
		}
	}
}