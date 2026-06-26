class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n,0);
        for(int i=0;i<leftChild.size();i++){
            if(leftChild[i]!=-1){
                indegree[leftChild[i]]++;
                if(indegree[leftChild[i]]>1) return false;
            }
        }
        for(int i=0;i<rightChild.size();i++){
            if(rightChild[i]!=-1){
                indegree[rightChild[i]]++;
                if(indegree[rightChild[i]]>1) return false;
            }
        }
        int root=-1;
        int rootCount=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                root=i;
                rootCount++;
            }
        }

        if(rootCount!=1) return false;

        vector<bool> visited(n,false);
        stack<int> st;
        st.push(root);
        int count=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(visited[node]) return true;
            visited[node]=true;
            count++;
            if(leftChild[node]!=-1){
                st.push(leftChild[node]);
            }
            if(rightChild[node]!=-1){
                st.push(rightChild[node]);
            }

        }

        return count==n;
    }
};