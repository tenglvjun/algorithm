#if !defined(__HEAP_HEAD_FILE__)
#define __HEAP_HEAD_FILE__

class Heap
{
  public:
    Heap(bool maxHeapify = true);
    Heap(int *data, int len, bool maxHeapify = true);
    virtual ~Heap();

  public:
    void Add(int v);
    void Output();

  protected:
    void Heapify();
    void Swap(int i, int j);
    void TrackDown(int node);
    void TrackUp(int node);
    void Alloc();

  private:
    int *m_data;
    int m_len;
    int m_cap;
    bool m_isMaxHeapify;
};

#endif // __HEAP_HEAD_FILE__
