#include<bits/stdc++.h>
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(NULL);
    freopen("input.txt","r",stdin);

    int transaction,maximum_purchase_item,minimum_support;

   // cout << "Enter Transaction Number : " ;
    cin >> transaction ;
    //cout << endl << "Enter Maximum Purchase Item : " ;
    cin >> maximum_purchase_item;
    //cout << endl;
    //cout << "Enter Minimum Support : " ;
    cin >> minimum_support;
    //cout << endl;

    cout << "Transaction Number : " << transaction << endl << "Maximum Purchase Item : " << maximum_purchase_item << endl << "Minimum Support : " << minimum_support << endl << endl;

    string purchase_data[10][15];
    for(int i = 0 ; i < transaction ; i++){
        //cout << "Enter Transaction Id :" ;
        cin >> purchase_data[i][0];
        //cout << endl;
        //cout << "Enter Purchase Item :" ;
            for(int k = 1; k <= maximum_purchase_item ; k++){
                cin >> purchase_data[i][k];
            }
            //cout << endl;
    }
    cout << "Purchase Data : " << endl;
        for(int i = 0 ; i < transaction ; i++){
          cout << purchase_data[i][0] << " : ";
            for(int k = 1; k <= maximum_purchase_item ; k++){
                cout << " " << purchase_data[i][k];
            }
            cout << endl;
    }

    return 0;
}
