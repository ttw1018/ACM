#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

using namespace std;

// 函数原型
#define f(x) (10 * sin(5 * x) + 7 * abs(x - 5) + 10)

// 随机数生成
#define ra(x) rand() % x

// MA 最大值 MI 最小值
const double MA = 10;
const double MI = 0;

//  变异概率
const double varition_possiblity = 0.1;

//  交叉概率
const double cross_possibility = 0.8;

// 精度
const double precision = 0.01;

// 能够生成的最大随机数
int max_random;

// 编码的位数
int bit_cnt;

// 种群
vector<double> group;

// 获取编码
int getid(double x) { return (x - MI) / precision; }

// 从编码到值
double getval(int x) { return MI + x * precision; }

// 产生初始种群
void init(int num) {
  srand(clock());
  max_random = (MA - MI) / precision + 1;

  for (int i = 0; i < 30; i++) {
    if (max_random < (1 << i)) {
      bit_cnt = i + 1;
      break;
    }
  }
  group.clear();
  for (int i = 0; i < num; i++) {
    group.push_back(getval(ra(max_random)));
  }
}

// 交叉 这里采用单点交叉
void cross() {
  srand(int(time(NULL)));
  for (int i = 0; i < group.size() * 5; i++) {
    if (ra(100) > 100 * cross_possibility)
      continue;
    int p1 = ra(group.size());
    int p2 = ra(group.size());
    int bit = ra(bit_cnt);
    int id1 = getid(group[p1]);
    int id2 = getid(group[p2]);
    int b1 = id1 & (1 << bit);
    int b2 = id2 & (1 << bit);
    b1 ^= b2;
    double val1 = getval(id1 ^ b1);
    double val2 = getval(id2 ^ b1);
    if (val1 <= MA && val2 <= MA) {
      group[p1] = val1;
      group[p2] = val2;
    }
  }
}

// 变异
void varite() {
  srand(int(time(NULL)));
  for (auto &i : group) {
    if (ra(100) > 100 * varition_possiblity) {
      continue;
    }
    int bit = ra(bit_cnt);
    int id = getid(i);
    id ^= (1 << bit);
    double now = getval(id);
    if (now <= MA) {
      i = now;
    }
  }
}

// 生成下一代
void nex_gen() {
  srand(int(time(NULL)));
  vector<pair<double, double>> val;
  double sum = 0;
  pair<double, double> best_son(0, 0);
  for (int i = 0; i < group.size(); i++) {
    sum += f(group[i]);
    best_son = max(best_son, {f(group[i]), group[i]});
  }

  double now = 0;
  for (int i = 0; i < group.size(); i++) {
    val.push_back({now, now + f(group[i])});
    now += f(group[i]);
  }

  vector<double> next_group;
  for (int i = 0; i < group.size() - 1; i++) {
    double x = double(ra(1000)) / 1000 * sum;
    for (int j = 0; j < group.size(); j++) {
      if (val[j].first <= x && x < val[j].second) {
        next_group.push_back(group[j]);
      }
    }
  }
  group = next_group;
  cross();
  varite();
  group.push_back(best_son.second);
}

int best_ans_cnt = 0;
int best_ans_sum = 0;

double max_res = 0;
double min_res = 1e18;
double sum_res = 0;

// num 种群数目
// times 迭代次数

void run(int num, int times) {
  srand(int(time(NULL)));
  init(num);
  int flag = 0;
  for (int t = 0; t < times; t++) {
    nex_gen();
    pair<double, double> ans(0, 0);
    for (auto i : group) {
      ans = max(ans, {f(i), i});
    }
    if (ans.second == 0.29) {
      if (!flag) {
        printf("找到最佳结果， 迭代次数: %d\n", t + 1);
        flag = 1;
        best_ans_cnt++;
        best_ans_sum += t + 1;
      }
    }
    // if (t % 10 == 9) {
    //   printf("%-10d\t%-10d\t%.2f\t%.2f\t\n", num, t + 1, ans.second,
    //   ans.first);
    // }
  }
  pair<double, double> ans(0, 0);
  for (auto i : group) {
    ans = max(ans, {f(i), i});
  }
  max_res = max(max_res, ans.first);
  min_res = min(min_res, ans.first);
  sum_res += ans.first;

  printf("%-10d\t%-10d\t%.2f\t%.2f\t\n", num, times, ans.second, ans.first);
}

int main() {

  pair<double, double> best(0, 0);

  for (double t = 0; t <= MA; t += precision) {
    best = max(best, {f(t), t});
  }
  printf("%s\t%-s\t%s\t%s\t\n", "种群数目", "迭代次数", "x取值", "函数值");
  printf("%s\t%-10s\t%.2f\t%.2f\t\n", "最佳答案", "无", best.second,
         best.first);
  for (int t = 0; t < 20; t++) {
    run(20, 30);
  }

  cout << "最好解: " << max_res << endl;
  cout << "最坏解: " << min_res << endl;
  cout << "平均解: " << sum_res / 20 << endl;
  cout << "最好解频率: " << best_ans_cnt << endl;
  cout << "最好解的平均代数: " << double(best_ans_sum) / best_ans_cnt << endl;

  return 0;
}
