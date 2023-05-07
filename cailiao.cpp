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
}//内部链表创建
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
}//内部打印
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
					printf("编号  材料名   单价   数量   种类  入库数   出库数      入库时       出库时          备注\n");
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
		printf("无对应材料信息\n");
	}
}//输入量查找
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
					printf("编号  材料名   单价   数量   种类  入库数   出库数      入库时       出库时          备注\n");
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
		printf("无对应材料信息\n");
	}
}//输出量查找
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
					printf("编号  材料名   单价   数量   种类  入库数   出库数      入库时       出库时          备注\n");
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
		printf("无对应材料信息\n");
	}
}//输入时间查找
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
					printf("编号  材料名   单价   数量   种类  入库数   出库数      入库时       出库时          备注\n");
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
		printf("无对应材料信息\n");
	}
}//输出时间查找
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
					printf("编号  材料名   单价   数量   种类  入库数   出库数      入库时       出库时          备注\n");
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
		printf("无对应材料信息\n");
	}
}//输出ps查找
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
				printf("编号  材料名   单价   数量   种类  入库数   出库数      入库时       出库时          备注\n");
			}
			flag = false;
			printf("%d  % 8s  % 4.2f  % 3d  % 7s ", p->num, p->name, p->price, p->quantity, p->classs);
			mater.print(p->hea);
		}
	}
	if (flag == true)
	{
		printf("无对应材料信息\n");
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
				printf("编号  材料名   单价   数量   种类  入库数   出库数      入库时       出库时          备注\n");
			}
			flag = false;
			printf("%d  % 8s  % 4.2f  % 3d  % 7s ", p->num, p->name, p->price, p->quantity, p->classs);
			mater.print(p->hea);
		}
	}
	if (flag == true)
	{
		printf("无对应材料信息\n");
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
				printf("编号  材料名   单价   数量   种类  入库数   出库数      入库时       出库时          备注\n");
			}
			flag = false;
			printf("%d  % 8s  % 4.2f  % 3d  % 7s ", f->num, f->name, f->price, f->quantity, f->classs);
			mater.print(f->hea);
		}
	}
	if (flag == true)
	{
		printf("无对应材料信息\n");
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
				printf("编号  材料名   单价   数量   种类  入库数   出库数      入库时       出库时          备注\n");
			}
			flag = false;
			printf("%d  % 8s  % 4.2f  % 3d  % 7s ", f->num, f->name, f->price, f->quantity, f->classs);
			mater.print(f->hea);
		}
	}
	if (flag == true)
	{
		printf("无对应材料信息\n");
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
				printf("编号  材料名   单价   数量   种类  入库数   出库数      入库时       出库时          备注\n");
			}
			flag = false;
			printf("%d  % 8s  % 4.2f  % 3d  % 7s ", f->num, f->name, f->price, f->quantity, f->classs);
			mater.print(f->hea);
		}
	}
	if (flag == true)
	{
		printf("无对应材料信息\n");
	}
}
material* material::creatlink(material* head)
{
	int num, i;
	char ps[20], intime[10], outtime[10] = { "0" };
	material* q = NULL, * ff = NULL;
	material mater;
	bool flag = true;
	printf("请输入入库材料编号\n");
	scanf("%d", &num);
	if (head == NULL)
	{
		q = (material*)malloc(sizeof(material));
		q->num = num;
		printf("该材料暂无记录，请填写入库材料名称，单价，种类,入库量,入库时间及备注，各项以空格键隔开。(时间格式为xx:xx,如12:55)\n");
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
				printf("请填写入库材料入库量,入库时间及备注，各项以空格键隔开。\n");
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
			printf("该材料暂无记录，请填写入库材料名称，单价，种类,入库量,入库时间及备注，各项以空格键隔开。\n");
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
	printf("入库成功\n");
	return head;
}//外部链表创建
int material::output(material* head)
{
	int num, o;
	char outtime[10], intime[10] = { "0" }, ps[20];
	material* p = NULL, * f = NULL;
	bool flag = true;
	material mater;
	printf("请输入出库材料编号：\n");
	scanf("%d", &num);
	if (head == NULL)
	{
		printf("此材料不存在\n");
		return 0;
	}
	for (p = head; p != NULL; p = p->next)
	{
		if (p->num == num)
		{
			flag = false;
			printf("请填写出库材料出库量,出库时间及备注，各项以回车键隔开。（时间格式为xx:xx,如12:55)\n");
			scanf("%d", &o);
			scanf("%s", outtime);
			scanf("%s", ps);
			if (mater.creat(0, o, intime, outtime, ps, p) == true)
				printf("出库成功\n");
			else
			{
				printf("出库失败，材料数量不足\n");
			}
			break;
		}
	}
	if (flag == true)
	{
		printf("此材料不存在\n");
	}
	return 0;
}//出库
bool repeat1()
{
	int a;
	printf("是否继续入库？\n");
	printf("1.是  2.否\n");
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
	printf("是否继续出库？\n");
	printf("1.是  2.否\n");
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
	printf("是否继续查找？\n");
	printf("1.是  2.否\n");
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
	printf("是否继续修改？\n");
	printf("1.是  2.否\n");
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
	printf("网店信息管理系统\n");
	printf("1.商品总览\n");
	printf("2.查找信息\n");
	printf("3.入库\n");
	printf("4.出库\n");
	printf("5.修改信息\n");
	printf("6.清理屏幕\n");
	printf("7.结束程序\n");
	printf("8.保存信息\n");
	printf("请输入选项：\n");
}//菜单
void boundary()
{
	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}//分割线
int material::print(material* head) {
	int a;
	material* p = NULL;
	material meter;
	if (head == NULL)
	{
		printf("仓库暂无材料\n");
		printf("输入0返回菜单\n");
	}
	else
	{
		printf("编号  材料名   单价   数量   种类  入库数   出库数      入库时       出库时          备注\n");
		for (p = head; p != NULL; p = p->next)
		{
			printf("%d  % 8s  % 4.2f  % 3d  % 7s ", p->num, p->name, p->price, p->quantity, p->classs);
			meter.print(p->hea);
		}
		printf("输入0返回菜单\n");
	}
	scanf("%d", &a);
	return a;
}//外部打印
int search(material* head) {
	int a, b;
	double p;
	char name[10], pss[20];
	material mater;
	if (head == NULL)
	{
		printf("仓库暂无材料,无法查询\n");
		return 1;
	}

	printf("请输入查询信息选项：\n");
	printf("1.编号\n");
	printf("2.材料名\n");
	printf("3.单价\n");
	printf("4.种类\n");
	printf("5.存货数量\n");
	printf("6.入库数量\n");
	printf("7.出库数量\n");
	printf("8.入库时间\n");
	printf("9.出库时间\n");
	printf("0.备注\n");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		printf("请输入编号\n");
		scanf("%d", &b);
		mater.print1(head, b);
		break;
	case 2:
		printf("请输入材料名\n");
		scanf("%s", name);
		mater.print2(head, name, 0.1, 0.1);
		break;
	case 3:
		printf("请输入单价\n");
		scanf("%lf", &p);
		mater.print3(head, p);
		break;
	case 4:
		printf("请输入种类\n");
		scanf("%s", name);
		mater.print4(head, name, 0.1);
		break;
	case 5:
		printf("请输入存货数量\n");
		scanf("%d", &b);
		mater.print5(head, b, 0, 0);
		break;
	case 6:
		printf("请输入入库数量\n");
		scanf("%d", &b);
		mater.shurucha(head, b, 0.1);
		break;
	case 7:
		printf("请输入出库数量\n");
		scanf("%d", &b);
		mater.shuchucha(head, b, 0);
		break;
	case 8:
		printf("请输入入库时间\n");
		scanf("%s", name);
		mater.shurutime(head, name);
		break;
	case 9:
		printf("请输入出库时间\n");
		scanf("%s", name);
		mater.shuchutime(head, name, 0);
		break;
	case 0:
		printf("请输入备注\n");
		scanf("%s", pss);
		mater.ps(head, pss, 0, 0);
		break;
	default:
		break;
	}
	boundary();
	return 0;
}//查找
void material::revise(material* head)   {
	int a, b, c, d, e = 0;
	double p;
	char name[10], pss[20];
	bool flag = true;
	node* ff = NULL;
	material* q = NULL;
	material mater;
	printf("请输入你想要修改的信息所在材料的编号\n");
	scanf("%d", &a);
	printf("修改%d号材料的哪一信息：\n", a);
	printf("1.编号\n");
	printf("2.材料名\n");
	printf("3.单价\n");
	printf("4.种类\n");
	printf("5.存货数量\n");
	printf("6.入库数量\n");
	printf("7.出库数量\n");
	printf("8.入库时间\n");
	printf("9.出库时间\n");
	printf("0.备注\n");
	scanf("%d", &b);
	printf("修改为：\n");
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
		printf("修改第几次记录的信息？\n");
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
		printf("修改第几次记录的信息？\n");
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
		printf("修改第几次记录的信息？\n");
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
		printf("修改第几次记录的信息？\n");
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
		printf("修改第几次记录的信息？\n");
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
		printf("修改失败，未查询到此信息\n");
	}
	else
	{
		printf("修改成功\n");
	}
}//修改
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
				printf("保存成功\n");
			}
			else
			{
				printf("保存失败,原因为仓库中无信息或找不到文本文件夹\n");
			}
		}
	}
	return 0;
}
