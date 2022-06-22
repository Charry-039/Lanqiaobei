//
// Created by Charry on 2022/4/28.
//

#include <vector>
#include <algorithm>
#include "iostream"

using namespace std;
vector<int>axis;//数轴
vector<pair<int,int>>idx_value;//键值对
vector<pair<int,int>>q;
int n,m;

int main() {
    int x,c,l,r;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d",&x,&c);
        axis.push_back(x);//数轴存有值的点
        idx_value.push_back({x,c});//键值对，存入坐标和值
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d",&l,&r);
        axis.push_back(l);
        axis.push_back(r);
        q.push_back({l,r});//存入所查询区间
    }
    sort(axis.begin(),axis.end());
    long len= unique(axis.begin(),axis.end())-axis.begin();
    for (int i = 0; i <=len ; i++) {
        x=
    }
    return 0;
}