// RPN calculator

#include <iostream> 
#include <string>
#include <stack> 

using namespace std;
bool is_str_digit(string);  // returns true if input parameter string is and integer (e.g., "127343")
bool is_str_operator(string); // returns true if the input parameter is an operator character (e.g., "+", "*")


int main() 
{
    string in;
    stack<string> st;   // stack definition

    cin >> in;
    
    int value1;
    int value2;
    int value3;    
    int stackSize;
    
    while(in != "q")
    {
        try{
            if(is_str_digit(in)){
                st.push(in);
            }
            else if(is_str_operator(in))
            {
                stackSize = st.size();
                try{
                    if(stackSize < 2){//Stack already has 1 element by default which is the operator somehow
                        //throw st.size();
                        throw stackSize;
                    }
                }
                catch(int e){
                    cout << "ERROR: Stack does not have at least 2 operands but has " << e << " element(s) in the stack when operator is given!" << endl;
                    exit(1);
                }
                
                value1 = stoi(st.top());
                st.pop();
                value2 = stoi(st.top()); 
                st.pop();
                
                switch(in[0])
                {
                    case '+':
                        value3 = value2 + value1;
                        break;

                    case '-':
                        value3 = value2 - value1;
                        break;

                    case '*':
                        value3 = value2 * value1;
                        break;

                    case '/':
                        value3 = value2 / value1;
                        break;

                }
                st.push(to_string(value3));

            }
            else{
                throw in;
            }
        }
        catch(string e){
            cout << "ERROR: " << '"' << e << '"' << " is not an integer nor an operator!" << endl;
            exit(1);
        }
        cout << "<" <<st.top() << ">" << endl; 
        cin >> in;
    }
    stackSize = st.size();
    try{
        if(stackSize > 1){
            throw stackSize;
        }
    }
    catch(int e){
        cout << "ERROR: " << "There is more than one item on the stack when we want to print the result!" << endl;
        exit(1);
    }
    cout << "The answer is : " << st.top() << endl;

    return 0; 
}

bool is_str_digit(string s)
{
    for (int i = 0; i < s.length(); ++i)
    {
            if(!isdigit(s[i]))
                return false;
    }
    return true;
}
bool is_str_operator(string s)
{
    return (s.length()==1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0]== '/'));
}
