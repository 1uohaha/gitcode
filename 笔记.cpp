/*
* 时间2021.1.24
* 罗显威
*/
//#include

#include<iostream>
#include<string>//字符串
#include<ctime>//时间 随机数
#include<fstream>

using namespace std;

void 笔记()
{
	//小知识点
	/*#define a 5 不可为左，不可作变量名
	const int d = 5;同上
	标识符不能数字开头，数字、下划线、字母区分大小写
	cout << "长度为：" << sizeof(a); 长度函数  short<int<long<long long
	科学计数 a = 3e-2;
	随机数种子 srand((unsigned int)time(NULL))   需包含ctime头文件  
	rand()%100    其值为0~99随机数    rand()%100+1 生成1~100随机数
	*/
	//数据类型
	/*
	整型 short int long longlong
	浮点型 float double
	字符型 char ch = 'a';单引号内只有一个字母
	转义字符 \n \\ 输出反斜杠要多一个 \t一个代表8个位置制表对齐

	字符串
	C：char str[] = "****";字符串、双引号
	C++：string str = "****";需先声明
	string str;      cin >> str; 输入字符串的话计算机只读到输入空格之后

	字符数组
	string str[2] = {"张三","李四" };



	bool类型 bool a = true（false）; 只占一字节，零为假，非零为真
	*/
	//运算符
	/*
	+加-减*乘/除
	除法需注意数据类型，整形除法直接舍去小数部分不会四舍五入，定义float类型是为了方便除法运算
	取余：10 % 3 = 1；取余被除数不能为零，且小数不能取余；
	递增递减：前置先加减再运算，后置是先运算表达式再加减；
	赋值：+=  -=  *=  /=  %=
	比较：==相等？  ！=不相等？
	逻辑：非：!a(非零置零，零置一)  与：a&&b(都不为0则为1)  或：a||b(有非零则为1)    (C++中除了0都是真)
	
	☆☆☆☆☆☆☆☆☆☆ int c = a > b && b > a ? 1 : 0; ☆☆☆☆☆☆☆☆☆☆
	
	*/
	//选择和循环
	/*
	结构

	选择结构：
	1.if:if(~) {~} else {~}   if(~) {~} else if {~} else if {~} else if {~} → switch
	2.三目运算:(a < b ?  a : b) = 100   d = (c == 1 ? a : b);
	3.switch:
	switch(变量)
	{
	case 1(值): ~ ;
	break;
	case 2: ~ ;
	break;
	default: ~ ;
	break;
	}

	循环结构：
	while: while (~) {~};          while(1) 是死循环，可以用break退出
		   do{~} while(~);         do~while 先执行一遍
	for: for(i=0,i<10,i++){~};     0~9 循环10遍

	跳转语句：
	break: 不多说
	continue: 跳过本次循环进行下次
	标记： FLAG: 直接命名加冒号
	goto: goto FlAG; 转到
	*/
	//数组
	/*
	一维数组：
	三种命名形式             数组初始化的时候必须明确有多长
	1.数据类型 名[长度];
	2.数据类型 名[长度]={1,2,3,4...};
	3.数据类型 名[    ]={1,2,3,4...};
	  a[2] → a[0],a[1]    0、1是值在数组中的位置
	  数组可以用 sizeof(arr)来获取内存大小，可以用 sizeof(arr)/sizeof(arr[0]) 来获取元素个数
	  数组首地址 cout<<arr;  默认十六进制 可以强转为十进制 cout<<(int)arr;
	  元素的地址 cout<<&arr[0];  同上
							***数组名是不可修改的地址***

	二维数组：
	四种命名方式
	1.数据类型 名[行][列];
	2.数据类型 名[行][列]={{1,2,3,4},{5,6,7,8}...}
	3.数据类型 名[行][列]={1,2,3,4...}
	4.数据类型 名[  ][列]={1,2,3,4...}   根据列数可以自动排列，但只能省略行数
	  同理
	  a[1][2] 代表第一行第二列的元素
	  整个内存大小：sizeof(arr)
	  一个元素内存大小：sizeog(arr[0][0])
	  一行内存大小：sizeof(arr[0])
	  元素个数：sizeof(arr)/sizeof(arr[0][0])
	  行数：sizeof(arr[0])/sizeog(arr[0][0])           行除单个
	  列数：sizeof(arr)/sizeof(arr[0])                 整个除行
	  首地址：cout<<arr; cout<<(int)arr;
	  行首地址：cout<<arr[0]; cout<<(int)arr[0];
	  元素地址：cout<<&arr[0][0];


	*/
	//函数
	/*
	普通类型：

	    ************形参列表只需要名字即可**************

		返回值类型 名 (参数列表/形参)            需注意实参和形参，形参相当于局部变量
		{
			语句
			return 某个变量
		}

	不需要返回值类型时就用：

		void 名(形参列表)
		{
			语句
			不需要return
		}

	值传递时，形参不影响实参，也就是说，形参和实参就算名字一样，占用的也是不同路径的地址
	类型有：无参无返 有参无返 无参有返 有参有返


	分文件编写：       头文件里写函数声明: ~.h       源文件里写函数定义: ~.cpp


	函数的默认参数：
	void exp(int s,int a = 10,int b = 20)
	{
		cout<<...;
	}
	在函数有默认参数的时候，有默认值的参数可以不进行赋值： exp(10); 此时10默认赋值给s，如果更改可以继续赋值，但是会默认给后面的参数
	注意事项：
	1.如果有个位置有默认值，那么从这个值往后的每一个参数都应该有默认值。
	2.如果函数在声明中已经有了默认参数，那函数本体中就不能有默认参数，就是说同一个函数不能同时存在两个默认参数！
	

	函数的占位参数：
	就是相当与在函数中占一个参数位置
	void exp(int a,int ,int )
	{
		cout<<...;
	}
	并且占位参数，也可以有默认参数


	函数重载：
	就是说函数名可以相同，需满足以下条件
	1.同一个作用域
	2.函数名相同
	3.参数的类型，个数，顺序不同都可以重载
	

	函数重载注意事项：
	1.引用作为重载的条件
	void exp(int& a)   这里只能传变量  因为 int& a = 10; 不合法 只有const int& a = 10; 才合法
	{
		cout<<...;
	}
	void exp(const int& a)  所以两个函数可以实现重载，传入变量走上边，传入常量走下边
	{
		cout<<...;
	}


	2.函数重载碰到默认参数
	void exp(int a,int b = 10 )
	{
		cout<<...;
	}
	void exp(int a )        这两个函数也可以实现重载，但是如果调用exp(10); 此时两个函数都可以调用，程序错误
	{
		cout<<...;
	}




	*/
    //指针
    /*
	                        指针就是用来保存地址的
    指针的定义： 数据类型* 名;      int * p;     p为指向 *p为值
	取地址 → &a     解引用 → *p
	解引用就是直接的读取内存中的数据
	简洁表述为：      “ int* p = &a; ”

	32位系统指针4字节 64位系统指针8字节

	空指针：指向内存编号为0的指针，空指针无法访问，即不可以解引用，可用于初始化   int* p = NULL; 
	野指针：野指针就是初始化指针地址了，没有申请，非法操作应尽量避免             int* p = (int *)0x0100;
	最好不要访问空指针和野指针

	const指针
	指针常量：“int* const p = &a;”，指向不可改，可改地址的值     p = &b;错误     *p = 10;正确
	常量指针：“const int* p = &a;”，指向可改，不可改地址的值     p = &b;正确     *p = 10;错误
	常量指针常量：“const int* const p = &a;”，都不可改，需初始化

	指针和数组
	int arr[] = {......};
	int* p = arr;    这里arr就是数组首地址位置      ***** 理解什么是“数组指针” *****
	p++；    p++就是直接下一个地址，偏移四个或八个字节，而不是加一，这也就是为什么指针也需要初始化数据类型
	
	int **arr=(int **)malloc(sizeof(int));  // 定义一个二级指针，并分配内存
	int *p=(int *)malloc(sizeof(int));      // 定义一个一级指针，并分配内存
	*arr=p;  // 将arr的第二级指针指向指针p所指向的内存单元
	*p = 4;  // 对指针p所指向的内存单元赋值
	printf("%d\n", **arr);  // 输出二级指针所指向的内存单元的值

	指针和函数
	1.值传递
	2.地址传递：形参用地址来表示
	           void function(int* p1,int* p2){ ~ }
	           地址传递时如果*p作为左值是可以改变实参的！！！
	*/
    //结构体
    /*
	1.结构体：自定义数据类型
	struct 名 
	struct 名 = {*,*,*};
	创建时顺便创建变量
	用“.”访问结构体
	创建结构体时不可以省略struct 创建结构体变量时可以省略struct 带名就行了 结构体定义放在主函数外面
	struct people {
		string name;
		int age;
		int score;
	};
	struct people s1;  为结构体变量，创建结构体变量时可以省略关键字，如下
	people s2;

	2.结构体数组：
	struct 名 数组名[3] = {};
    struct people student[3] = {
	{*，*，*}，
	{*，*，*}，
	{*，*，*}，
	};

	3.结构体指针
	用->可以通过结构体指针访问结构体的某一属性
	结构体的数据类型是struct： 例如指针指向结构体变量：(struct) 结构体名 *p = &变量名
	结构体指针的解引用相当于 p->name

	4.结构体的嵌套
	struct stu
    {
	    string name;
	    int age;
	    int score;
    };
	struct teach
	{
		string name;
		int age;
		int score;
		stu s1；
	};

	5.结构体作函数参数
	值传递 地址传递
	结构体函数，形参用指针，可以节省空间，因为指针只占四个字节，不用拷贝所有数据

	6.const结构体
	struct student s = {*，*，*}；
	上述，结构体作函数参数一般是地址传递，这样就有可能误操作更改了实参的值，于是可以在形参前加const
	void 函数名(const 结构名* 名){    } 这样就将指针改为了不可修改的指针


	*/
	//内存
	/*
	内存四个区：代码 全局 栈区 堆区

	1.堆区：自定义生成和释放
	new 数据类型(数据);  new定义出来的这个是指向数据的指针 所以要用指针类型的变量来接收，如:int * p = new int(10);
	delete p；
	堆区生成数组：int * arr = new int[10]; 表示生成了十个数的数组
	数组的释放：delete[] arr;  语法很奇怪，记住就行

	2.栈区
		函数的局部变量在栈区，自动释放



	*/
	//引用
	/*
	给一个变量起别名
	首先数据类型要一样
	例如：int a = 10; int &b = a; 这样数据就有ab两个名字，并且操纵的是同一个地址，例如讲b改为20之后a也是20
	但是 int & a = 10 ; 这是错误操作！！！引用必须是堆区或栈去的数据！！！
	想要直接引用一个数需要 const int & a = 10 ; 编译器才看得懂 

	注意事项：
	1.引用必须初始化
	2.引用一旦初始化了，就不能再更改，就相当于静态指针

	引用作函数参数：
	相当于地址传递

	引用作函数返回值：
	显然局部变量的引用也存在于栈区中，所以也不能作为函数返回值
	引用做返回值时，函数可以作为左值，因为引用本质是地址，函数作左值相当于赋值

	常量引用：
	修饰形参防止误操作
	void ***(const int & a)
	{
		a = 10； 此时a是不能更改的，相当于，指针类型的值传递，这样做的好处是不占用地址空间，指针作函数参数所占空间非常小
	}
	*/
	//类和对象
	/*
	面向对象的特征：封装、继承、和对象
	任何事物都可以作为对象，对象有属性和行为
	封装是将属性和行为囊括为一个整体


	关键字：class
	class 名
	{
		访问权限：public；
		属性：int R；
		行为：行为一般是函数 S();
	}
	有了类就可以在main函数中创建具体的对象，即为“实例化”
	名.R;通过点给类的属性赋值
	名.S;通过点使类产生行为，即把属性传递到行为函数里！ 

	类声明: class 名;
	类外函数实现:
	class person
	{
	public:
		person();
		~person();
		void visit();
	private:
		int size;
	};
	person::person()//构造函数外部实现
	{
		this->size = 76;
	}
	person::~person()
	{

	}
	void person::visit()
	{

	};




	访问权限：
	公共：public        里边可以访问，外边也可以访问
	保护：protected     里边可以访问，外边不可以访问
	私有：private       里边可以访问，外边不可以访问


	struct和class的区别：
	struct默认公共，而class默认私有
	将成员属性私有化，在公共访问函数可以自定义属性的只读只写和读写
	class person
	{
	    public; 即为接口
		void ***()
		{
			...		
		}

		private;
		int ***;
	}

	
	！！！！！！属性放在private里，再在public里写读写的函数！！！！！！
	然后初始值用类的写入函数来赋值
	行为可以通过访问行为函数来实现


	构造函数：**(){}
	析构函数：~**(){}
	没有返回值也不写void，名字与类相同，可有参数可重载，无需调用

	构造函数的分类：
	有参和无参  普通和拷贝
	拷贝构造：
	person(const person &p)  只有这种形式叫拷贝构造
	{
		age = p.age;
	}
	调用方式：
	括号法 显示法 隐式转换法
	1.括号法：
		person p1;
		person p2(10);
		person p3(p2);
		注意事项：
		调用默认构造函数不内有括号！不然会被当成函数声明！
	2.显示法：
		person p1;
		person p2 = person(10);
		person p3 = person(p2);
		匿名对象：person(10); 构造完直接析构
		注意事项：不要用拷贝构造函数初始化匿名对象，相当于创建对象了 person (p3); 相当于 person p3;
	3.隐式转换法：
		person p4 = 10; 相当于 person p4 = person (10);
		person p5 = p4; 相当于拷贝
	括号法和隐式比较好用


	拷贝构造的使用情况：           拷贝构造就是说，有拷贝构造，就可以被其他的函数直接调用，类的属性？
	1.需创建一个已经创建过的对象，拷贝
		class person
		{
		public:
			person()
			{
				cout << "默认！" << endl;
			};
			person(int a)
			{
				cout << "有参！" << endl;
			};
			person(const person& p)
			{
				cout << "拷贝！" << endl;
			};
			~person()
			{
			};
		private:
			int age;
		};

		main:
		person p1;
		person p2(10);
		person p3(p2);

		person p1(30); 这种形式赋值需要有参构造函数！！！！！！！！！！！
		person p2(p1); 这种形式赋值需要拷贝构造函数！！！！！！！！！！！
	
	2.类作变量，以值传递的方式给函数传值，用相当于用const指针，不改变实参
		person p;
		myfunction(p); 此处p为类，直接给函数赋值需要先写拷贝构造
	3.以值的方式返回局部对象
		person myfunction()
		{
			person p;
			return p;这里返回的是类变量，也是相当于值传递，需要调用拷贝构造
		}


	构造函数调用规则：
		一般编译器会默认有的三个函数
		1.默认构造
		2.默认解析
		3.默认拷贝
		注意：
		1.写了有参构造编译器就不会提供默认构造了，所以有参和默认要写就一起写，但拷贝仍有
		2.如果写了拷贝构造，那就都不提供了
	深拷贝和浅拷贝：
		浅拷贝：直接赋值            浅拷贝拷贝堆区的指针(该堆区指针是一个属性)的话会带来重复析构的问题
		深拷贝：在堆区创建新的值     适用于属性有在堆区开辟的情况，
		深拷贝的时候就可以用到析构函数了，用其来释放堆区的数据

	自己写拷贝构造函数，可以解决浅拷贝的重复析构问题：
		person(const Person &p)
		{
			m_age = p.m_age; 属性是值，可以直接拷贝
			m_hight = new int(*p.m_hight); 属性是堆区指针，避免浅拷贝，用深拷贝
		}


	初始化列表：
		构造函数():属性1(值1),属性2(值2),......{}
		方便的构造函数写法：
		person(int a, int b, int c):m_a(a), m_b(b), m_c(c){}
		这样就可以直接：person(10,20,30);


	类对象可以作为类成员：
		class phone
		{
		public:
			phone() {}
			~phone() {}

		private:
			string p_name;
		};
		class person
		{
		public:
			person() {}
			~person() {}

		private:
			phone m_p;
		};
		类作属性的时候，属性中的类先构造
		析构的时候相反
		先析构外层，再析构内层属性


	静态成员变量
		静态成员变量 static 所有对象共享一份数据相当于全局变量
		静态成员变量：
		类内声明 static int a；
		类外初始化：int 类名：：a = 100；
		私有的静态成员变量类外同样访问不到
		不属于某一个对象，因此静态成员变量有两种访问方式，第一种是对象进行访问，第二种是类名访问
		person p;
		p.m_a;//第一种
		person::m_a;//第二种

	静态成员函数
		静态成员函数 所有对象共享一个函数，静态成员函数只能访问静态成员变量
		静态成员函数的变量只能是静态成员变量，不能有别的变量，调用方法和性质和静态成员变量类似
		静态成员函数也可以设置访问权限
		！！！成员变量和函数关键是成员二字！！！意味着作用于所有对象，所以二者只能相互作用，不能有其他参数


	对象模型和this指针
	1.成员变量和成员函数分开存储
		静态成员和函数不是对象的组成部分，不占对象的空间
		空对象
		class name{};
		name a;
		空对象占一字节
		有了变量占四字节，空对象消失
	2.this指针
		两大用途：解决名称冲突和返回对象本身*this
		1）this->指向被调用的 成员函数 所属的对象    具体的对象
		2）成员函数return *this之后可以鬼畜操作（链式编程）（返回类型为：“类名&”）
		3）防止空指针访问成员函数
		C++中成员函数访问成员变量时每一个成员变量前面都默认有this指针所以，访问成员函数时对象不能为空，如果是用空指针访问成员函数就会崩溃，防止方法如下
		防止this指针崩溃
		if(this == NULL){return;}

	常函数
		1.成员函数 “后” 加const  相当于把this指针常量变成常量指针常量  指向和值都不可改
		class person
		{   
		public： void fct (){}
		int a;
		}
		2.常函数 内 不可修改 成员属性（外不影响）
		3.在 属性前 加 mutable 则可以被常函数修改
	
	常对象
		1.在对象前加 const 对象属性不可修改   （加了声明了mutable的属性除外）
		2.常对象只能调用常函数


	友元
		1.友元可以访问私有成员 关键字friend
		2.实现方式
			1.全局函数友元 
			2.类友元 
			3.成员函数友元

		代码实现
		class guys
		{
		public:
			guys();
			~guys() {}
			void guyscoming();
			void text();

		};
		class person
		{
		public:
			person();
			~person();
			friend void visit();               //全局函数友元
			friend class guys;                 //类友元，需注意的是，类友元的所有函数皆是友元成员函数
			friend void gu ys::guyscoming();    //成员函数友元
		private:
			int wallet;
		};


		person::person()
		{
			this->wallet = 76;
		}
		person::~person()
		{

		}
		guys::guys()
		{
			person* p2 = new person;//堆区也可
			cout << p2->wallet << endl;
			cout << "类正在查看钱包" << endl;
		}
		void guys::guyscoming()
		{
			person p3;//直接创建也可
			cout << p3.wallet << endl;
			cout << "成员函数正在查看钱包" << endl;

		}
		void guys::text()
		{
			person* p4 = new person;
			cout << p4->wallet << endl;
			cout << "友元类的非友元成员函数正在查看钱包" << endl;
		}
		void visit()
		{
			person* p1 = new person;
			cout << p1->wallet << endl;
			cout << "全局函数正在查看钱包" << endl;
		};

		主函数部分：
		visit();
		guys g1;
		g1.guyscoming();
		g1.text();


	运算符重载
		自定义运算
		
		1.加号运算符重载
			将函数名改为      operator+
			则加号被重载为自定义加法函数
			***运算符重载函数也可以重载***套娃
		2.左移运算符重载
			operator<<
			代码如下：
			ostream& operator<<(ostream& out, person& p1)  
			{
				out << p1.a << endl << p1.b;
				return out;                            //cout的类型为ostream返回cout可以实现流式传输
			}
		3.递增运算符重载
			operator++

		4.赋值运算符
			person& operator=(person p)//1.赋值运算重载必须是成员函数!!! 2.返回类型为对象实现链式编程!!!
			{
				if (p_a != NULL)//p_a是构造函数构造的堆区变量
				{
					delete p_a;//先释放
					p_a = NULL;
				}
				p_a = new int(*p.p_a);
			}
			~person();
			int* p_a;
			int p_b = 20;
		5.比较运算符
			bool operator==/>/</!= ()
			{
				if(this->)         //因为是成员函数，所以可以直接用this指针访问参数
				{
					return true
				};
				return false;
			}
		6.函数调用运算符重载->()"仿函数"
			int operator()(int a,int b)
			{
				//函数体可以随便写，灵活应用；
			}
			调用： 
			person p; 
			p(a,b);
			匿名调用：
			person()(a,b);     //person()是匿名对象，调用之后立即释放

	继承：
		1.语法
			class cls1:public baseclass;
			class 子类:继承方式 父类;

		2.继承方式
			public/private/protected；
			1.父类的私有内容继承都无法访问
			2.public继承，public和protected原封不动
			3.protected继承，父类全继承为protected
			4.private继承，父类全继承为private

		3.构造析构顺序
			1.构造先父后子，析构相反

		4.继承同名成员
			1.加作用域
			person.base::m_a;
			person.base::func();/person.base::func(int a); //父类同名成员重载

		5.同名静态成员属性和函数
			调用父类同名静态成员，必须加作用域！！！
			1.访问属性
			son1.m_a;          //对象访问子类静态
			son1.base::m_a;    //父类静态
			son::m_a;          //类名访问
			son::base::m_a;    //子类类名访问父类静态，第一个双冒号表示，类名访问，第二个表示作用域
			2.访问函数
			son1.func();       //对象访问  
			son1.base::func();
			son::func();       //类名访问
			son::base::func();

		6.多继承
			并不推荐使用！
			class cls1:public baseclass1,public baseclass2;
			class 子类:继承方式 父类1,继承方式 父类2;
			调用同名成员 需要加作用域区分 不同的父类

		7.菱形继承
			子类继承两份相同的数据，导致资源浪费
			虚继承解决
				class cls1:virtual public baseclass; 虚继承，baseclass为虚基类
				虚继承之后，同名数据只保留一个，继承的是一个虚基类指针
			class Person
			{
			public:
				int age = 10;
			private:
			};
			class male :virtual public Person
			{
			};
			class female :virtual public Person
			{
			};
			class aliant :public male, public female
			{
			};
			aliant a;    调用	
			a.age = 20;
			cout << a.age << endl;

		8.动态多态
			问题：
				函数传入对象，会使地址早绑定
			满足条件：
				1.继承关系
				2.子类重写父类的虚函数，返回值 函数名 参数列表，必须完全一致，virtual关键字可以不写
			使用：
				多态可以实现 -> 父类指针可以指向子类对象
				!!!创建父类类型的指向子类的指针!!!也可以调用
					Cat cat;
					test(&cat);
					test(new Cat);
			代码：
				成员函数前加virtual，为虚函数，在调用时才绑定地址

		9.多态原理
			
		10.纯虚函数和抽象类
			纯虚函数：
			virtual void func() = 0;
			有纯虚函数即为抽象类
			* 抽象类无法实例化
			* 抽象类的子类必须重写纯虚函数，否则无法实例化，也属于抽象类
		
		11.虚析构和纯虚析构
			虚析构释放子类堆区变量，存在纯虚析构即为抽象类
				抽象类存在虚析构，则基类必须重写虚构函数
				没有虚析构的 构造析构顺序：
				* 父类构造
				* 子类构造
				* 父类析构
				子类的析构函数没有调用
			纯虚析构需要声明也需要实现
				virtual ~AbstractClass() = 0;           类内声明
				AbstractClass::~AbstractClass(){};		类外实现

			
	*/
	//文件操作
	/*
	三大类：
	* 写    ofstream
	* 读	  ifstream
	* 读写  stream
	* 
	一.写
		1. 包含头文件
		   #include <fstream>
		2. 创建流对象
		   ofstream ofs;
		3. 打开文件
		   ofs.open("文件路径",打开方式);
		4. 写数据
		   ofs << "写入的数据";
		5. 关闭文件
		   ofs.close();    //必须关闭

		打开方式 
		ios::in     | 为读文件而打开文件         
		ios::out    | 为写文件而打开文件         
		ios::ate    | 初始位置：文件尾           
		ios::app    | 追加方式写文件             
		ios::trunc  | 如果文件存在先删除，再创建 
		ios::binary | 二进制方式                 

		配合方法：|

	二.读
		1. 包含头文件   
		   #include <fstream>
		2. 创建流对象  
		   ifstream ifs;
		3. ☆☆☆☆☆☆打开文件并判断文件是否打开成功☆☆☆☆☆☆
		   ifs.open("文件路径",打开方式);
		4. 读数据
		   四种方式读取
			第一种方式
			char buf[1024] = { 0 };
			while (ifs >> buf)
			{
				cout << buf << endl;
			}

			第二种
			char buf[1024] = { 0 };
			while (ifs.getline(buf,sizeof(buf)))
			{
				cout << buf << endl;
			}

			第三种
			string buf;
			while (getline(ifs, buf))
			{
				cout << buf << endl;
			}

			char c;
			while ((c = ifs.get()) != EOF) //end of file
			{
				cout << c;
			}

			ifs.close();
		5. 关闭文件
		   ifs.close();

	三.二进制
			写：
			ofs.write((const char *)&p, sizeof(p));
			读：
			ifstream ifs("person.txt", ios::in | ios::binary);
			if (!ifs.is_open())
			{
				cout << "文件打开失败" << endl;
			}

			Person p;
			ifs.read((char *)&p, sizeof(p));

			cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;

			*/
	//模板
	/*
	模板创建自定义关键字类型
	最好用显示指定类型

	template  ---  声明创建模板
	typename  --- 表面其后面的符号是一种数据类型，可以用class代替
	T    ---   通用的数据类型，名称可以替换，通常为大写字母

	利用模板提供通用的交换函数
	template<class T>
	void mySwap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}

	调用：
		1、自动类型推导  //自推导型必须数据类型一致
		mySwap(a, b);
		2、显示指定类型
		mySwap<int>(a, b);

		* 普通函数调用时可以发生自动类型转换（隐式类型转换）
		* 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
		* 如果利用显示指定类型的方式，可以发生隐式类型转换
		myfunc<int>(a, c);   //最好是用显示类型转换

	重载情况：
		1. 都可以实现，优先调用☆普通函数☆
		2. 可以通过空模板参数列表来强制调用函数模板
			myfunc<>(a, c);   //空尖括号
		3. ☆☆☆函数模板也可以发生重载
		4. ☆☆☆如果函数模板可以产生更好的匹配,优先调用函数模板
		

	类模板：
		1.类模板          ***只能用显示： ->  person<int,string>p;
			template<class NameType, class AgeType>
			类模板显然不能自动类型推导

			1. 类模板没有自动类型推导的使用方式
			// 指定NameType 为string类型，AgeType 为 int类型
			Person<string, int>P1("孙悟空", 999);
			
			2. 类模板在模板参数列表中可以有默认参数
			template<class NameType, class AgeType = int>
			class Person
			则可 => Person <string> p("猪八戒", 999);

			3. ☆☆☆类模板在调用阶段才会创建成员函数  因为调用之前无法确定  模板的具体类型	

				1、指定传入的类型         <最常用的>
					void printPerson1(Person<string, int> &p)

				2.函数参数模板化
					只需在声明前加入模板语句
					template <class T1, class T2>
					void printPerson2(Person<T1, T2>&p)

				3.获取模板具体关键字名
					cout << "T的类型为： " << typeid(T).name() << endl;

				4.或者直接整个类模板化
					template<class T>
					void printPerson3(T & p)


		4.类模板继承
		* 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
		* 如果不指定，编译器无法给子类分配内存
		* 如果想灵活指定出父类中T的类型，子类也需变为类模板
		template<class T>
		class Base
		{
			T m;
		};
		template<class T1, class T2> //******其中T1为继承的父类模板量，T2为自身模板量
		class Son2 :public Base<T2>


		5.类模板成员函数类外实现

		模板类定义的时候类名后面都要带  person“<>”    <-尖括号
		并且头上还要声明模板

			1）构造函数 类外实现
			template<class T1, class T2>
			Person<T1, T2>::Person(T1 name, T2 age) {
				this->m_Name = name;
				this->m_Age = age;
			}

			2）成员函数 类外实现
			template<class T1, class T2>
			void Person<T1, T2>::showPerson() {
				cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << endl;
			}
	
		6.类模板份文件编写
			1）由于类模板的成员函数创建时机是在调用阶段，导致分文件编写时链接不到
			vs2019好像没有这个问题
			解决方法是在头文件中加上类成员函数实现，并把文件类型改为.hpp ，用的时候包含.hpp 文件就行了

		7.类模板与友元
			













	*/
	//容器
	/*
	STL大体分为六大组件，分别是:**容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器**

	1.容器
		1.vector
		#include <vector>

		void fun(int val)
		{
			cout << val << endl;
		}
		void test01()
		{
			vector<int> a;
			a.push_back(10);
			a.push_back(20);                   //插入
			a.push_back(30);
			a.push_back(40);
			a.push_back(50);
			for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
			{
				cout << *it << endl;			//遍历
			}
			for_each(a.begin(), a.end(), fun); //算法遍历，起点 终点 和行为；
		}

		容器嵌套——>二维容器

		2.string容器
			1.构造函数
			* `string();`          				//创建一个空的字符串 例如: string str;
			* `string(const char* s);`	        //使用字符串s初始化
			* `string(const string& str);`      //使用一个string对象初始化另一个string对象
			* `string(int n, char c);`          //使用n个字符c初始化
			
			2.赋值操作
			赋值的函数原型：
			* `string& operator=(const char* s);`           //char*类型字符串 赋值给当前的字符串
			* `string& operator=(const string &s);`         //把字符串s赋给当前的字符串
			* `string& operator=(char c);`                  //字符赋值给当前的字符串
			* `string& assign(const char *s);`              //把字符串s赋给当前的字符串
			* `string& assign(const char *s, int n);`       //把字符串s的前n个字符赋给当前的字符串
			* `string& assign(const string &s);`            //把字符串s赋给当前字符串
			* `string& assign(int n, char c);`              //用n个字符c赋给当前字符串
		
			3.字符串拼接
			* `string& operator+=(const char* str);`              //重载+=操作符
			* `string& operator+=(const char c);`                 //重载+=操作符
			* `string& operator+=(const string& str);`            //重载+=操作符
			* `string& append(const char *s); `                   //把字符串s连接到当前字符串结尾
			* `string& append(const char *s, int n);`             //把字符串s的前n个字符连接到当前字符串结尾
			* `string& append(const string &s);`                  //同operator+=(const string& str)
			* `string& append(const string &s, int pos, int n);`  //字符串s中从pos开始的n个字符连接到字符串结尾

			4.字符串的查找和替换
			* `int find(const string& str, int pos = 0) const;`      //查找str第一次出现位置,从pos开始查找
			* `int find(const char* s, int pos = 0) const; `         //查找s第一次出现位置,从pos开始查找
			* `int find(const char* s, int pos, int n) const; `      //从pos位置查找s的前n个字符第一次位置
			* `int find(const char c, int pos = 0) const; `          //查找字符c第一次出现位置
			* `int rfind(const string& str, int pos = npos) const;`  //查找str最后一次位置,从pos开始查找
			* `int rfind(const char* s, int pos = npos) const;`      //查找s最后一次出现位置,从pos开始查找
			* `int rfind(const char* s, int pos, int n) const;`      //从pos查找s的前n个字符最后一次位置
			* `int rfind(const char c, int pos = 0) const;  `        //查找字符c最后一次出现位置
			* `string& replace(int pos, int n, const string& str); ` //替换从pos开始n个字符为字符串str
			* `string& replace(int pos, int n,const char* s); `      //替换从pos开始的n个字符为字符串s
			
			5.字符串比较
			* `int compare(const string &s) const; `        //与字符串s比较
			
			6.字符存取
			* `char& operator[](int n); `     //通过[]方式取字符
			* `char& at(int n);   `           //通过at方法获取字符

			7.插入和删除
			* `string& insert(int pos, const char* s);  `       //插入字符串
			* `string& insert(int pos, const string& str); `    //插入字符串
			* `string& insert(int pos, int n, char c);`         //在指定位置插入n个字符c
			* `string& erase(int pos, int n = npos);`           //删除从Pos开始的n个字符   
			str.insert(1, "111");  //从1号开始改变
			str.erase(1, 3);       //从1号开始删除

			8.子串
			* `string substr(int pos = 0, int n = npos) const;` //返回由pos开始的n个字符组成的字符串
			
			string email = "hello@sina.com";
			int pos = email.find("@");
			string username = email.substr(0, pos);             //示例找到@位置并取前面的字符串

		
		3.vector容器深入
			*动态扩展
			1.构造函数
			* `vector<T> v; `               		 //默认构造函数
			* `vector(v.begin(), v.end());    ***只要是指针就可以，不一定非要begin，end       //将v[begin(), end())区间中的元素拷贝给本身。
			* `vector(n, elem);`                     //构造函数将n个elem拷贝给本身。
			* `vector(const vector &vec);`           //拷贝构造函数。

			2.赋值
			* `vector& operator=(const vector &vec);`//重载等号操作符
			* `assign(beg, end);`                    //将[beg, end)区间中的数据拷贝赋值给本身。
			* `assign(n, elem);`                     //将n个elem拷贝赋值给本身。
			例如：
			v3.assign(v1.begin(), v1.end());
			v4.assign(10, 100);

			3.容量和大小
			* `empty(); `                            //判断容器是否为空
			* `capacity();`                          //容器的容量
			* `size();`                              //返回容器中元素的个数
			* `resize(int num);`            0填充    //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
			  ​					       短了则删除    //如果容器变短，则末尾超出容器长度的元素被删除。
			* `resize(int num, elem);`   elem填充    //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
			  ​				           短了则删除    //如果容器变短，则末尾超出容器长度的元素被删除

			4.插入和删除
			* `push_back(ele);`                                 //尾部插入元素ele
			* `pop_back();`                                     //删除最后一个元素
			* `insert(const_iterator pos, ele);`                //迭代器指向位置pos插入元素ele
			* `insert(const_iterator pos, int count,ele);`      //迭代器指向位置pos插入count个元素ele
			* `erase(const_iterator pos);`                      //删除迭代器指向的元素
			* `erase(const_iterator start, const_iterator end);`//删除迭代器从start到end之间的元素
			* `clear();`                                        //删除容器中所有元素

			5.数据存取
			* `at(int idx); `        //返回索引idx所指的数据
			* `operator[]; `         //返回索引idx所指的数据
			* `front(); `            //返回容器中第一个数据元素
			* `back();`              //返回容器中最后一个数据元素

			6.vector互换
			* `swap(vec);`  // 将vec与本身的元素互换
			互换妙用：
			//收缩内存
			vector<int>(v).swap(v); //匿名对象
			
			原理刨析
			1.互换会换掉所有属性，无论是大小还是容量，但拷贝构造只拷贝大小
			2.vector拷贝构造只创建与传入参数的大小相等的容量
			3.第一个括号是调用了vector拷贝构造函数，将v的大小拷贝给匿名对象，匿名对象的容量大小相等，其值为传入参数大小
			3.匿名对象只存在一行代码，代码结束后匿名对象被释放

		4.deque容器
			双端容器
			1.构造
			* `deque<T>` deqT;             //默认构造形式
			* `deque(beg, end);`           //构造函数将[beg, end)区间中的元素拷贝给本身。
			* `deque(n, elem);`            //构造函数将n个elem拷贝给本身。
			* `deque(const deque &deq);`   //拷贝构造函数

			2.赋值操作
			* `deque& operator=(const deque &deq); `  //重载等号操作符
			* `assign(beg, end);`                     //将[beg, end)区间中的数据拷贝赋值给本身。
			* `assign(n, elem);`                      //将n个elem拷贝赋值给本身。

			3.大小操作
			* `deque.empty();`             //判断容器是否为空
			* `deque.size();`              //返回容器中元素的个数
			* `deque.resize(num);`         //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
			  ​			                   //如果容器变短，则末尾超出容器长度的元素被删除。
			* `deque.resize(num, elem);`   //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
			  ​                             //如果容器变短，则末尾超出容器长度的元素被删除。
			
			4.插入和删除
			* `insert(pos,elem);`       //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
			* `insert(pos,n,elem);`     //在pos位置插入n个elem数据，无返回值。
			* `insert(pos,beg,end);`    //在pos位置插入[beg,end)区间的数据，无返回值。
			* `clear();`                //清空容器的所有数据
			* `erase(beg,end);`         //删除[beg,end)区间的数据，返回下一个数据的位置。
			* `erase(pos);`             //删除pos位置的数据，返回下一个数据的位置。
			
			//尾插                      //尾删
			d.push_back(10);            d.pop_back();
			//头插                      //头删
			d.push_front(100);	        d.pop_front();
			
			5.数据存取
			- `at(int idx); `     //返回索引idx所指的数据
			- `operator[]; `      //返回索引idx所指的数据
			- `front(); `         //返回容器中第一个数据元素
			- `back();`           //返回容器中最后一个数据元素

			6.排序
			* `sort(iterator beg, iterator end)`  //对beg和end区间内元素进行排序
	
		5.stack容器
			栈区容器，先进后出，不允许遍历		

			* `stack<T> stk;`               //stack采用模板类实现， stack对象的默认构造形式
			* `stack(const stack &stk);`    //拷贝构造函数
			赋值操作：
			* `stack& operator=(const stack &stk);` //重载等号操作符
			数据存取：
			* `push(elem);`           //向栈顶添加元素
			* `pop();`                //从栈顶移除第一个元素
			* `top(); `               //返回栈顶元素
			大小操作：
			* `empty();`              //判断堆栈是否为空
			* `size(); `              //返回栈的大小

		6.queue容器
			队列容器，先进先出，只允许一端新增一端移除

			构造函数：
			- `queue<T> que;`            //queue采用模板类实现，queue对象的默认构造形式
			- `queue(const queue &que);` //拷贝构造函数
			赋值操作：
			- `queue& operator=(const queue &que);` //重载等号操作符
			数据存取：
			- `push(elem);`         //往队尾添加元素
			- `pop();`              //从队头移除第一个元素
			- `back();`             //返回最后一个元素
			- `front(); `           //返回第一个元素
			大小操作：
			- `empty();`            //判断堆栈是否为空
			- `size(); `            //返回栈的大小

		7.list容器
			链表容器：list是双向循环链表

			1.构造函数
			* `list<T> lst;`           //list采用采用模板类实现,对象的默认构造形式：
			* `list(beg,end);`         //构造函数将[beg, end)区间中的元素拷贝给本身。
			* `list(n,elem);`          //构造函数将n个elem拷贝给本身。
			* `list(const list &lst);` //拷贝构造函数。

			2.赋值和交换
			* `assign(beg, end);`                  //将[beg, end)区间中的数据拷贝赋值给本身。
			* `assign(n, elem);`                   //将n个elem拷贝赋值给本身。
			* `list& operator=(const list &lst);`  //重载等号操作符
			* `swap(lst);`                         //将lst与本身的元素互换。

			3.大小操作
			* `size(); `            //返回容器中元素的个数
			* `empty(); `           //判断容器是否为空
			* `resize(num);`        //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
			  ​					    //如果容器变短，则末尾超出容器长度的元素被删除。
			* `resize(num, elem); ` //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
								​	//如果容器变短，则末尾超出容器长度的元素被删除。

			4.插入和删除
			* push_back(elem);            //在容器尾部加入一个元素
			* pop_back();                 //删除容器中最后一个元素
			* push_front(elem);           //在容器开头插入一个元素
			* pop_front();                //从容器开头移除第一个元素
			* insert(pos,elem);   指针    //在pos位置插elem元素的拷贝，返回新数据的位置。
			* insert(pos,n,elem);         //在pos位置插入n个elem数据，无返回值。
			* insert(pos,beg,end);        //在pos位置插入[beg,end)区间的数据，无返回值。
			* clear();                    //移除容器的所有数据
			* erase(beg,end);             //删除[beg,end)区间的数据，返回下一个数据的位置。
			* erase(pos);         指针    //删除pos位置的数据，返回下一个数据的位置。
			* remove(elem);               //删除容器中所有与elem值匹配的元素。

			5.数据存取
			* `front();`        //返回第一个元素。
			* `back();`         //返回最后一个元素。

			6.反转和排序
			* `reverse();`      //反转链表
			* `sort();`         //链表排序     
								需要包含基本算法，但此处不能用全局函数的sort，
								不支持随机访问的迭代器，内部会提供对应的算法成员函数
			
			//默认的排序规则 从小到大：
			L.sort(); 

			从大到小需要自己写回调函数：
			bool myCompare(int val1 , int val2)
			{
				return val1 > val2;
			}
			
			L.sort(myCompare); 

		8.set容器
			二叉树容器，自动排序，set容器不允许重复插入，multiset允许
			
			1.构造
			* `set<T> st;`                        //默认构造函数：
			* `set(const set &st);`               //拷贝构造函数
			* `set& operator=(const set &st);`    //重载等号操作符
			* `insert();`                         //插入数据时用insert

			2.大小和交换
			* `size();`          //返回容器中元素的数目
			* `empty();`         //判断容器是否为空
			* `swap(st);`        //交换两个集合容器

			3.插入和删除
			* `insert(elem);`    //在容器中插入元素。
			* `clear();`         //清除所有元素
			* `erase(pos);` 指针 //删除pos迭代器所指的元素，返回下一个元素的迭代器。
			* `erase(beg, end);` //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
			* `erase(elem);`     //删除容器中值为elem的元素。

			4.查找和统计
			* `find(key);`       //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
			* `count(key);`      //统计key的元素个数
			
			5.multiset
			* set不可以插入重复数据，而multiset可以
			* set插入数据的同时会返回插入结果，表示插入是否成功
			* multiset不会检测数据，因此可以插入重复数据

			pair的创建
			* `pair<type, type> p ( value1, value2 );`
			* `pair<type, type> p = make_pair( value1, value2 );`
			
			6.set容器指定排序顺序
			需要用自定义类来写仿函数
				class MyCompare
				{
				public:
					bool operator()(int v1, int v2) {
						return v1 > v2;
					}
				};
			
				set<int,MyCompare> s1;  //这样才定义好了排序方式
			自定义数据类型同理：
				class comparePerson
				{
				public:
					bool operator()(const Person& p1, const Person &p2)
					{
						//按照年龄进行排序  降序
						return p1.m_Age > p2.m_Age;
					}
				};
				
				set<Person, comparePerson> s;

			7.map/multimap容器
			自动排序
			map中的数据类型为pair，其中第一个值为key 第二个值为value，可以根据key值快速找到value值，底层结构是用二叉树实现。
			1.构造和赋值
			* `map<T1, T2> mp;`                   //map默认构造函数: 
			* `map(const map &mp);`               //拷贝构造函数
			* `map& operator=(const map &mp);`    //重载等号操作符
			
			map<int,int>m; //默认构造
			m.insert(pair<int, int>(1, 10));      //插入

			2.大小和交换
			- `size();`          //返回容器中元素的数目
			- `empty();`        //判断容器是否为空
			- `swap(st);`      //交换两个集合容器

			3.插入和删除
			- `insert(elem);`           //在容器中插入元素。
			//第一种插入方式
			m.insert(pair<int, int>(1, 10));
			//第二种插入方式
			m.insert(make_pair(2, 20));
			//第三种插入方式
			m.insert(map<int, int>::value_type(3, 30));

			不建议用[]插入，建议用[]访问

			- `clear();`                //清除所有元素
			- `erase(pos);`   指针删除  //删除pos迭代器所指的元素，返回下一个元素的迭代器。
			- `erase(beg, end);`        //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
			- `erase(key);`     按key删 //删除容器中值为key的元素。

			4.查找和统计
			- `find(key);`          //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
			- `count(key);`         //统计key的元素个数

			5.排序

			仿函数：
				class MyCompare {
				public:
					bool operator()(int v1, int v2) {
						return v1 > v2;
					}
				};
			map<int,int,MyCompare> m;











	*/
	//仿函数/函数对象
	/*
	1.仿函数
	重载 "函数调用操作符" 的类，其对象常称为**函数对象**
	函数对象**使用重载的()时，行为类似函数调用，也叫**仿函数**
	其本质是类，而不是函数

	特点：
	* 函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
	* 函数对象超出普通函数的概念，函数对象可以有自己的状态
	* 函数对象可以作为参数传递


	2.谓词
	返回bool类型的仿函数称为谓词，根据接收变量数量不同分为一元谓词和二元谓词

	3.内建仿函数
		1）算数仿函数
		plus<T>`                //加法仿函数
		minus<T>`               //减法仿函数
		multiplies<T>`          //乘法仿函数
		divides<T>`             //除法仿函数
		modulus<T>`             //取模仿函数
		negate<T>`              //取反仿函数

		用法
		plus<int> p;
		cout << p(10, 20) << endl;

		2）关系仿函数        *** #include <functional> ***
		equal_to<T>`                //等于
		not_equal_to<T>`            //不等于
		greater<T>`                 //大于
		greater_equal<T>`           //大于等于
		less<T>`                    //小于
		less_equal<T>`              //小于等于

		用法：
		*** #include <functional> ***
		sort(v.begin(), v.end(), greater<int>());

		3）逻辑仿函数
		logical_and<T>`              //逻辑与
		logical_or<T>`               //逻辑或
		logical_not<T>`              //逻辑非

	4.常用算法
		* 算法主要是由头文件`<algorithm>` `<functional>` `<numeric>`组成。
		* `<algorithm>`是所有STL头文件中最大的一个，范围涉及到比较、 交换、查找、遍历操作、复制、修改等等
		* `<numeric>`体积很小，只包括几个在序列上面进行简单数学运算的模板函数
		* `<functional>`定义了一些模板类,用以声明函数对象。
	
		1.常用遍历
		* `for_each`     //遍历容器
		* `transform`   //搬运容器到另一个容器中
			
			1）for_each
				//普通函数
				void print01(int val)
				{
					cout << val << " ";
				}
				//函数对象
				class print02
				{
				 public:
					void operator()(int val)
					{
						cout << val << " ";
					}
				};
			for_each(v.begin(), v.end(), print01); //一行搞定，在后面加回调函数或者仿函数都可以
		
			2）transform  搬运
			* `transform(iterator beg1, iterator end1, iterator beg2, _func);`
			vector<int>vTarget; //目标容器
			vTarget.resize(v.size()); // 目标容器需要提前开辟空间		

				class TransForm
				{
				public:
					int operator()(int val)
					{
						return val;
					}

				};
			transform(v.begin(), v.end(), vTarget.begin(), TransForm());
	
		2.常用查找
			1）find
			- `find(iterator beg, iterator end, value);  `
			 // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
				vector<int> v;
				for (int i = 0; i < 10; i++) {
					v.push_back(i + 1);
				}
				//查找容器中是否有 5 这个元素
				vector<int>::iterator it = find(v.begin(), v.end(), 5);
				if (it == v.end())
				{
					cout << "没有找到!" << endl;
				}
				else
				{
					cout << "找到:" << *it << endl;
				}

			2）find_if
			- `find_if(iterator beg, iterator end, _Pred);  `
			  // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
			  // _Pred 函数或者谓词（返回bool类型的仿函数）
				
				vector<int>::iterator it = find_if(v.begin(), v.end(), 谓词());

			3）ajiacent_find
			查找相邻重复元素
			- `adjacent_find(iterator beg, iterator end);  `    
			  // 查找相邻重复元素,返回相邻元素的第一个位置的迭代器

				vector<int>::iterator it = adjacent_find(v.begin(), v.end());

			4）binary_search  //二分查找
			- `bool binary_search(iterator beg, iterator end, value);  `
			  // 查找指定的元素，查到 返回true  否则false
			  在**无序序列中不可用**

			5）count
			- `count(iterator beg, iterator end, value);  `
			  // 统计元素出现次数
			
			6）count_if
			- `count_if(iterator beg, iterator end, _Pred);  `
			  // 按条件统计元素出现次数

		3.常用排序
			- `sort`             //对容器内元素进行排序
			- `random_shuffle`   //洗牌   指定范围内的元素随机调整次序
			- `merge `           // 容器元素合并，并存储到另一容器中
			- `reverse`          // 反转指定范围的元素

			1）sort
			- `sort(iterator beg, iterator end, _Pred);  `
			  // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置

			2）random_shuffle    // 洗牌   指定范围内的元素随机调整次序
			- `random_shuffle(iterator beg, iterator end, );  `
			  // 指定范围内的元素随机调整次序

			  for_each(v.begin(), v.end(), myPrint());

			3）merge             // 合并
			* 两个容器元素合并，并存储到另一容器中
			- `merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  `
			  // 注意: 两个容器必须是**有序的**
			  // beg1   容器1开始迭代器
			  // end1   容器1结束迭代器
			  // beg2   容器2开始迭代器
			  // end2   容器2结束迭代器
			  // dest   目标容器开始迭代器

			4）reverse           // 反转
			- `reverse(iterator beg, iterator end);  `

		4.拷贝和替换算法
		- `copy`                 // 容器内指定范围的元素拷贝到另一容器中
		- `replace`              // 将容器内指定范围的旧元素修改为新元素
		- `replace_if `          // 容器内指定范围满足条件的元素替换为新元素
		- `swap`                 // 互换两个容器的元素
			
			1）copy
			- `copy(iterator beg, iterator end, iterator dest);  `
			  // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置

			2）replace
			- `replace(iterator beg, iterator end, oldvalue, newvalue);  `
			  // 将区间内旧元素 替换成 新元素
			 按值查找

			3）replace_if
			- `replace_if(iterator beg, iterator end, _pred谓词, newvalue);  `
			  // 按条件替换元素，满足条件的替换成指定元素

			4）swap
			- `swap(container c1, container c2);  `
			  // 互换两个容器的元素

		5.常用算数生成算法
		- `accumulate`           // 计算容器元素累计总和
		- `fill`                 // 向容器中添加元素

			1）accumulate
			*  计算区间内 容器元素累计总和
			- `accumulate(iterator beg, iterator end, value);  `
			  // 计算容器元素累计总和
			  // value 为起始值，初值一般为0

			2）fill
			* 向容器中填充指定的元素
			- `fill(iterator beg, iterator end, value);  `
			  // value 填充的值

		6.常用集合算法
		- `set_intersection`          // 求两个容器的交集
		- `set_union`                 // 求两个容器的并集
		- `set_difference `           // 求两个容器的差集

			1）set_intersection
			* 求两个容器的交集
			  // **注意:两个集合必须是有序序列**
			- `set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  `
			  // dest 目标容器开始迭代器

			  for_each(vTarget.begin(), itEnd, myPrint()); ***迭代输出时必须用返回的迭代器itEnd***

			2）set_union
			* 求两个集合的并集
			  // **注意:两个集合必须是有序序列**
			- `set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  `
			  // dest 目标容器开始迭代器

			  for_each(vTarget.begin(), itEnd, myPrint()); ***迭代输出时必须用返回的迭代器itEnd***

			3）set_difference
			* 求两个集合的差集
			  // **注意:两个集合必须是有序序列**
			- `set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  `
			  // dest 目标容器开始迭代器
			  
			  ***注意顺序，得到的值是，前面的容器减去和后面容器交集的部分***

			  for_each(vTarget.begin(), itEnd, myPrint()); ***迭代输出时必须用返回的迭代器itEnd***

	*/
	//理解仿函数
	/*
			class Person
			{
			public:
				Person(string name, int age)
				{
					this->m_Name = name;
					this->m_Age = age;
				}
				bool operator==(const Person & p)
				{
					if (this->m_Age == p.m_Age)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				string m_Name;
				int m_Age;
			};

			void test02()
			{
				vector<Person> v;

				Person p1("刘备", 35);
				Person p2("关羽", 35);
				Person p3("张飞", 35);
				Person p4("赵云", 30);
				Person p5("曹操", 25);

				v.push_back(p1);
				v.push_back(p2);
				v.push_back(p3);
				v.push_back(p4);
				v.push_back(p5);

				Person p("诸葛亮",35);

				int num = count(v.begin(), v.end(), p);  //自定义数据类型，底层代码用的 < > == 无法比较，需要在p中将运算符重载。
				cout << "num = " << num << endl;
			}
			int main() {
				test02();
				system("pause");
				return 0;
			}
	*/

}
void 代码() {
	//猜数
	/*
	srand((unsigned int)time(NULL));//生成随机数
	int a, b, c = 0,k = 8;
	b = rand() % 100 + 1;
	cout << "请输入一个数" << endl;
	while (1)
	{
		cout << "你还有" << (k - c) << "次机会" << endl;
		cin >> a;
		c++;
		if (a < b)
		{
			cout << "小了哥" << endl;
		}
		else if (a > b)
		{
			cout << "大了哥" << endl;
		}
		else
		{
			cout << "对了哥" << endl;
			break;
		}
		if (c >= k)
		{
			cout << "游戏结束" << endl;
			break;
		}
	}
	*/
	//水仙花数
	/*
	int num = 100, a = 0, b = 0, c = 0,d;
	do
	{
		a = num % 10;
		b = num / 10 % 10;
		c = num / 100;
		d = c * c * c + b * b * b + a * a * a;
		if (num == d)
		{
			cout << num << endl;
		}
		num++;

	} while (num < 1000);
	*/
	//敲桌子
	/*
	for (int i = 0; i < 100; i++)
	{
		if (i % 7 == 0|| i % 10 == 7 || i / 10 % 10 == 7)
		{
			cout << "拍桌子" << endl;
		}
		else
		{
			cout << i << endl;
		}
	}
	*/
	//打印乘法口诀表
	/*
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < i + 1; j++)
		{
			cout <<j << "*" << i << "=" << i * j << " ";
		}
		cout << endl;
	}
	*/
	//起泡法从小到大输出
	/*
	int a, k = 14;
	int arr[14];
	cout << "请输入" << k << "个数" << endl;
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i; j < k - 1; j++)
		{
			if (arr[i] > arr[j + 1])
			{
				a = arr[i], arr[i] = arr[j + 1], arr[j + 1] = a;
			}
		}
	}
	cout << "从小到大为：";
	for (int i = 0; i < k; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << "从大到小为：";
	for (int i = 0; i < k; i++)
	{
		cout << arr[k - 1 - i] << " ";
	}
	cout << endl;
	*/
	//加和
	/*
	int a, b, c;
	cout << "请输入两个数字" << endl;
	cin >> a >> b;
	cout << "和为：" << add(a, b) << endl;
	*/
	//封装冒泡函数
	/*
	int arr[5];
	int len = sizeof(arr) / sizeof(arr[0]);
	cout << "请输入" << len << "个数" << endl;
	for (int i = 0; i < len; i++)
	{
		cin >> arr[i];
	}
	cout << "冒泡前的实参数组为:";
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	冒泡(arr, len);                  //形参为首地址和长度
	printArray(arr, len);
	cout << "冒泡后的实参数组为:";
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	*/
    //封装教师结构体
	/*
	struct stu
	{
	string name;
	int score;
	};
	struct teach
	{
	string name;
	struct stu s1[5];
	};
	
	srand((unsigned int)time(NULL));
	struct teach tarr[3];
	int len = sizeof(tarr) / sizeof(tarr[0]);
	allocate(tarr, len);
	printTeacher(tarr,len);

	*/
	//点与圆关系
	/*
	struct cp//定义点结构体 圆心和点
	{
		int x;
		int y;
	};
	class cycle //圆类，属性有圆心和半径，圆心是点结构体
	{
	public:
		cycle()
		{
			cout << "构造调用" << endl;
		}
		~cycle()
		{
			cout << "析构调用" << endl;
		}
		void setr(int r)
		{
			c_r = r;
		}
		void setc(cp c)
		{
			c_c = c;
		}
		void judge(cp &p)//成员函数判断，只需传入点的地址就行了，圆心类内已有
		{
			int D = (p.x - c_c.x)* (p.x - c_c.x) +
			(p.y - c_c.y) * (p.y - c_c.y);
			int R = c_r * c_r;
			if (D == 0)
			{
				cout << "is center" << endl;
			}else if (D == R)
			{
				cout << "on the cycle" << endl;
			}
			else if (D < R)
			{
				cout << "in the cycle" << endl;
			}
			else
			{
				cout << "in the out" << endl;
			}
		}
	private:
		int c_r;
		cp c_c;
	};

	主函数如下：
	cp p;
	int x, y;
	cout << "please type the point" << endl;
	cin >> x >> y;
	p.x = x;
	p.y = y;
	int R = 20;
	cp cp;
	cp.x = 30;
	cp.y = 30;
	cycle C1;
	C1.setr(R);
	C1.setc(cp);
	C1.judge(p);
	*/
	//快排
	class quicklysort
	{
	public:
		void quicksort(int arr[], int l, int r)
		{
			if (l < r)
			{
				srand((unsigned int)time(NULL));
				swap(arr, ((int)rand() % (r - l + 1)) + l, r);	//随机取一位，为中间位，与最后一位交换
				int left = l;									//left维护数组左端位置
				int less = l - 1;								//less为小于区域最后一个值 less<mid
				int more = r;									//more为大于区域的前一个值 more>mid
				while (l < more)
				{
					if (arr[l] < arr[r])
					{
						swap(arr, ++less, l++);					//小于情况先加less，此时less为等于区最后一个值，再换less和l，再l++，直到l与more汇合
					}
					else if (arr[l] > arr[r])
					{
						swap(arr, --more, l);					//大于情况先减more，此时more为r左边一个未排序的值，再把l的值换到more上，注意此时l的值仍未排序，l不++
					}
					else
					{
						l++;									//等于情况l++，l始终为等于区下一个值
					}
				}
				swap(arr, r, more);								//排序完成后将置后的r与more交换
				quicksort(arr, left, less);					//left为数组最左端，less为等于区前一个位置
				quicksort(arr, more + 1, r);						//r为数组最右端，more+1为等于区后一个位置
			}
		}
		void swap(int arr[], int a, int b)
		{
			int tmp = arr[a];
			arr[a] = arr[b];
			arr[b] = tmp;
		}
	};
	//
}






int add(int a, int b)
{

	int c = a + b;
	//cout << "形参a的地址为：" << &a << endl;
	return c;
}
void 冒泡(int* ak,int len)           //形参一为首地址位置，形参二为长度
{
	
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i; j < len - 1; j++)
		{
			if ( ak[i] > ak[j + 1])
			{
				int a = ak[i];       //这里的ak相当于指针了，将实参也改变了！！！
				ak[i] = ak[j + 1];   
				ak[j + 1] = a;
			}
		}
	}
}
void printArray(int* arr, int len)
{
	cout << "从小到大为：";
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << "从大到小为：";
	for (int i = 0; i < len; i++)
	{
		cout << arr[len - 1 - i] << " ";
	}
	cout << endl;
}
/*
void 学生信息(stu a)//值传递, "."
{
	cout << "姓名:" << a.name << endl <<  endl << "成绩：" << a.score << endl;
} 
void 指针学生信息(const stu* a)//地址传递, "->"
{
	cout << "姓名:" << a->name << endl <<  endl << "成绩：" << a->score << endl;
}
void allocate(struct teach tarr[], int len) //结构体初始化赋值
{
	string rank = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		tarr[i].name = "teacher_";
		tarr[i].name += rank[i];
		for (int j = 0; j < 5; j++)
		{
			tarr[i].s1[j].name = "student_";
			tarr[i].s1[j].name += rank[j];
			tarr[i].s1[j].score = rand() % 100;//随机数
		}
	}
}
void printTeacher(struct teach tarr[], int len)//结构体打印
{
	for (int i = 0; i < len; i++)
	{
		cout << "老师名字：" << tarr[i].name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "学生名字：" << tarr[i].s1[j].name << " 学生成绩：" << tarr[i].s1[j].score << " ";
		}
		cout << endl;
	}
}
*/