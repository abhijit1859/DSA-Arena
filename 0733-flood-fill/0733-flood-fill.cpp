class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int original=image[sr][sc];
        if(original==color) return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};

        image[sr][sc]=color;

        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+delr[i];
                int nc=c+delc[i];
                if(nr>=0&&nc>=0&&nr<n&&nc<m&&image[nr][nc]==original){
                    image[nr][nc]=color;
                    q.push({nr,nc});
                }
                
            }
        }

        return image;
        
    }
};