#include<bits/stdc++.h>
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

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

    string purchase_data[10][15],value;
    map<string,int>sort_value;
    set<string>sort_v;
    for(int i = 0 ; i < transaction ; i++){
        //cout << "Enter Transaction Id :" ;
        cin >> purchase_data[i][0];
        //cout << endl;
        //cout << "Enter Purchase Item :" ;
            for(int k = 1; k <= maximum_purchase_item  ; k++){
                cin >> value;
                if(value == "*") break;
                //cout << purchase_data[i][k] << endl;
                sort_value[value]++;
                sort_v.insert(value);
            }
            set<string>::iterator it1 = sort_v.begin();
            //it1++;
            for(int j = 1; j <= sort_v.size() ; j++,it1++)
                  purchase_data[i][j] = *it1;

            sort_v.clear();
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

    int c_count = 0,l_count = 0;
    bool first_time = true;
   // while(true){
            c_count++,l_count++;
            if(first_time){
      cout <<endl << "Generating C" << c_count << " from data : " << endl;
      map<string,int>::iterator it = sort_value.begin();
      //it++;
      map<string, int>L_result;

      for(; it != sort_value.end(); it++){
        cout << it->first << " :  " << it->second << endl;
        if(it->second >= minimum_support)
           L_result[it->first] = it->second;
      }

      cout <<endl << "Generating L" << l_count << " from C" << c_count << " : " << endl;
      for(map<string, int>::iterator it2 = L_result.begin(); it2 != L_result.end() ; it2++)
         cout << it2->first << " :  " << it2->second << endl;
        first_time != first_time;
       }else{

       }
    //}
    return 0;
}
