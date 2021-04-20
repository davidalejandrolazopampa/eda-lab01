#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

vector<pair<int, int>> data1;
vector<pair<int, int>> data2;
vector<pair<int, int>> data3;


void dataset1(int n) {
    srand (time(NULL));

    data1.clear();
    for(int i=0; i<n; i++) {
        auto x = rand() % 901;
        auto y = rand() % 901;
        data1.push_back(make_pair(x, y));
    }
}

void dataset2(int n) {
    srand (time(NULL));

    data2.clear();
    for(int i=0; i<n; i++) {
        auto x = rand() % 601 + 900;
        auto y = rand() % 601 + 900;
        data2.push_back(make_pair(x, y));
    }
}

void dataset3(int n) {

    srand (time(NULL));

    data3.clear();
    for(int i=0; i<n; i++) {
        auto x = rand() % 1501;
        auto y = rand() % 1501;
        data3.push_back(make_pair(x, y));
    }
}

float ed(pair<int, int> p1, pair<int, int> p2) {
    float res = 0;

    auto a = p2.first - p1.first;  // x
    auto b = p2.second - p1.second; // y

    res = pow( a + b, 2);
    return sqrt(res);
}

vector<pair<int, int>> knn(pair<int, int> point, int k, vector<pair<int, int>> data) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPQ;
    vector<pair<int, int>> result;

    for(int i=0; i<data.size(); i++) {
        auto d = ed(point, data.at(i));

        minPQ.push(make_pair(d, i));
    }

    result.clear();
    for (int j=0 ; j<k; j++) {
        float index = minPQ.top().second;
        minPQ.pop();
        result.push_back(data.at(index));
    }

    return result;
}

int main() {
    dataset1(50000);
    dataset2(25000);
    dataset3(50000);

    auto point = make_pair( 0, 900);
    cout << "Data set 1"  << endl;
    auto res1 = knn(point, 25, data1);

    for (auto elem: res1)
        cout << "x="<< elem.first << ", y="<< elem.second <<endl;

    auto point2 = make_pair( 959, 1450);
    cout << "Data set 2"  << endl;
    auto res2 = knn(point2, 1100, data2);

    for (auto elem: res2)
        cout << "x="<< elem.first << ", y="<< elem.second <<endl;

    auto point3 = make_pair( 1499, 667);
    cout << "Data set 3"  << endl;
    auto res3 = knn(point3, 100, data3);

    for (auto elem: res3)
        cout << "x="<< elem.first << ", y="<< elem.second <<endl;

    return 0;
}
