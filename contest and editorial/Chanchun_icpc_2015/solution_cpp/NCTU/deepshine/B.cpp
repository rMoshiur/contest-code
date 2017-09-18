#include <cstdio>
#include <cstdlib>
#include <vector>
#include <unordered_map>

using namespace std;

typedef unsigned long long unsignedll;

bool isPrime[100000];
vector<int> prime;
unordered_map<long long, unsignedll> Map; 

void buildPrime(){
    for(int i=0;i<100000;i++) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i<100000;i++){
        if(!isPrime[i]) continue;
        for(int j=i+i;j<100000;j+=i) isPrime[j] = false;
        prime.push_back(i);
    }
    //for(int i : prime) printf("%d\n", i);
}

void decomposition(int n, vector<int>& base, vector<int>& expo){
    for(int i : prime){
        if(i > n) break;
        int counter = 0;
        while(n % i == 0){
            counter++;
            n /= i;
        }
        if(counter){
            base.push_back(i);
            expo.push_back(counter);
        }
    }
    if(n > 1){
        base.push_back(n);
        expo.push_back(1);
    }
}

inline long long encode(int base, int expo){
    return ((long long)base<<17) | expo;
}

unsignedll pow(int a, int b){
    unsignedll result = 1llu;
    for(int i=0;i<b;i++) result *= a;
    return result;
}

unsignedll h(int base, int expo){
    //printf("call h : %d, %d\n", base, expo);
    long long code = encode(base, expo);
    if(Map.count(code)) return Map[code];
    if(expo == 0) return Map[code] = 1;
    unsignedll result = 0;
    result = h(base, expo-1)*base + pow(base, expo) - pow(base, expo-1);
    Map[code] = result;
    //printf("h(%d, %d) = %llu\n", base, expo, result);
    return result;
}

void enumerate(int now, unsignedll value, unsignedll chosen, unsignedll& result, vector<int>& base, vector<int>& expo){
    if(now == base.size()){
        result += value*value - chosen;
        return;
    }
    int temp = 1;
    for(int i=0;i<=expo[now];i++){
        enumerate(now+1, value*temp, chosen * h(base[now], i), result, base, expo);
        temp *= base[now];
    }
}

int main(){
    buildPrime();
    int testcases;
    scanf("%d", &testcases);
    while(testcases--){
        int n;
        scanf("%d", &n);
        vector<int> base;
        vector<int> expo;
        decomposition(n, base, expo);
        //printf("%d = ", n);
        //for(int i=0;i<base.size();i++){
        //    printf("%d x %d + ", base[i], expo[i]);
        //}
        //printf("0\n");
        unsignedll result = 0;
        enumerate(0, 1, 1llu, result, base, expo);
        printf("%llu\n", result);
    }
    return 0;
}
