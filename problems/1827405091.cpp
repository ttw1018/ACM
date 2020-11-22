#include <iostream>
#include <ctime>
#include <pthread.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const int maxn = 1050;
double A[maxn][maxn], B[maxn][maxn];
double C[maxn][maxn];
int n = 1024;
const int N = 8;

//线程函数
void *test0(void *ptr) {
  for (int i = 1; i <= n; i += N)
    for (int k = 1; k <= n; ++k) {
      double s = A[i][k];
      for (int j = 1; j <= n; ++j)
        C[i][j] += s * B[k][j];
    }
}
void *test1(void *ptr) {
  for (int i = 2; i <= n; i += N)
    for (int k = 1; k <= n; ++k) {
      double s = A[i][k];
      for (int j = 1; j <= n; ++j)
        C[i][j] += s * B[k][j];
    }
}
void *test2(void *ptr) {
  for (int i = 3; i <= n; i += N)
    for (int k = 1; k <= n; ++k) {
      double s = A[i][k];
      for (int j = 1; j <= n; ++j)
        C[i][j] += s * B[k][j];
    }
}
void *test3(void *ptr) {
  for (int i = 4; i <= n; i += N)
    for (int k = 1; k <= n; ++k) {
      double s = A[i][k];
      for (int j = 1; j <= n; ++j)
        C[i][j] += s * B[k][j];
    }
}
void *test4(void *ptr) {
  for (int i = 5; i <= n; i += N)
    for (int k = 1; k <= n; ++k) {
      double s = A[i][k];
      for (int j = 1; j <= n; ++j)
        C[i][j] += s * B[k][j];
    }
}
void *test5(void *ptr) {
  for (int i = 6; i <= n; i += N)
    for (int k = 1; k <= n; ++k) {
      double s = A[i][k];
      for (int j = 1; j <= n; ++j)
        C[i][j] += s * B[k][j];
    }
}
void *test6(void *ptr) {
  for (int i = 7; i <= n; i += N)
    for (int k = 1; k <= n; ++k) {
      double s = A[i][k];
      for (int j = 1; j <= n; ++j)
        C[i][j] += s * B[k][j];
    }
}
void *test7(void *ptr) {
  for (int i = 8; i <= n; i += N)
    for (int k = 1; k <= n; ++k) {
      double s = A[i][k];
      for (int j = 1; j <= n; ++j)
        C[i][j] += s * B[k][j];
    }
}

int main() {
  clock_t startTime, endTime;
  freopen("M1024A.txt", "r", stdin);
  startTime = clock();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%lf", &A[i][j]);
    }
  }
  freopen("M1024B.txt", "r", stdin);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%lf", &B[i][j]);
    }
  }
  endTime = clock();
  printf("读入时间%lf\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);

  startTime = clock();
  pthread_t pId[N];
  int i, ret;
  //创建子线程，线程id为pId
  ret = pthread_create(&pId[0], NULL, test0, NULL);
  if (ret != 0) {
    printf("create pthread error!\n");
    exit(1);
  }
  ret = pthread_create(&pId[1], NULL, test1, NULL);
  if (ret != 0) {
    printf("create pthread error!\n");
    exit(1);
  }
  ret = pthread_create(&pId[2], NULL, test2, NULL);
  if (ret != 0) {
    printf("create pthread error!\n");
    exit(1);
  }
  ret = pthread_create(&pId[3], NULL, test3, NULL);
  if (ret != 0) {
    printf("create pthread error!\n");
    exit(1);
  }
  ret = pthread_create(&pId[4], NULL, test0, NULL);
  if (ret != 0) {
    printf("create pthread error!\n");
    exit(1);
  }
  ret = pthread_create(&pId[5], NULL, test1, NULL);
  if (ret != 0) {
    printf("create pthread error!\n");
    exit(1);
  }
  ret = pthread_create(&pId[6], NULL, test2, NULL);
  if (ret != 0) {
    printf("create pthread error!\n");
    exit(1);
  }
  ret = pthread_create(&pId[7], NULL, test3, NULL);
  if (ret != 0) {
    printf("create pthread error!\n");
    exit(1);
  }

  pthread_join(pId[0], NULL);
  pthread_join(pId[1], NULL);
  pthread_join(pId[2], NULL);
  pthread_join(pId[3], NULL);
  pthread_join(pId[4], NULL);
  pthread_join(pId[5], NULL);
  pthread_join(pId[6], NULL);
  pthread_join(pId[7], NULL);
  //	for(int i=1;i<=n;++i)
  //    for(int j=1;j<=n;++j)
  //        for(int k=1;k<=n;++k)
  //            C[i][j]+=A[i][k]*B[k][j];

  //    for(int i=1;i<=n;++i)
  //    for(int k=1;k<=n;++k){
  //        double s=A[i][k];
  //        for(int j=1;j<=n;++j)
  //            C[i][j]+=s*B[k][j];
  //	}
  endTime = clock();
  printf("运行时间：%lf\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);

  freopen("1024.out", "w", stdout);
  startTime = clock();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%.12lf ", C[i][j]);
    }
    printf("\n");
  }
  endTime = clock();
  freopen("CON", "w", stdout);
  printf("写入时间：%lf\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);

  return 0;
}