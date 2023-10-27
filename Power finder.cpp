#include <iostream>
#include <string>

namespace std {
    int to_number(std::string s){
    	int total =0;
    	for(int i=0;i<s.length();i++){
    		total*=10;
    		total+= s.at(i)-48;
		}
		return total;
	}
}

bool isAllDigits(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}


std::string PowerUp(std::string& numberStr, int multiplier) {
    if (numberStr.empty() || multiplier == 0) {
        return "0";
    }

    std::string result = "";
    int carry = 0;

    for (int i = numberStr.size() - 1; i >= 0; i--) {
        int digit = numberStr[i] - '0';
        int product = digit * multiplier + carry;
        carry = product / 10;
        product %= 10;

        result = char('0' + product) + result;
    }

    while (carry > 0) {
        result = char('0' + carry % 10) + result;
        carry /= 10;
    }

    return result;
}

int main() {
    std::cout << "<---Find the any power of n--->\n";
    std::string s = "";

    while (true) {
    std::cout << "Enter n = ";
    std::cin >> s;
    if(s.empty() || !isAllDigits(s))
    std::cout << "Invalid input for 'n'. Please enter a valid number.\n";
    else break;
    }

    std::string q = s;

    bool perm;
    int p;

    int n;
    std::string t;
    while (true) {
    std::cout << "Enter p(power) = ";
    std::cin >> t;
    	if (!isAllDigits(t))
        std::cout << "Invalid input for 'p'. Please enter a valid number.\n";
        else break;
    }
    n = std::to_number(t);
    while(true){
    std::cout << "Choose 1 to see every power of " << s << " from 1 to " << n << "\nChoose 2 to see only the answer of " << s << " to the power of " << n << "\n";
    std::cin >> p;
    if(p == 1 || p == 2){
    	break;
	}else{
		std::cout<<"Invalid input. Please enter 1 or 2.\n";
	}
	}
    if (p == 1) {
        perm = true;
    } else {
        perm = false;
    }

    int k = s[0] - '0';
    s = "1";

    for (int i = 1; i <= n; i++) {
        s = PowerUp(s, k);
        if (perm)
            std::cout << q << "^" << i << ": " << s << std::endl;
    }

    if (!perm)
        std::cout << q << "^" << n << " = " << s;

    return 0;
}

