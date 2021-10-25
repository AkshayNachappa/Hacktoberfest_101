#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

template <class T>
class Algebra
{
public:
    static T binExpIterative(T a, T b)
    {
        T ans = 1;
        do
        {
            if (b & 1)
                ans *= a;
            b >>= 1; //b/=2
            a *= a;  //a^2
        } while (b != 0);
        return ans;
    }

    static T binExpRecursive(T a, T b) //a^b
    {
        if (b < 1)
            return 1;
        // cout<<a<<endl;
        if (b & 1)
            return a * binExpRecursive(a * a, b / 2);
        else
            return binExpRecursive(a * a, b / 2);
    };
};

int main()
{
    
    ll b, e;
    cout<<"Enter base: ";
    cin>>b;
    cout<<"Enter exponent: ";
    cin>>e;
    cout<<Algebra<ll>::binExpIterative(b,e)<<endl;

    cout << Algebra<ll>::binExpRecursive(b,e) << endl;

}