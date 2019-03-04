#if !defined(__MACRO_HEAD_FILE__)
#define __MACRO_HEAD_FILE__

#define SAFE_DELETE(p)   \
    {                    \
        if (p)           \
        {                \
            delete p;    \
            p = nullptr; \
        }                \
    }

#define SAFE_DELETE_ARRAY(p) \
    {                        \
        if (p)               \
        {                    \
            delete[] p;      \
            p = nullptr;     \
        }                    \
    }

#define IS_ZERO(v) ((fabs(v) < 1e-7) ? true : false)

#endif // __MACRO_HEAD_FILE__
