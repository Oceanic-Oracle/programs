#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#define capacity 3 
#define SIZE_BEGIN 3 
 
typedef std::vector<int> container_type;
void print(std::vector<container_type> term,int SIZE)
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < capacity; ++j)
        {
            std::cout << term[i][j] << ' ';
        }
        
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
}
 
int perebor ( std::vector<container_type> term,int &SIZE)
{
    int result=0;
    SIZE--;
    std::vector< std::vector< int > > ::iterator iter;
    for (int nomer=0,temp=0;nomer<SIZE;nomer++,temp=0,iter=term.begin())
    {
        for (int i=0;i<capacity;i++)
        {
            if(term[nomer][i] !=term[nomer+1][i])
            temp++;
        }
        if(temp>1)
        {
            continue;
        }
        
        else
        {
            for (int i=0;i<capacity;i++)
            {
                if( ((term[nomer][i]==0) && (term[nomer+1][i]==1)) || ((term[nomer][i]==1) && (term[nomer+1][i]==0)) )
                {
                    term[nomer][i]=-1;
                    break;
                }
            }
            iter+=nomer +1;
            term.erase(iter);
            SIZE--;
            nomer--;
            print( term, SIZE+1);
            result++;
        }
 
    }
return result;
}
 
int main()
{
    int SIZE=SIZE_BEGIN;
    int array[SIZE_BEGIN][capacity]={ {1,1,0} , {1,1,1}, {1,-1,-1}};
    std::vector<container_type> vec(SIZE,std::vector< int > (capacity));
    std::vector<container_type>::iterator iter = vec.begin();
    
    for (int i = 0; i < SIZE; ++i)
    {
        for (int i2 = 0; i2 < capacity; ++i2)
        {
            iter[i][i2]=array[i][i2];
        }
    }
    while(perebor(vec,SIZE))
    system("PAUSE");
    return EXIT_SUCCESS;
}