#include <iostream>
#include <string>
using namespace std;

int romToMod(string romanNum, int arraySize) {
    int modernNum = 0;
    int curNum = 0;
    int modArray[arraySize];
    
    for(int i = 0; i < arraySize; i++) {
        switch(romanNum[i]) {
            case 'I':
                modArray[i] = 1;
                break;
            case 'V':
                modArray[i] = 5;
                break;
            case 'X':
                modArray[i] = 10;
                break;
            case 'L':
                modArray[i] = 50;
                break;
            case 'C':
                modArray[i] = 100;
                break;
            case 'D':
                modArray[i] = 500;
                break;
            case 'M':
                modArray[i] = 1000;
                break;
        }
    }
    
    for(int i = 0; i < arraySize; i++) {
        if(modArray[i] >= modArray[i + 1]) {
            curNum = modArray[i];
            modernNum = modernNum + curNum;
        }
        else {
            modernNum = modernNum + modArray[i + 1] - modArray[i];
            i++;
        }
    }    return modernNum;
}

string buildRom(int modNum, string romanNum) {
    if(modNum == 0) {
        return romanNum;
    }
    else if(modNum >= 1000) {
        romanNum.append("M");
        modNum = modNum - 1000;
        return buildRom(modNum, romanNum);
    }
    else if((modNum >= 500) && (modNum < 1000)) {
        if(modNum >= 900) {
            modNum = modNum + 100;
            romanNum.append("C");
        }
        else {
            modNum = modNum - 500;
            romanNum.append("D");
        }
        return buildRom(modNum, romanNum);
    }
    else if((modNum >= 100) && (modNum < 500)) {
        if(modNum >= 400) {
            modNum = modNum + 100;
            romanNum.append("C");
        }
        else {
            modNum = modNum - 100;
            romanNum.append("C");
        }
        return buildRom(modNum, romanNum);
    }
    else if((modNum >= 50) && (modNum < 100)) {
        if(modNum >= 90) {
            modNum = modNum + 10;
            romanNum.append("X");
        }
        else {
            modNum = modNum - 50;
            romanNum.append("L");
        }
        return buildRom(modNum, romanNum);
    }
    else if((modNum >= 10) && (modNum < 50)) {
        if((modNum - (3 * 10)) >= 10) {
            modNum = modNum + 10;
            romanNum.append("X");
        }
        else {
            modNum = modNum - 10;
            romanNum.append("X");
        }
        return buildRom(modNum, romanNum);
    }
    else if((modNum >= 5) && (modNum < 10)) {
        if(modNum == 9) {
            modNum = modNum + 1;
            romanNum.append("I");
        }
        else {
            modNum = modNum - 5;
            romanNum.append("V");
        }
        return buildRom(modNum, romanNum);
    }
    else if((modNum >= 1) && (modNum < 5)) {
        if((modNum - (3 * 1)) >= 1) {
            modNum = modNum + 1;
            romanNum.append("I");
        }
        else {
            modNum = modNum - 1;
            romanNum.append("I");
        }
        return buildRom(modNum, romanNum);
    }
    else{
        return "Failed to convert modern number to roman numeral";
    }
}

string modToRom(string modernNum, int modCt) {
    string romanNum = "";
    int modNum = stoi(modernNum);
    
    if(modNum == 0) {
        return "Not defined";
    }
    
    romanNum = buildRom(modNum, romanNum);
    
    return romanNum;
}

int main(int argc, const char * argv[]) {
    string userInput;
    int modCt = 0;
    int romCt = 0;
    int invalCt = 0;
    
    cout << "Enter a modern number or a roman numeral:" << endl;
    getline(cin, userInput);
    
    for(int i = 0; i < userInput.size(); i++) {
        if(isdigit(userInput[i]) && (userInput[0] != 0)) {
            modCt++;
        }
        else if((userInput[i] == 'I' ) || (userInput[i] == 'V') || (userInput[i] == 'X') || (userInput[i] == 'L') || (userInput[i] == 'C') || (userInput[i] == 'D') || (userInput[i] == 'M')) {
            romCt++;
        }
        else {
            invalCt++;
        }
    }
    
    if((modCt != 0) && (romCt == 0) && (invalCt == 0)) {
        cout << "Modern Number: " << userInput << endl;
        string romNum = modToRom(userInput, modCt);
        cout << "Roman Numeral: " << romNum << endl;
    }
    else if((modCt == 0) && (romCt != 0) && (invalCt == 0)) {
        cout << "Roman Numeral: " << userInput << endl;
        int modNum = romToMod(userInput, romCt);
        cout << "Modern Number: " << modNum << endl;
    }
    else if(invalCt != 0) {
        cout << "Invalid input" << endl;
    }
    
    return 0;
}
