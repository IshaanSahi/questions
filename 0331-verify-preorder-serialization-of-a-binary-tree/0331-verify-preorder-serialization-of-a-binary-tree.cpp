class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slot=1;
        stringstream s(preorder);
        string str="";
        while(getline(s,str,',')){
            slot--;
            if(slot<0)
                return false;
            if(str!="#")
                slot+=2;
        }
        return slot==0;
    }
};