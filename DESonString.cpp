#include <iostream>
#include <bitset>
#include <string>

using namespace std;


int value_search_16(const string& fourBits){
    if (fourBits == "0000") return 0;
    else if (fourBits == "0001") return 1;
    else if (fourBits == "0010") return 2;
    else if (fourBits == "0011") return 3;
    else if (fourBits == "0100") return 4;
    else if (fourBits == "0101") return 5;
    else if (fourBits == "0110") return 6;
    else if (fourBits == "0111") return 7;
    else if (fourBits == "1000") return 8;
    else if (fourBits == "1001") return 9;
    else if (fourBits == "1010") return 10;
    else if (fourBits == "1011") return 11;
    else if (fourBits == "1100") return 12;
    else if (fourBits == "1101") return 13;
    else if (fourBits == "1110") return 14;
    else if (fourBits == "1111") return 15;
    return 16;
}


string value_search_int_string(int number){
    if (number == 0) return "0000";
    else if (number == 1) return "0001";
    else if (number == 2) return "0010";
    else if (number == 3) return "0011";
    else if (number == 4) return "0100";
    else if (number == 5) return "0101";
    else if (number == 6) return "0110";
    else if (number == 7) return "0111";
    else if (number == 8) return "1000";
    else if (number == 9) return "1001";
    else if (number == 10) return "1010";
    else if (number == 11) return "1011";
    else if (number == 12) return "1100";
    else if (number == 13) return "1101";
    else if (number == 14) return "1110";
    else if (number == 15) return "1111";
    return std::string();
}

int value_search_4(const string& twoBits){
    if (twoBits == "00") return 0;
    if (twoBits == "01") return 1;
    if (twoBits == "10") return 2;
    if (twoBits == "11") return 3;
    return 5;
}


string array_of_keys[16];
int IP[] = {58, 50, 42, 34, 26, 18, 10, 2,
            60, 52, 44, 36, 28, 20, 12, 4,
            62, 54, 46, 38, 30, 22, 14, 6,
            64, 56, 48, 40, 32, 24, 16, 8,
            57, 49, 41, 33, 25, 17,  9, 1,
            59, 51, 43, 35, 27, 19, 11, 3,
            61, 53, 45, 37, 29, 21, 13, 5,
            63, 55, 47, 39, 31, 23, 15, 7};

//Final Permutation
int FP[] = {40, 8, 48, 16, 56, 24, 64, 32,
            39, 7, 47, 15, 55, 23, 63, 31,
            38, 6, 46, 14, 54, 22, 62, 30,
            37, 5, 45, 13, 53, 21, 61, 29,
            36, 4, 44, 12, 52, 20, 60, 28,
            35, 3, 43, 11, 51, 19, 59, 27,
            34, 2, 42, 10, 50, 18, 58, 26,
            33, 1, 41,  9, 49, 17, 57, 25};


//Permuted choice PC-1
int PC_1[] = {57, 49, 41, 33, 25, 17,  9,
              1, 58, 50, 42, 34, 26, 18,
              10,  2, 59, 51, 43, 35, 27,
              19, 11,  3, 60, 52, 44, 36,
              63, 55, 47, 39, 31, 23, 15,
              7, 62, 54, 46, 38, 30, 22,
              14,  6, 61, 53, 45, 37, 29,
              21, 13,  5, 28, 20, 12,  4};

//Permuted choice PC-2
int PC_2[] = {14, 17, 11, 24,  1,  5,
              3, 28, 15,  6, 21, 10,
              23, 19, 12,  4, 26,  8,
              16,  7, 27, 20, 13,  2,
              41, 52, 31, 37, 47, 55,
              30, 40, 51, 45, 33, 48,
              44, 49, 39, 56, 34, 53,
              46, 42, 50, 36, 29, 32};

//Bits rotation
int shiftBits[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

//Expansion function
int E[] = {32,  1,  2,  3,  4,  5,
           4,  5,  6,  7,  8,  9,
           8,  9, 10, 11, 12, 13,
           12, 13, 14, 15, 16, 17,
           16, 17, 18, 19, 20, 21,
           20, 21, 22, 23, 24, 25,
           24, 25, 26, 27, 28, 29,
           28, 29, 30, 31, 32,  1};

//S-boxes
int S_BOX[8][4][16] = {
        {
                {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
                {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
                {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
                {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
        },
        {
                {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
                {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
                {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
                {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
        },
        {
                {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
                {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
                {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
                {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
        },
        {
                {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
                {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
                {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
                {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
        },
        {
                {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
                {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
                {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
                {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
        },
        {
                {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
                {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
                {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
                {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
        },
        {
                {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
                {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
                {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
                {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
        },
        {
                {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
                {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
                {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
                {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
        }
};

//Permutation
int P[] = {16,  7, 20, 21, 29, 12, 28, 17,
           1, 15, 23, 26,  5, 18, 31, 10,
           2,  8, 24, 14, 32, 27,  3,  9,
           19, 13, 30,  6, 22, 11,  4, 25
};

string TextToBinaryString(string words) {
    string binaryString = "";
    for (char& _char : words) {
        binaryString +=bitset<8>(_char).to_string();
    }
    return binaryString;
}




string IP_function(string text){
    string postIP;
    for (int i = 0; i < 64; ++i) {
        postIP += text[IP[i]-1];
    }
    return postIP;
}



void keyTransformation(string const& original_key) {
    string left;
    string right;

    string key_postShift;
    string subkey;
    string key56bit;

    for (int i = 0; i < 64; ++i) {
        if (i < 56)key56bit += original_key[PC_1[i] - 1];
        else break;
    }
    for (int k = 0; k < 28; ++k) { //rodzielenie na prawa i lewa część
        left += key56bit[k];
        right += key56bit[k + 28];
    }
    for (int j = 0; j < 16; ++j) { // tworzenie 16 podkluczy

        for (int i = 0; i < shiftBits[j]; ++i) { //ilość bitów które trzeba przerzucić na koniec

            for (int k = 0; k < 27; ++k) { // pierwszy element na koniec
                swap(left[k], left[k + 1]);
            }
            for (int k = 0; k < 27; ++k) { // pierwszy element na koniec
                swap(right[k], right[k + 1]);
            }

        }
        key_postShift = "";
        key_postShift += left;
        key_postShift += right;

        //cout << key_postShift << endl;
        subkey = "";
        for (int m = 0; m < 48; ++m) {
            subkey += key_postShift[PC_2[m] - 1];
        }
        array_of_keys[j] = subkey;

    }
    //for (int n = 0; n < 16; ++n) cout << array_of_keys[n] << endl;
}

string xor_function(string plain_text, int num_of_subkey){
    string tmp = array_of_keys[num_of_subkey];
    string xor_output;
    for (int i = 0; i < 48; ++i) {
        if (plain_text[i] == '0' and tmp[i] == '0') xor_output += "0";
        else if (plain_text[i] == '0' and tmp[i] == '1') xor_output += "1";
        else if (plain_text[i] == '1' and tmp[i] == '0') xor_output += "1";
        else if (plain_text[i] == '1' and tmp[i] == '1') xor_output += "0";
    }
    return xor_output;
}

string xor_function_str(string left, string right){
    string xor_output;
    for (int i = 0; i < 32; ++i) {
        if (left[i] == '0' and right[i] == '0') xor_output += "0";
        else if (left[i] == '0' and right[i] == '1') xor_output += "1";
        else if (left[i] == '1' and right[i] == '0') xor_output += "1";
        else if (left[i] == '1' and right[i] == '1') xor_output += "0";
    }
    return xor_output;
}




string encryption (string postIP){

    string left, right, cos, postPermutationRight, postXOR, sixBits, fourBits, twoBits, postSBOX,new_left, new_right;
    string output;
    for (int i = 0; i < 32; ++i) {
        left += postIP[i];
        right += postIP[i+32];
    }

    for (int i = 0; i < 16; ++i) {
        postPermutationRight = "";
        for (int p = 0; p < 48; ++p) {
            postPermutationRight +=right[E[p] - 1];
        }
        postXOR = xor_function(postPermutationRight, i);
        postSBOX = "";
        for (int j = 0; j < 48; j+=6) { //operacje po permutacji z 32 na 48
            sixBits = "";
            fourBits = "";
            twoBits = "";
            for (int k = j; k < j+6; ++k) {
                sixBits += postXOR[k];
            }
            for (int k = 1; k < 5; ++k) {
                fourBits += sixBits[k];
            }
            twoBits += sixBits[0];
            twoBits += sixBits[5];
            int two = value_search_4(twoBits), four =value_search_16(fourBits);
            postSBOX += value_search_int_string(S_BOX[j/6][two][four]);
        }
        //cout << postSBOX << endl;
        new_left += right;
        right ="";
        for (int j = 0; j < 32; ++j) {
            right += postSBOX[P[j] - 1];
        }
        new_right += xor_function_str(left,right);
        right ="";
        left ="";
        right +=new_right;
        left += new_left;
        new_right = "";
        new_left = "";
        //cout << left << endl << right << endl;
    }

    cos += right;
    cos += left;
    for (int i = 0; i < 64; ++i) {
        output += cos[FP[i] - 1];
    }

    return output;
}


int main() {
    string enc;
    string text = "IEOFIT#1"; //8 znaków
    string key = "IEOFIT#1"; //8 znakow
    //cout << TextToBinaryString(key) << endl;
    string postIP = IP_function(TextToBinaryString(text));
    //cout << postIP << endl;
    keyTransformation(TextToBinaryString(key));
    //for (int i = 0; i < 16; ++i) cout << array_of_keys[i] << endl;
    //cout << array_of_keys[0] << endl << endl;
    string postXOR = xor_function(postIP,0);
    //cout << postXOR;
    enc=encryption(postIP);
    cout << enc;
    return 0;
}