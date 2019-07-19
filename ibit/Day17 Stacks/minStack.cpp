stack<int> mainStack;
stack<int> minStack;

MinStack::MinStack() {
    mainStack = stack<int> ();
    minStack = stack<int> ();
}

void MinStack::push(int x) {
    mainStack.push(x);
    stack<int> aux;
    while(!minStack.empty())
    {
        if(x<minStack.top())
        {
            minStack.push(x);
            break;
        }
        
        else
        {
            aux.push(minStack.top());
            minStack.pop();
        }
    }
    
    while(!aux.empty())
    {
        minStack.push(aux.top());
        aux.pop();
    }
}

void MinStack::pop() {
    int top = mainStack.top();
    stack<int> aux;
    while(minStack.top()!=top)
    {
        aux.push(minStack.top());
        minStack.pop();
    }
    minStack.pop();
    mainStack.pop();
    
    while(!aux.empty())
    {
        minStack.push(aux.top());
        aux.pop();
    }
}

int MinStack::top() {
    mainStack.top();
}

int MinStack::getMin() {
    minStack.top();
}


