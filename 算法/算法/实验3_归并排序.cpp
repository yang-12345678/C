//#include <iostream>
//using namespace std;
//
//void arrayMerge(int data[], int low, int center, int high) {
//    int* p = (int*)malloc(sizeof(int) * (high - low));
//    int i = low;
//    int j = center;
//    int k = 0;//������¼��ʱ������±�
//    while (i < center && j < high) {
//        if (data[i] < data[j]) {
//            p[k++] = data[i++];
//        }
//        else {
//            p[k++] = data[j++];
//        }
//    }
//    //��ʣ���Ԫ�ش��뵽������
//    while (i < center) 
//        p[k++] = data[i++];
//    while (j < high) 
//        p[k++] = data[j++];
//    //����ʱ�����е�Ԫ�ظ��Ƶ�ԭ������
//    for (i = 0, j = low; j < high; j++) 
//        data[j] = p[i++];
//    free(p);
//}
//void mergeSort(int data[], int low, int high) {
//    //�����ǰ������ֻʣ��һ��Ԫ�أ�����
//    if (high - low == 1) 
//        return;
//    int center = (high + low) / 2;
//    //���������
//    mergeSort(data, low, center);
//    //�Ҷ�������
//    mergeSort(data, center, high);
//    //�ϲ�������������
//    arrayMerge(data, low, center, high);
//}
//int main(void) {
//    int data[8] = { 3, 2, 5, 8, 4, 7, 6, 9 };
//    cout << "����ǰ:" << endl;
//    for (int i = 0; i < 8; i++) 
//        cout << data[i] << " ";
//    mergeSort(data, 0, 8);
//    cout << endl << "�����:" << endl;
//    for (int i = 0; i < 8; i++) 
//        cout << data[i] << " ";
//    return 0;
//}
