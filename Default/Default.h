#ifndef Default_h__
#define Default_h__

namespace Default
{

enum Const
{
    NameSize = 64,
    PasswordSize = 24,
    HostSize = 256,
    DataSize = 1024,
};

template<typename T>
T DefaultValue()
{
    T t;
    return t;
}

template<>
inline int DefaultValue()
{
    return 0;
}
template<>

inline bool DefaultValue()
{
    return false;
}

enum { ReceiveBufferSize = 1 << 16, };


class Token
{
public:
    static const u32 kLoginKey = 0X93981382;
};

}

#endif // Default_h__
