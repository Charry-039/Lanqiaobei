//
// Created by Charry on 2022/6/24.
//

#include "iostream"

using namespace std;

const int N = 5e4 + 10;

struct Ox{
    int w,s;
    bool operator<(const Ox &t)const{
        return this->w<t.w;
    }
}ox[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &ox[i].w, &ox[i].s);

    return 0;
}