class MyClass {
    std::unique_ptr<int> data;

public:
    // 构造函数，转移所有权
    MyClass(std::unique_ptr<int> ptr) : data(std::move(ptr)) {}

    void show() {
        if (data) {
            std::cout << "Data: " << *data << std::endl;
        }
        else {
            std::cout << "No data" << std::endl;
        }
    }
};






class MyClass {
    std::unique_ptr<int> data;

public:
    // 默认构造函数
    MyClass() = default;

    // 移动构造函数
    MyClass(MyClass&& other) noexcept : data(std::move(other.data)) {}

    // 移动赋值运算符
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            data = std::move(other.data);
        }
        return *this;
    }

    void setData(std::unique_ptr<int> ptr) {
        data = std::move(ptr);
    }

    void show() {
        if (data) {
            std::cout << "Data: " << *data << std::endl;
        }
        else {
            std::cout << "No data" << std::endl;
        }
    }
};

int main() {
    MyClass obj1;
    obj1.setData(std::make_unique<int>(100)); // 设置数据
    obj1.show();

    MyClass obj2 = std::move(obj1); // 转移所有权到 obj2
    obj2.show();
    obj1.show(); // 此时 obj1 不再拥有资源

    return 0;
}




#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = { 1, 2, 3 };

    // 使用迭代器遍历
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " "; // 使用 * 解引用迭代器
    }

    return 0;
}




