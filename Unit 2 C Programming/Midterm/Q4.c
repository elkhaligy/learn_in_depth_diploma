#include <stdio.h>

int reverse(int n);

int main() {
    int n, ans;
    printf("Enter a number: ");
    scanf("%d", &n);
    ans = reverse(n);
    printf("Reversed number: ");
    printf("%d",ans);
    return 0;
}

int reverse(int n) {
    int rem,ans=0;
    while(n!=0){
        rem=n%10;
        ans=ans*10+rem;
        n=n/10;
    }
    return ans;
}
