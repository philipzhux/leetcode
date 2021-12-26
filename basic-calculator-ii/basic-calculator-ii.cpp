class Solution {
public:
    int calculate(string s) {
        int last_num = 0;
        int final_res = 0;
        bool neg_flag = 0;
        enum SYM{NONE,ADD,MUL,DIV} last_sym;
        std::stack<int> storage;
        last_sym = NONE;
        for(char const &c: s){
        bool is_sym = (c=='+'||c=='-'||c=='*'||c=='/');
        if(is_sym) storage.push(last_num);
        if(is_sym&&(last_sym==MUL||last_sym==DIV)){
            int op1, op2, res;
            op1 = storage.top();
            storage.pop();
            op2 = storage.top();
            storage.pop();
            if(last_sym==MUL) res = op2*op1;
            else if (last_sym == DIV) res = op2/op1;
            storage.push(res);
        }
            
        switch(c){
                case '+':
                    last_sym = ADD;
                    last_num = 0;
                    neg_flag = 0;
                    break;
                case '-':
                    last_sym = ADD;
                    neg_flag = 1;
                    last_num = 0;
                    break;
                case '*':
                    last_sym = MUL;
                    last_num = 0;
                    neg_flag = 0;
                    break;
                case '/':
                    last_sym = DIV;
                    last_num = 0;
                    neg_flag = 0;
                    break;
            }
            if(neg_flag && std::isdigit(c)) last_num = last_num*10+'0'-c;
            else if(std::isdigit(c)) last_num = last_num*10-'0'+c;
        }
        
        storage.push(last_num);
        
        if(last_sym==MUL||last_sym==DIV){
            int op1, op2, res;
            op1 = storage.top();
            storage.pop();
            op2 = storage.top();
            storage.pop();
            if(last_sym==MUL) res = op2*op1;
            else if (last_sym == DIV) res = op2/op1;
            storage.push(res);
        }
        while(!storage.empty()){
            final_res += storage.top();
            storage.pop();
        }
        return final_res;
    }
};