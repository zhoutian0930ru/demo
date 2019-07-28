// IntegerSet.h
// Header file for class IntegerSet

#ifndef INTEGER_SET_H
#define INTEGER_SET_H

class IntegerSet
{
public:
	IntegerSet(); // constructor

	void inputSet();         //read values from user	
	void printSet() const;   //print set
	//a friend function: union of set
	friend void unionOfSet(IntegerSet&, IntegerSet&, IntegerSet&);
	//a friend function: intersection of set
	friend void intersectionOfSet(IntegerSet&, IntegerSet&, IntegerSet&);

private:
	int set[101]; // range of 0 - 100

	// determines a valid entry to the set
	int validEntry(int x) const
	{
		return (x >= 0 && x <= 100);
	} // end function validEntry
};

#endif