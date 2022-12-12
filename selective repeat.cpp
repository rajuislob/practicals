#include<bits/stdc++.h>

#include<ctime>
#include<queue>
#define ll long long int
using namespace std;
void receiver();
    queue<int>q;
void receiver(ll &,ll &,ll &,int &);
void transmission(ll & i, ll & N, ll & tf, ll & tt) {
  while (i <= tf) {
    int z = 0;
    for (int k = i; k < i + N && k <= tf; k++) {
      cout << "Sending Frame " << k << "..." << endl;
      tt++;
    }
 receiver(i,N,tf,z);
    receiver();
  }
}
void receiver()
{
   while(!q.empty()) 
   {
      int f = rand() % 2;
      if (!f) {
        cout << "Acknowledgment for Frame " << q.front()<< "..." << endl;
        q.pop();
      } else {
        cout << "Timeout!! Frame Number : " << q.front() << " Not Received" << endl;
   }
}
}
    void receiver(ll &i,ll&N,ll &tf,int &z)
    {
    for (int k = i; k < i + N && k <= tf; k++) {
      int f = rand() % 2;
      if (!f) {
        cout << "Acknowledgment for Frame " << k << "..." << endl;
        z++;
      } else {
        cout << "Timeout!! Frame Number : " << k << " Not Received" << endl;
         q.push(k);
         z++;
      }
    }
    cout << "\n";
    i = i + z;
  }

int main() {
  ll tf, N, tt = 0;
  srand(time(NULL));
  cout << "Enter the Total number of frames : ";
  cin >> tf;
  cout << "Enter the Window Size : ";
  cin >> N;
  ll i = 1;
  transmission(i, N, tf, tt);
  cout << "Total number of frames which were sent and resent are : " << tt <<
    endl;
  return 0;
}
