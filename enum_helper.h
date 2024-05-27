#ifndef ENUM_HELPER
#define ENUM_HELPER

#include <ostream>

#define _CREATE_ENUM_VALUE(enum_name, value, ...) value __VA_ARGS__,

#define CREATE_ENUM_CLASS(enum_name, values_generator)  \
    enum class enum_name                                \
    {                                                   \
        values_generator(enum_name, _CREATE_ENUM_VALUE) \
    };

#define _CREATE_CASE(enum_name, value, ...) \
    case enum_name::value:                  \
        os << #value;                       \
        break;

#define CREATE_OSTREAM_OPERATOR(enum_name, values_generator, logger)          \
    inline std::ostream &operator<<(std::ostream &os, enum_name enumVariable) \
    {                                                                         \
        switch (enumVariable)                                                 \
        {                                                                     \
            values_generator(enum_name, _CREATE_CASE);                        \
        default:                                                              \
            os << "Invalid enum value (" << enumVariable << ')';              \
            break;                                                            \
        }                                                                     \
        return os;                                                            \
    }

#define CREATE_ENUM_CLASS_OSTREAM(enum_name, values_generator) \
    CREATE_ENUM_CLASS(enum_name, values_generator)             \
    CREATE_OSTREAM_OPERATOR(enum_name, values_generator, logger)

#endif // ENUM_HELPER