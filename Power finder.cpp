#include <iostream>
#include <string>
namespace std {
    std::string to_string(int number) {
        std::string result;
        bool isNegative = false;

        if (number < 0) {
            isNegative = true;
            number = -number;
        }

        do {
            result.insert(result.begin(), '0' + (number % 10));
            number /= 10;
        } while (number);

        if (isNegative) {
            result.insert(result.begin(), '-');
        }

        return result;
    }
}
std::string Double(const std::string& numberString) {
    std::string doubledString;
    int carry = 0;

    for (int i = numberString.size() - 1; i >= 0; i--) {
        if (isdigit(numberString[i])) {
            int digit = numberString[i] - '0';
            int doubledDigit = (digit * 2) + carry;

            if (doubledDigit > 9) {
                carry = doubledDigit / 10;
                doubledDigit %= 10;
            } else {
                carry = 0;
            }

            doubledString = std::to_string(doubledDigit) + doubledString;
        }
    }
    if (carry > 0) {
        doubledString = std::to_string(carry) + doubledString;
    }

    return doubledString;
}
int main(){
	std::cout<<"<---Find the any power of n--->\n";
	std::string s = "";
	std::cout<<"Enter n = ";
	std::cin>>s;
	try{
	bool perm;
	int p;
	std::cout<<"Enter p(power) = ";
	int n;
	std::cin>>n;
	std::cout<<"choose 1 to see every power of 2 from 1 to "<<n<<" \nchoose 2 to see only the answer of 2 to the power of "<<n<<"\n";
	std::cin>>p;
	if(p==1){
		perm = true;
	}else{
		perm = false;
	}
	for(int i=0;i<n;i++){
		s=Double(s);
		if(perm)std::cout<<"2^"<<i<<": "<<s<<std::endl;
	}
	if(!perm)std::cout<<"2^"<<n<<" = "<<s;
	} catch(std::string s){
	std::cout<<"ERROR!!!";
}
}
