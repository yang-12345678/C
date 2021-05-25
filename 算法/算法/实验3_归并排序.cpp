//#include <iostream>
//using namespace std;
//
//void arrayMerge(int data[], int low, int center, int high) {
//    int* p = (int*)malloc(sizeof(int) * (high - low));
//    int i = low;
//    int j = center;
//    int k = 0;//用来记录临时数组的下标
//    while (i < center && j < high) {
//        if (data[i] < data[j]) {
//            p[k++] = data[i++];
//        }
//        else {
//            p[k++] = data[j++];
//        }
//    }
//    //将剩余的元素存入到数组中
//    while (i < center) 
//        p[k++] = data[i++];
//    while (j < high) 
//        p[k++] = data[j++];
//    //将临时数组中的元素复制到原数组中
//    for (i = 0, j = low; j < high; j++) 
//        data[j] = p[i++];
//    free(p);
//}
//void mergeSort(int data[], int low, int high) {
//    //如果当前序列中只剩下一个元素，返回
//    if (high - low == 1) 
//        return;
//    int center = (high + low) / 2;
//    //左二分排序
//    mergeSort(data, low, center);
//    //右二分排序
//    mergeSort(data, center, high);
//    //合并两个升序数组
//    arrayMerge(data, low, center, high);
//}
//int main(void) {
//    int data[8] = { 3, 2, 5, 8, 4, 7, 6, 9 };
//    cout << "排序前:" << endl;
//    for (int i = 0; i < 8; i++) 
//        cout << data[i] << " ";
//    mergeSort(data, 0, 8);
//    cout << endl << "排序后:" << endl;
//    for (int i = 0; i < 8; i++) 
//        cout << data[i] << " ";
//    return 0;
//}
