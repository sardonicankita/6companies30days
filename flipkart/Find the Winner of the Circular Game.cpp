class Solution {
public:
    int findTheWinner(int n, int k) {
     queue<int> q;
     for( int i = 1 ; i <= n ; ++i )
     {
         q.push(i);
     }

     for(int i = 0 ; i < n-1 ; ++i ) // n-1 times remove kth elment 
     {
         // kth elmen
         // reaching tth element by poping first t-1 element and inserting again at end becuase  they will in game 
         for( int j = 0 ; j < k-1 ; ++j)
         {
             int x = q.front();
             q.pop();
             q.push(x);
         } 
         q.pop(); // removing kth element 
     }

     return q.front();

    }
};