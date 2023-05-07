#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

class material 
{
	int num;
	char name[20];
	double price;
	int quantity;
	char classs[20];
	material* next;
	struct node {
		int input;
		int output;
		char inputtime[10];
		char outputtime[10];
		char ps[20];
		node* next;
	};
	node* hea;
public:
	bool creat(int i, int o, char* intime, char* outtime, char* ps, material* h);
	void print(node* head);
	int print(material* head);
	void shurucha(material* head, int inp, double p);
	void shuchucha(material* head, int outp, int l);
	void shurutime(material* head, char* intime);
	void shuchutime(material* head, char* outtime, int l);
	void ps(material* head, char* ps, int l, int g);
	void print1(material* head, int num);
	void print2(material* head, char* materialname, double gg, double kk);
	void print3(material* head, double p);
	void print4(material* head, char* humanname, double p);
	void print5(material* head, int quantity, int p, int l);
	material* creatlink(material* head);
	int output(material* head);
	void revise(material* head);
	int fprint(material* head);
	int fscan(material* head);
};
bool material::creat(int i, int o, char* intime, char* outtime, char* ps, material* h) {
	node* p = NULL, * f = NULL;
	if (h->hea == NULL)
	{
		p = (node*)malloc(sizeof(node));
		p->input = i;
		p->output = o;
		strcpy(p->inputtime, intime);
		strcpy(p->outputtime, outtime);
		strcpy(p->ps, ps);
		p->next = NULL;
		h->hea = p;
	}
	else
	{
		if (h->quantity + i - o < 0)
		{
			return false;
		}
		for (p = h->hea; p != NULL; f = p, p = p->next)
			;
		p = (node*)malloc(sizeof(node));
		p->input = i;
		p->output = o;
		strcpy(p->inputtime, intime);
		strcpy(p->outputtime, outtime);
		strcpy(p->ps, ps);
		f->next = p;
		p->next = NULL;
	}
	h->quantity = h->quantity + i - o;
	return true;
}//�ڲ�������
void material::print(material::node* head) {
	node* p = NULL;
	for (p = head; p != NULL; p = p->next)
	{
		if (p == head)
		{
			printf("% 6d  % 6d  % 12s % 10s  % 15s\n", p->input, p->output, p->inputtime, p->outputtime, p->ps);
		}
		else
		{
			printf("                                   ");
			printf("% 6d  % 6d  % 12s % 10s  % 15s\n", p->input, p->output, p->inputtime, p->outputtime, p->ps);
		}
	}
}//�ڲ���ӡ
void material::shurucha(material* head, int inp, double p)
{
	material* f = NULL;
	node* q;
	bool flag = true;
	for (f = head; f != NULL; f = f->next)
	{
		for (q = f->hea; q != NULL; q = q->next)
		{
			if (q->input == inp)
			{
				if (flag == true)
				{
					printf("���  ������   ����   ����   ����  �����   ������      ���ʱ       ����ʱ          ��ע\n");
					printf("%d  % 8s  % 4.2f  % 3d  % 7s ", f->num, f->name, f->price, f->quantity, f->classs);
					printf("% 6d  % 6d  % 12s % 10s  % 15s\n", q->input, q->output, q->inputtime, q->outputtime, q->ps);
					flag = false;
				}
				else
				{
					printf("                                   ");
					printf("% 6d  % 6d  % 12s % 10s  % 15s\n", q->input, q->output, q->inputtime, q->outputtime, q->ps);
				}
			}
		}

	}
	if (flag == true)
	{
		printf("�޶�Ӧ������Ϣ\n");
	}
}//����������
void material::shuchucha(material* head, int outp, int l)
{
	material* f = NULL;
	node* q;
	bool flag = true;
	for (f = head; f != NULL; f = f->next)
	{
		for (q = f->hea; q != NULL; q = q->next)
		{
			if (q->output == outp)
			{
				if (flag == true)
				{
					printf("���  ������   ����   ����   ����  �����   ������      ���ʱ       ����ʱ          ��ע\n");
					printf("%d  % 8s  % 4.2f  % 3d  % 7s ", f->num, f->name, f->price, f->quantity, f->classs);
					printf("% 6d  % 6d  % 12s % 10s  % 15s\n", q->input, q->output, q->inputtime, q->outputtime, q->ps);
					flag = false;
				}

				else {
					printf("                                   ");
					printf("% 6d  % 6d  % 12s % 10s  % 15s\n", q->input, q->output, q->inputtime, q->outputtime, q->ps);
				}
			}
		}

	}
	if (flag == true)
	{
		printf("�޶�Ӧ������Ϣ\n");
	}
}//���������
void material::shurutime(material* head, char* intime)
{
	material* f = NULL;
	node* q;
	bool flag = true;
	for (f = head; f != NULL; f = f->next)
	{
		for (q = f->hea; q != NULL; q = q->next)
		{
			if (strcmp(q->inputtime, intime) == 0)
			{
				if (flag == true)
				{
					printf("���  ������   ����   ����   ����  �����   ������      ���ʱ       ����ʱ          ��ע\n");
					printf("%d  % 8s  % 4.2f  % 3d  % 7s ", f->num, f->name, f->price, f->quantity, f->classs);
					printf("% 6d  % 6d  % 12s % 10s  % 15s\n", q->input, q->output, q->inputtime, q->outputtime, q->ps);
					flag = false;
				}
				else {
					printf("                                   ");
					printf("% 6d  % 6d  % 12s % 10s  % 15s\n", q->input, q->output, q->inputtime, q->outputtime, q->ps);
				}
			}
		}

	}
	if (flag == true)
	{
		printf("�޶�Ӧ������Ϣ\n");
	}
}//����ʱ�����
void material::shuchutime(material* head, char* outtime, int l)
{
	material* f = NULL;
	node* q;
	bool flag = true;
	for (f = head; f != NULL; f = f->next)
	{
		for (q = f->hea; q != NULL; q = q->next)
		{
			if (strcmp(q->outputtime, outtime) == 0)
			{
				if (flag == true)
				{
					printf("���  ������   ����   ����   ����  �����   ������      ���ʱ       ����ʱ          ��ע\n");
					printf("%d  % 8s  % 4.2f  % 3d  % 7s  ", f->num, f->name, f->price, f->quantity, f->classs);
					printf("% 6d  % 6d  % 12s % 10s  % 15s\n", q->input, q->output, q->inputtime, q->outputtime, q->ps);
					flag = false;
				}
				else
				{
					printf("                                   ");
					printf("% 6d  % 6d  % 12s % 10s  % 15s\n", q->input, q->output, q->inputtime, q->outputtime, q->ps);
				}
			}
		}

	}
	if (flag == true)
	{
		printf("�޶�Ӧ������Ϣ\n");
	}
}//���ʱ�����
void material::ps(material* head, char* ps, int l, int g)
{
	material* f = NULL;
	node* q;
	bool flag = true;
	for (f = head; f != NULL; f = f->next)
	{
		for (q = f->hea; q != NULL; q = q->next)
		{
			if (strcmp(q->ps, ps) == 0)
			{
				if (flag == true)
				{
					printf("���  ������   ����   ����   ����  �����   ������      ���ʱ       ����ʱ          ��ע\n");
					printf("%d  % 8s  % 4.2f  % 3d  % 7s  ", f->num, f->name, f->price, f->quantity, f->classs);
					printf("% 6d  % 6d  % 12s % 10s  % 15s\n", q->input, q->output, q->inputtime, q->outputtime, q->ps);
					flag = false;
				}
				else
				{
					printf("                                   ");
					printf("% 6d  % 6d  % 12s % 10s  % 15s\n", q->input, q->output, q->inputtime, q->outputtime, q->ps);
				}
			}
		}

	}
	if (flag == true)
	{
		printf("�޶�Ӧ������Ϣ\n");
	}
}//���ps����
void material::print1(material* head, int num)
{
	material* p = NULL;
	bool flag = true;
	material mater;
	for (p = head; p != NULL; p = p->next)
	{
		if (p->num == num)
		{
			if (flag == true)
			{
				printf("���  ������   ����   ����   ����  �����   ������      ���ʱ       ����ʱ          ��ע\n");
			}
			flag = false;
			printf("%d  % 8s  % 4.2f  % 3d  % 7s ", p->num, p->name, p->price, p->quantity, p->classs);
			mater.print(p->hea);
		}
	}
	if (flag == true)
	{
		printf("�޶�Ӧ������Ϣ\n");
	}
}
void material::print2(material* head, char* materialname, double gg, double kk)
{

	material* p = NULL;
	bool flag = true;
	material mater;
	for (p = head; p != NULL; p = p->next)
	{
		if (strcmp(p->name, materialname) == 0)
		{
			if (flag == true)
			{
				printf("���  ������   ����   ����   ����  �����   ������      ���ʱ       ����ʱ          ��ע\n");
			}
			flag = false;
			printf("%d  % 8s  % 4.2f  % 3d  % 7s ", p->num, p->name, p->price, p->quantity, p->classs);
			mater.print(p->hea);
		}
	}
	if (flag == true)
	{
		printf("�޶�Ӧ������Ϣ\n");
	}
}
void material::print3(material* head, double p)
{

	material* f = NULL;
	bool flag = true;
	material mater;
	for (f = head; f != NULL; f = f->next)
	{
		if (f->price == p)
		{
			if (flag == true)
			{
				printf("���  ������   ����   ����   ����  �����   ������      ���ʱ       ����ʱ          ��ע\n");
			}
			flag = false;
			printf("%d  % 8s  % 4.2f  % 3d  % 7s ", f->num, f->name, f->price, f->quantity, f->classs);
			mater.print(f->hea);
		}
	}
	if (flag == true)
	{
		printf("�޶�Ӧ������Ϣ\n");
	}
}
void material::print4(material* head, char* humanname, double p)
{

	material* f = NULL;
	bool flag = true;
	material mater;
	for (f = head; f != NULL; f = f->next)
	{
		if (strcmp(f->classs, humanname)==0 )
		{
			if (flag == true)
			{
				printf("���  ������   ����   ����   ����  �����   ������      ���ʱ       ����ʱ          ��ע\n");
			}
			flag = false;
			printf("%d  % 8s  % 4.2f  % 3d  % 7s ", f->num, f->name, f->price, f->quantity, f->classs);
			mater.print(f->hea);
		}
	}
	if (flag == true)
	{
		printf("�޶�Ӧ������Ϣ\n");
	}
}
void material::print5(material* head, int quantity, int p, int l)
{
	material* f = NULL;
	bool flag = true;
	material mater;
	for (f = head; f != NULL; f = f->next)
	{
		if (f->quantity == quantity)
		{
			if (flag == true)
			{
				printf("���  ������   ����   ����   ����  �����   ������      ���ʱ       ����ʱ          ��ע\n");
			}
			flag = false;
			printf("%d  % 8s  % 4.2f  % 3d  % 7s ", f->num, f->name, f->price, f->quantity, f->classs);
			mater.print(f->hea);
		}
	}
	if (flag == true)
	{
		printf("�޶�Ӧ������Ϣ\n");
	}
}
material* material::creatlink(material* head)
{
	int num, i;
	char ps[20], intime[10], outtime[10] = { "0" };
	material* q = NULL, * ff = NULL;
	material mater;
	bool flag = true;
	printf("�����������ϱ��\n");
	scanf("%d", &num);
	if (head == NULL)
	{
		q = (material*)malloc(sizeof(material));
		q->num = num;
		printf("�ò������޼�¼������д���������ƣ����ۣ�����,�����,���ʱ�估��ע�������Կո��������(ʱ���ʽΪxx:xx,��12:55)\n");
		q->hea = NULL;
		q->quantity = 0;
		scanf("%s", q->name);
		scanf("%lf", &q->price);
		scanf("%s", q->classs);
		scanf("%d", &i);
		scanf("%s", intime);
		scanf("%s", ps);
		mater.creat(i, 0, intime, outtime, ps, q);
		q->next = NULL;
		return q;
	}
	else
	{
		for (ff = head; ff != NULL; q = ff, ff = ff->next)
		{
			if (num == ff->num)
			{
				flag = false;
				printf("����д�����������,���ʱ�估��ע�������Կո��������\n");
				scanf("%d", &i);
				scanf("%s", intime);
				scanf("%s", ps);
				mater.creat(i, 0, intime, outtime, ps, ff);
				break;
			}
		}
		if (flag == true)
		{
			ff = (material*)malloc(sizeof(material));
			ff->num = num;
			printf("�ò������޼�¼������д���������ƣ����ۣ�����,�����,���ʱ�估��ע�������Կո��������\n");
			ff->hea = NULL;
			ff->quantity = 0;
			scanf("%s", ff->name);
			scanf("%lf", &ff->price);
			scanf("%s", ff->classs);
			scanf("%d", &i);
			scanf("%s", intime);
			scanf("%s", ps);
			q->next = ff;
			ff->next = NULL;
			mater.creat(i, 0, intime, outtime, ps, ff);
		}
	}
	printf("���ɹ�\n");
	return head;
}//�ⲿ������
int material::output(material* head)
{
	int num, o;
	char outtime[10], intime[10] = { "0" }, ps[20];
	material* p = NULL, * f = NULL;
	bool flag = true;
	material mater;
	printf("�����������ϱ�ţ�\n");
	scanf("%d", &num);
	if (head == NULL)
	{
		printf("�˲��ϲ�����\n");
		return 0;
	}
	for (p = head; p != NULL; p = p->next)
	{
		if (p->num == num)
		{
			flag = false;
			printf("����д������ϳ�����,����ʱ�估��ע�������Իس�����������ʱ���ʽΪxx:xx,��12:55)\n");
			scanf("%d", &o);
			scanf("%s", outtime);
			scanf("%s", ps);
			if (mater.creat(0, o, intime, outtime, ps, p) == true)
				printf("����ɹ�\n");
			else
			{
				printf("����ʧ�ܣ�������������\n");
			}
			break;
		}
	}
	if (flag == true)
	{
		printf("�˲��ϲ�����\n");
	}
	return 0;
}//����
bool repeat1()
{
	int a;
	printf("�Ƿ������⣿\n");
	printf("1.��  2.��\n");
	scanf("%d", &a);
	if (a == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool repeat2()
{
	int a;
	printf("�Ƿ�������⣿\n");
	printf("1.��  2.��\n");
	scanf("%d", &a);
	if (a == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool repeat3()
{
	int a;
	printf("�Ƿ�������ң�\n");
	printf("1.��  2.��\n");
	scanf("%d", &a);
	if (a == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool repeat4()
{
	int a;
	printf("�Ƿ�����޸ģ�\n");
	printf("1.��  2.��\n");
	scanf("%d", &a);
	if (a == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void meau()
{
	printf("������Ϣ����ϵͳ\n");
	printf("1.��Ʒ����\n");
	printf("2.������Ϣ\n");
	printf("3.���\n");
	printf("4.����\n");
	printf("5.�޸���Ϣ\n");
	printf("6.������Ļ\n");
	printf("7.��������\n");
	printf("8.������Ϣ\n");
	printf("������ѡ�\n");
}//�˵�
void boundary()
{
	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}//�ָ���
int material::print(material* head) {
	int a;
	material* p = NULL;
	material meter;
	if (head == NULL)
	{
		printf("�ֿ����޲���\n");
		printf("����0���ز˵�\n");
	}
	else
	{
		printf("���  ������   ����   ����   ����  �����   ������      ���ʱ       ����ʱ          ��ע\n");
		for (p = head; p != NULL; p = p->next)
		{
			printf("%d  % 8s  % 4.2f  % 3d  % 7s ", p->num, p->name, p->price, p->quantity, p->classs);
			meter.print(p->hea);
		}
		printf("����0���ز˵�\n");
	}
	scanf("%d", &a);
	return a;
}//�ⲿ��ӡ
int search(material* head) {
	int a, b;
	double p;
	char name[10], pss[20];
	material mater;
	if (head == NULL)
	{
		printf("�ֿ����޲���,�޷���ѯ\n");
		return 1;
	}

	printf("�������ѯ��Ϣѡ�\n");
	printf("1.���\n");
	printf("2.������\n");
	printf("3.����\n");
	printf("4.����\n");
	printf("5.�������\n");
	printf("6.�������\n");
	printf("7.��������\n");
	printf("8.���ʱ��\n");
	printf("9.����ʱ��\n");
	printf("0.��ע\n");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		printf("��������\n");
		scanf("%d", &b);
		mater.print1(head, b);
		break;
	case 2:
		printf("�����������\n");
		scanf("%s", name);
		mater.print2(head, name, 0.1, 0.1);
		break;
	case 3:
		printf("�����뵥��\n");
		scanf("%lf", &p);
		mater.print3(head, p);
		break;
	case 4:
		printf("����������\n");
		scanf("%s", name);
		mater.print4(head, name, 0.1);
		break;
	case 5:
		printf("������������\n");
		scanf("%d", &b);
		mater.print5(head, b, 0, 0);
		break;
	case 6:
		printf("�������������\n");
		scanf("%d", &b);
		mater.shurucha(head, b, 0.1);
		break;
	case 7:
		printf("�������������\n");
		scanf("%d", &b);
		mater.shuchucha(head, b, 0);
		break;
	case 8:
		printf("���������ʱ��\n");
		scanf("%s", name);
		mater.shurutime(head, name);
		break;
	case 9:
		printf("���������ʱ��\n");
		scanf("%s", name);
		mater.shuchutime(head, name, 0);
		break;
	case 0:
		printf("�����뱸ע\n");
		scanf("%s", pss);
		mater.ps(head, pss, 0, 0);
		break;
	default:
		break;
	}
	boundary();
	return 0;
}//����
void material::revise(material* head)   {
	int a, b, c, d, e = 0;
	double p;
	char name[10], pss[20];
	bool flag = true;
	node* ff = NULL;
	material* q = NULL;
	material mater;
	printf("����������Ҫ�޸ĵ���Ϣ���ڲ��ϵı��\n");
	scanf("%d", &a);
	printf("�޸�%d�Ų��ϵ���һ��Ϣ��\n", a);
	printf("1.���\n");
	printf("2.������\n");
	printf("3.����\n");
	printf("4.����\n");
	printf("5.�������\n");
	printf("6.�������\n");
	printf("7.��������\n");
	printf("8.���ʱ��\n");
	printf("9.����ʱ��\n");
	printf("0.��ע\n");
	scanf("%d", &b);
	printf("�޸�Ϊ��\n");
	switch (b)
	{
	case 1:
		scanf("%d", &c);
		for (q = head; q != NULL; q = q->next)
		{
			if (q->num == a)
			{
				q->num = c;
				flag = false;
				break;
			}
		}
		break;
	case 2:
		scanf("%s", name);
		for (q = head; q != NULL; q = q->next)
		{
			if (q->num == a)
			{
				strcpy(q->name, name);
				flag = false;
				break;
			}
		}
		break;
	case 3:
		scanf("%lf", &p);
		for (q = head; q != NULL; q = q->next)
		{
			if (q->num == a)
			{
				q->price = p;
				flag = false;
				break;
			}
		}
		break;
	case 4:
		scanf("%s", name);
		for (q = head; q != NULL; q = q->next)
		{
			if (q->num == a)
			{
				strcpy(q->classs, name);
				flag = false;
				break;
			}
		}
		break;
	case 5:
		scanf("%d", &c);
		for (q = head; q != NULL; q = q->next)
		{
			if (q->num == a)
			{
				q->quantity = c;
				flag = false;
				break;
			}
		}
		break;
	case 6:
		scanf("%d", &c);
		mater.print1(head, a);
		printf("�޸ĵڼ��μ�¼����Ϣ��\n");
		scanf("%d", &d);
		for (q = head; q != NULL; q = q->next)
		{
			if (q->num == a)
			{

				for (ff = q->hea; ff != NULL; ff = ff->next)
				{
					e++;
					if (e == d)
					{
						q->quantity = q->quantity + c - ff->input;
						ff->input = c;
						flag = false;
						break;
					}
				}
				break;
			}
		}
		break;
	case 7:
		scanf("%d", &c);
		mater.print1(head, a);
		printf("�޸ĵڼ��μ�¼����Ϣ��\n");
		scanf("%d", &d);
		for (q = head; q != NULL; q = q->next)
		{
			if (q->num == a)
			{

				for (ff = q->hea; ff != NULL; ff = ff->next)
				{
					e++;
					if (e == d)
					{
						q->quantity = q->quantity + c - ff->output;
						ff->output = c;
						flag = false;
						break;
					}
				}
				break;
			}
		}
		break;
	case 8:
		scanf("%s", name);
		mater.print1(head, a);
		printf("�޸ĵڼ��μ�¼����Ϣ��\n");
		scanf("%d", &d);
		for (q = head; q != NULL; q = q->next)
		{
			if (q->num == a)
			{

				for (ff = q->hea; ff != NULL; ff = ff->next)
				{
					e++;
					if (e == d)
					{
						strcpy(ff->inputtime, name);
						flag = false;
						break;
					}
				}
				break;
			}
		}
		break;
	case 9:
		scanf("%s", name);
		mater.print1(head, a);
		printf("�޸ĵڼ��μ�¼����Ϣ��\n");
		scanf("%d", &d);
		for (q = head; q != NULL; q = q->next)
		{
			if (q->num == a)
			{

				for (ff = q->hea; ff != NULL; ff = ff->next)
				{
					e++;
					if (e == d)
					{
						strcpy(ff->outputtime, name);
						flag = false;
						break;
					}
				}
				break;
			}
		}
		break;
	case 0:
		scanf("%s", pss);
		mater.print1(head, a);
		printf("�޸ĵڼ��μ�¼����Ϣ��\n");
		scanf("%d", &d);
		for (q = head; q != NULL; q = q->next)
		{
			if (q->num == a)
			{

				for (ff = q->hea; ff != NULL; ff = ff->next)
				{
					e++;
					if (e == d)
					{
						strcpy(ff->ps, pss);
						flag = false;
						break;
					}
				}
				break;
			}
		}
		break;
	default:
		break;
	}
	if (flag == true)
	{
		printf("�޸�ʧ�ܣ�δ��ѯ������Ϣ\n");
	}
	else
	{
		printf("�޸ĳɹ�\n");
	}
}//�޸�
int material::fprint(material* head)
{
	if (head == NULL)
	{
		return 0;
	}
	FILE* p = NULL;
	char kong[3] = { "  " };
	p = fopen("1.txt", "w");
	if (p == NULL)
	{
		return 0;
	}
	material* q = NULL;
	node* ff = NULL;
	int a;
	bool flag = true;
	for (q = head; q != NULL; q = q->next)
	{
		flag = true;
		fprintf(p, "%d", q->num);
		fprintf(p, kong);
		fprintf(p, q->name);
		fprintf(p, kong);
		fprintf(p, "%.2f", q->price);
		fprintf(p, kong);
		fprintf(p, q->classs);
		fprintf(p, kong);
		fprintf(p, "%d", q->quantity);
		fprintf(p, kong);
		for (ff = q->hea; ff != NULL; ff = ff->next)
		{
			if (flag == false)
			{
				fprintf(p, "\n");
				for (a = 0; a < 23; a++)
				{
					fprintf(p, kong);
				}
			}
			fprintf(p, "%d", ff->input);
			fprintf(p, kong);
			fprintf(p, "%d", ff->output);
			fprintf(p, kong);
			fprintf(p, ff->inputtime);
			fprintf(p, kong);
			fprintf(p, ff->outputtime);
			fprintf(p, kong);
			fprintf(p, ff->ps);
			flag = false;
		}
		fprintf(p, "\n");
	}
	fclose(p);
	return 1;
}
int main()
{
	material* head = NULL;
	int a;
	material mater;
	for (;;)
	{
		boundary();
		meau();
		scanf("%d", &a);
		if (a == 7)
		{
			break;
		}
		if (a == 3)
		{
			for (;;)
			{
				boundary();
				head = mater.creatlink(head);
				if (repeat1() == false)
				{
					break;
				}
			}
		}
		if (a == 4)
		{
			for (;;)
			{
				boundary();
				mater.output(head);
				if (repeat2() == false)
				{
					break;
				}
			}
		}
		if (a == 1)
		{
			for (;;)
			{
				boundary();
				if (mater.print(head) == 0)
				{
					break;
				}
			}
		}
		if (a == 6)
		{
			system("cls");
		}
		if (a == 2)
		{
			for (;;)
			{
				boundary();
				if (search(head) == 1)
				{
					break;
				}
				else if (repeat3() == 0)
				{
					break;
				}
			}
		}
		if (a == 5)
		{
			for (;;)
			{
				boundary();
				mater.revise(head);
				if (repeat4() == 0)
				{
					break;
				}
			}
		}
		
		if (a == 8)
		{
			boundary();
			if (mater.fprint(head) == 1)
			{
				printf("����ɹ�\n");
			}
			else
			{
				printf("����ʧ��,ԭ��Ϊ�ֿ�������Ϣ���Ҳ����ı��ļ���\n");
			}
		}
	}
	return 0;
}
