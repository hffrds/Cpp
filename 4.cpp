#include <iostream>
#include <cstring>//string头文件
int main()
{
    const char* a = "florida";
    const char* b = "kansas";
    std::cout.write(a, 9);
}

堆内存很大，new只需把指针放在栈即可
int* p = new int;
cout << *p << endl;
string* pString = new string("hellon") / (); 括号内有参数表示非默认构造函数 无参数表示默认构造函数
cout << *pString << endl;
new int[100]()初始化为0 不能赋初值
new string[100]() / nothing 初始化为0不能赋初值
boost库帮助确认变量类型(auto)
const int i = 100;
auto refi = i;  int
auto& refi = i;  const int&
auto在推断引用的类型时会将引用替换
int i;
const int* const pi = i;
auto refi = pi; const int*
auto& refi = pi; const int* const
临时变量 临时对象有地址 无法使用地址属性 不能做左值(等号赋给左边的地址)
左值引用 const左值引用 右值引用
std::move()将左值变为右值
可调用对象：函数，有重载()函数的类 该类的对象可当作函数用 称为仿函数
lambda表达式：匿名函数
[捕获列表](int i)-> int {

}();
函数参数为函数指针，可以相应类型函数名，对于匿名函数直接将其放在调用函数的参数列表 lamdba表达式此时捕获列表要为空
可以#include<functional>
std::function<void(int)>作为函数参数 与函数指针同等作用  但允许作为实际参数的匿名函数调用



类内常量通常用于定义不可变的值，它们可以是静态或非静态的
静态类内常量属于 类 而不是 类的实例
class MyClass {
public:
    static const int value = 42; // 静态常量成员，类内初始化
};
静态类内常量必须是整型或枚举类型才能直接在类内初始化，非整型静态常量需要在类外提供定义和初始化，inline 静态变量 使得非整型静态常量也可以在类内直接初始化，无需类外定义
class MyClass {
public:
    inline static const double doubleValue = 3.14;  // 类内直接初始化，无需类外定义
    inline static const std::string strValue = "Hello, C++";
};
非静态类内常量属于类的每个实例，意味着每个对象都有一份。必须在类的构造函数中初始化

常函数只能修改类的mutable成员变量，只能调用全局函数和类内常函数，this指针为const类型，常函数是唯一能被const对象调用的成员函数
常函数可以修改静态成员变量
mutable只适用于非静态成员
静态类内变量：
class MyClass {
public:
    static int counter;  // 静态变量，属于类
};

int MyClass::counter = 0;  // 定义并初始化静态变量
静态函数 与类相关：
class MyClass {
private:
    static int counter;

public:
    static void incrementCounter() { counter++; }
};

int MyClass::counter = 0;

int main() {
    MyClass::incrementCounter();  // 调用静态函数修改静态变量
}
非常量对象优先调用普通成员函数，常量对象优先调用常成员函数
静态成员变量必须在类外初始化 在静态变量区 编译前完成初始化
静态成员函数 在代码区 用于服务私有部分的静态成员变量(为了保持其封装性)


default delete
单例模式 不希望生成默认函数可以将其定义在私有部分或不定义不定义 也可delete

动态类型转换RTTI
typeid(*).name() 返回const char* 返回此时类型
dynamic_cast<base_class>()父类指针或引用转换为派生类
转换失败成为NULL，可以if(指针)判断
注意加条件判断修改是否成功与失败

移动构造函数与移动赋值运算符：
参数列表为(class&& T)，即用临时对象进行赋值时发生，需要构造参数列表的复制构造函数与赋值运算符 类内变量有数组，将新的指向等号右边，等号右边指向nullptr，一般用于临时对象进行复制与赋值，比如函数返回值作为等号右边
默认生成移动构造函数和移动赋值运算符，需要没有定义复制构造和赋值运算符且每个非静态成员都可以移动

智能指针
共享型：share_ptr
unique_ptr
weak_ptr
#include<memory>
std::shared_ptr<int> shared1(new int(100));（别用裸指针初始化：(p)）；可以用复制构造初始化：(share2);
std::shared_ptr<int> shared1 = std::make_shared<int>(100);
use_count函数可以得到shared_ptr的引用计数:share1.use_count()
share2.reset()释放智能指针对堆的控制权
share_ptr类重载使其可像普通类型的操作
unique函数判断该share_ptr是否独占 独占返回ture
reset()有参数改变share_ptr对象指向的内存(释放旧的指向新的)，无参数将share_ptr对象设为nullptr :
    share1 reset(new int(100));
share1.swap(share2);交换指针（虽然std名称空间内的swap函数也可以）
get()转换为普通指针(不推荐使用)
智能指针创建数组：
std::shared_ptr<int> shared1(new int[100]());
此时调用单个要用get() : std::cout << share1.get()[10] << std::endl;
智能指针share_ptr大小为两个指针，32位系统指针为4字节，64位指针为8字节

初始化：
std::shared_ptr<int> shared1(new int(100));
不可以换为：
std::shared_ptr<int> shared1(std::make_shared<int>(100))
构造函数接受的参数为普通指针
std::shared_ptr<int> shared1 = std::make_shared<int>(100);
这里make_shared函数是使用new创建普通指针对象初始化的， 然后make_shared函数返回值为右值会优化，不会复制再销毁


weak_ptr对象不会改变shared_ptr对象的引用计数(当share_ptr的引用计数为0时会自动释放内存空间)：
std::weak_ptr<int> weak1(share1);
weak_ptr用于解决循环引用
程序结束会销毁栈指针对象 释放空间， 用new初始化两个类对象并让两个智能指针分别指向两个类对象，若堆内两个类对象内有对方类的类型的智能指针互相指向对方的类对象此时不会自动释放 方法是将其中一个指针的类型变为weak_ptr weak_ptr对象不会改变shared_ptr对象的引用计数，程序结束栈指针对象消除 还有一个指针对象指向它，若变为weak_ptr则shared_ptr对象的引用计数仍变为0
就是原来有两个指针指向一个类对象 销毁一个 不会自动释放 其中一个为weak_ptr，对应的内存被释放，对象被销毁，另一个空间也被释放

unique_ptr
初始化同shared_ptr一样， 用的是make_unique
不允许复制构造与赋值运算符 除非对象是右值，进行右值优化(但此时实际上进行的是移动构造函数和移动赋值运算符) 可将一个左值move()变为右值           但允许深度复制构造与赋值运算符
将unique_ptr转换为share_ptr(不能将share_ptr转换为unique_ptr)：
std::share_ptr<int> share1(std::move(unique1));
unique指针大小为一个普通指针大小
size_t在32位系统上定义为 unsigned int，也就是32位无符号整型。在64位系统上定义为 unsigned long

对于智能指针，没有必要使用shared_ptr吧？都是使用unique_ptr，就像普通指针，要么类对象是左值就进行深度复制，右值就移动构造或赋值

智能指针优点是自动管理内存。 智能指针可以声明所有权，std::unique_ptr 表示唯一所有权，std::shared_ptr 表示共享所有权。通常不太需要深度复制，因为资源浪费。智能指针不进行深度复制，如果有多个指针，会用shared_ptr进行共享而非深度复制。


std::unique_ptr：表示唯一所有权，确保资源只被一个指针管理，无法复制，但可以通过移动语义转移所有权。
std::shared_ptr：表示共享所有权，多个 shared_ptr 可以共享同一资源，通过引用计数决定资源的释放时机。
深度复制需要为每个副本创建独立资源，开销较大，容易造成资源浪费。智能指针尤其是 std::shared_ptr 通过共享所有权机制解决了多个指针同时访问同一资源的需求，避免了频繁的深度复制。
现代 C++ 倾向于资源共享和移动语义，大多数情况下不需要为每个指针创建独立的资源副本。现代 C++ 推荐在动态内存管理中优先使用智能指针，而不是普通指针。这种方式不仅让代码更安全，也提升了开发效率和程序性能。 需要共享，同时访问同一资源就用share_ptr，否则用unique_ptr。 对于unique_ptr，不允许使用深度复制就需要移动构造 / 移动赋值 转移所有权，原来的指针就会指向nullptr。因为是唯一所有权，所以如果是唯一所有权就用unique_ptr。推荐用unique_ptr，因为原来的指针不用就不用了，唯一所有权                std::unique_ptr 表示唯一所有权：如果某个资源必须由单一模块 / 对象管理（独占资源），std::unique_ptr 能明确表明这一点，代码更容易理解。如果改用 std::shared_ptr，则所有权的语义变得模糊，开发者需要考虑引用计数的管理，可能引发误解
多个模块同时需要访问才用shared_ptr。

std::unique_ptr<Example> ptr1 = std::make_unique<Example>();
std::unique_ptr<Example> ptr2 = std::move(ptr1);  // 转移所有权
// ptr1 不再拥有资源，ptr2 负责销毁对象


std::shared_ptr<Example> ptr1 = std::make_shared<Example>();
std::shared_ptr<Example> ptr2 = ptr1;  // 共享所有权
// 对象只在最后一个 `shared_ptr` 销毁时释放


智能指针默认是为单一对象设计的，对数组支持需要明确指定删除器（std::default_delete<T[]>）。
对于 std::shared_ptr，必须显式提供自定义删除器，增加了复杂性。
优先使用 STL 容器（如 std::vector）：提供更高效、更安全的动态数组管理。
如果必须使用智能指针管理数组：
std::unique_ptr<T[]> 是最合适的选择。
对于共享资源的需求，可以结合自定义删除器使用 std::shared_ptr。
智能指针管理数组可以实现，但在实际项目中并不常用。现代 C++ 的首选方案是容器类，除非有特定需求。


hpp
类模板：
template<typename T>
class MyArray
{
    using iterator = T*;
    using const_iterator = const T*;
    /*
    MyArray(const std::initializer_list<T>& list);
    MyArray(const std::initializer_list<T>&& list);
    */
    T* data;->std::vector<T> data;
}
函数实现可以放在类模板里面，也可以放在类模板外面，但必须在同一文件
template<typename T>
typename MyArray<T>::out() const
{

}

#include .hpp
#include <vector>
#include <type_traits>

template<typename T>    //模板特化
struct get_type<T>
{
    using type = T;
}

template<typename T>
struct get_type<T*>
{
    using type = T;
}

int main()
{
    std::initializer_list<int> iList{ 1 ,2 ,3 };
    std::vector<int> ivec(iList); / {1, 2, 3}; 用左值初始化或用右值

}

template<typename T>
MyArray<T>::MyArray(const std::initializer_list<T>& list)
{
    if (list.size())
    {
        unsigned count = 0;
        data = new T[list.size()]();
        if (std::is_pointer<T>::value)
        {
            for (auto elem : list)
            {
                data[count++] = new typename get_type<T>::type(*elem);
            }
        }
        else
        {

            for (const auto& elem : list)
            {
                data[count++] = elem;
            }
        }
    }
    else
    {
        data = nullptr;
    }
}

template<typename T>
MyArray<T>::MyArray(const std::initializer_list<T>&& list)
{
    if (list.size())
    {
        unsigened count = 0;
        data = new T[list.size()]();
        for (const auto& elem : list)
        {
            data[count++] = elem;
        }
    }
    else
    {
        data = nullptr;
    }
}


std::initializer_list<int*> iList{ &i1,&i2,&i3 };
MyArray<int*> arrayPi(iList);
for (unsigned i = 0;i < 3;i++)
{
    std::cout << *arrayPi[i] << std::endl;
}


T& operator[](unsigned count)const
{
    return data[count];
}




函数模板：
template <typename T>
void Swap(T & a, T & b)
{
    T c;
    c = a;
    a = b;
    b = c;
}
常见的是将模板定义放在头文件，把要是有用模板的文件包含头文件
可重载模板定义，要求特征标必须不同
可为特定类型提供显式具体化的模板定义(参数不变)
显式具体化：
template <> void Swap(<job>)(job&, job&);


类模板：
template <typename T>
class MyArray
{

}
显式具体化：
template <> typename MyArray <int>
{

}
可以针对T做具体化如指针具体化：
template <typename T*>
class MyArray
{

}
实例化时：
MyArray <int> iList;
MyArray <int*> iList;



namespace mystd
{
    template<typename iter_type, typename func_type>
    void for_each(iter_type first, iter_type last, func_type func)
    {
        for (auto iter = first;iter != last; ++iter)
        {
            func(*iter);
        }
    }
}
namespace mystd
{
    using int_func_type = std::function<void(int&)>;       //默认模板参数  #include<functional>   function是类模板，保存函数参数与返回值，＋函数名代表函数，即类似于函数指针
    template<typename iter_type, typename func_type = int_func_type>
    void for_each(iter_type first, iter_type last, func_type func = [](int& elem) {
        ++elem;
        })
    {
        for (auto iter = first;iter != last; ++iter)
        {
            func(*iter);
        }
    }
}

vec.begin(); // 类型是 std::vector<int>::iterator。 vector是模板化的动态数组，若vec是vector类对象，vec.begin(); 类型是 std::vector<int>::iterator，迭代器类似指针。


void print(int x) {
    std::cout << x << " ";
}
int main()
{
    std::vector<int> vec = { 1, 2, 3, 4, 5 };

    // 调用 for_each
    for_each(vec.begin(), vec.end(), print);
    return 0;
}
或用lambda表达式：
for_each(vec.begin(), vec.end(), [](int& elem) {
    ++elem;
    });
for_each(vec.begin(), vec.end(), [](int x) {
    std::cout << x * x << " ";
    });

类内模板函数：
template<typename T>
class MyVector
{
public:
    template<typename T>
    void outPut(const T2& elem);
};
template<typename T>
template<typename T2>
void MyVector<T>::outPut(const T2 & elem)
{
    std::cout << elem << std::endl;
}

类模板默认参数
template<typename T, typename allocator_ = std::allocator<T>>
class MyVector
{
public:
    template<typename T2>
    void outPut(const T2& elem);
};
template<typename T, typename allocator_>
template<typename T2>
void MyVector<T, allocator_>::outPut(const T2 & elem)
{
    std::cout << elem << std::endl;
}




vector
#include<iostream>
#include<vector>

int main()
{
    std::vector<int> ivec{ 1,2,3,4 };
    std::cout << ivec[1] << std::endl;//无异常捕获(越界)
    std::cout << ivec.at(1) << std::endl;

    ivec.push_back(1);
    ivec.pop_back();
    ivec.insert(++ivec.begin(), 1);

    std::vector<int> ivec{ 1,2,3 };
    std::deque<int> ideque{ 1,2,3 };  //include<deque>
    std::set<int> iset{ 1,2,3 };    //include<set>
    std::vector<int> ivec2(ivec.cbegin(), ivec.cend());
    std::vector<int> ivec2(ideque.cbegin(), ideque.cend());
    std::vector<int> ivec2(iset.cbegin(), iset.cend());
    std::vector<int> ivec(10, *)
        增加insert / 删除erase

        遍历：
        int& i = T & front()
        int& i = T & back()

}
int main()
{
    std::deque<int> ideque{ 1,2,3 };
    ideque.push_front(1);
    ideque.pop_front();

    std::list<int> iList{ 1,2,3 };

    std::string str("hello,world");
    std::cout << str.c_str() << std::endl;
}

关联容器(红黑表)
int main()
{
    std::set / multiset<int> iset{ 1,3,2 };
    for (int elem : iset)
    {
        std::cout << elem << std::endl;
    }
}

int main()//include<map>  哈希表
{
    std::map<int, std::string> int_string_map;
    int_string_map.insert(std::pair<int, std::string>(1, "hak"));
    int_string_map.insert(std::pair<int, std::string>(3, "haka"));
    int_string_map.insert(std::pair<int, std::string>(2, "haks"));
    int_string_map.insert(std::pair<int, std::string>(4, "hakd"));
    for (const auto& elem : int_string_map)
    {
        std::cout << elem.first << '\t' << elem.second << std::endl;
    }
}
无序容器(哈希表)



#include<iostream>

int main()
{
    int i = 10;
    while (std::cin >> i, !std::cin.eof())
    {
        if (std::cin.bad())
        {
            throw std::runtime_error("cin is corrupted");
        }
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "data format error, please try again" << std::endl;
        }
        std::cout << i << endl;
    }
    std::cout << "process complete" << std::endl;
    return 0;
}

#include<iostream>
#include<string>

int main()
{
    std::string str;
    while (std::getline(std::cin, str), !std::cin.eof())
    {
        if (std::cin.bad())
        {
            throw std::runtime_error("cin is corrupted");
        }
        std::cout << str << std::endl;
    }
    return 0;
}

#include<iostream>
#include<string>
#include<fstream>

int main()
{
    std::string fileName;
    std::string fileContent;

    while (std::cin >> fileName, !std::cin.eof())
    {
        if (std::cin.bad())
        {
            throw std::runtime_error("cin is corrupted");
        }

        std::ifstream ifs(fileName);
        if (ifs.is_open())
        {
            while (std::getline(ifs, fileContent))
            {
                std::cout << fileContent << std::endl;
            }
            if (ifs.bad())
            {
                throw std::runtime_error("ifs is corrupted");
            }
            ifs.close();
        }
        else
        {
            ifs.clear();
            ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "file not exist, please try again" << std::endl;
            continue;
        }
    }
    std::cout << "process complete" << std::endl;
    return 0;
}

string ->int

#include<iostream>
#include<sstream>

int main()
{
    std::string str("12");
    std::stringstream strStream(str);

    int i = 0;
    strStream >> i;
    if (strStream.bad())
    {
        throw std::runtime_error("strStream is corrupted");
    }
    else if (strStream.fail())
    {
        strStream.clear();
        strStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "string format error" << std::endl;
    }
    else {
        std::cout << i << std::endl;
    }
}



#include<iostream>
#include<sstream>

int main()
{
    int srcI = 100;
    std::stringstream strStream;
    strStream << srcI << std::endl;
    if (strStream.bad())
    {
        throw std::runtime_error("strStream is corrupted");
    }
    else
    {
        std::cout << strStream str() << std::endl;
    }
    return 0;
}







异常处理
#include<iostream>

int devide(int divisior, int dividend)
{
    if (!dividend)
    {
        throw "dividend is zero";
    }
    return divisior / dividend;
}

void clientInputNum(const std::string & str, int& num)
{
    std::cout << str << std::endl;
    while (std::cin >> num, !std::cin.eof())
    {
        if (std::cin.bad())
        {
            throw std::runtime_error("cin is corrupted");
        }
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "number format error, please input again" << std::endl;
            continue;
        }
        break;
    }
}

int main()
{
    int divisior = 0;
    int dividend = 0;
    clientInputNum("please Input divisior", divisior);
    clientInputNum("please Input dividend", dividend);
    try
    {
        std::cout << divide(divisior, dividend) << std::endl;
    }
    catch (const std::string& str)
    {
        std::cout << "exception occurs,exception is : " << str << std::endl;
    }
    catch (...)
    {
        std::cout << "exception occurs, exception is : unknown exception" << std::endl;
    }
    return 0;
}





void outPutFileContent(const std::string & fileName)
{
    std::ifstream ifs(fileName);
    std::string fileLineContent;
    if (ifs.is_open())
    {
        while (ifs >> fileLineContent)
        {
            std::cout << fileLineContent << std::endl;
        }
        if (ifs.bad())
        {
            throw std::runtime_error("ifs is corrupted");
        }
        ifs.close();
    }
    else {
        if (ifs.bad())
        {
            throw std::runtime_error("ifs is corrupted");
        }
        if (ifs.fail())
        {
            throw std::string(file not exist);
        }
    }
}

int main()
{

}




#include<iostream>
#include<fstream>

int main()
{
    try
    {

        while (1)
        {
            int* pi = new int[1000000]();
        }

    }
    catch (const std::bad_alloc& except)
    {
        std::cout << except.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "unknown exception" << std::endl;
    }
    return 0;
}

#include<memory>
#include<vector>

main
std::vector<std::shared_ptr<int>> unique_int_vac:
while (1)
std::unique_ptr<int> uniqueI(new int[1000000]())
unique_int_vec.push_back(std::move(uniqueI));




#include<iostream>
#include<vector>

int main()
{
    std::vector<int> ivec{ 1,2,3 };
    try {
        ivec.at(10);
    }
    catch (const std::out_of_range& except)
    {
        std::cout << except.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "unknown exception" << std::endl;
    }
    return 0;
}
通常为重载[]

#include<vector>

template<typename T>
class Test
{
public:
    T& operator[](unsigned count)const {
        if (const >= data.size())
        {
            throw std::out_of_range("Test data is out of range");
        }
    }
private:
    std::vector<T> data;
}

int main()
{
    try
    {

    }
    catch (const std::out_of_range& except)
    {
        std::cout << except.what() << std::endl;
    }
    return 0;
}


万能指针
#include<iostream>
#include<boost/type_index.hpp>

using boost::typeindex::type_id_with_cvr;

template<typename T>
void test(T && elem)   //const T && elem 是右值引用   std::vector<T>&& elem 也不是万能引用
{
    std::cout << "elem type is : " << type_id_with_cvr<decltype(elem)>().pretty_name() << std::endl;
    std::cout << "T type is : " << type_id_with_cvr<T>.prett_name() << std::endl;
}

int main()
{
    int i = 10;
    test(10);
    return 0;
}

template<typename T>
class MyVector
{
public:
    template<typename T2>
    void push_back(T2&& elem)
}

auto&& elem =



完美转发
int main()
{
    int&& rrefI = 10; //是右值引用，但是左值
    return 0;
}



#include<iostream>
#include<vector>
#include<boost/type_index.hpp>

using boost::typeindex::type_id_with_cvr;

template<typename T>
void func2(T && parm);

template<typename T>
void func1(T && parm);
{
    func2(parm);//-> (std::forward<T>(parm));
}

template<typename T>
void func2(T && parm)
{
    std::cout << type_id_with_cvr<decltype(parm)>().pretty_name() << std::endl;
}
int main()
{
    int i = 10;
    func1(i);
    return 0;
}