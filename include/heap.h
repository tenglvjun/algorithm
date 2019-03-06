#if !defined(__HEAP_HEAD_FILE__)
#define __HEAP_HEAD_FILE__

#include "continue_container.h"

class Heap : public ContinueContainer
{
public:
  Heap(bool maxHeapify = true);
  Heap(int *data, int len, bool maxHeapify = true);
  virtual ~Heap();

public:
  void Add(int v);

protected:
  void Heapify();
  void TrackDown(int node);
  void TrackUp(int node);

private:
  bool m_isMaxHeapify;
};

#endif // __HEAP_HEAD_FILE__
