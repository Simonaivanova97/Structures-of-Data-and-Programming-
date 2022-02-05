#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

template <typename T>
struct node{
    T inf;
    node<T>* left, *right;
};

template <typename T>
void prettyPrintHelp(node<T> *current, int level){
  if (current == nullptr){
      return;
    }

  prettyPrintHelp (current->right,level+1);
  cout<< setw(level*2) << " " << current->inf<<endl;
  prettyPrintHelp (current->left, level+1);

}

template <typename T>
void prettyPrint(node<T>* root){
  prettyPrintHelp (root, 0);
}

// 1. Функция, която приема двоично дърво и елемент и връща дали елементът се съдържа в него.
template <typename T>
bool hasElement(const node<T>* root, const T& elem){
    if(root){
        if(root->inf==elem){
            return true;
        }
        else{
            return hasElement(root->left, elem) || hasElement(root->right, elem);
            
        }
    }
    return false;
}

// 2. Функция, която приема двоично дърво от числа и връща сумата на числата в него.
int sumOfNodes(const node<int>* root){
    if(root){
        return root->inf+sumOfNodes(root->left)+sumOfNodes(root->right);
    }
    return 0;
}

// 3. Функция, която приема двоично дърво и връща най-големия елемент в него.
int maxElement(const node<int>* root){
    if(root){
        return max(root->inf, max(maxElement(root->left), maxElement(root->right)));
    }
    return 0;
}

// 4. Функция, която приема двоично дърво и връща височината му.
template <typename T>
int heightOfTree(const node<T>* root){
    if(root){
        return 1+max(heightOfTree(root->left), heightOfTree(root->right));
    }
    return 0;
}

// 5. Функция, която приема двоично дърво и връща броя на елементите му.
template <typename T>
int numberOfElements(const node<T>* root){
    if(root){
        return 1+numberOfElements(root->left)+numberOfElements(root->right);
    }
    else{
        return 0;
    }
}

// 6. Функция, която приема двоично дърво с n върха и проверява дали числата от 1 до n се срещат точно веднъж в дървото.
// Функция, която брои, колко пъти се среща дадено число в дървото.
void countOccuranseOfElement(const node<int>* root, const int& elem, int& count){
    if(root){
        if(root->inf==elem){
            count++;
        }
        countOccuranseOfElement(root->left, elem, count);
        countOccuranseOfElement(root->right, elem, count);
    }
}
bool containsNumberOnlyOnce(const node<int>* root){
    for(int i=1;i<=numberOfElements(root);i++){
        int count=0;
        countOccuranseOfElement(root, i, count);
        if(count>1 || count==0){
            return false;
        }
    }
    return true;
}

// 7. Функция, която приема двоично дърво, чиито елементи са символи, и цяло число k и връща думата на к-тото ниво на дървото.
void wordOnKLevelHelper(const node<char>* root, const int& level, int countLevel, string& str){
    if(root){
        if(countLevel<level){
            countLevel++;
            wordOnKLevelHelper(root->left, level, countLevel, str);
            wordOnKLevelHelper(root->right, level, countLevel, str);
        }
        else if(countLevel==level){
            str+=root->inf;
        }
    }
}
string wordOnKLevel(const node<char>* root, const int level){
    string str="";
    wordOnKLevelHelper(root, level, 1, str);
    return str;
}

// 8. Функция, която приема двоично дърво и връща всички думи, които са получени от корена до някое листо.
void wordsInPathsToLeaves(const node<int>* root, vector<string>& vec, string str){
    if(root){
        int currentNumber=root->inf;
        string c=to_string(currentNumber);
        //char c=root->inf+48;
        if(!root->left && !root->right){
            str+=" ";
            vec.push_back(str+c);
        }
        else{
            str+=" ";
            str+=c;
            if(root->left){
                wordsInPathsToLeaves(root->left, vec, str);
            }
            if(root->right){
                wordsInPathsToLeaves(root->right, vec, str);
            }
        }
    }
}

// 9. Функция, която приема двоично дърво и връща сумата на листата.
int sumOfLeaves(const node<int>* root){
    if(root){
        if(root->left || root->right){
            return sumOfLeaves(root->left)+sumOfLeaves(root->right);
        }
        else{
            return root->inf;
        }
    }
    return 0;
}

// 10. Функция, която приема двоично дърво и обхожда елементите му по следния начин: ляво - корен - дясно (Inorder Traversal)
void inorderTraversal(const node<int>* root){
    if(root){
        inorderTraversal(root->left);
        cout<<root->inf<<" ";
        inorderTraversal(root->right);
    }
}

// 11. Функция, която приема указател към корена на дърво и цяло число n и принтира елементите, които се намират на ниво n.
template <typename T>
void elementsOfLevelNHelper(const node<T>* root, int n, int countLevel){
    if(root){
        if(countLevel<n){
            countLevel++;
            elementsOfLevelNHelper(root->left, n, countLevel);
            elementsOfLevelNHelper(root->right, n, countLevel);
        }
        else if(countLevel==n){
            cout<<root->inf<<" ";
        }
    }
}
template <typename T>
void elementsOfLevelN(const node<T>* root, int n){
    elementsOfLevelNHelper(root, n, 1);
}

// 12. Функция, която приема указател към корена на дърво и цяло число n и връща сумата на елементите, които се намират на ниво n.
void sumOfElementsLevNHelper(const node<int>* root, const int n, int countLevel, int& sum){
    if(root){
        if(countLevel<n){
            countLevel++;
            sumOfElementsLevNHelper(root->left, n, countLevel, sum);
            sumOfElementsLevNHelper(root->right, n, countLevel, sum);
        }
        else if(countLevel==n){
            sum+=root->inf;
        }
    }
}
int sumOfElementsLevN(const node<int>* root, const int n){
    int sum=0;
    sumOfElementsLevNHelper(root, n, 1, sum);
    return sum;
}

// 13. Функция, която приема указател към корена на дърво и низ, съставен само от символите 'l', 'r', и принтира елемента, към който сочи низът (като 'l' означава дa търсим в текущото ляво поддърво, а 'r' - в дясното).
template <typename T>
T elem(const node<T>* root, string& str){
    if(root && (root->left || root->right) && str.size()!=0){
        if(str[0]=='l'){
            str.erase(str.begin());
            return elem(root->left, str);
        }
        else if(str[0]=='r'){
            str.erase(str.begin());
            return elem(root->right, str);
        }
    }
    if(str.size()==0){
        return root->inf;
    }
    else{
        return -1;
    }
}

// 14. Функция, която приема указател към корена на дърво и променя дървото в неговата огледална форма.
template<typename T>
void mirrorTree(node<T>*& root){
    if(root){
        node<T>* copyLeftsubtree=root->left;
        root->left=root->right;
        root->right=copyLeftsubtree;
        mirrorTree(root->left);
        mirrorTree(root->right);
    }
}

// 15. Функция, която по подадено двоично дърво от цели числа намира листото с най-голяма стойност.
void maxLeave(const node<int>* root, int& maxElem){
    if(root){
        if(!root->left && !root->right){
            int currentMax=maxElem;
            maxElem=max(currentMax, root->inf);
        }
        else{
            maxLeave(root->left, maxElem);
            maxLeave(root->right, maxElem);
        }
    }
}

template <typename T>
void deleteTree(node<T>*& root){
    if(root){
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root=NULL;
    }
}

int main() {
    
    node<int>* start=NULL, *l=NULL, *r=NULL, *ll=NULL, *lr=NULL, *rl=NULL, *rr=NULL, *lrl=NULL, *rrl=NULL, *rrr=NULL, *rrrl=NULL, *root=NULL;
    start=new node<int>;
    assert(start!=NULL);
    l=new node<int>;
    assert(l!=NULL);
    ll=new node<int>;
    assert(ll!=NULL);
    r=new node<int>;
    assert(r!=NULL);
    lr=new node<int>;
    assert(lr!=NULL);
    rl=new node<int>;
    assert(rl!=NULL);
    rr=new node<int>;
    assert(rr!=NULL);
    lrl=new node<int>;
    assert(lrl!=NULL);
    rrl=new node<int>;
    assert(rrl!=NULL);
    rrr=new node<int>;
    assert(rrr!=NULL);
    rrrl=new node<int>;
    assert(rrrl!=NULL);
    
    start->inf=1;
    start->left=l;
    start->right=r;
    l->inf=2;
    l->left=ll;
    l->right=lr;
    r->inf=3;
    r->left=rl;
    r->right=rr;
    ll->inf=4;
    ll->left=NULL;
    ll->right=NULL;
    lr->inf=5;
    lr->left=lrl;
    lr->right=NULL;
    rl->inf=7;
    rl->left=NULL;
    rl->right=NULL;
    rr->inf=8;
    rr->left=rrl;
    rr->right=rrr;
    lrl->inf=6;
    lrl->left=NULL;
    lrl->right=NULL;
    rrl->inf=9;
    rrl->left=NULL;
    rrl->right=NULL;
    rrr->inf=10;
    rrr->left=rrrl;
    rrr->right=NULL;
    rrrl->inf=11;
    rrrl->left=NULL;
    rrrl->right=NULL;
    
    prettyPrint(start);
    
    cout<<"\nHas element 14? "<<hasElement(start, 14)<<endl;
    cout<<"\nHas element 3? "<<hasElement(start, 3)<<endl;
    //cout<<"\nHas element 14? "<<hasElement(root, 14)<<endl;
    
    cout<<"\nSum of nodes: "<<sumOfNodes(start)<<endl;
    //cout<<"\nSum of nodes: "<<sumOfNodes(root)<<endl;
    
    cout<<"\nMax element: "<<maxElement(start)<<endl;
    //cout<<"\nMax element: "<<maxElement(root)<<endl;
    
    cout<<"\nHight of tree: "<<heightOfTree(start)<<endl;
    //cout<<"\nHight of tree: "<<heightOfTree(root)<<endl;
    
    cout<<"\nNumber of elements: "<<numberOfElements(start)<<endl;
    //cout<<"\nNumber of elements: "<<numberOfElements(root)<<endl;
    
    int count=0;
    countOccuranseOfElement(start, 2, count);
    cout<<"\nCount occuranse of 2 in tree: "<<count<<endl;
    cout<<"Contains number ["<<1<<";"<<numberOfElements(start)<<"] only once: "<<containsNumberOnlyOnce(start)<<endl;
    
    /*node<char>* start2=NULL, *l2=NULL, *r2=NULL, *ll2=NULL, *lr2=NULL, *rl2=NULL, *rr2=NULL, *lll2=NULL, *llr2=NULL, *lrl2=NULL, *lrr2=NULL, *rrr2=NULL;
    start2=new node<char>;
    assert(start2!=NULL);
    l2=new node<char>;
    assert(l2!=NULL);
    r2=new node<char>;
    assert(r2!=NULL);
    ll2=new node<char>;
    assert(ll2!=NULL);
    lr2=new node<char>;
    assert(lr2!=NULL);
    rl2=new node<char>;
    assert(rl2!=NULL);
    rr2=new node<char>;
    assert(rr2!=NULL);
    lll2=new node<char>;
    assert(lll2!=NULL);
    llr2=new node<char>;
    assert(llr2!=NULL);
    lrl2=new node<char>;
    assert(lrl2!=NULL);
    lrr2=new node<char>;
    assert(lrr2!=NULL);
    rrr2=new node<char>;
    assert(rrr2!=NULL);
    start2->inf='a';
    start2->left=l2;
    start2->right=r2;
    l2->inf='b';
    l2->left=ll2;
    l2->right=lr2;
    r2->inf='c';
    r2->left=rl2;
    r2->right=rr2;
    ll2->inf='M';
    ll2->left=lll2;
    ll2->right=llr2;
    lr2->inf='o';
    lr2->left=lrl2;
    lr2->right=lrr2;
    rl2->inf='n';
    rl2->left=NULL;
    rl2->right=NULL;
    rr2->inf='i';
    rr2->left=NULL;
    rr2->right=rrr2;
    lll2->inf='H';
    lll2->left=NULL;
    lll2->right=NULL;
    llr2->inf='e';
    llr2->left=NULL;
    llr2->right=NULL;
    lrl2->inf='l';
    lrl2->left=NULL;
    lrl2->right=NULL;
    lrr2->inf='l';
    lrr2->left=NULL;
    lrr2->right=NULL;
    rrr2->inf='o';
    rrr2->left=NULL;
    rrr2->right=NULL;
    
    cout<<"\nWord on level 1: "<<wordOnKLevel(start2, 4)<<endl;
    deleteTree(start2);*/
    
    cout<<"\nSum of leaves: "<<sumOfLeaves(start)<<endl;
    
    cout<<"\nInorde traversal: ";
    inorderTraversal(start);
    cout<<endl;
    
    cout<<"\nElements on level 3: ";
    elementsOfLevelN(start, 3);
    cout<<endl;
    
    cout<<"\nSum of elements in level 3: "<<sumOfElementsLevN(start, 3)<<endl;
    
    cout<<"Mirror tree"<<endl;
    mirrorTree(start);
    prettyPrint(start);
    
    int maxL=INT8_MIN;
    maxLeave(start, maxL);
    cout<<"\nMax leave: "<<maxL<<endl;
    
    string s="lllr";
    cout<<"\nElement: "<<elem(start, s)<<endl;
    
    cout<<"\nAll words in paths to leaves"<<endl;
    vector<string> vec;
    wordsInPathsToLeaves(start, vec, "");
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    
    deleteTree(start);
    return 0;
}
