short 至少16（大部分16）（short int）
int（大部分32位） 至少与short
long至少32 且至少与int（大部分32）(long int)
ll 至少64 且至少与long
头文件climits定义INT_MAX为int的最大值，CHAR_BIT为字节位数
sizeof + 运算符要加括号； + 变量名可加可不加
#include与#define为预处理指令 创造常量可用#define INT_MAX 32767，但C++有更好的创建符号常量的方法：使用const
C++定义变量的一种方法：int wrens(432);int rocs{} / int rocs = {} 大括号用于单值变量 初始化为0
程序储存常量的值，默认为int，可通过后缀或者值太大来改变。（p47）
char字符集：Unicode、ISO 10646表示方法为转义序列\u加4位16进制数 / \U + 8位16进制数(即更改char单个字符所占字节数)
宽字符类型：wchar_t所占字符为系统使用最大字符集的字符所占大小 。cin / cout将输出看作是char流，要使用定义在iostream里的wcin / wcout。   特定字符类型char16_t / char32_t无符号 ：使用前缀u修饰字符''或字符串""表示前者 / U表示后者
声明常量(用const)时没有提供值，其值不确定且无法修改(定义常量const比define好)
浮点数的另一种表示格式：E表示法3.45E6 3.45e + / -6 这种表示方法适合表示很大或很小的数(E表示法确定以浮点数形式表示没有小数点)
浮点数的有效位数：float至少32位 double64位 cout最多打印6位小数，且会删除结尾的0（有的float6位即只对前6位数操作才有影响，double15位？） 使用后缀f / F例如1.234f指定储存为float类，默认为double 当然也可显式转换(float)1.0
在计算表达式中bool，char，unsigned char，signed char，short会提升为int；wchar_t提升为足够储存的最小的一个：int，unsigned int，long，unsigned long
long：2111222333转换为float(6位有效数字)：2.11122E9损失精度
强制类型转换(typename)value / typename(value)eg:  cout << int('Q') 不过在表达式里不用这样
auto类型变量让编译器自动推断（用于复杂类型）
sizeof运算符 数组名 得到整个数组的字节长度；数组元素得到元素长度
列表初始化{}不允许数据缩窄
"S" isnot char but string(字符串字面值 / 字符数组（const char[2]）)
cin 读取一个字符串（即string） 通过空格 / 制表符 / 换行符判断字符串结束  istream类中的函数getline() / get()读取一整行，前者丢弃换行符，后者保留  类函数要作用于类对象：cin.getline()  不带任何参数的cin.get()读取下一个字符，可用来处理换行符(由于cout读取char时会忽略空格因此输入多个字符串时可用cin.get(ch)而非cin >> ch)；get更优，可查看下一个字符判断读取停止是由于到达换行符还是数组已满 get()读取空行后会设置失效位会阻断输入(输入流没有停止)可以用cin.clear()恢复。如果输入的比配置的字符数多两者均会保留，getline会设置失效位
string类是用户定义的一种类，位于名称空间std，特点是隐藏了字符串的数组性质，能像普通变量一样进行处理，由于类设计会自动调整大小，声明(不初始化)会创造长度为0的string变量 可以用a = b + c进行合并
头文件cstring内定义有strcpy()函数和strcat()函数，两者是用于字符数组类型的，非string类型变量后者appendrighttoleft，strcat会有right小导致覆盖的问题，有更安全的选择strncpy() / strncat()
string类内成员函数size() obtain length 未初始化的数组是未知内容的，空字符随机出现所以strlen()返回值可能更大
原始字符串：不转义，在字符串前面加前缀R，界限为"(和)"，其中引号与括号之间可以加东西，前面加的东西后面要加在括号前面而不是括号和引号之间eg +
istream类出现在string类之前，cin可以处理int，double，但不能处理string，可以运算符重载
初始化结构用大括号，可以每个值占一行并在行尾用逗号，也可在一行用逗号，等号可选，大括号内无东西会将各成员赋为0，数组的话字节全为0.结构可以直接用 = 互相赋值，可以创建没有名称的结构但必须同时声明一个变量且不能再创建这种类型的变量了，可以有结构数组，初始化时就是大括号套多个大括号了。位字段(:)可定义结构内各元素所占字节数。共用体union长度为最大成员的长度，可以匿名共用体在结构中，此时可以将union内元素直接视为结构内元素 枚举enum a { b, c, d, g } 枚举创建新类型a 和 符号常量b，c，d，g，对应整数0，1，2。枚举类型变量只能 = ，也就是说只能互相赋值不能算术运算 a f = b，但不能 = 3，int不能转换为枚举类型，但枚举量是整形，可转换为int：int i = 1 + b；b转换为int类型。可以强制类型转换a(3)。可以省略名称，这样只使用创造的常量。可以在其内自定义值eg c = 5，其他没有的，第一个默认为0，其余的未初始化的要求比前一个大1。 枚举的取值范围：，a f = a(j)，只要j在范围内任意一个整数均可
对于地址，int * p;p = (int*)0x...要把后面的转换为地址类型。地址占4字节即0x后面8位 有的int2字节。不能用delete释放非new的内存，不能重复delete已经delete过的，对空指针使用delete是安全的。 new int[10] 要用delete[]。  int i[10] & i为40个字节， & i + 1 地址加40 ； & i[0](即i)为4字节，所以i + 1将地址增加4。
const char* bird = "wren";字符串字面量注意用const，说明不能用bird改变wren(bird指针被声明为const，说明不能改变bird指向的东西)。有些编译器将字符串字面量的一个副本表示程序中所有的，有的可能储存多个。  给cout提供指针会打印地址，如果是char* 类型会打印字符串可以强制类型转换为(int*) 栈后进先出，静态储存块内用static，动态：堆。
数组的替代品：类模板 vector / array。前者要包含头文件<vector>, 定义在名称空间std中：vector<int> vi / vector<double> vi(n) 创建了一个vector对象，可储存n个double类型的元素，前者长度为0，因为vector对象可插入 自动调节大小  array长度固定使用栈：array <int, 5> ai = { 1,2,3 }, vector的n可为常量可为变量，后者只能常量；vector适用于大小不固定功能更强
通常定义一个const值表示数组中的元素。   前缀递增将值加1后返回结果，后缀复制副本将其加1后返回副本，对于内置类型无差别，对于用户定义的类型，前缀更高效(p135)   word == "mate"这种比较地址，比较内容要用strcmp()，相等返回0。 头文件ctime定义了符号常量CLOCKS_PER_SEC, 等于每秒包含的系统时间单位数。延迟循环：ctime头文件将clock_t作为clock()返回类型的别名，说明可以将变量声明为clock_t类型，编译器负责对类型进行转换。延迟循环将函数条件放在while循环条件内   创建类型别名：#define or typedef typename aliasName 。typedef更佳。不会创造新类型，只是为类型创造新名称   文件尾(EOF)，gofish.exe， gofish < file 输入重定向 ，键盘输入：ctrl + z模拟文件尾(EOF)。检测到EOF后cin将eodbit和failbit均设置为1，可用成员函数eof()查看eofbit，是EOF则cin.eof()会返回bool ture，fail()也是。两函数均返回最近读取的结果，fail()更常用。检测到EOF后cin将不再读取(不应超过文件尾的内容)(检测EOF将关闭对输入的进一步读取)，"此时cin.get()锁屏幕不起作用(因为不读取输入)"对于键盘输入可以用cin.clear()清除EOF标记(cin.clear清除输入流)，不过有的系统ctrl + z结束输入输出此时cin.clear()无法恢复
    istream类有函数可将对象转换为bool值 通常用于条件判断时，读取成功返回ture：while(cin) better than !cin.fail / eof(), cin.get(char) 返回cin所以可以while(cin.get(ch))。     cin.get()不接受任何参数 返回输入的下一个字符 遇到EOF会返回EOF其类型为int通常其值为 - 1符号常量EOF定义在头文件iostream中可用while(int i != EOF)有的系统char是无符号因此测试EOF要将返回值返回给int变量，cout.put(ch)：可传int会转换为char，不过有的提供了多个原型：char，signed char，unsigned char，此时传int会出错，因为转换int的方法有多个，可以显式转换char(i)
    cin.get(ch) and cin.get()前者赋给ch返回istream对象，可执行bool转换，后者返回一个int类型。对于前者到达EOF时不会赋给ch值(ch不会用来储存非char值)
    二维数组初始化可以大括号内多个大括号 一般用value == variable而不是variable == value这样可以发现错误” = “，取值范围要用 && 而不是连续的 < < 。   头文件cctype定义有字符函数库，isalpha()如果是字母返回非0值，否则返回0；ispunch()如果是标点符号返回ture。这些函数返回类型为int，但可通过bool转换视其为bool类型
    int n; cin >> n;用户输入单词而非数字 此时会发生：n的值不变，输入留在队列，cin对象中的一个错误标记被设置，对cin方法的调用会返回false(如果转换为bool类型)。 需要重置错误标记才能继续读取输入，用clear(), clear()也重置文件尾(EOF)。 输入错误与EOF都将使cin返回false(即两者均会配置错误标记 停止输入读取 需要clear后才能继续读取) 返回false说明可用非数字输入结束读取数字的循环
    保持程序运行输出可见连续用两个cin.get()。     （p191）上半页  p(196)下半页与197上半页

    在外界为a[]传入函数为b，sizeof(a)为整个数组长度，后者为指针长度


    防止传入的数组被修改可在函数声明中为const char a[]说明a指向的内容为常量不可通过a修改但原始数据不一定是常量只能说明不能在函数内通过指针来修改原始数据那么函数将数组是为只读。   指针指向常量int age = 39；const int* pt = &age；pt指向const int  不可将const的地址赋给非const指针   指针参数指向const使函数能接收const和非const实参否则只能接受非const。  const在变量名前而不是类型前说明只能指向该变量
    二维数组函数原型指定了列数，只需将行数当作参数传递：函数声明方法：int sum(int ar2[][4], int size); 函数参数不能用const，const只适用于基本类型的指针。  二维数组表示数据可以两个[], 也可以两次解引用* (*(ar2 + r) + c)    不需要处理负数可以声明为unsigned        使用数学库中的函数要包含头文件cmath，有些编译器需要显式链接数学库： - lm  传递array模板类：定义一个array类对象：std::array<double, 4> expenses;函数原型 show(std::array<double, 4> da);
函数地址是储存其机器代码的内存的开始地址，对用户没用对程序有用，可以作为参数传递给函数该函数可运行该函数 通过函数指针。函数名就是函数指针(不加括号)，传递函数指针直接在括号里填函数名也就是函数指针，这样在内部可以使用指针对应的函数。  声明函数指针只需将函数原型中的函数名改为 * +指针名即可， * 和指针名要括起来 接受函数指针的函数原型跟声明函数指针变量的表达式一样  函数指针数组[3]:const double* (*pa[3])(const double*, int) = { , , }，此时pa是一个数组 可用auto pb = pa()(自动类型推断只能用于单值初始化不能用于列表初始化)p241(typedef const double* (*p)(const double*, int) p p1 = pa[0]) / const double* f(const double*, int); p p1 = f;(const double* (*p1)(const double*, int) = f)
包含头文件时""文件名在见括号内会在标准系统文件中查找，双引号内会优先查找当前工作目录或源代码目录 没找到再找标准。如果要包含自己定义的头文件应使用引号而不是尖括号。    有关头文件包含头文件的问题，不能重复定义函数与常量与结构，可以重复声明。 每个头文件前包含#ifndef COORDIN_H_ / n #define COORDIN_H_ / n #endif 这样在一个文件内可以只包含一次头文件(头文件包含内容：函数原型 定义的符号常量 结构声明 类声明 模板声明 内联函数)   名称修饰（p304）
对于自动变量 储存在栈内(一段连续内存空间)，新数据被放在原有数据的上面使用完后将其删除，程序使用两个指针跟踪栈，一个指向栈底，栈的开始，另一个栈顶，下一个添加的位置。函数结束时栈顶指针重置到调用前的位置 新值未被删除，但不再标记。   静态变量在程序执行期间数目不变，因此不用复杂管理，将分配固定内存块，没有显式初始化默认为0，静态数组与结构的每个元素或成员的每个位设置为0(p310有完整介绍如果清楚则不用看)  零初始化或常量表达式初始化被称为静态初始化，编译器处理文件(翻译单元)时初始化变量，动态初始化在编译后初始化，如变量初始化时包含函数调用 需要函数被链接，程序执行时才能初始化。 所有静态变量都先被零初始化，其次判断是否为常量表达式(包含sizeof运算符) p313下半页的程序   p317说明符和限定符       一文件内定义了a，另一文件可static定义。 const定义类似static，即多个包含头文件的文件包含的cons定义的变量均为内部链接性，同时也说明常量的定义也是每个文件私有的不共享的，因此可将常量定义在头文件中 此时可在前面加extern使之成为外部         头文件包含内容：函数原型   可重复(同一文件内)，定义的符号常量   不可重复，结构，类，模板声明   不可重复，内联函数 不可重复。和变量一样，函数也有链接性不允许在函数内定义另一个函数因此所有函数均为静态的。默认情况下函数的链接性为外部的即可以在文件中共享 可在原型和定义都用static设置为内部。      非内联函数只能有一个定义，内联函数可以有多个，因此可以放在头文件让多个文件都包含 要求同一函数的所有内联定义都相同。   如果文件内函数原型指出函数时静态的，编译器只在该文件内查找函数定义，否则在所有的链接文件 / 程序文件里找，没找到在库中找 p319下半语言链接性
通常编译器使用三块独立内存，静态变量(可能再细分)，自动变量，动态储存。   new在堆中找内存块，new是一种运算符，会调用函数(stf::size_t 是一个typedef 对应合适的整形) new运算符有变体称为定位new运算符 需包含new头文件 定义了这种版本的new运算符的原型，需要地址参数，可以指定分配的地址，其余语法与常规new运算符相同，参数所在的括号紧跟在new后面(char i[5];cout << i;会输出字符串除非(void*)进行强制类型转换)  比如要分配double，可从char数组中  delete只用于new分配的堆空间，如果char数组不是new分配的则不用delete。   new运算符的工作原理就是返回传递给他的指针并将其强制转换为(void*), 可以赋给任意指针类型。 这是默认的定位new函数 可以重载
除了全局名称空间外可以自定义名称空间，名称空间位于全局名称空间，也可以位于另一个全局空间 不可位于代码块 是外部的链接性。   名称空间是开放的，可以不断添加，可以提供函数原型之后在该文件后面或另一个文件提供定义。   using编译指令与using声明会增加名称冲突的可能性 可能会存在二义性，使用名称空间 + 作用域解析运算符则不会存在二义性（p328有细说）。     名称空间内定义的具有名称空间全局性
类规范包括两部分：类声明和类方法定义 用class声明类设计 必须通过公有 成员函数 或者友元函数(非成员函数) 类设计与实现细节分开称为封装。公有函数成为接口 用户只需了解接口无需了解实现细节 同时保持程序接口不变只需修改实现细节便于维护  默认private可显式强调。类与结构很像，区别就是后者默认public。 类内成员具有类作用域 其他成员无需使用作用域解析附就可以访问。  在类声明之外定义成员函数，需在类实现部分定义函数声明前加inline关键词，这种情况下内联函数要求每个使用它的文件都包含定义，因此通常将其放在定义类的头文件中而不是通常的实现文件中。    同一个类的所有对象共享同一组类方法，即调用同一代码块，用于不同数据，每个对象都有自己的储存空间存储该类的变量与成员  将同一方法作用于不同对象
类设计要求数据隐藏只有类方法可以访问私有数据但要初始化常规方法不行需要设计作为类方法的构造函数与析构函数。   类构造函数名称与类名相同 没有返回值声明 一个程序：       使用构造函数初始化对象：显式调用Stock food = Stock("World Cabbage", 250, 1.25); 隐式调用：Stock garment("Furry Mason", 50, 2.5);(使用new：Stock* pstock = new Stock("Electroshock Games", 18, 19.0)会创造一个类对象并让指针指向它)(p354上)完全可以不看        未提供任何构造函数将提供默认构造函数，用于未提供初始化值的构造语句：Stock f;    默认构造函数的形式：Stock::Stock() {}   这会创建对象但不初始化值，类似于int x(会创建未初始化的对象)；       如果自定义了构造函数则必须定义默认构造函数    定义默认构造函数的方式有两种：给已有构造函数的所有参数提供默认值 / 通过函数重载定义另一个构造函数————没有参数的构造函数：Stock();    只能有一个默认构造函数，不能同时采用这两种方式，通常采用前者提供初始化值进行隐式初始化    使用任何一种方法(没有参数或所有参数都有默认值)创建了默认构造函数后，便可以声明对象变量，而不对它们进行显式初始化：Stock first; Stock first = Stock();Stock* prelief = new Stock;     隐式调用默认构造函数不要用圆括号              类对象过期时自动调用析构函数，如果构造函数是通过new分配的内存析构函数将使用delete；没有使用new则析构函数没有实际要完成的任务   原型：~Stock();   函数定义：Stock::~Stock() {}            为了显示析构函数和时被调用可以在打括号内加一些输出语句。         没有自定义的析构函数编译器会隐式声明一个默认析构函数。  main()内如果没有额外大括号，析构函数的调用在离开代码块才调用，这样将关闭窗口环境(离开main函数时)无法看到析构函数执行语句可以双层大括号，return语句放在外层 对于显式调用，一种方式是直接赋值同隐式调用一样，另一种是创建临时变量并复制，可能调用立刻调用析构函数删除也可能等待一段时间  可用等号将类对象赋给另一个类对象  对于显式调用构造函数如果类对象已经存在则是赋新值(构造函数创建新的临时对象并复制，随后解析函数删除)(显式调用构造函数，初始化不一定创建临时变量，赋值一定创建)    由于自动变量类对象放在栈中，函数块结束时最先创建的对象将最后删除      可以列表初始化类对象(p361下)    一个类对象为const，有的类方法没有参数，用的是类对象内定义的变量，要使用这种类方法需要声明与函数实现的开头语句结尾加上const来保证类对象使用该成员函数不会修改const的类对象 称为const成员函数 应尽可能使用const引用与指针，同时只要该类方法不需修改调用的类对象，就声明为const(防止修改)             接受一个参数的构造函数允许使用赋值语句将对象初始化为一个值         const Stock& topval(const Stock& s) const;  this指针指向调用类方法的类对象(后两个const决定了返回类型也为const)  （类成员函数最后的const说明函数不会修改调用函数的类对象）          初始化对象数组，首先使用默认构造函数创建数组元素，然后大括号内的构造函数创建临时对象并复制，即创建类对象数组要有临时构造函数 大括号内可以只有初始化部分元素，其余元素用默认构造函数创建元素并将内容复制进行初始化 有时需要让符号常量的作用域为类，但类声明只能描述类对象的形式，不能创建对象，可以用枚举 例如在private中：enum { Months = 12 }; 这种方式不会创建类数据成员，即类对象中不包含枚举成员。 这里只是创建符号常量不用枚举类型变量所以不用枚举名。   ios_base::fixed就是定义在ios_base类公有部分的枚举。   另一种方法是：static const int Months = 12;创建常量，同其他常量储存在一起而非储存在对象中(p372作用域内枚举)     类适合描述抽象数据类型如栈
运算符函数可以重载运算符：operator + (argument)重载 + 运算符，必须是已有的运算符(函数返回对象将创造对象的副本，调用函数可以使用)   定义在类中的运算符函数，可以像常规类方法一样使用(第一种调用函数方法：函数表示法)  运算符左边是运算符函数对应的类对象右边是函数参数，则可用运算符表示法 将调用运算符函数  如Time operator+(const Time & t) const;此时total = coding + fixing(两者均为类对象)左右两边符合运算符函数的格式 所以将调用运算符函数(p386下相加)  对于乘法运算符是类对象乘以整形，类对象在左边 可定义运算符函数参数为整形 便可调用运算符函数 整形在右边不能用定义在类中的运算符函数  友元函数为非成员函数，原型声明放在类声明中且在前面加friend(不用于函数定义 可为内联将实现放在声明后) 可访问类的私有成员(与成员函数访问权限相同) 可定义友元运算符函数： 运算符左边的为第一个参数，右边为第二个  将整形声明为第一个变量，类对象声明为第二个参数                                                类内符号函数要求运算符左边为类对象(右边为参数) 友元函数要求运算符左边为第一个参数，右边为第二个参数(通常为类对象)
m * t，对于友元函数可以访问私有数据即类对象的成员，其函数定义内可访问(函数实现可用私有数据)    同样参数 也可定义为非友元函数：
Time operator *(double m, comst Time & t)
{
    return t * m;
}
非友元函数将m* t转换为t* m 通过调用类符号函数实现
重载 << 运算符    cout << 最好不要修改iostream文件(对于int，double，float等基本类型已经重载了 用户自定义的类对象没有) 因此定义后面类类型的友元函数      重载函数参数应为cout的引用，返回类型也是cout的引用                     运算符可以选择使用成员函数重载或者非成员函数，如果是非成员函数，一般是友元函数，因为可以访问类的私有数据       如果是重载两个类对象的加法，可以用成员函数重载，也可以用友元函数重载，但由于两种函数被调用的情况相同，只能定义一种。  一般用成员函数                  对于重载一元运算符 成员函数无需参数(p410随机数函数)   不过二元运算符友元函数右边参数不一定是类对象可能左边是，也可以(不定义成成员函数)即区别为两个参数
接受一个参数的构造函数Stonewt(double); Stonewt myCat; / n myCat = 19.6; 第二条函数语句会调用构造函数创造临时变量初始化为19.6 并将该临时对象的值复制到myCat中去    隐式转换为类，类的构造函数必须只有一个参数才可以，如果给多的参数提供默认值也可以 可以在构造函数前加exolicit拒绝这样，但仍可显式转换myCat = Stonewt(19.6) / (Stonewt)19.6   可发生隐式转换的情况：将Stonest对象初始化为double值；将double值赋给Stonewt对象；将d传递给接受s参数的函数；返回值被声明为s的函数试图返回d值；在上述任意一种情况下，使用可转换为double类型的内置类型时 转换有二义性会拒绝(p414上) 可以进行相反的转换 将类转换为double需使用转换函数例如a为Stonewt类对象，则可以像强制类型转换一样调用转换函数：double host = double(a)(实际调用转换函数时只有右边就可以了不一定必须是赋值比如cout << int(a), 还可以是double host = a这样隐式调用转换函数，但对于cout如果是单纯的a没有显式说明 不知道转换为int还是double会发生错误，如果只定义了double转换函数不存在二义性则可以，赋值时也一样：long gone = a；会错误因为二义性：int和double都可以赋给long变量) / (double)a / a(此时编译器发现左边为double右边为Stonewt会查看是否定义了匹配的转换函数 如果没有 将错误)：原型operator double();转换函数必须是类方法，int转换将待转换的值四舍五入 即int转换函数内返回语句为：return int(pounds + 0.5);  有时不想隐式转换最好可以只显式转换，可在类定义的转换函数声明前加explicit，也可以用一个需要显式调用的非转换函数替代转换函数实现此功能("总之将类对象赋给typeName变量是将自动调用")          对于类对象与double类型相加的加法的运算符函数，可以为：参数是两个类对象的友元函数，此时利用转换函数；成员函数 + 友元函数。对于前者不用类方法，即一般将加法定义为友元 因为左边是double不会调用成员函数（"将string类对象与常规C字符串比较也是最好用友元函数--可用单参数构造函数"）
类内private部分声明的static类型为静态储存类对象 无论创建了多少个类对象都只共享同一个静态成员(在内存中只有一个，所有类成员共享) 不能在类声明中初始化该静态成员，因为声明只描述如何分配内存，并不分配内存，可以在类声明之外单独语句初始化，初始化时使用作用域运算符不用static，初始化在方法文件(包含类方法的文件中)而非类的声明文件 特殊情况之前说过：静态数据成员为整形或枚举型const 可以在类声明中初始化  a为Stonewt类对象，Stonewt b = a；等同于 = Stonewt(a)；当用对象初始化对象时编译器会自动生成复制构造函数：Stonewt(const Stonewt&)；    C++自动提供以下成员函数(如果没有定义)：默认构造函数，默认析构函数，复制构造函数，赋值运算符，地址运输算符。  默认构造函数：编译器提供的不执行任何操作，如果希望创建对象时不显式地初始化 则显式地定义默认构造函数，没有参数但可以用它设置特定的值。但参数也可以成为默认构造函数只要所有参数都有默认值，即默认参数值确定。只能有一种默认构造函数否则会有二义性。   复制构造函数用于将一个对象复制到新创建的对象中，用于初始化而非常规赋值： Stonewt(const Stonewt&);发生以下情况：Stonewt ditto(motto); / s d = m; / s d = s(m); / s * d = new s(m);中间两种可能用复制构造函数直接创建也可能用复制构造函数先创建临时对象，再将临时对象的内容进行赋值。 按值传递和返回对象时均会调用复制构造函数。  默认的只会浅复制(类对象复制时静态数据不受影响，因为他们属于整个类而非每个对象)    试图释放两次内存可能会导致程序异常终止。（stringbad）               赋值运算符 Stonewt& Stonewt::operator=(const Stonewt&); 初始化对象时不一定使用赋值运算符eg：Stonewt knot = h；knot是新创建的类对象，会使用复制构造函数；也可能复制构造函数创建临时变量，通过赋值运算符复制值到创建的对象中。  将一个已有对象赋给一个已有对象会使用赋值运算符。 自定义赋值运算符进行深度复制，与复制构造函数的不同之处：对象可能以储存数据，需要delete[];避免赋给自身否则复制之前会被delete[];函数返回对象的引用，即可以连续赋值。               赋值运算符是只能由类成员函数重载。
默认析构函数用delete[]，所以构造函数要用new char[1]而非new char；   C语言宏nullptr表示空指针，0可为数字也可为空指针，后者也可表示为(void*)0。   delete[]兼容空指针
String类对象的比较函数：
bool operator<(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}
bool operator>(const String& st1, const String& st2)
{
    return st2 < st1;
}
重载[]使string类对象可用，但若answer为const的string类数据，原来的char& string::operator[](int i);会出错，因为无法保证数据不被修改  不过在重载版本会区分常量与非量函数, 可另定义一个供const string对象使用的operator[]()版本：const char& string::operator[](int i)const;       静态类成员函数在类声明中前面加上static。不与任何特定的类对象关联，不可通过对象调用静态成员函数不可使用this指针，必须用类名加作用域解析符调用，只能访问静态数据成员(没记全 p441上)
对于string类的赋值运算符：
String name；
char temp[40];
cin.getline(temp, 40);
name = temp;
最后一行 "将C风格字符串赋给string类" 调用赋值运算符但效率低下：单个参数的构造函数创建临时string对象 运算符函数 删除临时类对象。    可对赋值运算符再次进行重载 另一版本能够直接使用C风格字符串无需转换为string类 注意delete[]
可能有多个类构造函数但只有一个析构函数，构造函数要以相同的方式都加[]或都不加使用new.包含类成员的类的逐成员复制，比如包含String类和标准string类，无需编写此类的复制构造函数和赋值运算符，默认的逐成员复制与赋值行为将使用成员类型定义的复制构造函数和赋值运算符，如果有其他成员需要定义复制构造函数和赋值运算符必须显式调用String和string类的复制构造函数和赋值运算符(p449 章节12.4 可不看) p453：使用new初始化对象，new为创建的对象分配储存空间，是在构造函数中进行的，需要析构函数delete(创建对象要调用构造函数)           用定位new运算符创建的对象销毁时要显式调用析构函数：指针p，p->~place() 创建顺序应与销毁顺序相反，因为晚创建的对象可能依赖于早创建的独享。只有所有对象都被销毁后才能释放用于储存这些对象的缓冲区。
嵌套结构和类：声明不会创建数据对象，嵌套的结构和类作用域为整个类，声明在私有部分只能在这个类中使用，共有部分可以通过作用域解析运算符。
类中被声明为const的元素 是常量 可以初始化不能赋值。调用构造函数时对象将在大括号内代码执行之前创建，对于const成员要在创建对象时初始化：成员初始化列表(只能用于构造函数)，放在参数列表右括号右边 Queue::Queue(int qs) : qsize(qs), 非常量也可以以这种方式初始化，被声明为引用的类成员也必须使用这种语法。 这种情况调用复制构造函数，而普通情况将调用默认构造函数然后赋值运算符进行赋值。
p468伪私有方法
rand()* x / RAND_MAX(定义在cstdlib 是rand()可能返回的最大值 0是最小值)   String类有一个将const
t::t(const string & fn, const string & ln, bool ht)
{
    firstname = fn;
    lastname = ln;
    hasTable = ht;
}
如果传递的是C风格字符串会在传递时转换，t obj("John", "Doe", true); 字符串字面量 是const char数组(储存在)
会先调用构造函数创建一个临时的std::string对象，并将其引用传递给函数。      String类有将const char* 作为参数的构造函数，是系统自带的   大括号内的为赋值 即会调用赋值操作符
class RatedPlayer : public TableTennisPlayer 只能通过基类的公有方法访问基类的私有部分。 派生类需要添加自己的构造函数，派生类必须使用基类构造函数。创建派生类对象必须先创建基类对象，C++使用成员初始化列表(第80行) ：RatedPlayer::RatedPlayer(unsigned int r, const string & fn, const string & ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{
    rating = r;(派生类成员，也可以写进初始化列表)
}  会调用TableTennisPlayer的构造函数
RatedPlayer rplayer1(1140, "Mallory", "Duck", ture);
可以省略初始化列表，省略等效于:TableTennisPlayer() 会调用默认基类构造参数
第二个构造函数：RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer& tp) : TableTennisPlayer(tp) 会调用基类的复制构造函数，基类没有定义编译器会自动生成一个。这个类没有用动态内存分配，可以用隐式复制构造函数(虽然string成员用了，但成员复制时会用string类的复制构造函数进行复制)    释放对象的顺序与创建对象的顺序相反：先执行派生类的析构函数再基类    创建派生类对象时，首先调用基类构造函数，再调用派生类构造函数。基类构造函数负责初始化继承的数据成员，派生类构造函数主要用于初始化新增的数据成员                                  派生类成员过期时先调用派生类析构函数，再调用基类析构函数      （p486上）
程序 要使用派生类要能访问基类声明，一般将两种类的声明放于同一个文件，也可独立，实现也是               派生类对象可以使用基类的非私有方法  基类指针可以在不显式类型转换情况下指向派生类都西昂，基类引用也是
多态  Brass dom();BrassPlus dot(); Brass& b1_ref = dom;Brass& b2_ref = dot;    b1_ref.ViewAcct();b2_ref.ViewAcct();  如果ViewAcct()不是虚的，会看指针或引用的类型；是虚的看指针或引用指向的对象的类型。  通常要把在派生类中重新定义的方法声明为虚的，这样将根据对象类型而非指针或引用类型选择版本。 为基类声明一个虚析构函数也是一种惯例。  派生类方法可以调用基类的公有方法(重新定义的那个方法)，使用作用域解析运算符。    不可用数组但可以创建指向Brass的指针数组，用一个数组表示多种类型的对象   delete[]释放new分配的空间，调用析构函数。析构函数不是虚的将只调用指针类型的析构函数；是虚的将调用指针对应元素的类型的析构函数。 如果析构函数没有执行任何操作都可以，如果BrassPlus的析构函数包含某些操作则Brass必须有一个虚析构函数(可以不执行操作)
对非虚方法编译时知道类型使用静态联编(编译时链接)，对虚方法使用动态联编(运行时链接) 派生类重新定义使用虚方法 否则非虚方法
虚函数实现原理(p504下)   在基类声明中使用virtual使该方法在基类和所有派生类中都是虚的。  派生类构造函数调用基类构造函数 不继承因此不用将构造函数声明为虚函数。 要给基类定义一个析构函数：Employee* pe = new Singer；... delete pe；  使用默认的静态联编(默认析构函数, 非virtual)会调用~Employee()析构函数 释放Singer对象中Employee部分占用的内存，在基类中声明为虚方法析构函数后 会先调用~Singer析构函数释放Singer指向的内存，再调用~Employee析构函数。  友元不是类成员函数 不能是虚函数 可以使用虚函数。  重新定义的虚方法会隐藏旧版本，参数特征标可以改变。经验之谈是保持参数类型不变，返回类型是基类引用或指针可以修改为派生类的引用或指针(返回类型协变)。  对于虚方法基类被重载，派生类应全部重新定义，重新定义一个会隐藏其他的 无法使用(p507如果不需要修改？)            访问控制介绍：(了解不用看，推荐看p507 13.5)
在类继承中如果不需要使用某方法可以在私有部分重新定义该方法使不能通过公有方式调用该方法作用于派生类。   可以提取共性(共有的数据和方法，不同的方法被声明为虚函数)抽象成一个基类 ，这样可以使用基类指针数组管理这两个派生类，可以使用多态方法。  C++在声明结尾添加 = 0 表示纯虚函数(表示未实现的函数)，不能创建该类对象，只用作基类(要成为ABC即抽象 必须至少包含一个纯虚函数) 虽然对于可以实现的函数也可以加上 = 0使其成为纯虚函数 使类成为抽象基类，内联函数将把实现放在实现文件中。    总之在原型中使用 = 0表明类是一个抽象基类且可以不定义该函数。其派生类将使用常规虚函数进行实现
派生类继承基类方法和类内对象。派生类方法内可访问基类公有方法和成员，派生类方法内可通过作用域解析符调用基类同一方法，只能通过从基类继承的公有方法访问基类的私有部分                      访问控制：对于派生类是公有，对于基类是私有(基类只能通过公有方法访问)      保护方法 对于派生类只能公有方法调用。    两个类均要输出一个类内元素，若将该元素声明为private 如果方法相同，抽象出的基类公有方法可输出该元素 若不相同则声明为虚方法，可声明protected函数输出 两派生类定义公有方法可调用该函数(抽象基类的元素和接口都是由两派生类共同部分提取的，但privated类是新生成的)(要想基类的某元素对派生类保持封装 就定义在private里，派生类想访问需要通过基类中public函数或者protected函数)
构造函数内使用动态内存分配空间创建基类对象或对象内的部分成员： 需要显式定义析构函数，复制构造函数和重载赋值运算符(使其深度复制)。对于派生类，若派生类不使用动态内存分配 则无需定义析构函数，默认的即可：不执行任何操作然后调用基类析构函数；无需定义复制构造函数，因为默认复制构造函数执行成员复制，对于继承的类将调用该类的复制构造函数；赋值运算符也是。派生类需要使用动态储存方式创建类对象，则需要显式定义析构函数，复制构造函数和赋值运算符。 即类对象需要使用new创建则类需要定义析构函数，复制构造函数和重载赋值运算符 基类用不用与派生类无关。派生类使用new：析构函数：派生类析构函数自动调用基类析构函数 ，派生类析构函数只负责派生类构造函数创建的成员。 复制构造函数：派生类复制构造函数只能创建派生类成员，需在成员初始化列表调用基类复制构造函数创建基类成员。 赋值运算符：派生类赋值运算符只能复制派生类成员，需要在函数内显式调用基类赋值运算符 : base::operator=(a)，这里采用函数表示法调用基类赋值运算符。                     派生类友元函数：friend std::ostream & operator<<(std::ostream & os, const derive & a) 不能访问基类私有元素 可以调用基类友元：os << (const base&)a(友元函数不是成员函数，不能通过作用域解析运算符指出要使用派生类还是基类的函数 这里采取强制类型转换匹配原型正确的函数)
valarray类由头文件valarray支持 用于处理与数值有关的 是模板类，声明时要加上数据类型 valarray<int / double> q_values;
double gpa[5] = { 3.1,3.5,3.8,2.9,3.3 };
valarray<double> v1; 创建长度为0的数组
valarray<int> v2(8); 指定长度的空数组
valarray<int> v3(10, 8); 初始化为指定值的数组
valarray<double> v4(gpa, 4); 其他数组初始化
valarray<int> v5 = { 20,32,17,9 }; 初始化列表
类方法：operator[](); size();sum();max();min();
class Student
{
private:
    string name;
    valarray<double> scores;
    ...
}
将数据成员声明为私有的，Student类的成员函数内可以使用String和valarray公有接口如name.size()，scores.sum()，但类外面不能使用该接口。 与公有继承的区别，公有继承继承接口和实现，而组合只继承实现不继承接口
typedef std::valarray<double> ArrayDb;放在类定义的私有部分意味着可以在Student类的实现中使用它，但在Student类外面不能使用
继承对象与成员对象：
class Student
{
private:
    std::string name;
    std::valarray<double> scores;
}
构造函数的成员初始化列表对于成员对象要使用数据成员的名称而非类型的名称，继承对象用类型名称 成员对象也要调用相应的构造函数 对于成员对象可以不必在成员初始化列表(因为据称对象要先创建而成员对象不必)   成员初始化列表中包含多个项目，顺序是被声明的顺序
私有继承，基类的公有成员和保护成员都成为派生类的私有成员。公有继承，基类公有方法成为派生类公有方法，派生类继承基类接口；私有继承，基类公有方法成为派生类私有方法，派生类不继承基类接口，私有继承同成员对象一样获得实现不获得接口。
class Student : private std::string, private std::valarray<>double(private是默认 可以省略，使用多个基类的继承为多重继承)
    私有继承的基类对象没有名称，访问时：
    const string& Student::Name() const
{
    return (const string&)*this;
}
返回引用避免return时创建新的对象
访问基类的友元函数(行104末尾) ：用类名限定函数名不适合友元函数，因为友元函数不属于类，可以显式转换为基类调用基类友元函数：
ostream& operator << (ostream& os, const Student& stu)
{
    os << (const String&)stu;
}
一般使用包含而不是私有继承，比如需要多个相同类的对象；对于保护成员，包含不是继承 不是派生类不能访问保护成员；另一种情况是需要重新定义虚函数，派生类可以。
保护继承：将基类公有成员和保护成员变为保护成员：class Student : protected std::string, protected std::valarray<double>{ ... };
私有继承不进行显示类型转换不可以将指向派生类的引用或指针赋给基类引用或指针
保护或私有继承的派生类使用基类方法，一种是定义同名公有方法，实现内调用基类方法；另一种在派生类公有中加入using声明(只适用于继承不适用包含)：using std::valarray<double>::min(没有圆括号函数特征标和返回类型); 例如using std::valarray<double>::operator[];使const与非const都可用，这样便可删除Student::operator[]声明与定义。
公有继承：worker->waiter + singer->singingwaiter
worker * base = (waiter / singer*) & sw;
虚基类使从多个类(基类相同)派生出的类对象只继承一个基类对象，在singer和waiter类声明中加入virtual(与public前后顺序任意) 这样实际会使singer与waiter共享一个worker对象而不是各自引入一个
已知在singer protected中有enum{ other，alto,contralto };对于初始化singingwaiter：singingwaiter(const worker& wk, int p = 0, int v = Singer::other) : waiter(wk, p), singer(wk, v) {};因为会有两个途径初始化worker，所以编译器采取默认的worker构造函数，需在初始化列表中加上worker(wk) 显示调用构造函数。 对于虚函数 singer与waiter会有两个，如果没有在singingwaiter中重新定义会二义性，最好重新定义：
void Singingwaiter::Show()
{
    Singer::Show();
}
指定使用哪个show(), 也可不重新定义，用作用域解析运算符指定继承哪个：nw.Singer::Show();（出现在源文件创造对象后的额外语句）
Singingwaiter类方法调用基类方法 必须要同时使用Singer和waiter，但这样将输出两次worker的show(), 可以重新定义只显示worker与只显示waiter和worker(p559有说明)
友元类：友元类的所有方法都可以访问原始类的私有成员和保护成员，可以只将友元类特定的成员函数指定为友元原始类的函数 友元类声明：friend class Remote; 可以位于公有私有或保护 无关紧要。友元类使用了原始类的方法或元素，因此先定义原始类后定义友元类。只将特定：在原始类中声明，则需要了解友元类的定义，避免循环依赖用前向声明，先声明(非定义)原始类，再定义友元类再定义原始类 因为友元类方法可能调用原始类方法，所以再定义友元类实现 通过在方法定义中使用inline关键词仍可使其成为内联方法。 内联函数的链接性是内部的，函数定义必须在使用函数的文件中，将内联函数定义放在头文件可在包含该头文件的文件中使用。 互为友元，共同友元
嵌套类：将一个类声明放在另一个类中
异常：abort()原型位于头文件cstdlib，向标准错误流(cerr使用的错误流)发送消息 程序异常终止 ，然后终止程序，同时返回一个值 给操作系统或者父进程，处理失败。该函数是否刷新文件缓存区取决于实现，也可用exit()函数，刷新文件缓存区但不显示消息。更好的一种是不结束程序，看返回值判断，此时可以传入引用或指针进行实际的运算返回。   出现错误(而非调用abort()函数)会用异常机制处理，先用异常处理程序捕获异常
读取C风格字符串的getline函数是istream类的方法，对于String类，getline()是独立的函数，所以cin作为函数参数而不是调用函数的类对象。也适用于 >> ，用函数表示法为：cin.operator>>(fname);operator>>(cin, lname);  String类转换为C风格字符串指针：String s;s.c_str()(p666下)(如fout.open()要求C字符串)
cout << 指针，对于字符串，输出字符串，可以(void*)强制类型转换输出指针，其它类型的指针会输出地址。 ios类包含一个指向streambuf对象的指针，streambuf管理输入 / 输出的缓冲区。              cout ＜＜endl / flush前者额外输入换行符 刷新缓冲区 将缓冲区内容全部传入输出, flush(cout)原型为函数，进行了重载, 浮点默认一共输出六位。ios_base类储存描述格式状态的信息：一个成员的某些位决定使用的计数系统，另一个成员的某些位决定字符宽度。   cout << oct / dec / hex.实际上是函数hex(cout)。       默认右对齐，调整字符宽度int width() / width(int i) 只影响下一次输出后恢复默认0 函数返回值前者为当前设置的后者为设置之前的，前者不设置只返回，两者为int 便于恢复原来的字符宽度，是成员函数要用，cout.put(char)显示字符 小括号内可为int，会输出ascii码为int的字符。某些编译器用int，unsigned int，signed int 重载put函数，int参数会引起二义性         cout.width 永远不会截短，i设置的小会按照实际的。cout.fill('?')修改填充字符。          cout.precision(2)设置浮点数精度，默认为6（不显示末尾0），对于浮点数，默认模式为6位数字，定点和科学计数法模式为6为小数，与fill()一样，与width()不同，设置一直有效。      cout.setf(ios_base::showpoint)会显示小数点和结尾0 showpoint是在类声明中定义的类级静态常量。类级说明加上作用域解析运算符可以在外界使用。     setf原型：fmtflags setf(fmtflags);  修改一直有效 仅当输出格式为十进制才能输出符号，16与8进制都是无符号的。   科学计数法指数部分显示三位。    setf另一原型：fmtflags setf(fmtflags, fmtflags);第一个参数为设置的，第二个参数为清除的。cout.setf(ios_base::hex, ios_base::basefield)与使用十六进制控制符的作用一样。   第二参数floatfield : fixed / scientific;第二参数adjustfield:left / right / internal     定点表示法和科学计数法显示末尾的0。   恢复以前的设置可以把第一个参数设置为old，setf将位设置为1，void unsetf(fmtflags mask);恢复为0。  对于floatfield，第一个参数为0是默认模式浮点数。也可调用unsetf(fixed / scientific / floatfield)恢复默认。
cin >> a;会将输入字符流2，3转换为整数23占2字节的二进制表示；转换为23.0占8字节的二进制浮点表示。  原型为：istream & oerator >> (int&)参数为引用，能够修改用作参数的变量的值。cin >> hex 将整数输入解释为十六进制(可以输入12 / 0x12 意思一样)。  参数为字符指针 会读取一个单词并在末尾追加一个空字符使其成为字符串(cin读取会跳过空白字符:空格，换行符，制表符 单字符读取也是，不过C语言的字符输入函数不是)。   输入错误如int 输入字符串，不会修改原变量的值 函数返回值转换为bool为false表示读取失败，读取成功返回ture。    cin / cout有成员流状态类型iostate(从ios_base继承的)：eofbit文件结尾 / failbit未读到预期字符 / I / O失败如读取不可访问文件或写入保护的磁盘 / badbit 无法诊断的失败 / goodbit(默认值0)三个状态均为0表示一切顺利 good()流可以使用返回yure；eof()eofbit被设置返回ture。     设置状态：clear(eofbit);设置eofbit，清除其他两个 成员函数 clear();调用默认参数0 / goodbit 清除3个状态位。  setstate()只影响参数中的位。(只能添加状态标志，不能清除已有的标志)  最常见的理由去重新设置流状态是输入不匹配或到达文件结尾导致流关闭需要使用不带参数的clear()重新打开输入。    流的状态设置了 eofbit并不会引发异常，可以通过exceptions()函数设置引发异常的状态标志：返回一个位字段3字节 修改流状态的两种方法(无论哪种流状态修改便与exceptions()设置的位字段进行比较 任何一位) (exception()返回goodbit将不会引发异常)。  引发异常的类型为ios_base::failure, 从std::exception派生的异常类，因此包含what()方法。exception()默认设置为goodbit，可重载为exception(iostate) :exception(badbit)；        异常发生，用catch(ios_base::failure& bf)捕获异常，函数调用what()函数输出字符串描述异常信息。  设置流状态将关闭流直到位被清除。 处理错误的条件建立在不恰当的输入，也有可能是到达文件结尾or硬件故障，此时处理错误的代码将毫无意义 可用fail()检测：if(cin.fail() && cin.eof())       （头文件iomanip p752）
istream类成员函数get()与getline() 文件尾或键盘模仿的文件尾cin.get(char&)到达文件尾 不会给参数赋值 同时调用setstate(failbit)使语句转换为bool为false：
char ch;
while (cin.get(ch))
{
    // process input
}
cin.get(void)到达文件尾返回头文件iostream定义的符号常量EOF，一般将ch声明为int而不是char，因为值EOF可能无法用char类型表示 cin.ignore(255, '\n');去读并丢弃255个字符 / 到达第一个换行符，该函数原型为istream & ignore(int = 1, int = EOF);
get(char*, int)和getline()同其他输入函数一样，遇到文件尾设置eofbit，流被破坏(如设备故障)设置badbit。另外两种情况也会影响流：无输入(到达文件尾，对于get(char*, int)来说也可能是输入空行)，无输入将无法抽取字符，会把空值字符放置到输入字符串并使用setstate()设置failbit。对于getline()来说，空行仍正常读取，读取换行符虽然不会储存它，如果希望getline()也在空行时终止循环，可以：char temp[80];while (cin.getline(temp, 80) && temp[0] != '\0') 。        另一种情况是输入队列超过了最大字符数：char temp[30];while (cin.getline(temp, 30))   如果读了29个字符且下一个字符不是换行符则设置failbit，因此超过数量字符的输入行会终止输入。

除此之外，istream方法还有：read() :char gross[144];cin.read(gross, 144);与getline()和get()不同 不会在结尾加上空值字符，不能转换为字符串，通常与ostream::write()用于文件输入输出。peek()查看下一个字符但不读取(赋给ch)。gcount()返回最后一个非格式化抽取方法读取(>> )的字符数。 >> 对输入进行格式化使与特定类型匹配。putback()将一个字符插入到下一条输入语句的第一个字符
while (cin.get() != '\n') continue;(不懂就看p768)
头文件fstream定义类：ifstream，ofstream，fstream 从头文件iostream中的类派生而来的，可以用之前介绍过的方法。大部分实现包含fstream就自动包含iostream      ostream是ofstream的基类。 ofstream类使用被缓冲的输出，创建一个类对象像fout一样的会为输出缓冲区分配空间，创建两个ofstream对象将创建两个缓冲区，一个对象一个。 程序逐字节输出到fout缓冲区，直至填满将内容一同传输给输出文件             以默认方式打开文件会将文件长度截断为0。     当输入输出流对象过期(如程序结束)，自动关闭与文件的连接，也可显式关闭：fout.close();fin.close()。   关闭连接不会删除类对象，不会删除流，fin对象与管理的缓冲区仍然存在 可重新与文件连接 关闭文件将刷新缓冲区确保文件更新  p769 c_str()          C++文件流继承了流状态成员，fin.open();打开不存在的文件会设置failbit位，if(fin.fail() / !fin.good() / !fin)      不如is_open()方法：if(!fin.is_open())   可以检测试图以不合适的文件模式打开文件的失败    将文件与ifstream关联起来是否会自动重置流状态，会要求使用fin.clear()在循环末尾，但使用是无害的因此一般加上
ios_base定义了openmode类型表示模式
ifstream fin("banjo", mode1);
ofstream fout();
fout.open("harp", mode2); 没有第二个 默认参数为ios_base::out | ios_base::trunc，ifstream默认为ios_base::in。位运算符OR | 用于将两个位值合并。   fstream类不提供默认。    不想清除换trunc为app(打开文件来输入--打开文件来追加)。               ifstream fin(filename, c++mode);类似于C的fopen()函数: fopen(filename, cmode); C++mode是一个openmode值，而cmode是相应C模式的字符串如"r"。  不允许的组合禁止文件打开，is_open()方法可用于检测这种原因导致的打开失败。       ios_base::ate与ios_base::app均将文件指针指向文件末尾，前者无限制但后者只允许将数据添加到到文件尾
二进制文件：二进制格式；文本文件：文本格式 插入运算符负责类型转换格式。   unix只有一种文件格式对它来说二进制模式和文本模式一样。  结构pl，fout.write((char*)&pl, sizeof pl);必须将地址强制转换为char的指针 对应的为fin.read。  也适用于不使用虚函数的类因为会有复制隐藏指针：
struct pt
{
    char name[20];//存储字符串 不能用string 复制到文件中只是指针
    double population;
    double g;
}
不能用string替代name数组，那样复制的只是指针而不是数组元素
fstream从iostream派生 iostream从istream和ostream派生，继承了两个缓冲区且同步化处理输入指针和输出指针
随机存取 ：
finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
文件移动：
basic_istream<charT, traits>& seekg(off_type, ios_base::seehdir);
basic_istream<charT, traits>& seekg(pos_type);
fstream继承的方法 可让指针移动
char具体化： istream& seekg(streamoff, ios_base::seekdir);
istream& seekg(streampos);
streamoff为偏移量单位字节，第二个参数有三个值：ios_base::beg
ios_base::cur;ios_base::end。       streampos为字节数 表示绝对位置从文件开始处算，可以是类，需要构造函数包含接受streamoff参数可转换为streampos。   输入流可用tellg()返回指针位置streampos值，输出流是tellp()，对于fstream对象，输入指针与输出指针同步移动因此两函数相同，可用istream和ostream两个对象管理，此时输入与输出流独立，两值不同。   无参数seekg()移到开头
pl可以为类 注意重载 << 插入运算符。 临时文件
iostream派生出sstream类，其内包含ostream派生出的ostringstream类。类对象缓冲区储存数据，sstream可通过动态内存分配增大缓冲区。str()成员函数返回缓冲区内容的字符串对象：string mesg = outstr.str();    创建类对象输入流并关联到string：istringstream instr(facts)










return vector(x + b.x, y + b.y)
返回副本时调用构造函数  构造函数创建无名新对象并返回副本 确保对象是符合规则创建的




typedef std::ios_base::fmtflags format;（p498上）
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

format initialState = setFormat();
precis prec = cout.precision(2);
restore(initialState, prec);
以及p514上

ios_base::fmtflags initial;initial = os.setf(ios_base::fixed);...;os.setf(initial)




单参数类型转换doh = 5；会使用构造函数Student(int n)转换为student类(or之前就生成了duixiang 采用赋值运算符？)反正这里对于那个单参数的构造函数explicit就好了 p538


cin 读取一个字符串（即string） 通过空格 / 制表符 / 换行符判断字符串结束  istream类中的函数getline() / get()读取一整行，前者丢弃换行符，后者保留  类函数要作用于类对象：cin.getline()  不带任何参数的cin.get()读取下一个字符，可用来处理换行符(由于cout读取char时会忽略空格因此输入多个字符串时可用cin.get(ch)而非cin >> ch)；get更优，可查看下一个字符判断读取停止是由于到达换行符还是数组已满 get()读取空行后会设置失效位会阻断输入(输入流没有停止)可以用cin.clear()恢复。如果输入的比配置的字符数多两者均会保留，getline会设置失效位
