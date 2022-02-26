//Bài toán
//Đếm số lượng thành phần liên thông mạnh trên đồ thị có hướng.
//
//Thành phần liên thông mạnh là một tập hợp các đỉnh mà với bất cứ cặp u, v nào, ta luôn có u đi tới được v và v đi tới được u (có thể qua một số đỉnh trung gian). Khi phân tích một đồ thị ra thành phần liên thông mạnh, mỗi TPLTM phải là cực đại, nghĩa là không thể thêm bất cứ đỉnh nào vào một TPLTM mà vẫn tạo thành TPLTM.

#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int N = 100005;
const int oo = 0x3c3c3c3c;

int n, m, Num[N], Low[N], cnt = 0;
vector<int> a[N];
stack<int> st;
int Count = 0;

void visit(int u) {
    Low[u] = Num[u] = ++cnt;
    st.push(u);

    for (int v : a[u])
        if (Num[v])
            Low[u] = min(Low[u], Num[v]);
        else {
            visit(v);
            Low[u] = min(Low[u], Low[v]);
        }

    if (Num[u] == Low[u]) {  // found one
        Count++;
        int v;
        do {
            v = st.top();
            st.pop();
            Num[v] = Low[v] = oo;  // remove v from graph
        } while (v != u);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
    }

    for (int i = 1; i <= n; i++)
        if (!Num[i]) visit(i);

    cout << Count << endl;
}

//Mô tả
//int Num[]
//Num[u] là thời gian thăm nút u trong quá trình duyệt DFS
//int Low[]
//Tưởng tượng, khi xuất phát từ u, đi qua một số cung trên cây DFS, và nhiều nhất một cung ngược, ta được một danh sách tập hợp các nút đến được. Low[u] là Num[x] nhỏ nhất trong tất cả các x nằm trong tập này.
