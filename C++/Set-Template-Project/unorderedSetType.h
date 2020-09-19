#ifndef H_unorderedSetType
#define H_unorderedSetType

#include "unorderedArrayListType.h"

template <class elemType>
class unorderedSetType: public unorderedArrayListType<elemType>
{
  public:
    void insertEnd(const elemType& insertItem);
    void insertAt (int location, const elemType& insertItem);
    void replaceAt (int location, const elemType& repItem);

    //this function overloads the (+) operator to perform a union
    //    of 2 sets. Output should be all unique items from each set
    unorderedSetType<elemType> operator+(const unorderedSetType<elemType>& itemSet1) const;

    //this function overloads the (-) operator to perform an 
    //  intersection of 2 sets. Output is all items found in both sets
    unorderedSetType<elemType> operator-(const unorderedSetType<elemType>& itemSet1) const;

};

template <class elemType>
void unorderedSetType<elemType>:: insertEnd(const elemType& insertItem)
{
  if (unorderedSetType::seqSearch(insertItem)== -1)
  {
    unorderedArrayListType<elemType>:: insertEnd(insertItem);
  } 
}

template <class elemType>
void unorderedSetType<elemType>:: insertAt(int location, const elemType& insertItem)
{
  if(unorderedSetType::seqSearch(insertItem) == -1)
  {
    unorderedArrayListType<elemType>:: insertAt(location, insertItem);
  }
}

template <class elemType>
void unorderedSetType<elemType> :: replaceAt(int location, const elemType& repItem)
{
  if (unorderedSetType::seqSearch(repItem)== -1)
  {
    unorderedArrayListType<elemType> :: replaceAt(location, repItem);
  }
}


//Operator overloading (+) to perform union of 2 sets
template <class elemType>
unorderedSetType<elemType> unorderedSetType<elemType> :: operator+(const unorderedSetType<elemType>& itemSet1) const
{
  unorderedSetType set3;
  for (int i = 0; i < 100; i ++)
  {
    set3.insertEnd(this->list[i]);
    set3.insertEnd(itemSet1.list[i]);
  }
  return set3;
}

//Operator overloading (-) to perform intersection
template <class elemType>
unorderedSetType<elemType> unorderedSetType<elemType> :: operator-(const unorderedSetType<elemType>& itemSet1) const
{
  unorderedSetType set3;
  
  for (int i = 0; i < 100; i ++)
  {
    if (itemSet1.seqSearch(this->list[i]) != -1)
    {
      set3.insertEnd(this->list[i]);
    }
  }
  return set3;
}


#endif