#if !defined(__CONTINUE_CONTAINER_HEAD_FILE__)
#define __CONTINUE_CONTAINER_HEAD_FILE__

class ContinueContainer
{
  public:
    ContinueContainer();
    ContinueContainer(const int *data, const int len);
    ContinueContainer(const ContinueContainer &c);
    virtual ~ContinueContainer();

  public:
    ContinueContainer &operator=(const ContinueContainer &c);
    int &operator[](const int idx);

  public:
    void Resize(const int cap);
    void Resize(const int *data, const int len);
    void Swap(const int i, const int j);
    void PushBack(const int v);
    int Erase(const int idx);
    void Insert(const int v, const int idx);
    void Output();

  protected:
    void Alloc();
    void Dealloc();

  protected:
    int *m_data;
    int m_len;
    int m_cap;
};

#endif // __CONTINUE_CONTAINER_HEAD_FILE__
