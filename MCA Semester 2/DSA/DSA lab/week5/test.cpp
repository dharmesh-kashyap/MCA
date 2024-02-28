#include <iostream>
#include <string>
using namespace std;
class stack
{
    int capacity;
    int *arr;
    int top;
public:
    stack(int size)
    {
        capacity = size;
        top = -1;
        arr = new int[capacity];
    }
    ~stack()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "\nStack is Full";
            return;
        }
        arr[++top] = x;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "\nThe stack is empty";
            return top = -1;
        }
        return arr[top--];
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "\nThe stack is empty";
            return -1;
        }
        return arr[top];
    }
};

int PostfixEvaluation(const string& postFixExpression){
    stack S(postFixExpression.length());
    for(int i = 0; i < postFixExpression.length(); i++){
        char index = postFixExpression[i];
        if( index >= '0' && index <= '9'){
            S.push(index - 48);
        }
        else if(index == '+' || index == '-' ||index == '*' ||index == '/'){
            
            int operand2 = S.pop();
            int operand1 = S.pop();
            int result = 0;
            switch(index) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            S.push(result);
        }
    }
    return S.peek();
}
int main(){
    cout<<"Enter the postfix Expression: ";
    string postFixExpression;
    getline(cin,postFixExpression);
    int result = PostfixEvaluation(postFixExpression);
    cout<<"\nThe evaluated postfix operation is: "<<result<<endl;
    return 0;
}