#include<iostream>
#include<vector>
using namespace std;

class ProgramFrame {
protected:
    virtual void startMessage(ostream& );
    virtual void Input(istream&) = 0;
    virtual bool Check() = 0;
    virtual void errorMessage(ostream& );
    virtual void Output(ostream&) = 0;
    virtual void Process() = 0;
    virtual bool askContinue(istream&, ostream&);
public:
    void run(istream&, ostream&);
};
//#endif

void ProgramFrame::startMessage(ostream& os) {
    os << "Welcome, entering data : ";
}
void ProgramFrame::errorMessage(ostream& os) {
    os << "Input data error!" << endl;
}
bool ProgramFrame::askContinue(istream& is, ostream& os) {
    os << "\nPress y to continue, others to stop : ";
    char ch;  is >> ch;
    return (ch == 'Y' || ch == 'y');
}
void ProgramFrame::run(istream& is, ostream& os) {
    bool b=true;
    do {
        startMessage(os);
        Input(is);
        if (!Check()) {
            errorMessage(os);
            continue;
        }
        Process();
        Output(os);
        b = askContinue(is, os);
    } while (b);
}

class ArrayAlgorithm {
public:
    virtual void Process(vector<float>& a) = 0;
};

class AlgorithmTest : public ProgramFrame {
    ArrayAlgorithm* mAlg;
    vector<float> Data;
public:
    AlgorithmTest(ArrayAlgorithm* pAlg) { mAlg = pAlg; }
    void Input(istream& is) { 
        float tmp;
        int n;
        is >> n;
        for (int i = 0; i < n; i++) 
        {
            is >> tmp;
            Data.push_back(tmp);
        }
    }
    bool Check() { return Data.size() > 0; }
    void Output(ostream& os) {
        os << "\nResult after sorting : ";
        for (int i = 0; i < Data.size(); i++)
        {
            os << Data[i] << "  ";
        }
    }
    void startMessage(ostream& os) {
        os << "Enter n, then a[i]: ";
    }
    void Process() {
        if (mAlg != NULL) mAlg->Process(Data);
    }
};
class SelectionS : public ArrayAlgorithm {
public:
    void Process(vector<float>& a) { 
        float i, j, min_idx;
        float n = a.size();

        for (i = 0; i < n - 1; i++)
        {
            
            min_idx = i;
            for (j = i + 1; j < n; j++)
                if (a[j] < a[min_idx])
                    min_idx = j;

           
            swap(a[min_idx], a[i]);
        }
    }
};


int main()
{
    AlgorithmTest sortTest(new SelectionS());
    sortTest.run(cin, cout);

	return 0;
}