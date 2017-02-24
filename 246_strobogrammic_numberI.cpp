class Solution {
public:
    bool isStrobogrammatic(string num) {
        make_lut();
        int n = num.length();
        for (int l = 0, r = n - 1; l <= r; l++, r--)
            if (lut.find(num[l]) == lut.end() ||
                lut.find(num[r]) == lut.end() ||
                lut[num[l]] != num[r])
                return false;
        return true;
    }
private:
    unordered_map<char, char> lut;
    void make_lut(void) {
        lut['0'] = '0';
        lut['1'] = '1';
        lut['6'] = '9';
        lut['8'] = '8';
        lut['9'] = '6';
    }
};