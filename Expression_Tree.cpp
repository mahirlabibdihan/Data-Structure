// C++ implementation of the approach
#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <cmath>
using namespace std;

namespace Math {

    pair<double, double> fraction(double s)
    {
        double numerator = s , denominator = 1;

        int i, j;
        while (numerator - int(numerator) > .0000001)
        {
            numerator *= 10;
            denominator *= 10;
        }

        double temp = numerator;
        for (i = 2; i <= numerator ; i++)
        {
            if (fmod(numerator , i) == 0 && fmod(denominator , i) == 0)
            {
                numerator /= i;
                denominator /= i ;
            }
        }
        return {numerator, denominator};
    }

    double recursivePower(double x, int n)
    {
        if (n == 0) return 1;
        return x * recursivePower(x, n - 1);
    }

    double root(double n, double x)
    {
        double l = 0, r = n, m = 0;
        if (n <= 1) r = 1;
        while (r - l > .000000000001)
        {
            double temp = (l + r) / 2;
            if (m == temp)
            {
                break;
            }
            m = temp;
            (recursivePower(m, x) > n) ? r = m : l = m;
        }
        return m;
    }

    double power(double n, double pow)
    {
        pair<double, double> num(fraction(pow));
        n = recursivePower(n, num.first);
        if (num.second == 1) return n;
        else return root(n, num.second);
    }
}

using namespace Math;
// Tree Structure
class Node
{
public:
    string data;
    Node *left, *right;
    Node(string str = nullptr) {
        data = str;
        left = right = nullptr;
    }

    void operate(stack<Node*> &stN, stack<string> &stC)
    {
        Node *t, *t1, *t2;
        // Get and remove the top element
        // from the character stack
        t = new Node(stC.top());
        stC.pop();

        // Get and remove the top element
        // from the Node stack
        t1 = stN.top();
        stN.pop();

        // Get and remove the currently top
        // element from the Node stack
        t2 = stN.top();
        stN.pop();

        // Update the tree
        t->left = t2;
        t->right = t1;

        // Push the Node to the Node stack
        stN.push(t);
    }

    // Function to build Expression Tree
    void build(string s)
    {
        // stack to hold nodes
        stack<Node*> stN;

        // stack to hold chars
        stack<string> stC;

        // Prioritising the operators
        map<char, int> operators;
        operators['+'] = operators['-'] = 1;
        operators['/'] = operators['*'] = operators['%'] = 2;
        operators['^'] = 3;
        operators[')'] = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if(s[i]==' ') continue;

            // Push '(' in char stack
            else if (s[i] == '(') {
                stC.push(string(1, s[i]));
            }

            // Push the numbers in Node stack
            else if (isdigit(s[i]) || s[i] == '.')
            {
                string num;
                while (i < s.length() && (isdigit(s[i]) || s[i] == '.')) {
                    num += s[i];
                    i++;
                }

                stN.push(new Node(num));
                i--;
            }

            // Evaluate whole expression from '(' to ')'
            else if (s[i] == ')') {
                while (!stC.empty() && stC.top() != "(")
                {
                    operate(stN, stC);
                }
                if (!stC.empty()) stC.pop();
            }

            // Push operators in char stack
            else if (operators.find(s[i])!=operators.end())
            {
                // If an operator with lower or
                // same associativity appears
                while ( !stC.empty() && stC.top() != "(" && operators[stC.top()[0]] >= operators[s[i]] )
                {
                    if (s[i] == '^') {
                        if (operators[stC.top()[0]] >  operators[s[i]]) {   // Associativity: Right to Left
                            operate(stN, stC);
                        }
                    }
                    else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                        if (operators[stC.top()[0]] >= operators[s[i]]) {   // Associativity: Left to Right
                            operate(stN, stC);
                        }
                    }
                }

                // Push s[i] to char stack
                stC.push(string(1, s[i]));
            }
        }

        // Least Precedence operations are left
        while (!stC.empty())
        {
            operate(stN, stC);
        }
        this->data = stN.top()->data;
        this->left = stN.top()->left;
        this->right = stN.top()->right;
    }
};

// Function to print the post order
// traversal of the tree
void postorder(Node* root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void preorder(Node* root)
{
    if (root)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

double evaluate(Node* root) {
    double x, y, z;
    try {
        return stod(root->data);
    }
    catch (exception &e) {
        x = evaluate(root->left);
        y = evaluate(root->right);
        if (root->data == "+") {
            z = x + y;
        }
        else if (root->data == "-") {
            z = x - y;
        }
        else if (root->data == "*") {
            z = x * y;
        }
        else if (root->data == "/") {
            z = x / y;
        }
        else if (root->data == "%") {
            z = fmod(x,y);
        }
        else if (root->data == "^") {
            z = power(x, y);
        }
        return z;
    } return stod(root->data);
}

int main()
{
    cout<<"Equation: ";
    string s;
    cin >> s;
    Node* root = new Node(s);
    root-> build(s);

    cout << "Result: "<<evaluate(root) << endl;
    return 0;
}
