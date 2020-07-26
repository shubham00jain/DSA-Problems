/
   print a Matrix with Y at (i,i) always and at (i,j) if it satisfies a condition else print N.
   conditions: outgoing at i must be Y and incoming at j must be Y and mod(i-j) must be 1.
       
   Sample Input:                         
    5
    2
    YY
    YY
    2
    NY
    YY
    2
    NN
    YY
    5
    YNNYY
    YYYNY
    10
    NYYYNNYYYY
    YYNYYNYYNY
    
    
    Sample Output:
    Case #1: 
    YY
    YY
    Case #2: 
    YY
    NY
    Case #3: 
    YN
    NY
    Case #4: 
    YNNNN
    YYNNN
    NNYYN
    NNNYN
    NNNYY
    Case #5: 
    YYYNNNNNNN
    NYYNNNNNNN
    NNYNNNNNNN
    NNYYNNNNNN
    NNYYYNNNNN
    NNNNNYNNNN
    NNNNNNYYYN
    NNNNNNYYYN
    NNNNNNNNYN
    NNNNNNNNYY    
*/

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





