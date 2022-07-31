#include<iostream>
using namespace std;

struct Array
{
int *A;
int size;
int length;
};

void Display(struct Array arr)
{
    int i;
    cout<<"\nElements are: \n";
    for(i=0;i<arr.length;i++)
    cout<<arr.A[i]<<" ";
}

void Append(struct Array *arr,int x)
{
    if(arr->length<arr->size)
    arr->A[arr->length++]=x;
}

void Insert(struct Array *arr,int index,int x)
{
    int i;
    if(index>=0 && index <=arr->length)
    {
        for(i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }
}
int Delete(struct Array *arr,int index)
{
    int x=0;
    int i;
    if(index>=0 && index<arr->length)
    {
        x=arr->A[index];
        for(i=index;i<arr->length-1;i++)
            arr->A[i]=arr->A[i+1];
        arr->length--;
        return x;
    }
    return 0;
}

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
//Improving Linear Search with method 1-Tranposition(swap(A[i],A[i-1])) method 2-Move to Front/Head(swap(A[i],A[0]))
int linearSearch(struct Array *arr ,int key)
{
    int i;
    for(i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        {
            swap(&arr->A[i],&arr->A[i-1]);
            return i;
        }
    }
   return -1;
}

int binarySearch(struct Array *arr,int key)
{
    int l,h,mid;
    l=0;
    h=arr->length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr->A[mid])
            return mid;
        else if(key<arr->A[mid]) 
            h=mid-1;
        else
            l=mid+1;   
    }
    return -1;
}

int recursiveBinarySearch(int a[],int l,int h,int key)
{
    int mid=0;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            return recursiveBinarySearch(a,l,mid-1,key);
        else
            return recursiveBinarySearch(a,mid+1,h,key);
    }
    return -1;
}

int get(struct Array arr,int index)
{
    if(index>=0 && index<arr.length)
        return arr.A[index];
    return -1;
}

void set(struct Array *arr,int index,int x)
{
    if(index>=0 && index<arr->length)
        arr->A[index]=x;
}

int Max(struct Array arr)
{
    int max=arr.A[0];
    for(int i=0;i<arr.length;i++){
        if(arr.A[i]>max)
            max=arr.A[i];
    }
    return max;
}

int Min(struct Array arr)
{
    int min=arr.A[0];
    for(int i=0;i<arr.length;i++){
        if(arr.A[i]<min)
            min=arr.A[i];
    }
    return min;
}

int Sum(struct Array arr)
{
    int s=0;
    for(int i=0;i<arr.length;i++)
        s+=arr.A[i];
    return s;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}

void reverse_Method1(struct Array *arr)
{
     
    int i,j;
    int *B;
    B=new int [5];
    for(i=arr->length-1,j=0;i>=0;i--,j++)
        B[j]=arr->A[i];
    for(i=0;i<arr->length;i++)
        arr->A[i]=B[i];
}

void reverse_Method2(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
        swap(&arr->A[i],&arr->A[j]);
}

int isSorted(struct Array arr)
{
    for(int i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
        return 0;
    }
    return 1;
}
//same as Insert Function
void insertSort(struct Array *arr,int x)
{
    int i=arr->length-1;
    if(arr->length==arr->size)return;
    while(i>=0 && arr->A[i]>x){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

void Rearrange(struct Array *arr)
{
    int i=0;
    int j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0)
            i++;
        while(arr->A[i]>0)
            j--;
        if(i<j)
            swap(&arr->A[i],&arr->A[j]);
    }
}

struct Array* Merge(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    Array *arr3 = new Array;
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
            arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];
    arr3->length=arr1->length+arr2->length;
    arr3->size=10;
    return arr3;
}

struct Array* Union(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    Array *arr3 = new Array;
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            arr3->A[k++]=arr2->A[j++];
        else
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];
    arr3->length=k;
    arr3->size=10;
    return arr3;
}

struct Array* Intersection(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    Array *arr3 = new Array;
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else if(arr1->A[i]==arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    arr3->length=k;
    arr3->size=10;
    return arr3;
}

struct Array* Difference(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    Array *arr3 = new Array;
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    arr3->length=k;
    arr3->size=10;
    return arr3;
}

int main() 
{
    // struct Array arr1={{2,3,4,5,6},10,5};
    // // Append(&arr1,10);
    // // Insert(&arr1,0,12);
    // // Delete(&arr1,0);
    // // cout<<linearSearch(&arr1,4);
    // cout<<"\nIndex for key using binary search is :"<<binarySearch(&arr1,3);
    // cout<<"\nIndex for key using recursive binary search is :"<<recursiveBinarySearch(arr1.A,0,arr1.length-1,2);
    // cout<<get(arr1,3);
    // set(&arr1,0,15);
    // cout<<"\n"<<Max(arr1);
    // cout<<"\n"<<Min(arr1);
    // cout<<"\n"<<Sum(arr1);
    // cout<<"\n"<<Avg(arr1);  
    // reverse_Method1(&arr1);
    // reverse_Method2(&arr1);
    //cout<<isSorted(arr1);
    //insertSort(&arr1,10);
    //Rearrange is use to arrange negative nos. on left side and positive nos. on the other side
    //Rearrange(&arr1);
    //Display(arr1);
    // Merge is use to sort and concatinate two arrays using structure
    // struct Array arr1={{2,9,21,28,35},10,5};
    // struct Array arr2={{1,3,16,18,28},10,5};
    // struct Array *arr3;
    // arr3=Merge(&arr1,&arr2);
    // Display(*arr3);
    //------------------------------------------------------------------------------------//
    //SET Operations on Array
    // struct Array arr1={{1,9,21,28,35},10,5};
    // struct Array arr2={{2,3,9,18,28},10,5}; 
    // struct Array *arr3;
    // arr3=Union(&arr1,&arr2);
    // arr3=Intersection(&arr1,&arr2);
    // arr3=Difference(&arr1,&arr2);
    // Display(*arr3);
    // struct Array arr1;
    // arr1.size=10;
    // c++ declare arr1.A=new int[arr1.size]; //here struct Array has int *A not A[10] 
    //c declare arr1.A=(int *)malloc(arr1.size*sizeof(int));
    
    struct Array arr1;
    struct Array arr2;
    int ch;
    int x,index;
    cout<<"Enter Size of Array: ";
    cin>>arr1.size;
    arr1.A=new int[arr1.size];
    arr1.length=0;

    do
    {
        cout<<"\n\nMenu\n";
        cout<<"1. Insert\n";
        cout<<"2. Delete\n";
        cout<<"3. Linear Search\n";
        cout<<"4. Binary Search\n";
        cout<<"5. get\n";
        cout<<"6. set\n";
        cout<<"7. Min-Max\n";
        cout<<"8. Average\n";
        cout<<"9. Sum\n";
        cout<<"10. Reverse Array\n";
        cout<<"11. Check if Sorted Asc\n";
        cout<<"12. Rearrange -ve and +ve\n";
        cout<<"13. Display\n";
        cout<<"14.Exit\n";
        cout<<"Enter you choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1: 
                cout<<"Enter an element and index: ";
                cin>>x>>index;
                Insert(&arr1,index,x);
                break;
        case 2: 
                cout<<"Enter index: ";
                cin>>index;
                x=Delete(&arr1,index);
                cout<<"Deleted Element is "<<x;
                break;
        case 3:
                cout<<"Enter element to search: ";
                cin>>x;
                index=linearSearch(&arr1,x);
                cout<<"Element index "<<index;
                break;
        case 4:
                int choice;
                cout<<"Chose Binary Search Method: "; 
                cout<<"1.Iterative \n 2.Recursive : ";
                cin>>choice;
                cout<<"\nEnter element to search: ";
                cin>>x;
                index=binarySearch(&arr1,x);
                if(choice== 1)
                    cout<<"Iteratibe Approch Element "<<x<<" is at "<<index<<" index.";
                else if(choice==2)
                    cout<<"Recursive Approch Element "<<x<<" is at "<<recursiveBinarySearch(arr1.A,0,arr1.length-1,x)<<" index.";
                break;
        case 5:
                cout<<"Enter the Index: ";
                cin>>index;
                cout<<"Elemet at "<<index<<" is "<<get(arr1,index);
                break;
        case 6:
                cout<<"Enter set index and element : ";
                cin>>index>>x;
                set(&arr1,index,x);
                cout<<"Index element Set/replace";
                break;
        case 7: 
                cout<<"\nMinimum value in Array is "<<Min(arr1);
                cout<<"\nMaximum value in Array is "<<Max(arr1);
                break;
        case 8:
                cout<<"Average is "<<Avg(arr1);
                break;
        case 9:
                cout<<"Sum is "<<Sum(arr1);
                break;
        case 10:
                int op;
                cout<<"Reversing an Array\n1.Iterative Approch\n2.Swap Method : ";
                cin>>op;
                if(op==1){
                    reverse_Method1(&arr1);
                    Display(arr1);
                }
                else if (op==2){
                    reverse_Method2(&arr1);
                    Display(arr1);
                }
                break;
        case 11:
                int r;
                r=isSorted(arr1);
                if(r==1) cout<<"Array is sorted";
                else cout<<"Array not sorted";
                break;
        case 12:
                Rearrange(&arr1);
                Display(arr1);
                break;
        case 13:
                Display(arr1);
        }
    }while(ch<14);
    return 0;
}
