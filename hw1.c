#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int data[100000]; // 최대 10만개라고 가정
int n; // 데이터 개수 (문제의 크기)
void DataGen(int);
int SequentialSearch(int key);
int BinarySearch(int key);
int main()
{
    int key; // 찾을 키 값
    int s, b;
    int sMin, sMax, sAvg;
    int bMin, bMax, bAvg;
    srand(time(NULL)); // 난수 초기화
    // 문제의 크기인 n을 5000씩 증가시키면서 다음을 실행
    for (n = 5000; n <= 100000; n += 5000) {
        DataGen(n); // data[]에 n 개의 키 값 생성
        // 동일한 data[]로 키 값을 바꿔가면서 100회 반복
        sMin = 100001; // sMin은 SequentialSearch 연산 횟수의 최소 값
        sMax = 0; // sMax는 SequentialSearch 연산 횟수의 최대 값
        sAvg = 0; // sAvg는 SequentialSearch 연산 횟수의 평균 값
        bMin = 100001; // bMin은 BinarySearch 연산 횟수의 최소 값
        bMax = 0; // bMax는 BinarySearch 연산 횟수의 최대 값
        bAvg = 0; // bAvg는 BinraySearch 연산 횟수의 평균 값

        for (int i = 0; i < 100; i++) {
            key = rand() % n; // 임의의 키 값 선택
            s = SequentialSearch(key); // SequentialSearch 시행
            b = BinarySearch(key); // BinarySearch 시행
            // 100회 반복하면서 s, b의 최소, 최대, 평균 값 계산
            sMin = (s < sMin ? s : sMin); // sMin의 값 구하는 과정
            sMax = (s > sMax ? s : sMax); // sMax의 값 구하는 과정
            sAvg += s; // sAvg의 값을 구하는 과정

            bMin = (b < bMin ? b : bMin); // bMin의 값 구하는 과정
            bMax = (b > bMax ? b : bMax); // bMax의 값 구하는 과정
            bAvg += b; // bAvg의 값을 구하는 과정
        }
        // s, b의 최소, 최대, 평균 값 출력
        printf("sMIN: %d, sMAX: %d, sAVG: %d \n", sMin, sMax, sAvg / 100); // SequentailSearch 시행의 최소 값, 최대 값, 평균 값 출력
        printf("bMIN: %d, bMAX: %d, bAVG: %d \n\n", bMin, bMax, bAvg / 100); // BinarySearch 시행의 최소 값, 최대 값, 평균 값 출력
    }
}
int SequentialSearch(int key)
{
    // Algorithm 1.1을 활용하여 작성
    // ... data[] 에서 key의 인덱스를 확인할 때까지 키 값들을 비교한 횟수 반환
    // SequentialSearch를 통해 key값을 찾음.
    int location = 0;
    while (location < n && data[location] != key) {
        location++;
    }

    return location;
}

int BinarySearch(int key)
{
    // Algorithm 1.5 또는 2.1를 활용하여 작성
    // ... data[] 에서 key의 인덱스를 확인할 때까지 키 값들을 비교한 횟수 반환
    // BinarySearch를 통해 key값을 찾음.
    int count = 0;
    size_t low = 0;
    size_t high = n;
    size_t mid = (low + high) / 2;

    while (low <= high) {
        mid = (low + high) / 2;
        count++;
        if (data[mid] == key) {
            break;
        } else if (key < data[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return count;
}

void DataGen(int n)
{
    int i;
    for (i = 0; i < n; i++) // 아주 단순하게 만들었음
        data[i] = i;
}