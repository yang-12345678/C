#include <iostream>
using namespace std;

class Cube
{
private:
	int l;  // 长
	int w;  // 宽
	int h;  // 高

public:
	// 设置长
	void setL(int L)
	{
		l = L;
	}
	// 获取长
	int getL()
	{
		return l;
	}
	// 设置宽
	void setW(int W)
	{
		w = W;
	}
	// 获取宽
	int getW()
	{
		return w;
	}
	// 设置高
	void setH(int H)
	{
		h = H;
	}
	// 获取长
	int getH()
	{
		return h;
	}
    // 获取立方体面积
	int getS()
	{
		return 2 * l * w + 2 * l * h + 2* h * w;
	}
	// 获取立方体体积
	int getV()
	{
		return l * w * h;
	}
};

int main()
{
	Cube li;

	li.setL(10);
	li.setW(10);
	li.setH(10);

	cout << "面积为：" << li.getS() << endl;
	cout << "体积为：" << li.getV() << endl;

	system("pause");

	return 0;
}