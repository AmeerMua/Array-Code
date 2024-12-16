#include <iostream>
using namespace std;

class Set
{
private:
	char symbol;
	int* Pset;
	int size;
	int counter;
public:
	Set(char symbol, int size)
	{
		this->symbol = symbol;
		this->size = size;
		this->counter = 0;
		Pset = new int [size];
	}
	char getSymbol()
	{
		return symbol;
	}
	char getsize ()
	{
		return size;
	}
	int* getPset()
	{
		return Pset;
	}
	int getCounter()
	{
		return counter;
	}
	void setsymbol(char)
	{
		this-> symbol =symbol;

	}
	void setsize(int)
	{
		this->size = size;
	}

	void addElement(int number)
	{
		if (counter < size)
		{
			Pset [counter++]= number;
		}
		else
		{
			cout << "Set is Full, cannot add more elements. "<<endl;

		}
	
	}
	void addElementsInteractive()
	{
		int number;
		for (int i=0; i< size ; ++i)
		{
			cout << "Enter element "<< (i + 1) << "for Set" << symbol << ":";
			cin >> number;
			addElement (number);
		}
	}

	void removeDuplicates()
	{
		for(int i =0 ; i < counter ; ++i)
		{
		
			for (int j= i+1 +; j < counter ;0)
			{
				if (Pset[i] == Pset[j])
				{
					for (int k =j; k < counter -1 ; ++k)
					{
						Pset[k] = Pset [k+1];
					}
					--counter;
				}
				else
				{
					++j;
				}
			}
		}
	
	}
	void resize (int newSize)
	{
		int* newSet = new int [newSize];
		for (int i =0 ; i< counter; ++i )
		{
			newSet[i] = Pset[i];
		}
		delete[] Pset;
		Pset = newSet;
		size = newSize;
	}
	void sortSet()
	{
		for (int i = 0; i < counter -1; ++i)
		{
			for( int j = 0; j < counter -i -1; ++j)
			{
				if (Pset[j] > Pset[j+1])
				{
					int temp = Pset[j];
					Pset[j] = Pset[j + 1];
					Pset[j + 1] = temp;
				}
			}
		}
	}
	void displaySet()
	{
		cout << "Set " << symbol <<":";
		for (int i = 0; i< counter; ++i )
		{
			cout <<Pset[i] << "";
		}
		cout << endl;
	}

};

void Union(Set& set1, Set& set2) 
{
    // dono set ka size get kare ga
    int size1 = set1.getCounter();
    int size2 = set2.getCounter();

    // ek array baanae ga jo dono set ka data hold kar sake
    int* unionArray = new int[size1 + size2];
    int unionSize = 0;

    // set ka element add kare ga
    for (int i = 0; i < size1; i++) 
	{
        bool isDuplicate = false;

        for (int j = 0; j < unionSize; j++) 
		{
            if (set1.getPset()[i] == unionArray[j]) 
			{
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) 
		{
            unionArray[unionSize++] = set1.getPset()[i];
        }
    }

    // set 2 ka element add kare ga
    for (int i = 0; i < size2; i++) 
	{
        bool isDuplicate = false;

        for (int j = 0; j < unionSize; j++) 
		{
            if (set2.getPset()[i] == unionArray[j]) 
			{
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) 
		{
            unionArray[unionSize++] = set2.getPset()[i];
        }
    }

    // data print karna ka liye 
    cout << "Union of Set " << set1.getSymbol() << " and Set " << set2.getSymbol() << ": ";
    for (int i = 0; i < unionSize; i++) 
	{
        cout << unionArray[i] << " ";
    }
    cout << endl;

    
    delete[] unionArray;
}


void Intersection(Set& set1, Set& set2) 
{
    
    int size1 = set1.getCounter();
    int size2 = set2.getCounter();

    
    int* intersectionArray = new int[size1];
    int intersectionSize = 0;

    // Find common elements
    for (int i = 0; i < size1; i++) 
	{
        for (int j = 0; j < size2; j++) 
		{
            if (set1.getPset()[i] == set2.getPset()[j]) 
			{
                intersectionArray[intersectionSize++] = set1.getPset()[i];
                break; // Stop checking once a match is found
            }
        }
    }

    // Display the intersection set
    cout << "Intersection of Set " << set1.getSymbol() << " and Set " << set2.getSymbol() << ": ";
    for (int i = 0; i < intersectionSize; i++) 
	{
        cout << intersectionArray[i] << " ";
    }
    cout << endl;

    // Free allocated memory
    delete[] intersectionArray;
}

void Difference(Set& set1, Set& set2) 
{
    // Get the size of the first set
    int size1 = set1.getCounter();
    int size2 = set2.getCounter();

    // Create an array to store the difference elements
    int* differenceArray = new int[size1]; // Maximum size can be all elements of set1
    int differenceSize = 0;

    // Find elements in set1 that are not in set2
    for (int i = 0; i < size1; i++) 
	{
        bool isUnique = true; // Assume the current element is unique
        for (int j = 0; j < size2; j++) 
		{
            if (set1.getPset()[i] == set2.getPset()[j]) 
			{
                isUnique = false; // Element found in set2
                break; // No need to check further
            }
        }
        if (isUnique) 
		{
            differenceArray[differenceSize++] = set1.getPset()[i]; // Add unique element to result
        }
    }

    // Display 
    cout << "Difference of Set " << set1.getSymbol() << " and Set " << set2.getSymbol() << ": ";
    for (int i = 0; i < differenceSize; i++) 
	{
        cout << differenceArray[i] << " ";
    }
    cout << endl;

    // Free allocated memory
    delete[] differenceArray;
}

int main ()
{

    
    Set setA('A', 5); 
    Set setB('B', 5); 

    // Add elements 
    cout << "Add elements to Set A:" << endl;
    setA.addElementsInteractive();

    // Add elements interactively to Set B
    cout << "Add elements to Set B:" << endl;
    setB.addElementsInteractive();

    // dono set display kare ga
    cout << "Original Sets:" << endl;
    setA.displaySet();
    setB.displaySet();

    // for union
    cout << endl <<"Performing Union:" << endl;
    Union(setA, setB);

    // for intersection
    cout <<"Performing Intersection:" << endl;
    Intersection(setA, setB);

    // for difference
    cout <<"Performing Difference (A - B):" << endl;
    Difference(setA, setB);

    return 0;
}
