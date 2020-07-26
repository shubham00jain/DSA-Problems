#include<fstream>
#include<vector>
#include<string>
#include<cmath>
#include<math.h>

using namespace std;

int main(){
    int t;
    ifstream f("p1.txt");
    ofstream g("sol1.txt");
    f>>t;
    int k=t;
    while(t--){
        int n;
        f>>n;
        vector<string> str;

        for(int i=0;i<2;i++){
            string input;
            f>>input;
            str.push_back(input);
        }
        
        vector<string> res;

        for(int i=0;i<n;i++){
            string input;
            for(int j=0;j<n;j++){
                if(i == j)
                    input.push_back('Y');
                else
                {
                    input.push_back('N');
                }
            }
            res.push_back(input);
        }

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(str[1][j] == 'Y' && j+1<=n && str[0][j+1] == 'Y'&& res[i][j] == 'Y'){
                    res[i][j+1] = 'Y';
                }
            }
            for(int j = i;j>0;j--){
                if(str[1][j] == 'Y' && j-1>=0 && str[0][j-1] == 'Y' && res[i][j] =='Y'){
                    res[i][j-1] = 'Y';
                }
            }
        }
        g<<"Case #"<<k-t<<": ";

        for(int i=0;i<n;i++){
            g<<res[i]<<endl;
        }
    }

    return 0;
}
