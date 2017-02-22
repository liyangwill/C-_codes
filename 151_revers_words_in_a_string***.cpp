//reverse each word, and reverse the whole string
//two pointers "read" "write"
class Solution {
public:
    void reverseword(string &s, int i, int j){
        while(i<j){
            char t=s[i];
            s[i++]=s[j];
            s[j--]=t;
        }
    }
    
    void reverseWords(string &s) {
        
        int read=0, write=0;
        int head=0;
        int len=s.length();
        int wordcount=0;
        
        while(true){
            while(read<len && s[read] == ' ') read++;  // skip spaces in front of the word
            if(read==len) break;
            if(wordcount) s[write++]=' ';
            head=write;
            while(read<len && s[read] != ' '){s[write]=s[read]; write++; read++;}
            reverseword(s,head,j-1);                // reverse word in place
            wordcount++;
            
        }
        
        s.resize(write);                           // resize result string
        reverseword(s,0,write-1);                  // reverse whole string
    }
};