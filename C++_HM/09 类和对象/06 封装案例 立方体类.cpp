#include <iostream>
using namespace std;

class Cube
{
private:
	int l;  // ��
	int w;  // ��
	int h;  // ��

public:
	// ���ó�
	void setL(int L)
	{
		l = L;
	}
	// ��ȡ��
	int getL()
	{
		return l;
	}
	// ���ÿ�
	void setW(int W)
	{
		w = W;
	}
	// ��ȡ��
	int getW()
	{
		return w;
	}
	// ���ø�
	void setH(int H)
	{
		h = H;
	}
	// ��ȡ��
	int getH()
	{
		return h;
	}
    // ��ȡ���������
	int getS()
	{
		return 2 * l * w + 2 * l * h + 2* h * w;
	}
	// ��ȡ���������
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

	cout << "���Ϊ��" << li.getS() << endl;
	cout << "���Ϊ��" << li.getV() << endl;

	system("pause");

	return 0;
}