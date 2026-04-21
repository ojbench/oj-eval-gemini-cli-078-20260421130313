#ifndef EVIL_HPP
#define EVIL_HPP

#include <iostream>
using namespace std;

class Evil{
private:
	int st, ed, val;
	int *data;

public:
    // 默认构造函数
    Evil() : st(0), ed(0), val(0) {
        data = new int[1];
        data[0] = 0;
    }

    // 带参数的构造函数
    Evil(int s, int e, int v) : st(s), ed(e), val(v) {
        int size = ed - st + 1;
        if (size < 1) size = 1; 
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = 0;
        }
    }

    // 析构函数
    ~Evil() {
        if (data) {
            delete[] data;
        }
    }

    // 拷贝构造函数
    Evil(const Evil& other) : st(other.st), ed(other.ed), val(other.val) {
        int size = ed - st + 1;
        if (size < 1) size = 1;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // 赋值运算符重载
    Evil& operator=(const Evil& other) {
        if (this == &other) return *this;
        if (data) delete[] data;
        st = other.st;
        ed = other.ed;
        val = other.val;
        int size = ed - st + 1;
        if (size < 1) size = 1;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    // 下标运算符重载
    int& operator[](int i) {
        if (i < st || i > ed) {
            return data[0];
        }
        return data[i - st];
    }

    // 前置++
    Evil& operator++() {
        val++;
        return *this;
    }

    // 后置++
    Evil operator++(int) {
        Evil temp(*this);
        val++;
        return temp;
    }

    // 输出运算符重载
    friend ostream& operator<<(ostream& os, const Evil& e) {
        os << e.val << " ";
        for (int i = 0; i < e.ed - e.st + 1; ++i) {
            os << e.data[i] << " ";
        }
        os << endl;
        return os;
    }

    void Print(){
	    cout << val << " ";
	    for(int i = 0;i < ed-st+1;++i)
	        cout << data[i] <<" ";
	    cout << endl;
	}
};

#endif//EVIL_HPP
