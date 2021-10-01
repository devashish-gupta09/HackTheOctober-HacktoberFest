#include <iostream>
#include <climits>
using namespace std;
int kadane(int arr[], int n){
        for (int i = 0; i < n; i++)
    {
        cout<< arr[i]<<" ";
    }
cout<<endl;
    int currentsum=0,maxsum=INT_MIN;
    for (int i=0;i<n;i++){
        currentsum+=arr[i];
        if(currentsum<0)
        {
            currentsum=0;
        }
        maxsum=max(maxsum,currentsum);
    }
    return maxsum;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }



    int totalsum=0;
    for (int i=0;i<n;i++)
    {
       totalsum+=arr[i];
       arr[i]= -arr[i];
    }
    int nonwrapsum=kadane(arr,n),wrapsum;
    cout<<nonwrapsum<<endl;
    wrapsum = totalsum - nonwrapsum;
    cout<<wrapsum<<endl;

    return 0;
}

