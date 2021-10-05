#include<iostream>
#include<set>
#include<iomanip>
using namespace std;
void sets_generator()
{
    int n1,x,n2,y,n;
    set<int>:: iterator l;
    int choice;
    set<int> set1;
    cout << "\nEnter no. of elements for 1st Set :  " ;
    cin >> n1 ;
    for (int i = 0; i < n1; i++)
    {
        cin >> x;
        set1.insert(x);
    }
    set <int> ::iterator g;
    cout << "\nElements for Set-1 : " ;
    cout << "{ ";
    for ( g = set1.begin(); g != set1.end(); g++)
    {
         cout << *g << " " ;
    }
    cout << "}";
    set<int>set2 ;
    cout << "\n\nEnter no. of elements for 2nd Set : " ;
    cin >> n2 ;
    for (int i = 0; i < n2; i++)
    {
        cin >> y;
        set2.insert(y);
    }
    set <int> ::iterator k;
    cout << "\nElements for Set-2 : " ;
    cout << "{ ";
    for ( k = set2.begin(); k!= set2.end(); k++)
    {
        cout << *k << " " ;
       
    }
    cout << "}";
    conditions:
    set<int> Set3;
    cout << "\n\n    Which operation you want to use ?    "   << endl;
    cout << setw(5) << "1. Union of 2 Sets" << endl;
    cout << setw(5) << "2. Intersection of 2 Sets " << endl;
    cout << setw(5) << "3. Difference between 2 Sets " << endl;
    cout << setw(5) << "4. Cartesian product of 2 Sets " << endl;
    cout << setw(5) << "5. Compliment of a Set" << endl;
    cin >> choice;

    if (choice == 1)
    
    {
        system("CLS");
        cout << "\nUnion of Set 1 and Set 2 is : ";
        for ( g = set1.begin(); g != set1.end(); g++)
       {
           Set3.insert(*g);
       }
        for ( k = set2.begin(); k != set2.end(); k++)
       {
           Set3.insert(*k);  
        }
        set<int>:: iterator l;
        cout << "{ ";
        for(l = Set3.begin(); l != Set3.end() ; l++)
        {
            cout << *l << " " ;
        } 
        cout << "}";
        cout << "\n" ;
        goto conditions;
        
    }
    
    if(choice == 2)
     
    {
        Set3.clear();
        for ( g = set1.begin(); g != set1.end(); g++)
        {
            for ( k = set2.begin(); k != set2.end(); k++)
            {
               if (*g == *k)
               {
                   Set3.insert(*g);
                   
               }
               
            } 
        }
        system("CLS");
        cout <<"\nIntersection of A and B : ";
        cout << "{ ";
            for (l = Set3.begin(); l != Set3.end(); l++)
            {
                cout << *l <<  " ";
            }  
        cout << "}";
        goto conditions;
    } 
         

        if(choice == 3)
        {
            int choose;
            set <int> :: iterator itr;
            cout << "\n 1. For Set 1 - Set 2  " ;
            cout << "\n 2. For Set 2 - Set 1  " ;
            cout << "\n\n Enter your choice : " ;
            cin >> choose;

            switch (choose)
            {
             case (1):
                     for ( itr = set2.begin() ; itr != set2.end(); itr++)
                {
                   set1.erase(*itr);
                }
                cout << "\nDifference of Set 1 - Set 2 is : ";
                cout << "{ ";
                for ( itr = set1.begin() ; itr != set1.end(); itr++)
                {
                   cout << *itr << " ";
                }   
                cout << "}";
                goto conditions;
                break;

             case (2):
             for (itr= set1.begin(); itr != set1.end() ; itr++)
                {
                    set2.erase(*itr);
                }
                cout << "\nDifference of Set 2 - Set 1 is : ";
                cout << "{ ";
                for ( itr = set2.begin() ; itr != set2.end(); itr++)
                {
                   cout << *itr << " ";
                }
                cout << "}";
                goto conditions;
             break;
            
             default:
             cout << "\nERROR !!!";
             goto conditions;
                break;
            }
        }        

     if (choice == 4)
    {
        system("CLS");
        cout << "Press 1 for A X B ";
        cout << "\nPress 2 for B X A  ";
        cout << "\n " << endl;
        
      int choose2;
      cin >> choose2;

      switch (choose2)
      {
      case (1):
          cout << "{ ";
          for ( g = set1.begin(); g != set1.end(); g++)
          {
              for ( k = set2.begin(); k != set2.end(); k++)
              {
                  cout << "(" << *g << "," << *k << ")";
              }
          }cout << " }";
          goto conditions;
          break;
       case (2):
               cout << "{ ";
              for ( k = set2.begin(); k != set2.end(); k++)
             {
             for ( g = set1.begin(); g != set1.end(); g++)
              {
                  cout << "(" << *k << "," << *g << ")";
              }
          }
               cout << " }";
          goto conditions;
          break;

         default:
         cout << "\nERROR !!!";
             goto conditions;
          break;
      }
    }
    if(choice = 5)
    {
        system("CLS");
        cout << "\nSet limit of the Universal Set : ";
        int limit;
        cin >> limit;
        set<int> setU;
        set<int>:: iterator U;
        for (int i = 1; i <= limit; i++)
        {
          setU.insert(i)  ;
        }
        cout << "{";
        for ( U = setU.begin(); U != setU.end(); U++)
          {
              cout << *U << " ";
           }  
        cout << "}";
        cout << "\nWhich Set's Compliment you want to show ? "; 
        cout << "\nPress 1 for A or 2 for B  ";
        int comp;
        cin >> comp;
        switch (comp)
        {
        
          case (1):
          
            for ( U = set1.begin(); U != set1.end(); U++) 
            {
                setU.erase(*U);
            }
             cout << "\nA's Compliment is :";
             cout << "\n{";
             for ( U = setU.begin(); U != setU.end(); U++)
             {
              cout << *U << " ";
             }  
             cout << "}";
             goto conditions;
             break;

             case(2):
           
           for ( U = set2.begin(); U != set2.end(); U++) 
            {
                setU.erase(*U);
            }
             cout << "\nB's Compliment is :";
             cout << "\n{";
             for ( U = setU.begin(); U != setU.end(); U++)
             {
              cout << *U << " ";
             } 
             cout << "}";

             goto conditions;
             break;
             default:
             break;
        }

                         
    } 
}        
int main()
{
    sets_generator();
    return 0;
}