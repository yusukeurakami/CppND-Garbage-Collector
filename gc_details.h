// This class defines an element that is stored
// in the garbage collection information list.
//
template <class T>
class PtrDetails
{
  public:
    unsigned refcount; // current reference count
    T *memPtr;         // pointer to allocated memory
    /* isArray is true if memPtr points
    to an allocated array. It is false
    otherwise. */
    bool isArray{false}; // true if pointing to array
    /* If memPtr is pointing to an allocated
    array, then arraySize contains its size */
    unsigned arraySize; // size of array
    // Here, mPtr points to the allocated memory.
    // If this is an array, then size specifies
    // the size of the array.
    PtrDetails(T* Ptr, unsigned size=0)
    {
      // TODO: Implement PtrDetails
      refcount = 1;
      if (size>0){
        isArray=true;
        arraySize = size;
      }
      memPtr = Ptr;
    }
};

// Overloading operator== allows two class objects to be compared.
// This is needed by the STL list class.
template <class T>
bool operator==(const PtrDetails<T> &ob1,
                const PtrDetails<T> &ob2)
{
    // TODO: Implement operator==
  	return (ob1.memPtr == ob2.memPtr && 
            ob1.arraySize==ob2.arraySize);
}