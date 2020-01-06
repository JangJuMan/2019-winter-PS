// for 노트/ 공부
#include <bits/stdc++.h>

#define din(a) scanf("%d", &a)
#define printd(a) printf("%d\n", a)

using namespace std;

// inline은 내부에서 사용되는 짧은 코드를 컴파일러가 빠르게 처리하기 위해 사용.
// 그런데 요즘은 컴파일러가 알아서 해주는 경우가 대부분이라 안해도 됨(그냥 기억만 하자고 써봄).
inline int my_abs(int a){
    return (a > 0) ? a : -a;
}

struct node{
    int d;
    node() {
        d = 0;
    }
    node(int i):d(i){}
    bool operator < (node t){   // ???
        if(my_abs(d) == my_abs(t.d)){
            if(d < t.d) 
                return true;
            return false;
        }
        else if(my_abs(d) < my_abs(t.d)){
            return true;
        }
        return false;
    }
};

template<typename T>
struct heap{
    T d[1 << 18];   // ???
    int e;
    heap(){
        e = 0;
    }
    bool empty(){
        return !e;
    }
    bool full(){
        return (e+1) == (1 << 18);  // ??? 2^18?
    }
    void push(T input){
        if(full())
            return;
        d[++e] = input;
        int curr = e;
        while((curr/2) > 0){
            if(d[curr] < d[curr/2]){
                swap(d[curr], d[curr/2]);
            }
            else{
                break;
            }
            curr /= 2;
        }
    }
    void pop(){
        if(empty())
            return;
        d[1] = d[e];
        e--;
        int curr = 1;
        while(curr * 2 <= e){
            int child;
            if(curr * 2 + 1 > e){
                child = curr * 2;
            }
            else{
                if(d[curr *2] < d[curr*2 + 1]){
                    child = curr * 2;
                }
                else{
                    child = curr * 2 + 1;
                }
            }
            if(d[curr] < d[child]){
                break;
            }
            swap(d[curr], d[child]);
            curr = child;
        }
    }
    T top(){
        T ret;
        if(empty())
            return ret;
        return d[1];
    }
    void swap(T& a, T& b){
        T t = a;
        a = b;
        b = t;
    }
};

heap<node> PQ;

int main(){
    int n, input;
    din(n);
    for(int i=0; i<n; i++){
        din(input);
        if(input == 0){
            if(PQ.empty()){
                printd(0);
            }
            else{
                printd(PQ.top().d);
                PQ.pop();
            }
        }
        else{
            PQ.push(node(input));
        }
    }
}