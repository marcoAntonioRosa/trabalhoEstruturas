#ifndef TYPEOF_H_INCLUDED
#define TYPEOF_H_INCLUDED

template <typename T> const char* typeof(T&)
{
    return "unknown";    // default
}
template<> const char* typeof(int&)
{
    return "int";
}
template<> const char* typeof(short&)
{
    return "short";
}
template<> const char* typeof(long&)
{
    return "long";
}
template<> const char* typeof(unsigned&)
{
    return "unsigned";
}
template<> const char* typeof(unsigned short&)
{
    return "unsigned short";
}
template<> const char* typeof(unsigned long&)
{
    return "unsigned long";
}
template<> const char* typeof(float&)
{
    return "float";
}
template<> const char* typeof(double&)
{
    return "double";
}
template<> const char* typeof(long double&)
{
    return "long double";
}
template<> const char* typeof(std::string&)
{
    return "String";
}
template<> const char* typeof(char&)
{
    return "char";
}
template<> const char* typeof(signed char&)
{
    return "signed char";
}
template<> const char* typeof(unsigned char&)
{
    return "unsigned char";
}
template<> const char* typeof(char*&)
{
    return "char*";
}
template<> const char* typeof(signed char*&)
{
    return "signed char*";
}
template<> const char* typeof(unsigned char*&)
{
    return "unsigned char*";
}

#endif // TYPEOF_H_INCLUDED
