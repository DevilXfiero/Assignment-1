#include<bits/stdc++.h>


using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());



int mergeAndCount(const vi &v1, const vi &v2, vi &ans)
{
	ans.clear();
	int i = 0, j = 0, count = 0;

	while (i < v1.size() and j < v2.size())
	{
		if (v1[i] <= v2[j])
			ans.pb(v1[i]), i++;

		else
		{
			count += v1.size() - i;
			ans.pb(v2[j]), j++;
		}
	}

	//atleast 1 of the 2 would've exhausted
	while (i < v1.size())
		ans.pb(v1[i++]);

	while (j < v2.size())
		ans.pb(v2[j++]);

	return count;
}

int countInvAndSort(vi &arr)
{
	if (arr.size() <= 1)
		return 0;

	int n = arr.size();

	vi left(arr.begin(), arr.begin() + n / 2); //0 to (n/2 - 1)
	vi right(arr.begin() + n / 2, arr.end()); //n/2 to (n - 1)

	return countInvAndSort(left) + countInvAndSort(right) + mergeAndCount(left, right, arr);
}

int32_t main()
{


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	FIO;
	int n; cin >> n;
	vi arr(n);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int inv = countInvAndSort(arr);
	cout << inv << '\n';


	return 0;
}
