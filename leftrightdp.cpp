Cho một dãy số nguyên dương gồm 𝑁 phần tử 𝑎1, 𝑎2, … , 𝑎𝑁. Gọi 𝑓(𝐿, 𝑅) = (𝑅 − 𝐿 + 1) ×
min{𝑎𝐿, 𝑎𝐿+1, … , 𝑎𝑅} với 1 ≤ 𝐿 ≤ 𝑅 ≤ 𝑁.
Yêu cầu: Xác định giá trị 𝑓(𝐿, 𝑅) lớn nhất có thể trên dãy 𝐴.
Input:
Dòng đầu gồm duy nhất một số nguyên dương 𝑁 (𝑁 ≤ 105);
Dòng thứ hai gồm 𝑁 số nguyên dương 𝑎1, 𝑎2, … , 𝑎𝑁 (𝑎𝑖 ≤ 104).

//Sol
Gọi L[i] và  R[i] là 2 mảng sao cho:
L[i]<=i<=R[i]
min{a[Li], a([Li]+1), ..., a[Ri]} >= a[i]
Tất cả các phần tử từ L[i]->R[i] không nhỏ hơn a[i].
L[i] nhỏ nhất, R[i] lớn nhất
=> (R[i]-L[i]+1)max
Khi đó: kq=max{R[i]-L[i]+1}*a[i];
Xây dựng L[i], R[i]
for(int i=1; i<=n; i++)
{
L[i]=i-1;
while(L[i]>0&&a[L[i]]>=a[i]) L[i]=L[L[i]];
}
for(int j=n; j>0; j--)
{
R[j]=j+1;
while(R[j]<=n&&a[R[j]]>=a[i]) R[j]=R[R[j]];
}
Duyệt: for(i=1->n) mx=max(mx,(R[i]-L[i]-1)*a[i]);
