#include<iostream>
using namespace std;
class LongInt {
private:
    struct digit {
        int d_val;
        digit *more, *less;
    };
    struct Ibase {
        digit *most, *least;
    };
    Ibase _base;
    void zeroStrip( );
public:
    LongInt();
    friend void printLongInt( LongInt );
    friend LongInt inputLongInt( );
    friend LongInt addLongInt( LongInt, LongInt );
};
void LongInt::zeroStrip( ){
    LongInt::digit * dptr = _base.most;
    LongInt::digit * extra = 0;
    while( ( !dptr->d_val ) && dptr->less ) {
        extra = dptr;
        _base.most = dptr->less;
        dptr = dptr->less;
        dptr->more = 0;
        delete extra;
    }
}

LongInt::LongInt(){
    _base.most = _base.least = new digit;
    _base.most->d_val = 0;
    _base.most->more = _base.most->less = 0;
};
void printLongInt( LongInt LIval ){
    LongInt::digit * dptr = LIval._base.most;
    while ( dptr ) {
        cout <<  dptr->d_val;
        dptr = dptr->less;
    } }


LongInt inputLongInt( ){
    LongInt returnValue;
    int inValue;
    LongInt::digit * dptr = 0;
    LongInt::digit * inputList = 0;
    inputList = returnValue._base.least;
    inValue = cin.get();
    while ( '0' <= inValue && inValue <= '9' ){
        dptr = new LongInt::digit;
        dptr->d_val = inValue - '0';
        dptr->less = 0;
        dptr->more = inputList;
        returnValue._base.least = dptr;
        inputList->less = dptr;
        inputList = dptr;
        inValue = cin.get();
    }
    returnValue.zeroStrip( );
    return returnValue;
}

LongInt addLongInt(LongInt s1, LongInt s2) {
    LongInt result;
    LongInt::digit* dptr1 = s1._base.least;
    LongInt::digit* dptr2 = s2._base.least;
    LongInt::digit* resultptr = nullptr;
    int carry = 0;
    int sum = 0;

    while (dptr1 != nullptr || dptr2 != nullptr || carry != 0) {
        sum = carry;

        // Add digits from s1 if available
        if (dptr1 != nullptr) {
            sum += dptr1->d_val;
            dptr1 = dptr1->more;
        }

        // Add digits from s2 if available
        if (dptr2 != nullptr) {
            sum += dptr2->d_val;
            dptr2 = dptr2->more;
        }

        carry = sum / 10; // Compute carry
        sum = sum % 10;   // Get the single digit

        // Create a new digit for the result
        LongInt::digit* newDigit = new LongInt::digit;
        newDigit->d_val = sum;
        newDigit->more = nullptr; // Initially, this is the last digit

        // Insert the new digit at the beginning of the result list
        if (result._base.most == nullptr) {
            result._base.most = newDigit;
            result._base.least = newDigit;
        } else {
            newDigit->less = result._base.most;
            result._base.most->more = newDigit;
            result._base.most = newDigit;
        }
    }

    result.zeroStrip();
    return result;
}




int main(){
    LongInt summand1, summand2, sum;
    cout << "-> " << flush;
    summand1 = inputLongInt();
    cout << "-> " << flush;
    summand2 = inputLongInt();
    cout << "\n-----\n";
    sum = addLongInt( summand1, summand2 );
    printLongInt( sum );
    cout << endl;
}
// works great