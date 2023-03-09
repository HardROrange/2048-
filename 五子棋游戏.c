#include<stdio.h>
#include<stdlib.h>

//��λ��Ϊ0 ����Ϊ1 ����Ϊ2 
void place(void);//���� 
int map[15][15]={};

void black(void);//����ѡ�� 
int x1=0;
int y3=0;
void white(void);//����ѡ�� 
int x2=0;
int y2=0;
int whitefinish(void);//��������
int blackfinish(void); 

int main (void)
{
	while(1)
	{
		place(); 
		white();
		if(whitefinish())
		{
			place();
			printf("����ʤ����\n");
			return 0; 
		}
		place();
		black();
		if(blackfinish())
		{
			place();
			printf("����ʤ����\n");
			return 0; 
		}	
	}
}

void place(void)
{
	system("cls");
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			if(0==map[i][j])
			 {
				printf("* ");
			 }
			 if(1==map[i][j])
			 {
				printf("@ ");
			 }
			 if(2==map[i][j])
			 {
				printf("$ ");
			 }
		}
		printf("\n");
	}
}

void black(void)
{
	int flag = 1;
	printf("���������\n");
	while(flag)
	{
		scanf("%d%d",&x1,&y3);//��������λ��
		if(x1>15||y3>15||(2==map[x1-1][y3-1])||(3==map[x1-1][y3-1]))
		{
			printf("�����ӵ�λ�÷Ƿ�������������\n");
			flag = 1; 
		}
		else
		{
			map[x1-1][y3-1]=1;
			flag = 0;
		}
	}
}

void white(void)
{
	int flag = 1;
	printf("���������\n");
	while(flag)
	{
		scanf("%d%d",&x2,&y2);//��������λ��
		if(x2>15||y2>15||(3==map[x2-1][y2-1])||(2==map[x2-1][y2-1]))
		{
			printf("�����ӵ�λ�÷Ƿ�������������\n");
			flag = 1; 
		}
		else
		{
			map[x2-1][y2-1]=2;
			flag = 0;
		}
	}
}

int whitefinish(void)
{
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<11;j++)//�������� 
		{
			if(map[i][j]==map[i][j+1]&&map[i][j]==map[i][j+2]&&map[i][j]==map[i][j+3]&&map[i][j]==map[i][j+4]&&map[i][j]==2)
			{
				return 1; 
			}
		} 
	}
	for(int j=0;j<15;j++)
	{
		for(int i=0;i<11;i++)//�������� 
		{
			if( map[i][j]== map[i+1][j]&& map[i+1][j]== map[i+2][j]&& map[i+2][j]== map[i+3][j]&& map[i+3][j]== map[i+4][j]&&map[i][j]==2)
			{
				return 1;
			}
		}
    }
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<11;j++)//����б������ 
		{
			if( map[i][j]== map[i+1][j+1]&& map[i][j]== map[i+2][j+2]&& map[i][j]== map[i+3][j+3]&& map[i+4][j+4]== map[i][j]&&map[i][j]==2)
			{
				return 1;
			}
		}
	}
	for(int i=4;i<15;i++)
	{
		for(int j=4;j<15;j++)//����б������ 
		{
			if( map[i][j]== map[i-1][j-1]&& map[i][j]== map[i-2][j-2]&& map[i][j]== map[i-3][j-3]&& map[i-4][j-4]== map[i][j]&&map[i][j]==2)
			{
				return 1;
			}
		}
	}
	for(int i=0;i<11;i++)
	{
		for(int j=4;j<15;j++)//����б������ 
		{
			if( map[i][j]== map[i+1][j-1]&& map[i][j]== map[i+2][j-2]&& map[i][j]== map[i+3][j-3]&& map[i+4][j-4]== map[i][j]&&map[i][j]==2)
			{
				return 1;
			}
		}
	}
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<11;j++)//����б������ 
		{
			if( map[i][j]== map[i+1][j-1]&& map[i][j]== map[i+2][j-2]&& map[i][j]== map[i+3][j-3]&& map[i][j]== map[i+4][j-4]&&map[i][j]==2)
			{
				return 1; 
			}
		} 
	}
	return 0;	 
}

int blackfinish(void)
{
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<11;j++)//�������� 
		{
			if( map[i][j]== map[i][j+1]&& map[i][j]== map[i][j+2]&& map[i][j]== map[i][j+3]&& map[i][j]== map[i][j+4]&&map[i][j]==1)
			{
				return 1; 
			}
		} 
	}
	for(int j=0;j<15;j++)
	{
		for(int i=0;i<11;i++)//�������� 
		{
			if( map[i][j]== map[i+1][j]&& map[i+1][j]== map[i+2][j]&& map[i+2][j]== map[i+3][j]&& map[i+3][j]== map[i+4][j]&&map[i][j]==1)
			{
				return 1;
			}
		}
    }
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<11;j++)//����б������ 
		{
			if( map[i][j]== map[i+1][j+1]&& map[i][j]== map[i+2][j+2]&& map[i][j]== map[i+3][j+3]&& map[i+4][j+4]== map[i][j]&&map[i][j]==1)
			{
				return 1;
			}
		}
	}
	for(int i=4;i<15;i++)
	{
		for(int j=4;j<15;j++)//����б������ 
		{
			if( map[i][j]== map[i-1][j-1]&& map[i][j]== map[i-2][j-2]&& map[i][j]== map[i-3][j-3]&& map[i-4][j-4]== map[i][j]&&map[i][j]==1)
			{
				return 1;
			}
		}
	}
	for(int i=0;i<11;i++)
	{
		for(int j=4;j<15;j++)//����б������ 
		{
			if( map[i][j]== map[i+1][j-1]&& map[i][j]== map[i+2][j-2]&& map[i][j]== map[i+3][j-3]&& map[i+4][j-4]== map[i][j]&&map[i][j]==1)
			{
				return 1;
			}
		}
	}
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<11;j++)//����б������ 
		{
			if( map[i][j]== map[i+1][j-1]&& map[i][j]== map[i+2][j-2]&& map[i][j]== map[i+3][j-3]&& map[i][j]== map[i+4][j-4]&&map[i][j]==1)
			{
				return 1; 
			}
		} 
	}
	return 0;	 
}









