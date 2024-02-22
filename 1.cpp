#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define  ll  long long
#define fastread() (ios_base::sync_with_stdio(0),cin.tie(0));
using namespace __gnu_pbds;
using namespace std;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod = 1e9+7;
int FirstDayOfMonth(int year, int month) {
    int t[12] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int y = year - (month < 2);
    y = (y + y / 4 - y / 100 + y / 400 + t[month] + 1) % 7;
    return y;
}

int GetDaysInMonth(int year, int month) {
    int The_months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool leap = ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));

    if (leap)
        The_months[1] = 29;

    return The_months[month];
}

void solve()
{
    string s;
    cin.ignore();
    getline(cin, s);
    int month = stoi(s.substr(3, 2));
    int year = stoi(s.substr(6, 4));
    cout << "|---------------------------|" << endl;
    cout << "|Sun|Mon|Tue|Wed|Thu|Fri|Sat|" << endl;
    int firstDay = FirstDayOfMonth(year, month - 1);
    int days = GetDaysInMonth(year, month - 1);


    int row = 1, countDay = 1;
    while (countDay <= days && row <= 5) {
        if (row == 1 && 35 - firstDay < days) {
            int lastDays = 36 - firstDay;
            for (int i = 0; i < 7; i++) {
                cout << "|";
                if (lastDays <= days) {
                    cout << " " << lastDays;
                    lastDays++;
                } else if (i < firstDay)cout << " - ";
                else {
                    if (countDay < 10)cout << "  " << countDay; else cout << " " << countDay;
                    countDay++;
                }
            }
            cout << "|" << endl;
            cout << "|---------------------------|" << endl;
            row++;
        } else if (row == 1) {
            for (int i = 0; i < 7; i++) {
                cout << "|";
                if (i < firstDay)cout << " - ";
                else {
                    if (countDay < 10)cout << "  " << countDay; else cout << " " << countDay;
                    countDay++;
                }
            }
            cout << "|" << endl;
            cout << "|---------------------------|" << endl;
            row++;

        } else {
            for (int i = 0; i < 7; i++) {
                cout << "|";
                if (countDay > days)cout << " - ";
                else if (countDay < 10)cout << "  " << countDay; else cout << " " << countDay;
                countDay++;
            }
            cout << "|" << endl;
            cout << "|---------------------------|" << endl;
            row++;
        }
    }
    cout << endl;
}
 
int main()
{
    fastread();
    int t;
    cin>>t;
    while(t--)
    {
       solve();
    }
     
    return 0;
}