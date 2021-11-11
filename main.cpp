#include <iostream>
#include <algorithm>
using namespace std;

class Rational{
public:
    Rational() {
        numer=0;
        denom=1;
    }
    Rational(int numerator, int denominator) {
        if (denominator<0){
            throw invalid_argument("Invalid argument");
        }
        int gcd;
        int num_tmp = abs(numerator);
        int den_tmp = abs(denominator);
        while (num_tmp > 0 && den_tmp > 0) {

            if (num_tmp > den_tmp) {
                num_tmp %= den_tmp;
            }
            else {
                den_tmp %= num_tmp;
            }

        }

        gcd = num_tmp + den_tmp;
        if (gcd != 0) {
            numerator = numerator / gcd;
            denominator = denominator / gcd;
        }

        double res = 0;
        if (denominator != 0) {
            res = (double)numerator / (double)denominator;
        } else {
            throw invalid_argument("Invalid argument");
        }
        if (res < 0) {
            numerator = 0 - abs(numerator);
            denominator = abs(denominator);
        }
        else if (res > 0) {
            numerator = abs(numerator);
            denominator = abs(denominator);
        }
        if (numerator == 0) {
            denominator = 1;
        }
        numer = numerator;
        denom = denominator;
    }

    int Numerator() const {
        return numer;
    };
    int Denominator() const {
        return denom;
    };

    Rational addition(const Rational& r2) const{
        if (this -> Denominator()==r2.Denominator()) {
            return {this->Numerator() + r2.Numerator(), this->Denominator() };
        } else {
            return {this->Numerator()*r2.Denominator()+r2.Numerator()* this->Denominator(),this->Denominator()*r2.Denominator()};
        }
    }

    Rational subtraction(const Rational& r2) const{
        if (this->Denominator()==r2.Denominator()) {
            return {this->Numerator() - r2.Numerator(), this->Denominator() };
        } else {
            return {this->Numerator()*r2.Denominator()-r2.Numerator()*this->Denominator(),this->Denominator()*r2.Denominator()};
        }
    }

    Rational multiplication(const Rational& r2) const{
        return {this->Numerator()*r2.Numerator(),this->Denominator()*r2.Denominator()};
    }

    Rational division(const Rational& r2) const {
        return {this->Numerator() * r2.Denominator(), this->Denominator() * r2.Numerator()};
    }

    Rational negative() const{
        return { -(this->Numerator()), this->Denominator()};
    }
    int composition() const{
        return int((this->Numerator() + this->Denominator()));
    }

    bool more(Rational r2) const{
        if ((this->Numerator()/(double)this->Denominator())>(double(r2.Numerator())/(double)r2.Denominator())){
            cout << "TRUE\t";
            return true;
        }else {
            cout<< "False\t";
            return false;
        }
    }

    bool equals(const Rational& r2) const{
        if ((this->Denominator()==r2.Denominator())&&(this->Numerator()==r2.Numerator())){
            cout << "TRUE\t";
            return true;
        } else {
            cout<< "False\t";
            return false;
        }
    }

    static istream& input(istream& stream,Rational& r) {
        int n = 0, m = 1;
        char c;
        stream >> n;
        stream>>c;
        if (c!='/'){
            return stream;
        }
        stream >> m;
        if (stream) {
            r = Rational(n, m);
            return stream;
        } else {
            return stream;
        }
    }

    static ostream& output(ostream& stream,const Rational& r){
        stream<<r.Numerator()<<"/"<<r.Denominator();
        return stream;
    }
private:
    int numer, denom;

};

int main() {
    Rational a,b;
    cout<<"Enter the first Rational number(Fraction):"<<endl;
    Rational::input(std::cin,a);
    cout<<"Enter the second Rational number(Fraction):"<<endl;
    Rational::input(std::cin,b);

    cout<<"\nEnter the number of operation you want to perform:"<<endl;
    cout<<"1: a/b + c/d"<<endl;
    cout<<"2: (a*d + b*c) / b*d"<<endl;
    cout<<"3: a/b - c/d"<<endl;
    cout<<"4: (a*d - b*c)/b*d"<<endl;
    cout<<"5: (a/b) / (c/d)"<<endl;
    cout<<"6: (a*d) / (c*b)"<<endl;
    cout<<"7: - (a/b)"<<endl;
    cout<<"8: (a/b) > (c/d)"<<endl;
    cout<<"9: (a/b) == (c/d)"<<endl;

    int c;
    cin>>c;
    if(c==1 || c==2) {
        Rational::output(std::cout, (a.addition(b)));
    } else if(c==3 || c==4) {
        Rational::output(std::cout << "\n", (a.subtraction(b)));
    } else if(c==5 || c==6) {
        Rational::output(std::cout << "\n", (a.division(b)));
    } else if (c==7) {
        Rational::output(std::cout, (a.negative()));
    } else if (c==8) {
        cout<<a.more(b);
    } else if (c==9) {
        cout<<a.equals(b);
    } else {
        cout << "\nWrong choice please choose a number from 1 -> 7";
    }
    return 0;
}