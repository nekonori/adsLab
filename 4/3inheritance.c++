#include <bits/stdc++.h>
using namespace std;

class A {
public:
	A()
	{
	cout << "This is a A\n";
	}
};

class B : public A {
    public:
    B(){}
};

class C{};

class D : public A, public C{};

class E : public B{};

int main()
{
    // single inheritance
	B obj;

    // multiple & hierarchical inheritance
    D obj2;

    // multilevel inheritance
    E obj3;
	return 0;
}
