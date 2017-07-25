
/*----------------------------------------------------------------------------------------------------------------------------------------\\
|                                                                                                                                          |
|                                             Name           : ARIF KHAN NIHAR                                                             |
|                                             E_mail         : arifkhanshubro@gmail.com                                                    |
|                                             github_link    : https://github.com/arifkhan1990/Algorithm_Implementation                    |
|                                             Problem        : Implementation of Apriori Algorithm in C++                                  |
|                                             Date           : 23/07/2017                                                                  |
|                                             Subject_ref    : Data Mining                                                                 |
|                                             Execution Time : 0.017s                                                                      |
|                                                                                                                                          |
|                                                                                                                                          |
|                                                                                                                                          |
|                                             My Blog link :   https://arif778.blogspot.com/                                               |
-------------------------------------------------------------------------------------------------------------------------------------------*/

#include<bits/stdc++.h>
using namespace std;

int br[10][10],m_ar[10];
int ar[10];
vector<int>result;
map<string,int>L_c;
string st;
int transaction,maximum_purchase_item,minimum_support;
void output(int m);
void C_cal_And_L_cal(int pt)
{
  for(int h1 = 0; h1 < result.size() ; h1++){
        st.clear();
    for(int h2 = h1+1; h2 < result.size() and h1+2 == pt;h2++){
      for(int h3 = 0; h3 <= h1 ; h3++ ){
            st += result[h3]+ '0';
            cout << result[h3] << " ";
                 }
                 cout << result[h2] << endl;
                 st += result[h2]+ '0';
                 int po = L_c.find(st)->second;
                 L_c[st]++;
                 //L_c.insert(pair<string,int>(st,po++));

                 st.clear();
            }

        }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

   // cout << "Enter Transaction Number : " ;
    cin >> transaction ;
    //cout << endl << "Enter Maximum Purchase Item : " ;
    cin >> maximum_purchase_item;
    //cout << endl;
    //cout << "Enter Minimum Support : " ;
    cin >> minimum_support;
    //cout << endl;
    cout << "Transaction Number : " << transaction << endl << "Maximum Purchase Item : " << maximum_purchase_item << endl << "Minimum Support : " << minimum_support << endl << endl;

    set<int>cr;
    map<int,int>sort_value;
    map<int,int>::iterator it;

       for(int i = 0 ; i < transaction ; i++){
            int value;
            for(int k = 0 ; k < maximum_purchase_item  ; k++){
                cin >> value;

                if(value == 0) {
                        break;
                }
                sort_value[value]++;
                br[i][k] = value;
                cr.insert(value);
            }
    }

    cout << "Purchase Data : " << endl;
    for(int i = 0 ; i < transaction ; i++){
            cout << i+1 << " : ";
            for(int k = 0 ; k < maximum_purchase_item and br[i][k] != 0  ; k++){
                cout << " " << br[i][k];
            }
            cout << endl;
    }

    int c_count = 1,l_count = 1,combination_num = 1;

    cout <<endl << "Generating C1 from data : " << endl;
    for(it = sort_value.begin();it != sort_value.end();it++)
         cout << it->first << " :  " << it->second << endl;

    cout <<endl << "Generating L1 from C1 : " << endl;
        for(it= sort_value.begin();it != sort_value.end();it++)
             {
                 if(it->second >= minimum_support)
                          cout << it->first << " :  " << it->second << endl;

             }

    int i = 0;
    for(set<int>::iterator it = cr.begin(); it != cr.end(); it++,i++)
          m_ar[i] = *it;

    bool bt = false;
    for(int i1 = 2 ; i1 <= transaction - 1; i1++){
           int p;
       if(bt){
        cout << "C" << i1-1 << " after scaning itemset : " << endl;
        for(map<string,int>::iterator ito = L_c.begin(); ito != L_c.end(); ito++){
            string ph = ito->first;
            for(int ip = 0; ip < ph.size(); ip++)
                 cout << ph[ip] <<" ";
           cout << " :  " << ito->second << endl;
        }
        cout <<endl << "Generating L" << i1 - 1 << " from C" << i1-1 << " : " << endl;
        for(map<string,int>::iterator ito = L_c.begin(); ito != L_c.end(); ito++){
            string ph = ito->first;
           if(ito->second >= minimum_support){
             for(int ip = 0; ip < ph.size(); ip++)
              cout << ph[ip] <<" ";

            cout << " :  " << ito->second << endl;
           }
        }
        cout << "Generating C" << i1 << " after prune :" << endl;
        L_c.clear();
       }else{
           cout << "Generating C" << i1 << " after prune :" << endl;
           bt = true;
       }
        for(int i = 0 ; i < transaction ; i++){

                p=0 ;
                memset(ar,0,sizeof(ar));
            for(int k = 0; k < maximum_purchase_item and br[i][k] != 0  ; k++){
                    ar[k] = br[i][k];
                    p++;
            }
            sort(ar,ar+p);
            int p1,check_v ;
                    p1 = 0;
                    result.clear();
                for(int l = 0; l < maximum_purchase_item and ar[l] != 0; l++){
                        p1++;
                        result.push_back(ar[l]);
                }
           int g = p1,g1 = 0;

                if(p1 >= i1){

                            for(int h = 0; h < transaction - i1; h++,c_count++){

                                if(h == 0)
                                    C_cal_And_L_cal(i1);
                                else
                                {
                                    result.erase(result.begin()+0);
                                    C_cal_And_L_cal(i1);
                                }
                            }

                        }
                    }
                }

    return 0;
}
