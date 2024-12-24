#include <iostream>（头文件）
int main()
{
    using namespace std;
    cout << "Come up.";
    cout << endl;
    return 0;
}
1. namespace 名称空间std定义在头文件iostream中
using namespace std  此时cout变量实际为std::cout;std::endl    cout为输出流，是定义在std中的iostream类对象
也可用 using std::cout和using std::endl / cin
可在main函数和用户构造的函数中均使用using namespace std；将using编译指令放在两函数前面这两个函数均可
cout << hex;修改显示整数的方式（hex定义在std中）
，若省略编译指令using，则应使用std::hex)
cout.put() :std命名空间定义了ostream类 类内有类成员和成员函数，只能通过类对象使用成员函数，句点为成员运算符
这里参数为(char类型)打印一个字符
用cout 要包含头文件iostream，头文件定义了ostream类且声明了类对象cout。    endl定义在该头文件        对于文件输入(仍需包含iostream头文件)则是fstream头文件 ofstream类。  需要将类对象与文件关联，用open()方法，使用完文件后用close()关闭       声明一个ofstream对象并将其同文件关联起来后可以像使用cout一样使用它，所有适用于cout的操作和方法都是用于该对象(eg << , setf())。 忘记用close()关闭文件，程序正常终止时会自动关闭 open()时文件不存在会创造文件，存在则将其长度截断为0即丢弃原有内容。 文件可能禁止访问所以可能打开失败，可用is_open()方法判断，成功打开会返回ture，失败则执行 exit(EXIT_FAILURE)函数原型和参数值EXIT_FAILURE定义在头文件cstdlib，该函数终止程序。 文件名包含路径，否则只在所属文件夹找     windows文本文件每行均以回车字符和换行符结尾，读取时将这两个字符转换为换行符，写入时执行相反转换。有些文本编辑器不会自动在最后一行末尾加上换行符，应手动输入回车键再保存文件
内联函数：直接将副本替换到原调用地点 运行速度更快但占用更多内存 原方法只有一个副本 适用于较为短小的函数，方法是在函数声明或定义前加inline，通常方法是把定义放在原型之处。    创建引用变量：int rats；int& rodents = rats；必须在声明引用变量时初始化  函数原型不同，函数调用语句与函数实际定义不包括声明 相同 常量引用(const double& ra)   当参数为const引用时，参数类型不匹配 / 匹配但不是左值 会创造临时变量只存在于函数内，函数内存在的是这个创造的临时变量 返回类型为引用则可以放在赋值语句的左边，按值返回不能。    按值返回时会将值复制到一个临时位置 之后会使用该值 按引用传递注意不能返回临时变量 可将const用于有引用返回类型说明返回的引用是const的 对于形式参数与实际参数是字符串与string则会发生转换，就是创造临时变量
ostream的类方法setf()设置格式化状态：setf(ios_base::showpoint)显示小数点即使小数为0；precision()指定显示多少位小数(假定对象处于定点模式下) 这些设置将保持不变知道设置新的替换；width()设置下一次输出的字段宽度，下一次就恢复默认，默认为0.意味着刚好能容纳要显示的内容 ios_base::fmtflags initial;initial = os.setf(ios_base::fixed);...;os.setf(initial); 每个对象都储存自己的格式化设置     默认参数 即参数有默认值，在函数原型中，必须从左向右添加默认值，且不是必须要有默认值
函数重载 函数参数列表即函数特征标 编译器把类型引用和类型本身视作相同 返回类型不同不能重载 返回类型可以不同，特征标必须不同    函数模板：类型用参数表示 template <typename / class AnyType> / n void Swap(AnyType & a, AnyType & b具体定义) 模板不创建函数只是告诉编译器如何定义函数(函数调用会生成示例，该实例模板就是函数定义 这种实例化方式为隐式实例化 可以显式实例化 如：使用Swap模板生成int类型的函数定义：template void Swap <int>(int, int))  可进行模板重载要求特征标不同，并非所有的模板参数都必须是模板参数类型 由于某些操作对于元素类型有局限性 可为特定数据类型提供特定版本(因为特征标一样所以不重载，给定的函数名，可以有非模板函数、模板函数、显式具体化模板、以及它们的重载函数)：显式具体化，定义一个函数，优先不找模板：template <> void Swap<int>(int&, int&)其中<int>是可选的   与显式实例化不同的是显式具体化：不使用Swap()模板生成函数定义，使用为特定类型的 这些原型要求必须有自己的函数定义：template <> void Swap<int>(int&, int&);或者省略<int>  不可同时使用同一类型的显式实例与显示具体   Swap(AnyType, AnyType) 对于隐式实例化swap与括号之间可以加<double>强制为double类型实例化，如果传的参数类型不匹配 将参数强制转换为double
对于函数重载，函数模板和函数模板重载需要进行重载解析进行判断采取哪个。float实参可转换为double 整形不能隐式转换为指针：完全匹配 > 提升转换(char和shorts自动转换为int，float自动转换为double) > 标准转换(int转换为char，long转换为double) 其中完全匹配允许无关紧要的转换(p290下到本章结尾)
