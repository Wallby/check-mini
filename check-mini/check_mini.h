#ifndef CHECK_MINI_H
#define CHECK_MINI_H

// NOTE: e.g. CM_CHECK_VARIABLE_USING_CONDITIONS(a, MayNotBe0) ->..
//       .. conditions == E<CM_ENUMPREFIX2>CheckaCondition_MayNotBe0
//       ^
//       CM_ENUMPREFIX2 is always defined but unlike CM_ENUMPREFIX is empty..
//       .. if CM_ENUMPREFIX is not defined
//#define CM_ENUMPREFIX
// NOTE: if CM_FUNCTIONPREFIX is defined.. e.g. CM_CHECK_VARIABLE(a) ->..
//       .. <CM_FUNCTIONPREFIX>_check_a(<..>)
//       otherwise.. e.g. CM_CHECK_VARIABLE(a) -> check_a(<..>)
//#define CM_FUNCTIONPREFIX


// NOTE: CM_EMPTY should not be required, but is to work around empty..
//       .. argument causing __VA_OPT__ to not produce any output
#define CM_EMPTY

// NOTE: CM_NOT_* is a macrofunction not intended for direct use
//       CM_* (where * does not start with NOT_) is a macrofunction intended..
//       .. for direct use
// NOTE: every macrofunction intended for direct use always assures..
//       .. expansion (argument prescan) of every parameter

// NOTE: a and b are already expanded by CM_CONCATENATE
//       ## cancels argument prescan for both a and b
#define CM_NOT_CONCATENATE(a, b) a##b
// NOTE: different from a##b in that assured that expands a and b first
// NOTE: a and b are expanded during argument prescan
#define CM_CONCATENATE(a, b) CM_NOT_CONCATENATE(a, b)

// NOTE: __VA_ARGS__ is already expanded by CM_REMOVE_PARENTHESES
#define CM_NOT_REMOVE_PARENTHESES(...) __VA_ARGS__
// NOTE: e.g. CM_REMOVE_PARENTHESES((a, b, c)) == a, b, c
// NOTE: a is expanded during argument prescan
#define CM_REMOVE_PARENTHESES(a) CM_NOT_REMOVE_PARENTHESES a

#define CM_NOT_LENGTH_2 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
// NOTE: n is already expanded by CM_NOT_LENGTH
#define CM_NOT_LENGTH_1(a, b, c, d, e, f, g, h, i, j, n, ...) n
// NOTE: __VA_ARGS__[(lengthof __VA_ARGS__) - 1] (i.e...
//       .. CM_NOT_LENGTH_2) is expanded during argument prescan
//       rest of __VA_ARGS__ is already expanded by CM_LENGTH
#define CM_NOT_LENGTH(...) CM_NOT_LENGTH_1(__VA_ARGS__)
// NOTE: e.g. CM_LENGTH(a, b, c) == 3
// NOTE: __VA_ARGS__ is expanded during argument prescan
#define CM_LENGTH(...) CM_NOT_LENGTH(__VA_ARGS__ __VA_OPT__(,) CM_NOT_LENGTH_2)

// NOTE: CM_FIRST(a, b, c) == a
// NOTE: a is expanded during argument prescan
#define CM_FIRST(a, ...) a

// NOTE: CM_SECOND(a, b, c) == b
// NOTE: b is expanded during argument prescan
#define CM_SECOND(a, b, ...) b

#define CM_NOT_CONCATENATE_VA_ARGS_9(separator, parameter, ...) CM_CONCATENATE(parameter, __VA_OPT__(CM_CONCATENATE(separator,CM_NOT_CONCATENATE_VA_ARGS_10(separator, __VA_ARGS__))))
#define CM_NOT_CONCATENATE_VA_ARGS_8(separator, parameter, ...) CM_CONCATENATE(parameter, __VA_OPT__(CM_CONCATENATE(separator,CM_NOT_CONCATENATE_VA_ARGS_9(separator, __VA_ARGS__))))
#define CM_NOT_CONCATENATE_VA_ARGS_7(separator, parameter, ...) CM_CONCATENATE(parameter, __VA_OPT__(CM_CONCATENATE(separator,CM_NOT_CONCATENATE_VA_ARGS_8(separator, __VA_ARGS__))))
#define CM_NOT_CONCATENATE_VA_ARGS_6(separator, parameter, ...) CM_CONCATENATE(parameter, __VA_OPT__(CM_CONCATENATE(separator,CM_NOT_CONCATENATE_VA_ARGS_7(separator, __VA_ARGS__))))
#define CM_NOT_CONCATENATE_VA_ARGS_5(separator, parameter, ...) CM_CONCATENATE(parameter, __VA_OPT__(CM_CONCATENATE(separator,CM_NOT_CONCATENATE_VA_ARGS_6(separator, __VA_ARGS__))))
#define CM_NOT_CONCATENATE_VA_ARGS_4(separator, parameter, ...) CM_CONCATENATE(parameter, __VA_OPT__(CM_CONCATENATE(separator,CM_NOT_CONCATENATE_VA_ARGS_5(separator, __VA_ARGS__))))
#define CM_NOT_CONCATENATE_VA_ARGS_3(separator, parameter, ...) CM_CONCATENATE(parameter, __VA_OPT__(CM_CONCATENATE(separator,CM_NOT_CONCATENATE_VA_ARGS_4(separator, __VA_ARGS__))))
#define CM_NOT_CONCATENATE_VA_ARGS_2(separator, parameter, ...) CM_CONCATENATE(parameter, __VA_OPT__(CM_CONCATENATE(separator,CM_NOT_CONCATENATE_VA_ARGS_3(separator, __VA_ARGS__))))
// NOTE: separator, parameter and __VA_ARGS__ are already expanded by..
//       .. CM_CONCATENATE_VA_ARGS
//       ^
//       same applies to each of the above macrofunctions
#define CM_NOT_CONCATENATE_VA_ARGS_1(separator, parameter, ...) CM_CONCATENATE(parameter, __VA_OPT__(CM_CONCATENATE(separator,CM_NOT_CONCATENATE_VA_ARGS_2(separator, __VA_ARGS__))))
// NOTE: e.g. CM_CONCATENATE_VA_ARGS(_and_, a, b) == a_and_b
// NOTE: firstParameter, both separator copies, and __VA_ARGS__ are expanded..
//       .. during argument prescan
#define CM_CONCATENATE_VA_ARGS(separator, firstParameter, ...) CM_CONCATENATE(firstParameter, __VA_OPT__(CM_CONCATENATE(separator, CM_NOT_CONCATENATE_VA_ARGS_1(separator, __VA_ARGS__))))

#define CM_NOT_CONCATENATE_NUM_TIMES_9(separator, a) CM_CONCATENATE(a##separator, CM_NOT_CONCATENATE_NUM_TIMES_8(separator, a))
#define CM_NOT_CONCATENATE_NUM_TIMES_8(separator, a) CM_CONCATENATE(a##separator, CM_NOT_CONCATENATE_NUM_TIMES_7(separator, a))
#define CM_NOT_CONCATENATE_NUM_TIMES_7(separator, a) CM_CONCATENATE(a##separator, CM_NOT_CONCATENATE_NUM_TIMES_6(separator, a))
#define CM_NOT_CONCATENATE_NUM_TIMES_6(separator, a) CM_CONCATENATE(a##separator, CM_NOT_CONCATENATE_NUM_TIMES_5(separator, a))
#define CM_NOT_CONCATENATE_NUM_TIMES_5(separator, a) CM_CONCATENATE(a##separator, CM_NOT_CONCATENATE_NUM_TIMES_4(separator, a))
#define CM_NOT_CONCATENATE_NUM_TIMES_4(separator, a) CM_CONCATENATE(a##separator, CM_NOT_CONCATENATE_NUM_TIMES_3(separator, a))
#define CM_NOT_CONCATENATE_NUM_TIMES_3(separator, a) CM_CONCATENATE(a##separator, CM_NOT_CONCATENATE_NUM_TIMES_2(separator, a))
// NOTE: separator and a are already expanded by CM_NOT_CONCATENATE_NUM_TIMES
#define CM_NOT_CONCATENATE_NUM_TIMES_2(separator, a) CM_CONCATENATE(a##separator, CM_NOT_CONCATENATE_NUM_TIMES_1(separator, a))
// NOTE: a is already expanded by CM_NOT_CONCATENATE_NUM_TIMES
#define CM_NOT_CONCATENATE_NUM_TIMES_1(separator, a) a
// NOTE: separator numTimes and a are already expanded by..
//       .. CM_CONCATENATE_NUM_TIMES
//       ## cancels argument prescan for numTimes
#define CM_NOT_CONCATENATE_NUM_TIMES(separator, numTimes, a) CM_NOT_CONCATENATE_NUM_TIMES_##numTimes(separator, a) 
// NOTE: e.g. CM_CONCATENATE_NUM_TIMES(_and_, 3, int) -> int_and_int_and_int
// NOTE: separator, numTimes, and a are expanded during argument prescan
#define CM_CONCATENATE_NUM_TIMES(separator, numTimes, a) CM_NOT_CONCATENATE_NUM_TIMES(separator, numTimes, a)

#define CM_NOT_PREFIX_VA_ARGS_9(separator, prefix, parameter, ...) prefix##parameter __VA_OPT__(separator CM_NOT_PREFIX_VA_ARGS_10(separator, prefix, __VA_ARGS__))
#define CM_NOT_PREFIX_VA_ARGS_8(separator, prefix, parameter, ...) prefix##parameter __VA_OPT__(separator CM_NOT_PREFIX_VA_ARGS_9(separator, prefix, __VA_ARGS__))
#define CM_NOT_PREFIX_VA_ARGS_7(separator, prefix, parameter, ...) prefix##parameter __VA_OPT__(separator CM_NOT_PREFIX_VA_ARGS_8(separator, prefix, __VA_ARGS__))
#define CM_NOT_PREFIX_VA_ARGS_6(separator, prefix, parameter, ...) prefix##parameter __VA_OPT__(separator CM_NOT_PREFIX_VA_ARGS_7(separator, prefix, __VA_ARGS__))
#define CM_NOT_PREFIX_VA_ARGS_5(separator, prefix, parameter, ...) prefix##parameter __VA_OPT__(separator CM_NOT_PREFIX_VA_ARGS_6(separator, prefix, __VA_ARGS__))
#define CM_NOT_PREFIX_VA_ARGS_4(separator, prefix, parameter, ...) prefix##parameter __VA_OPT__(separator CM_NOT_PREFIX_VA_ARGS_5(separator, prefix, __VA_ARGS__))
#define CM_NOT_PREFIX_VA_ARGS_3(separator, prefix, parameter, ...) prefix##parameter __VA_OPT__(separator CM_NOT_PREFIX_VA_ARGS_4(separator, prefix, __VA_ARGS__))
#define CM_NOT_PREFIX_VA_ARGS_2(separator, prefix, parameter, ...) prefix##parameter __VA_OPT__(separator CM_NOT_PREFIX_VA_ARGS_3(separator, prefix, __VA_ARGS__))
// NOTE: separator, prefix and firstParameter are already expanded by..
//       .. CM_PREFIX_VA_ARGS
//       ## cancels argument prescan for prefix and firstParameter
#define CM_NOT_PREFIX_VA_ARGS_1(separator, prefix, firstParameter, ...) prefix##firstParameter  __VA_OPT__(separator CM_NOT_PREFIX_VA_ARGS_2(separator, prefix, __VA_ARGS__))
// NOTE: e.g. CM_PREFIX_VA_ARGS(+, ETest_, 0, 1) == ETest_0 + ETest_1
// NOTE: separator, prefix, firstParameter and __VA_ARGS__ are expanded..
//       .. during argument prescan
#define CM_PREFIX_VA_ARGS(separator, prefix, firstParameter, ...) CM_NOT_PREFIX_VA_ARGS_1(separator, prefix, firstParameter __VA_OPT__(,) __VA_ARGS__)

//************************ not intended for direct use ************************

// NOTE: a (i.e. CM_FUNCTIONPREFIX) is expanded during argument prescan
#define CM_NOT_NOT_FUNCTIONPREFIX_0(a) a
#define CM_NOT_NOT_FUNCTIONPREFIX_1(a)
#define CM_NOT_FUNCTIONPREFIX_CM_FUNCTIONPREFIX(...) , 0
// NOTE: if defined(CM_FUNCTIONPREFIX).. CM_CONCATENATE(..
//       ..CM_NOT_NOT_FUNCTIONPREFIX_, CM_LENGTH())(CM_FUNCTIONPREFIX)
//       otherwise.. CM_CONCATENATE(CM_NOT_NOT_FUNCTIONPREFIX_, CM_LENGTH(..
//       ..0))(CM_FUNCTIONPREFIX)
// NOTE: a and __VA_ARGS__ are already expanded by CM_NOT_FUNCTIONPREFIX
#define CM_NOT_FUNCTIONPREFIX_1(a, ...) CM_CONCATENATE(CM_NOT_NOT_FUNCTIONPREFIX_, CM_LENGTH(__VA_ARGS__))(CM_FUNCTIONPREFIX)
// NOTE: if defined(CM_FUNCTIONPREFIX).. CM_NOT_FUNCTIONPREFIX_1(..
//       .. CM_NOT_FUNCTIONPREFIX_<CM_FUNCTIONPREFIX>)
//       otherwise.. CM_NOT_FUNCTIONPREFIX_1(..
//       ..CM_NOT_FUNCTIONPREFIX_CM_FUNCTIONPREFIX)
// NOTE: a (i.e. CM_CONCATENATE(<..>) is expanded during argument prescan
#define CM_NOT_FUNCTIONPREFIX(a) CM_NOT_FUNCTIONPREFIX_1(a)
// NOTE: if defined(CM_FUNCTIONPREFIX).. CM_FUNCTIONPREFIX_2 ==..
//       .. <CM_FUNCTIONPREFIX>
//       if !defined(CM_FUNCTIONPREFIX).. CM_FUNCTIONPREFIX_2 == 
#define CM_FUNCTIONPREFIX2 CM_NOT_FUNCTIONPREFIX(CM_CONCATENATE(CM_NOT_FUNCTIONPREFIX_, CM_FUNCTIONPREFIX) ())

#define CM_NOT_NOT_ENUMPREFIX_0(a) a
#define CM_NOT_NOT_ENUMPREFIX_1(a)
#define CM_NOT_ENUMPREFIX_CM_ENUMPREFIX(...) , 0
#define CM_NOT_ENUMPREFIX_1(a, ...) CM_CONCATENATE(CM_NOT_NOT_ENUMPREFIX_, CM_LENGTH(__VA_ARGS__))(CM_ENUMPREFIX)
#define CM_NOT_ENUMPREFIX(a) CM_NOT_ENUMPREFIX_1(a)
// NOTE: if defined(CM_ENUMPREFIX).. CM_ENUMPREFIX_2 == <CM_ENUMPREFIX>
//       if !defined(CM_ENUMPREFIX).. CM_ENUMPREFIX_2 == 
// NOTE: copy of CM_FUNCTIONPREFIX2 with FUNCTION changed to ENUM
//       see CM_FUNCTIONPREFIX2 for documentation
#define CM_ENUMPREFIX2 CM_NOT_ENUMPREFIX(CM_CONCATENATE(CM_NOT_ENUMPREFIX_, CM_ENUMPREFIX) ())

// NOTE: e.g. CM_NOT_NOT_TYPENAME_0(int) -> int
// NOTE: type is already expanded by CM_NOT_TYPENAME_2
#define CM_NOT_NOT_TYPENAME_0(type) type
// NOTE: e.g...
//       .. CM_NOT_NOT_TYPENAME_1(struct a_t, a_t) -> a_t
//       .. CM_NOT_NOT_TYPENAME_1(enum ETest, ETest) -> ETest
// NOTE: typename is already expanded by CM_NOT_TYPENAME_2
#define CM_NOT_NOT_TYPENAME_1(type, typename) typename
// NOTE: e.g...
//       .. CM_NOT_TYPENAME_2(int, CM_NOT_TYPENAMEint) -> CM_CONCATENATE(..
//          ..CM_NOT_NOT_TYPENAME, CM_LENGTH())(int)
//       .. CM_NOT_TYPENAME_2(struct a_t, , a_t) -> CM_CONCATENATE(..
//          ..CM_NOT_NOT_TYPENAME, CM_LENGTH(a_t))(struct a_t, a_t)
// NOTE: type, a and __VA_ARGS__ are already expanded by CM_NOT_TYPENAME_1
#define CM_NOT_TYPENAME_2(type, a, ...) CM_CONCATENATE(CM_NOT_NOT_TYPENAME_, CM_LENGTH(__VA_ARGS__))(type __VA_OPT__(,) __VA_ARGS__)
// NOTE: e.g...
//       .. CM_NOT_TYPENAME_1(int, CM_NOT_TYPENAME_int) ->..
//          .. CM_NOT_TYPENAME_2(int, CM_NOT_TYPENAME_int)
//       .. CM_NOT_TYPENAME_1(struct a_t, CM_NOT_TYPENAME_struct) ->..
//          .. CM_NOT_TYPENAME_2(struct a_t, , CM_EMPTY)
// NOTE: type is already expanded by CM_NOT_TYPENAME
//       a (i.e. CM_NOT_TYPENAME_<type>) is expanded during argument prescan
// NOTE: CM_NOT_TYPENAME_2(type, a) is not identical as CM_NOT_TYPENAME_2..
//       .. has __VA_ARGS__
#define CM_NOT_TYPENAME_1(type, a) CM_NOT_TYPENAME_2(type, a)
#define CM_NOT_TYPENAME_struct , CM_EMPTY
#define CM_NOT_TYPENAME_enum , CM_EMPTY
// NOTE: e.g...
//       .. CM_NOT_TYPENAME(int) -> CM_NOT_TYPENAME_1(int,..
//          .. CM_NOT_TYPENAME_int)
//       .. CM_NOT_TYPENAME(struct a_t) -> CM_NOT_TYPENAME_2(struct a_t,..
//          .. CM_NOT_TYPENAME_struct a_t)
// NOTE: type is already expanded by CM_NOT_TYPENAME
//       ## cancels argument prescan for second type
// NOTE: CM_NOT_TYPENAME_##type won't conflict with..
//       .. CM_NOT_TYPENAME_<1/2/...> as type can never start with a number
#define CM_NOT_TYPENAME(type) CM_NOT_TYPENAME_1(type, CM_NOT_TYPENAME_##type)
// NOTE: e.g...
//       .. CM_TYPENAME(int) -> int
//       .. CM_TYPENAME(struct a_t) -> a_t
//       .. CM_TYPENAME(enum ETest) -> ETest
// NOTE: type is expanded during argument prescan
#define CM_TYPENAME(type) CM_NOT_TYPENAME(type)

// NOTE: e.g. CM_NOT_NOT_VARIABLENAME_0(a) -> a
// NOTE: variable is already expanded by CM_NOT_VARIABLENAME_3
#define CM_NOT_NOT_VARIABLENAME_0(variable) variable
// NOTE: e.g. CM_NOT_NOT_NOT_VARIABLENAME(CM_REMOVE_PARENTHESES(int, a)) ->..
//       .. CM_SECOND(int, a)
// NOTE: a (i.e. CM_REMOVE_PARENTHESES(<..>)) is expanded during argument..
//       .. prescan
#define CM_NOT_NOT_NOT_VARIABLENAME(a) CM_SECOND(a)
// NOTE: e.g. CM_NOT_NOT_VARIABLENAME_1((int, a)) ->..
//       .. CM_NOT_NOT_NOT_VARIABLENAME(CM_REMOVE_PARENTHESES((int, a)))
// NOTE: typeAndVariable is already expanded by CM_NOT_VARIABLENAME_3
// NOTE: CM_NOT_NOT_NOT_VARIABLENAME(<..>) is required here to expand..
//       .. CM_REMOVE_PARENTHESES(<..>) as CM_SECOND has __VA_ARGS__
#define CM_NOT_NOT_VARIABLENAME_1(typeAndVariable) CM_NOT_NOT_NOT_VARIABLENAME(CM_REMOVE_PARENTHESES(typeAndVariable))
// NOTE: e.g...
//       .. CM_NOT_VARIABLENAME_3(a, CM_NOT_VARIABLENAME_1 a) ->..
//          .. CM_CONCATENATE(CM_NOT_NOT_VARIABLENAME_, CM_LENGTH())(..
//          ..a)
//       .. CM_NOT_VARIABLENAME_3((int, a), , 0) -> CM_CONCATENATE(..
//          ..CM_NOT_NOT_VARIABLENAME_, CM_LENGTH(0))((int, a))
// NOTE: typeAndVariable, a, and __VA_ARGS__ are already expanded by CM_NOT_VARIABLENAME_2
#define CM_NOT_VARIABLENAME_3(typeAndVariable, a, ...) CM_CONCATENATE(CM_NOT_NOT_VARIABLENAME_, CM_LENGTH(__VA_ARGS__))(typeAndVariable)
// NOTE: e.g...
//       .. CM_NOT_VARIABLENAME_2(a, CM_NOT_VARIABLENAME_1 a) ->..
//          .. CM_NOT_VARIABLENAME_3(a, CM_NOT_VARIABLENAME_1 a)
//       .. CM_NOT_VARIABLENAME_2((int, a), CM_NOT_VARIABLENAME_1(int, a))..
//          .. -> CM_NOT_VARIABLENAME_3((int, a), , 0)
// NOTE: typeAndVariable is already expanded by CM_NOT_VARIABLENAME
//       a (i.e. CM_NOT_VARIABLENAME1 <typeAndVariable>) is expanded during..
//       .. argument prescan
// NOTE: CM_NOT_VARIABLENAME_3(type, a) is not identical as..
//       .. CM_NOT_VARIABLENAME_3 has __VA_ARGS__
#define CM_NOT_VARIABLENAME_2(typeAndVariable, a) CM_NOT_VARIABLENAME_3(typeAndVariable, a)
#define CM_NOT_VARIABLENAME_1(...) , 0
// NOTE: e.g...
//       .. CM_NOT_VARIABLENAME(a) -> CM_NOT_VARIABLENAME_2(a,..
//          .. CM_NOT_VARIABLENAME_1 a)
//       .. CM_NOT_VARIABLENAME((int, a)) -> CM_NOT_VARIABLENAME_2((int, a),..
//          .. CM_NOT_VARIABLENAME_1(int, a))
// NOTE: typeAndVariable is already expanded by CM_VARIABLENAME
#define CM_NOT_VARIABLENAME(typeAndVariable) CM_NOT_VARIABLENAME_2(typeAndVariable, CM_NOT_VARIABLENAME_1 typeAndVariable)
// NOTE: e.g...
//       .. CM_VARIABLENAME(a) -> a
//       .. CM_VARIABLENAME((int, a)) -> a
//       .. CM_VARIABLENAME((struct a_t, a)) -> a
//       .. CM_VARIABLENAME((enum ETest, a)) -> a
// NOTE: typeAndVariable is expanded during argument prescan
#define CM_VARIABLENAME(typeAndVariable) CM_NOT_VARIABLENAME(typeAndVariable)

#define CM_NOT_VARIABLENAMES_9(typeAndVariable, ...) CM_VARIABLENAME(typeAndVariable)__VA_OPT__(, CM_NOT_VARIABLENAMES_10(__VA_ARGS__))
#define CM_NOT_VARIABLENAMES_8(typeAndVariable, ...) CM_VARIABLENAME(typeAndVariable)__VA_OPT__(, CM_NOT_VARIABLENAMES_9(__VA_ARGS__))
#define CM_NOT_VARIABLENAMES_7(typeAndVariable, ...) CM_VARIABLENAME(typeAndVariable)__VA_OPT__(, CM_NOT_VARIABLENAMES_8(__VA_ARGS__))
#define CM_NOT_VARIABLENAMES_6(typeAndVariable, ...) CM_VARIABLENAME(typeAndVariable)__VA_OPT__(, CM_NOT_VARIABLENAMES_7(__VA_ARGS__))
#define CM_NOT_VARIABLENAMES_5(typeAndVariable, ...) CM_VARIABLENAME(typeAndVariable)__VA_OPT__(, CM_NOT_VARIABLENAMES_6(__VA_ARGS__))
#define CM_NOT_VARIABLENAMES_4(typeAndVariable, ...) CM_VARIABLENAME(typeAndVariable)__VA_OPT__(, CM_NOT_VARIABLENAMES_5(__VA_ARGS__))
#define CM_NOT_VARIABLENAMES_3(typeAndVariable, ...) CM_VARIABLENAME(typeAndVariable)__VA_OPT__(, CM_NOT_VARIABLENAMES_4(__VA_ARGS__))
#define CM_NOT_VARIABLENAMES_2(typeAndVariable, ...) CM_VARIABLENAME(typeAndVariable)__VA_OPT__(, CM_NOT_VARIABLENAMES_3(__VA_ARGS__))
// NOTE: firstTypeAndVariable and __VA_ARGS__ are already expanded by..
//       .. CM_VARIABLENAMES
//       ^
//       same applies to each of the above macrofunctions
#define CM_NOT_VARIABLENAMES_1(firstTypeAndVariable, ...) CM_VARIABLENAME(firstTypeAndVariable)__VA_OPT__(, CM_NOT_VARIABLENAMES_2(__VA_ARGS__))
// NOTE: first <type and variable>
// NOTE: e.g. CM_VARIABLENAMES(a, (int, b), (struct a_t, c), (enum ETest,..
//       .. d)) == a, b, c, d
// NOTE: firstTypeAndVariable and __VA_ARGS__ are expanded during argument..
//       .. prescan
// NOTE: for consistency calls CM_NOT_VARIABLENAMES_1 even though first..
//       .. iteration could happen here
#define CM_VARIABLENAMES(firstTypeAndVariable, ...) CM_NOT_VARIABLENAMES_1(firstTypeAndVariable __VA_OPT__(,) __VA_ARGS__)

// NOTE: e.g. CM_NOT_NOT_FUNCTIONNAMEPART_0(a) -> a
// NOTE: variable is already expanded by CM_NOT_FUNCTIONNAMEPART_2
#define CM_NOT_NOT_FUNCTIONNAMEPART_0(variable) variable
// NOTE: e.g. CM_NOT_NOT_FUNCTIONNAMEPART_1((int, a)) -> CM_TYPENAME(..
//       ..CM_FIRST(int, a))
// NOTE: typeAndVariable is already expanded by CM_NOT_FUNCTIONNAMEPART_2
#define CM_NOT_NOT_FUNCTIONNAMEPART_1(typeAndVariable) CM_TYPENAME(CM_FIRST typeAndVariable)
// NOTE: e.g...
//       .. CM_NOT_FUNCTIONNAMEPART_2(a, CM_NOT_FUNCTIONNAMEPART_1 a) ->..
//          .. CM_CONCATENATE(CM_NOT_NOT_FUNCTIONNAMEPART_, CM_LENGTH())(a)
//       .. CM_NOT_FUNCTIONNAMEPART_2((int, a), , 0) -> CM_CONCATENATE(..
//          ..CM_NOT_NOT_FUNCTIONNAMEPART_, CM_LENGTH(0))((int, a))
// NOTE: typeAndVariable, a and __VA_ARGS__ are already expanded by..
//       .. CM_NOT_FUNCTIONNAMEPART
#define CM_NOT_FUNCTIONNAMEPART_2(typeAndVariable, a, ...) CM_CONCATENATE(CM_NOT_NOT_FUNCTIONNAMEPART_, CM_LENGTH(__VA_ARGS__))(typeAndVariable)
#define CM_NOT_FUNCTIONNAMEPART_1(...) , 0
// NOTE: e.g...
//       .. CM_NOT_FUNCTIONNAMEPART(a, CM_NOT_FUNCTIONNAMEPART_1 a) ->..
//          .. CM_NOT_FUNCTIONNAMEPART_2(a, CM_NOT_FUNCTIONNAMEPART_1 a)
//       .. CM_NOT_FUNCTIONNAMEPART((int, a), CM_NOT_FUNCTIONNAMEPART_1(..
//          ..int, a)) -> CM_NOT_FUNCTIONNAMEPART_2(a, , 0)
// NOTE: typeAndVariable is already expanded by CM_FUNCTIONNAMEPART
//       a (i.e. CM_NOT_FUNCTIONNAMEPART_1 a) is expanded during argument..
//       .. prescan
// NOTE: CM_NOT_FUNCTIONNAMEPART_2(typeAndVariable, a) is not identical as..
//       .. CM_NOT_FUNCTIONNAMEPART_2 has __VA_ARGS__
#define CM_NOT_FUNCTIONNAMEPART(typeAndVariable, a) CM_NOT_FUNCTIONNAMEPART_2(typeAndVariable, a)
// NOTE: <functionname>part
// NOTE: e.g...
//       .. CM_FUNCTIONNAMEPART(a) -> a
//       .. CM_FUNCTIONNAMEPART((int, a)) -> int
//       .. CM_FUNCTIONNAMEPART((struct a_t, a)) -> a_t
// NOTE: both typeAndVariable copies are expanded during argument prescan
#define CM_FUNCTIONNAMEPART(typeAndVariable) CM_NOT_FUNCTIONNAMEPART(typeAndVariable, CM_NOT_FUNCTIONNAMEPART_1 typeAndVariable)

#define CM_NOT_FUNCTIONNAMEPARTS_9(typeAndVariable, ...) CM_FUNCTIONNAMEPART(typeAndVariable)__VA_OPT__(, CM_NOT_FUNCTIONNAMEPARTS_10(__VA_ARGS__))
#define CM_NOT_FUNCTIONNAMEPARTS_8(typeAndVariable, ...) CM_FUNCTIONNAMEPART(typeAndVariable)__VA_OPT__(, CM_NOT_FUNCTIONNAMEPARTS_9(__VA_ARGS__))
#define CM_NOT_FUNCTIONNAMEPARTS_7(typeAndVariable, ...) CM_FUNCTIONNAMEPART(typeAndVariable)__VA_OPT__(, CM_NOT_FUNCTIONNAMEPARTS_8(__VA_ARGS__))
#define CM_NOT_FUNCTIONNAMEPARTS_6(typeAndVariable, ...) CM_FUNCTIONNAMEPART(typeAndVariable)__VA_OPT__(, CM_NOT_FUNCTIONNAMEPARTS_7(__VA_ARGS__))
#define CM_NOT_FUNCTIONNAMEPARTS_5(typeAndVariable, ...) CM_FUNCTIONNAMEPART(typeAndVariable)__VA_OPT__(, CM_NOT_FUNCTIONNAMEPARTS_6(__VA_ARGS__))
#define CM_NOT_FUNCTIONNAMEPARTS_4(typeAndVariable, ...) CM_FUNCTIONNAMEPART(typeAndVariable)__VA_OPT__(, CM_NOT_FUNCTIONNAMEPARTS_5(__VA_ARGS__))
#define CM_NOT_FUNCTIONNAMEPARTS_3(typeAndVariable, ...) CM_FUNCTIONNAMEPART(typeAndVariable)__VA_OPT__(, CM_NOT_FUNCTIONNAMEPARTS_4(__VA_ARGS__))
#define CM_NOT_FUNCTIONNAMEPARTS_2(typeAndVariable, ...) CM_FUNCTIONNAMEPART(typeAndVariable)__VA_OPT__(, CM_NOT_FUNCTIONNAMEPARTS_3(__VA_ARGS__))
// NOTE: firstTypeAndVariable and __VA_ARGS__ are already expanded by..
//       .. CM_FUNCTIONNAMEPARTS
//       ^
///      same applies to each of the above macrofunctions
#define CM_NOT_FUNCTIONNAMEPARTS_1(firstTypeAndVariable, ...) CM_FUNCTIONNAMEPART(firstTypeAndVariable)__VA_OPT__(, CM_NOT_FUNCTIONNAMEPARTS_2(__VA_ARGS__))
// NOTE: first <type and variable>
// NOTE: e.g. CM_FUNCTIONNAMEPARTS(a, (int, b), (struct c_t, c)) -> a, int,..
//       .. struct c_t
// NOTE: firstTypeAndVariable and __VA_ARGS__ are expanded during argument..
//       .. prescan
// NOTE: for conistency calls CM_NOT_FUNCTIONNAMEPARTS_1 even though first..
//       .. iteration could happen here
#define CM_FUNCTIONNAMEPARTS(firstTypeAndVariable, ...) CM_NOT_FUNCTIONNAMEPARTS_1(firstTypeAndVariable __VA_OPT__(,) __VA_ARGS__)

// NOTE: functionname is already expanded by CM_NOT_PREFIX_FUNCTIONNAME
#define CM_NOT_PREFIX_FUNCTIONNAME_0(functionname) functionname
// NOTE: functionname is already expanded by CM_NOT_PREFIX_FUNCTIONNAME
//       ## cancels argument prescan for functionname
#define CM_NOT_PREFIX_FUNCTIONNAME_1(functionname) CM_CONCATENATE(CM_FUNCTIONPREFIX2, _##functionname)
// NOTE: functionname is already expanded by CM_PREFIX_FUNCTIONNAME
//       functionprefix (i.e. CM_FUNCTIONPREFIX2) is expanded during..
//       .. argument prescan
// NOTE: CM_LENGTH(functionprefix) is not identical t "CM_LENGTH(..
//       ..CM_FUNCTIONPREFIX2)" as CM_LENGTH has __VA_ARGS__
#define CM_NOT_PREFIX_FUNCTIONNAME(functionname, functionprefix) CM_CONCATENATE(CM_NOT_PREFIX_FUNCTIONNAME_, CM_LENGTH(functionprefix))(functionname)
// NOTE: if defined(CM_FUNCTIONPREFIX).. e.g. CM_PREFIX_FUNCTIONNAME(..
//       ..check_a) -> <CM_FUNCTIONPREFIX>_check_a
//       otherwise.. e.g. CM_PREFIX_FUNCTIONNAME(check_a) -> check_a
// NOTE: functionname is expanded during argument prescan
#define CM_PREFIX_FUNCTIONNAME(functionname) CM_NOT_PREFIX_FUNCTIONNAME(functionname, CM_FUNCTIONPREFIX2)

// NOTE: functionnameparts (i.e. CM_FUNCTIONNAMEPARTS(<..>)) is expanded..
//       .. during argument prescan
#define CM_NOT_FUNCTIONNAME(functionnameparts) CM_PREFIX_FUNCTIONNAME(CM_CONCATENATE(check_, CM_CONCATENATE_VA_ARGS(_and_, functionnameparts)))
// NOTE: if defined(CM_FUNCTIONPREFIX).. e.g. CM_FUNCTIONNAME(a, (int, b),..
//       .. (struct c_t, c)) -> <CM_FUNCTIONPREFIX>_check_a_and_int_and_c_t
//       otherwise.. e.g. CM_FUNCTIONNAME(a, (int, b), (struct c_t, c)) ->..
//       .. check_a_and_int_and_c_t
// NOTE: firstTypeAndVariable and __VA_ARGS__ expand during argument prescan
#define CM_FUNCTIONNAME(firstTypeAndVariable, ...) CM_NOT_FUNCTIONNAME(CM_FUNCTIONNAMEPARTS(firstTypeAndVariable __VA_OPT__(,) __VA_ARGS__))

// NOTE: functionnameparts (CM_FUNCTIONNAMEPARTS(<..>)) is expanded during..
//       .. argument prescan
#define CM_NOT_ENUMNAME_1(functionnameparts) CM_CONCATENATE(CM_CONCATENATE(CM_CONCATENATE(CM_CONCATENATE(E, CM_ENUMPREFIX2), Check), CM_CONCATENATE_VA_ARGS(And, functionnameparts)), Condition)
// NOTE: firstTypeAndVariable and __VA_ARGS__ are already expanded by..
//       .. CM_ENUMNAME
#define CM_NOT_ENUMNAME(firstTypeAndVariable, ...) CM_NOT_ENUMNAME_1(CM_FUNCTIONNAMEPARTS(firstTypeAndVariable __VA_OPT__(,) __VA_ARGS__))
// NOTE: e.g. CM_ENUMNAME(a, (int, b), (struct c_t, c)) ==..
//       .. E<CM_ENUMPREFIX>CheckaAndintAndc_tCondition
// NOTE: firstTypeAndVariable and __VA_ARGS__ are expanded during argument..
//       .. prescan
#define CM_ENUMNAME(firstTypeAndVariable, ...) CM_NOT_ENUMNAME(firstTypeAndVariable __VA_OPT__(,) __VA_ARGS__)

// NOTE: enumname is already expanded by CM_PREFIX_AND_SUFFIX_ENUMNAME
//       ## cancels argument prescan for enumname
#define CM_NOT_PREFIX_AND_SUFFIX_ENUMNAME(enumname) CM_CONCATENATE(CM_CONCATENATE(E, CM_ENUMPREFIX2), Check##enumname##Condition)
// NOTE: e.g. CM_PREFIX_AND_SUFFIX_ENUMNAME(aAndintAndc_t) ->..
//       .. E<CM_ENUMPREFIX>CheckaAndintAndc_tCondition
// NOTE: enumname is expanded during argument prescan
#define CM_PREFIX_AND_SUFFIX_ENUMNAME(enumname) CM_NOT_PREFIX_AND_SUFFIX_ENUMNAME(enumname)

// NOTE: CM_ENUMNAME_FROM_TYPE_AND_VARIABLES(int, a, b) ->..
//       .. E<CM_ENUMPREFIX2>CheckaAndbCondition
// NOTE: type, firstVariable and __VA_ARGS__ are expanded during argument..
//       .. prescan
#define CM_ENUMNAME_FROM_TYPE_AND_VARIABLES(type, firstVariable, ...) CM_PREFIX_AND_SUFFIX_ENUMNAME(CM_CONCATENATE_NUM_TIMES(And, CM_LENGTH(firstVariable __VA_OPT__(,) __VA_ARGS__), CM_FUNCTIONNAMEPART(type)))
// NOTE: type is already expanded by CM_ENUMNAME_FROM_TYPE_AND_VARIABLES2
//       a (i.e. CM_REMOVE_PARENTHESES(<..>)) is expanded during argument..
//       .. prescan
// NOTE: CM_ENUMNAME_FROM_TYPE_AND_VARIABLES(type, a) is not identical as..
//       .. CM_ENUMNAME_FROM_TYPE_AND_VARIABLES has __VA_ARGS__
#define CM_NOT_ENUMNAME_FROM_TYPE_AND_VARIABLES2(type, a) CM_ENUMNAME_FROM_TYPE_AND_VARIABLES(type, a)
// NOTE: e.g. CM_ENUMNAME_FROM_TYPE_AND_VARIABLES2(int, (a, b)) ==..
//       .. CM_ENUMNAME_FROM_TYPE_AND_VARIABLES(int, a, b)
// NOTE: type and variables are expanded during argument prescan
#define CM_ENUMNAME_FROM_TYPE_AND_VARIABLES2(type, variables) CM_NOT_ENUMNAME_FROM_TYPE_AND_VARIABLES2(type, CM_REMOVE_PARENTHESES(variables))

// NOTE: enumname and condition are already expanded by CM_NOT_CONDITION
//       ## cancels argument prescan for enumname and condition
#define CM_NOT_CONDITION_1(enumname, condition) enumname##_##condition
// NOTE: condition is already expanded by CM_CONDITION
//       enumname (i.e. CM_ENUMNAME(<..>)) is expanded during argument prescan
#define CM_NOT_CONDITION(enumname, condition) CM_NOT_CONDITION_1(enumname, condition)
// NOTE: e.g. CM_CONDITION((a, (int, b), (struct c_t, c)), aMayNotBe0) ->..
//       .. E<CM_ENUMPREFIX>CheckaAndintAndc_tCondition_aMayNotBe0
// NOTE: typesAndVariables and condition are expanded during argument prescan
#define CM_CONDITION(typesAndVariables, condition) CM_NOT_CONDITION(CM_ENUMNAME typesAndVariables, condition)

// NOTE: as using other CM_NOT_* here directly must assure that every..
//       .. parameter is fully expanded before calling for sanity
// NOTE: condition is already expanded by CM_CONDITION_FROM_TYPE_AND_VARIABLES
//       enumname (i.e. CM_ENUMNAME_FROM_TYPE_AND_VARIABLES2(<..>)) is..
//       .. expanded during argument prescan
#define CM_NOT_CONDITION_FROM_TYPE_AND_VARIABLES(enumname, condition) CM_NOT_CONDITION(enumname, condition)
// NOTE: type, variables, and condition are expanded during argument prescan
#define CM_CONDITION_FROM_TYPE_AND_VARIABLES(type, variables, condition) CM_NOT_CONDITION_FROM_TYPE_AND_VARIABLES(CM_ENUMNAME_FROM_TYPE_AND_VARIABLES2(type, variables), condition)

// NOTE: enumname and firstcondition are already expanded by CM_NOT_CONDITIONS
//       ## cancels argument prescan for enumname
#define CM_NOT_CONDITIONS_1(enumname, firstCondition, ...) CM_PREFIX_VA_ARGS(|, enumname##_, firstCondition __VA_OPT__(,) __VA_ARGS__)
// NOTE: firstCondition and __VA_ARGS__ are already expanded by CM_CONDITIONS
//       enumname (i.e. CM_ENUMNAME(<..>)) is expanded during argument prescan
#define CM_NOT_CONDITIONS(enumname, firstCondition, ...) CM_NOT_CONDITIONS_1(enumname, firstCondition __VA_OPT__(,) __VA_ARGS__)
// NOTE: e.g. CM_CONDITIONS((a,(int, b)), aMayNotBe0, intMayNotBe0) ==..
//       .. E<CM_ENUMPREFIX>CheckaAndintCondition_aMayNotBe0 |..
//       .. E<CM_ENUMPREFIX>CheckaAndintCondition_intMayNotBe0
// NOTE: typesAndVariables, firstCondition and __VA_ARGS__ are expanded..
//       .. during argument prescan
#define CM_CONDITIONS(typesAndVariables, firstCondition, ...) CM_NOT_CONDITIONS(CM_ENUMNAME typesAndVariables, firstCondition __VA_OPT__(,) __VA_ARGS__)
// NOTE: typesAndVariables are already expanded by CM_CONDITIONS2
//       a (i.e. CM_REMOVE_PARENTHESES(<..>)) is expanded during argument..
//       .. prescan
// NOTE: CM_CONDITIONS(typesAndVariables, a) is not identical as..
//       .. CM_CONDITIONS has __VA_ARGS__
#define CM_NOT_CONDITIONS2(typesAndVariables, a) CM_CONDITIONS(typesAndVariables, a)
// NOTE: e.g. CM_CONDITIONS2((a, (int, b)), (aMayNotBe0, intMayNotB0)) ==..
//       .. CM_CONDITIONS((a, (int, b)), aMayNotBe0, intMayNotBe0)
// NOTE: typesAndVariables and conditions are expanded during argument prescan
#define CM_CONDITIONS2(typesAndVariables, conditions) CM_NOT_CONDITIONS2(typesAndVariables, CM_REMOVE_PARENTHESES(conditions))

// NOTE: as using other CM_NOT_* here directly must assure that every..
//       .. parameter is fully expanded before calling for sanity
// NOTE: firstCondition and __VA_ARGS__ are already expanded by..
//       .. CM_CONDITIONS_FROM_TYPE_AND_VARIABLES
//       enumname (i.e. CM_ENUMNAME_FROM_TYPE_AND_VARIABLES2(<..>)) is..
//       .. expanded during argument prescan
#define CM_NOT_CONDITIONS_FROM_TYPE_AND_VARIABLES(enumname, firstCondition, ...) CM_NOT_CONDITIONS(enumname, firstCondition __VA_OPT__(,) __VA_ARGS__)
// NOTE: e.g. CM_CONDITIONS_FROM_TYPE_AND_VARIABLES(int, (a, b), aMayNotBe0,..
//       .. bMayNotBe0) ->..
//       .. E<CM_ENUMPREFIX2>CheckintAndintCondition_aMayNotBe0 |..
//       .. E<CM_ENUMPREFIX2>CheckintAndintCondition_bMayNotBe0
// NOTE: type, variables, firstCondition and __VA_ARGS__ are expanded during..
//       .. argument prescan
#define CM_CONDITIONS_FROM_TYPE_AND_VARIABLES(type, variables, firstCondition, ...) CM_NOT_CONDITIONS_FROM_TYPE_AND_VARIABLES(CM_ENUMNAME_FROM_TYPE_AND_VARIABLES2(type, variables), firstCondition __VA_OPT__(,) __VA_ARGS__)
// NOTE: type and variables are already expanded by..
//       .. CM_CONDITIONS_FROM_TYPE_AND_VARIABLES2
//       a (i.e. CM_REMOVE_PARENTHESES(<..>)) is expanded during argument..
//       .. prescan
// NOTE: CM_CONDITIONS_FROM_TYPE_AND_VARIABLES(type, variables, a) is not..
//       .. identical as CM_CONDITIONS_FROM_TYPE_AND_VARIABLES has __VA_ARGS__
#define CM_NOT_CONDITIONS_FROM_TYPE_AND_VARIABLES2(type, variables, a) CM_CONDITIONS_FROM_TYPE_AND_VARIABLES(type, variables, a)
// NOTE: e.g. CM_CONDITIONS_FROM_TYPE_AND_VARIABLES2(int, (a, b),..
//       .. (aMayNotBe0, bMayNotBe0)) ==..
//       .. CM_CONDITIONS_FROM_TYPE_AND_VARIABLES(int, (a, b), aMayNotBe0,..
//       .. bMayNotBe0)
// NOTE: type, variables and conditions are expanded during argument prescan
#define CM_CONDITIONS_FROM_TYPE_AND_VARIABLES2(type, variables, conditions) CM_NOT_CONDITIONS_FROM_TYPE_AND_VARIABLES2(type, variables, CM_REMOVE_PARENTHESES(conditions))

//******************************* functionnames *******************************

// NOTE: variable is already expanded by CM_CHECK_VARIABLE_FUNCTIONNAME
//       ## cancels argument prescan for variable
#define CM_NOT_CHECK_VARIABLE_FUNCTIONNAME(variable) CM_PREFIX_FUNCTIONNAME(check_##variable)
// NOTE: variable is expanded during argument prescan
#define CM_CHECK_VARIABLE_FUNCTIONNAME(variable) CM_NOT_CHECK_VARIABLE_FUNCTIONNAME(variable)

// NOTE: firstVariable and __VA_ARGS__ expand during argument prescan
#define CM_CHECK_VARIABLES_FUNCTIONNAME(firstVariable, ...) CM_PREFIX_FUNCTIONNAME(CM_CONCATENATE(check_, CM_CONCATENATE_VA_ARGS(_and_, firstVariable __VA_OPT__(,) __VA_ARGS__)))

// NOTE: typename is already expanded by..
//       .. CM_NOT_CHECK_VARIABLE_OF_TYPE_FUNCTIONNAME
//       ## cancels argument prescan for typename
#define CM_NOT_CHECK_VARIABLE_OF_TYPE_FUNCTIONNAME1(typename) CM_PREFIX_FUNCTIONNAME(check_##typename)
// NOTE: a (i.e. CM_TYPENAME(<..>)) is expanded during argument prescan
#define CM_NOT_CHECK_VARIABLE_OF_TYPE_FUNCTIONNAME(a) CM_NOT_CHECK_VARIABLE_OF_TYPE_FUNCTIONNAME1(a)
// NOTE: type is expanded during argument prescan
#define CM_CHECK_VARIABLE_OF_TYPE_FUNCTIONNAME(type) CM_NOT_CHECK_VARIABLE_OF_TYPE_FUNCTIONNAME(CM_TYPENAME(type))

// NOTE: variables and type expand during argument prescan
#define CM_CHECK_VARIABLES_OF_TYPE_FUNCTIONNAME(type, variables) CM_PREFIX_FUNCTIONNAME(CM_CONCATENATE(check_, CM_CONCATENATE_NUM_TIMES(_and_, CM_LENGTH variables, type)))

// NOTE: firstVariable and __VA_ARGS__ expand during argument prescan
#define CM_CHECK_VARIABLES_OF_TYPES_FUNCTIONNAME(firstTypeAndVariable, ...) CM_FUNCTIONNAME(firstTypeAndVariable __VA_OPT__(,) __VA_ARGS__)

//*****************************************************************************

// NOTE: e.g. CM_CHECK_VARIABLE(a, b) -> </CM_FUNCTIONPREFIX_>check_a(..
//       ..(char*)__FUNCTION__, a, b)
#define CM_CHECK_VARIABLE(variable, ...) CM_CHECK_VARIABLE_FUNCTIONNAME(variable)((char*)__FUNCTION__, variable __VA_OPT__(,) __VA_ARGS__)

// NOTE: e.g. CM_CHECK_VARIABLES((a, b), c) ->..
//       .. </CM_FUNCTIONPREFIX_>check_a_and_b((char*)__FUNCTION__, a, b, c)
#define CM_CHECK_VARIABLES(variables, ...) CM_CHECK_VARIABLES_FUNCTIONNAME variables((char*)__FUNCTION__, CM_REMOVE_PARENTHESES(variables) __VA_OPT__(,) __VA_ARGS__)

// NOTE: e.g. CM_CHECK_VARIABLE_OF_TYPE(int, a, b) ->..
//       .. </CM_FUNCTIONPREFIX_>check_int((char*)__FUNCTION__, a, b)
#define CM_CHECK_VARIABLE_OF_TYPE(type, variable, ...) CM_CHECK_VARIABLE_OF_TYPE_FUNCTIONNAME(type)((char*)__FUNCTION__, variable __VA_OPT__(,) __VA_ARGS__)
// NOTE: e.g. CM_CHECK_VARIABLES_OF_TYPE(int, (a, b), c) ->..
//       .. </CM_FUNCTIONPREFIX_>check_int_and_int((char*)__FUNCTION__, a,..
//       .. b, c)
#define CM_CHECK_VARIABLES_OF_TYPE(type, variables, ...) CM_CHECK_VARIABLES_OF_TYPE_FUNCTIONNAME(type, variables)((char*)__FUNCTION__, CM_REMOVE_PARENTHESES(variables) __VA_OPT__(,) __VA_ARGS__)
// NOTE: e.g. CM_CHECK_VARIABLES_OF_TYPES((a, (int, b), (struct c_t, c), (..
//       ..enum ED, d)), e) ->..
//       .. </CM_FUNCTIONPREFIX_>check_a_and_int_and_c_t_and_ED((char*)..
//       ..__FUNCTION__, a, b, c, d, e)
#define CM_CHECK_VARIABLES_OF_TYPES(typesAndVariables, ...) CM_CHECK_VARIABLES_OF_TYPES_FUNCTIONNAME typesAndVariables((char*)__FUNCTION__, CM_VARIABLENAMES typesAndVariables __VA_OPT__(,) __VA_ARGS__)

// NOTE: e.g. CM_CHECK_VARIABLE_USING_CONDITION(a, MayNotBe0, b) ->..
//       .. </CM_FUNCTIONPREFIX_>check_a((char*)__FUNCTION__, a,..
//       .. E<CM_ENUMPREFIX2>CheckaCondition_MayNotBe0, b)
#define CM_CHECK_VARIABLE_USING_CONDITION(variable, condition, ...) CM_CHECK_VARIABLE_FUNCTIONNAME(variable)((char*)__FUNCTION__, variable, CM_CONDITION((variable), condition) __VA_OPT__(,) __VA_ARGS__)
// NOTE: e.g. CM_CHECK_VARIABLE_USING_CONDITIONS(a, (MayNotBe0,..
//       .. MayNotBeLessThan0), b) -> </CM_FUNCTIONPREFIX_>check_a((char*)..
//       ..__FUNCTION__, a, E<CM_ENUMPREFIX2>CheckaCondition_MayNotBe0 |..
//       .. E<CM_ENUMPREFIX2>CheckaConditionMayNotBe0, b)
#define CM_CHECK_VARIABLE_USING_CONDITIONS(variable, conditions, ...) CM_CHECK_VARIABLE_USING_CONDITIONS2(variable, CM_CONDITIONS2((variable), conditions) __VA_OPT__(,) __VA_ARGS__)
// NOTE: same as CM_CHECK_VARIABLE_USING_CONDITIONS but conditions isn't..
//       .. parsed but directly supplied
#define CM_CHECK_VARIABLE_USING_CONDITIONS2(variable, conditions, ...) CM_CHECK_VARIABLE_FUNCTIONNAME(variable)((char*)__FUNCTION__, variable, conditions __VA_OPT__(,) __VA_ARGS__)
// NOTE: e.g. CM_CHECK_VARIABLES_USING_CONDITION((a, b), aMayNotBe0, c) ->..
//       .. </CM_FUNCTIONPREFIX_>check_a_and_b((char*)__FUNCTION__,..
//       .. E<CM_ENUMPREFIX2>CheckaAndbCondition_aMayNotBe0)
#define CM_CHECK_VARIABLES_USING_CONDITION(variables, condition, ...) CM_CHECK_VARIABLES_FUNCTIONNAME variables((char*)__FUNCTION__, CM_REMOVE_PARENTHESES(variables), CM_CONDITION(variables, condition) __VA_OPT__(,) __VA_ARGS__)
// NOTE: e.g. CM_CHECK_VARIABLES_USING_CONDITIONS((a, b), (aMayNotBe0,..
//       .. bMayNotBe0), c) -> </CM_FUNCTIONPREFIX_>check_a_and_b((char*)..
//       ..__FUNCTION__, a, b,..
//       .. E<CM_ENUMPREFIX2>CheckaAndbCondition_aMayNotBe0 |..
//       .. E<CM_ENUMPREFIX2>_CheckaAndbCondition_bMayNotBe0, c)
#define CM_CHECK_VARIABLES_USING_CONDITIONS(variables, conditions, ...) CM_CHECK_VARIABLES_USING_CONDITIONS2(variables, CM_CONDITIONS2(variables, conditions) __VA_OPT__(,) __VA_ARGS__)
// NOTE: same as CM_CHECK_VARIABLES_USING_CONDITIONS but conditions isn't..
//       .. parsed but directly supplied
#define CM_CHECK_VARIABLES_USING_CONDITIONS2(variables, conditions, ...) CM_CHECK_VARIABLES_FUNCTIONNAME variables((char*)__FUNCTION__, CM_REMOVE_PARENTHESES(variables), conditions __VA_OPT__(,) __VA_ARGS__)
// NOTE: e.g. CM_CHECK_VARIABLE_OF_TYPE_USING_CONDITION(int, a, MayNotbe0,..
//       .. b) -> </CM_FUNCTIONPREFIX_>check_int((char*)__FUNCTION__, a,..
//       .. E<CM_ENUMPREFIX2>CheckintCondition_MayNotBe0, b)
#define CM_CHECK_VARIABLE_OF_TYPE_USING_CONDITION(type, variable, condition, ...) CM_CHECK_VARIABLE_OF_TYPE_FUNCTIONNAME(type)((char*)__FUNCTION__, variable, CM_CONDITION(((type, variable)), condition) __VA_OPT__(,) __VA_ARGS__)
// NOTE: e.g. CM_CHECK_VARIABLE_OF_TYPE_USING_CONDITIONS(int, a, (MayNotBe0,..
//       .. MayNotBeLessThan0), b) -> </CM_FUNCTIONPREFIX_>check_int((char*)..
//       ..__FUNCTION__, a, E<CM_ENUMPREFIX2>CheckintCondition_MayNotBe0 |..
//       .. E<CM_ENUMPREFIX2>CheckintCondition_MayNotBeLessThan0, b)
#define CM_CHECK_VARIABLE_OF_TYPE_USING_CONDITIONS(type, variable, conditions, ...) CM_CHECK_VARIABLE_OF_TYPE_USING_CONDITIONS2(type, variable, CM_CONDITIONS2(((type, variable)), conditions) __VA_OPT__(,) __VA_ARGS__)
// NOTE: same as CM_CHECK_VARIABLE_OF_TYPE_USING_CONDITION(S) but conditions..
//       .. isn't parsed but directly supplied
#define CM_CHECK_VARIABLE_OF_TYPE_USING_CONDITIONS2(type, variable, conditions, ...) CM_CHECK_VARIABLE_OF_TYPE_FUNCTIONNAME(type)((char*)__FUNCTION__, variable, conditions __VA_OPT__(,) __VA_ARGS__)
// NOTE: e.g. CM_CHECK_VARIABLES_OF_TYPE_USING_CONDITION(int, (a, b),..
//       .. firstIntMayNotBe0, c) -> </CM_FUNCTIONPREFIX>check_int_and_int(..
//       ..(char*)__FUNCTION__, a, b,..
//       .. E<CM_ENUMPREFIX2>CheckintAndintCondition_firstIntMayNotBe0, c)
#define CM_CHECK_VARIABLES_OF_TYPE_USING_CONDITION(type, variables, condition, ...) CM_CHECK_VARIABLES_OF_TYPE_FUNCTIONNAME(type, variables)((char*)__FUNCTION__, CM_REMOVE_PARENTHESES(variables), CM_CONDITION_FROM_TYPE_AND_VARIABLES(type, variables, condition) __VA_OPT__(,) __VA_ARGS__)
// NOTE: e.g. CM_CHECK_VARIABLES_OF_TYPE_USING_CONDITIONS(int, (a, b),..
//       .. (firstIntMayNotBe0, secondIntMayNotBe0), c) ->..
//       .. </CM_FUNCTIONPREFIX2>check_int_and_int((char*)__FUNCTION__, a,..
//       .. b, E<CM_ENUMPREFIX2>CheckintAndintCondition_firstIntMayNotBe0,..
//       .. E<CM_ENUMPREFIX2>CheckintAndintCondition_secondIntMayNotBe0, c)
#define CM_CHECK_VARIABLES_OF_TYPE_USING_CONDITIONS(type, variables, conditions, ...) CM_CHECK_VARIABLES_OF_TYPE_USING_CONDITIONS2(type, variables, CM_CONDITIONS_FROM_TYPE_AND_VARIABLES2(type, variables, conditions) __VA_OPT__(,) __VA_ARGS__)
// NOTE: same as CM_CHECK_VARIABLE_OF_TYPE_USING_CONDITIONS but conditions..
// ..  isn't parsed but directly supplied
#define CM_CHECK_VARIABLES_OF_TYPE_USING_CONDITIONS2(type, variables, conditions, ...) CM_CHECK_VARIABLES_OF_TYPE_FUNCTIONNAME(type, variables)((char*)__FUNCTION__, CM_REMOVE_PARENTHESES(variables), conditions __VA_OPT__(,) __VA_ARGS__) 
// NOTE: e.g. CM_CHECK_VARIABLES_OF_TYPES_USING_CONDITION((a, (int, b)),..
//       .. aMayNotBe0, c) -> </CM_FUNCTIONPREFIX_>check_a_and_int((char*)..
//       ..__FUNCTION__, a, b,..
//       .. E<CM_ENUMPREFIX2>CheckaAndintCondition_aMayNotBe0, c)
#define CM_CHECK_VARIABLES_OF_TYPES_USING_CONDITION(typesAndVariables, condition, ...) CM_CHECK_VARIABLES_OF_TYPES_FUNCTIONNAME typesAndVariables((char*)__FUNCTION__, CM_VARIABLENAMES typesAndVariables, CM_CONDITION(typesAndVariables, condition) __VA_OPT__(,) __VA_ARGS__)
// NOTE: e.g. CM_CHECK_VARIABLES_OF_TYPES_USING_CONDITIONS((a, (int, b)),..
//       .. aMayNotBe0, intMayNotBe0, c) ->..
//       .. </CM_FUNCTIONPREFIX_>check_a_and_int((char*)__FUNCTION__, a, b,..
//       .. E<CM_ENUMPREFIX2>CheckaAndintCondition_aMayNotBe0 |..
//       .. E<CM_ENUMPREFIX2>CheckaAndintCondition_intMayNotBe0, c)
#define CM_CHECK_VARIABLES_OF_TYPES_USING_CONDITIONS(typesAndVariables, conditions, ...) CM_CHECK_VARIABLES_OF_TYPES_USING_CONDITIONS2(typesAndVariables, CM_CONDITIONS2(typesAndVariables, conditions) __VA_OPT__(,) __VA_ARGS__)
// NOTE: same as CM_CHECK_VARIABLES_OF_TYPES_USING_CONDITIONS but conditions..
//       .. isn't parsed but directly supplied
#define CM_CHECK_VARIABLES_OF_TYPES_USING_CONDITIONS2(typesAndVariables, conditions, ...) CM_CHECK_VARIABLES_OF_TYPES_FUNCTIONNAME typesAndVariables((char*)__FUNCTION__, CM_VARIABLENAMES typesAndVariables, conditions  __VA_OPT__(,) __VA_ARGS__) 

#endif