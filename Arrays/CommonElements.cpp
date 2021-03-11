/*
Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure?

Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.


Input:
n1 = 3; A = {3, 3, 3}
n2 = 3; B = {3, 3, 3}
n3 = 3; C = {3, 3, 3}
Output: 3
Explanation: 3 is  the onlycommon elements in A, B and C.
*/

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i=0,j=0,k=0; //pointers for three arrays
            vector<int> common;
            
            int prev1,prev2,prev3;
            prev1=prev2=prev3=INT_MIN; // prev variables will be used to keep a track of all previously encountered elemets
            
            // if any of the arrays is exhausted we break the array
            while(i<n1 && j<n2 && k<n3)
            {
                while(A[i]==prev1 && i<n1) i++;
                
                while(B[j]==prev2 && j<n2) j++;
                
                while(C[k]==prev3 && k<n3) k++;
                

                if(A[i]==B[j] && B[j]==C[k])
                {
                    common.push_back(A[i]);
                    prev1 = A[i];
                    prev2 = B[j];
                    prev3 = C[k];
                    i++;
                    j++;
                    k++;
                }
                
                else if(A[i]<B[j])
                {
                    prev1 = A[i];
                    i++;
                }
                
                else if(B[j]<C[k])
                {
                    prev2 = B[j];
                    j++;
                }
                
                else
                {
                    prev3 = C[k];
                    k++;
                }
            }
            
   
            return common;
        }

};
