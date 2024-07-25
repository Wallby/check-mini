#include "check_mini.h"

#include <test_mini.h>

#include <stdio.h>
#include <string.h>


#define NOT_STRINGIFY(...) #__VA_ARGS__
#define STRINGIFY(a) NOT_STRINGIFY(a)

enum
{
	EC_A = 0,
	EC_B,
	EC_C
};

struct b_t
{
	int a;
};

//*****************************************************************************

int check_a(char* functionname, int a, char* d)
{
	if(functionname == NULL)
	{
		fprintf(stderr, "error: functionname == NULL in %s\n", __FUNCTION__);
		return 0;
	}
	if(strcmp(functionname, "test_1") != 0)
	{
		fprintf(stderr, "error: functionname != \"test_1\" in %s\n", __FUNCTION__);
		return 0;
	}
	// ^
	// only check these once in this first CM_CHECK_VARIABLE* call
	
	if(a != 1)
	{
		fprintf(stderr, "error: a != 1 in %s\n", __FUNCTION__);
		return 0;
	}
	if(d == NULL)
	{
		fprintf(stderr, "error d == NULL in %s\n", __FUNCTION__);
		return 0;
	}
	if(strcmp(d, "test") != 0)
	{
		fprintf(stderr, "error: d != \"test\" in %s\n", __FUNCTION__);
		return 0;
	}
	
	return 1;
}

int check_a_and_b(char* functionname, int a, int b, char* d)
{
	if(a != 1)
	{
		fprintf(stderr, "error: a != 1 in %s\n", __FUNCTION__);
		return 0;
	}
	if(b != 2)
	{
		fprintf(stderr, "error: b != 2 in %s\n", __FUNCTION__);
		return 0;
	}
	if(d == NULL)
	{
		fprintf(stderr, "error: d == NULL in %s\n", __FUNCTION__);
		return 0;
	}
	if(strcmp(d, "test") != 0)
	{
		fprintf(stderr, "error: d != \"test\" in %s\n", __FUNCTION__);
		return 0;
	}
	
	return 1;
}

int check_a_and_b_and_c(char* functionname, int a, int b, int c, char* d)
{
	if(a != 1)
	{
		fprintf(stderr, "error: a != 1 in %s\n", __FUNCTION__);
		return 0;
	}
	if(b != 2)
	{
		fprintf(stderr, "error: b != 2 in %s\n", __FUNCTION__);
		return 0;
	}
	if(c != 3)
	{
		fprintf(stderr, "error: c != 3 in %s\n", __FUNCTION__);
		return 0;
	}
	if(d == NULL)
	{
		fprintf(stderr, "error: d == NULL in %s\n", __FUNCTION__);
	}
	if(strcmp(d, "test") != 0)
	{
		fprintf(stderr, "error: d != \"test\" in %s\n", __FUNCTION__);
		return 0;
	}
	
	return 1;
}

// NOTE: tests..
//       .. CM_CHECK_VARIABLE(S)
//       .. CM_FUNCTIONPREFIX undefined
int test_1()
{
	int a = 1;
	int b = 2;
	int c = 3;
	char d[] = "test";
	
#define TEST(check, a) \
	if(check == 0) \
	{ \
		fprintf(stderr, "error: " #check " == 0 in %s\n", __FUNCTION__); \
		return 0; \
	} \
	if(strcmp(STRINGIFY(check), a) != 0) \
	{ \
		fprintf(stderr, "error: " #check " != " a " (" #check " == " STRINGIFY(check) ") in %s\n", __FUNCTION__); \
		return 0; \
	}
	
	//                                           space caused by __VA_OPT__(,)
	//                                                           v
	TEST(CM_CHECK_VARIABLE(a, d), "check_a((char*)__FUNCTION__, a , d)")
	// ^
	// identical to above..
	TEST(CM_CHECK_VARIABLES((a), d), "check_a((char*)__FUNCTION__, a , d)")

	TEST(CM_CHECK_VARIABLES((a, b), d), "check_a_and_b((char*)__FUNCTION__, a, b , d)")
	TEST(CM_CHECK_VARIABLES((a, b, c), d), "check_a_and_b_and_c((char*)__FUNCTION__, a, b, c , d)")
	
	return 1;
}

int test_2_check_int(char* functionname, int a, char* d)
{
	return 1;
}

int test_2_check_int_and_int(char* functionname, int a, int b, char* d)
{
	return 1;
}

int test_2_check_int_and_int_and_int(char* functionname, int a, int b, int c, char* d)
{
	return 1;
}

// NOTE: tests..
//       .. CM_CHECK_VARIABLE(S)_OF_TYPE
//       .. CM_FUNCTIONPREFIX defined
int test_2()
{
	int a;
	int b;
	int c;
	char* d;
	
#define CM_FUNCTIONPREFIX test_2

	TEST(CM_CHECK_VARIABLE_OF_TYPE(int, a, d), "test_2_check_int((char*)__FUNCTION__, a , d)")
	TEST(CM_CHECK_VARIABLES_OF_TYPE(int, (a, b), d), "test_2_check_int_and_int((char*)__FUNCTION__, a, b , d)")
	TEST(CM_CHECK_VARIABLES_OF_TYPE(int, (a, b, c), d), "test_2_check_int_and_int_and_int((char*)__FUNCTION__, a, b, c , d)")

#undef CM_FUNCTIONPREFIX
	
	return 1;
}

int test_3_check_int(char* functionname, int a, char* d)
{
	return 1;
}

int test_3_check_int_and_b_t(char* functionname, int a, struct b_t b, char* d)
{
	return 1;
}

int test_3_check_int_and_b_t_and_EC(char* functionname, int a, struct b_t b, int c, char* d)
{
	return 1;
}

// NOTE: tests CM_CHECK_VARIABLES_OF_TYPES
int test_3()
{
	int a;
	struct b_t b;
	int c;
	char* d;
	
#define CM_FUNCTIONPREFIX test_3

	TEST(CM_CHECK_VARIABLES_OF_TYPES(((int, a)), d), "test_3_check_int((char*)__FUNCTION__, a , d)")
	TEST(CM_CHECK_VARIABLES_OF_TYPES(((int, a), (struct b_t, b)), d), "test_3_check_int_and_b_t((char*)__FUNCTION__, a, b , d)")
	TEST(CM_CHECK_VARIABLES_OF_TYPES(((int, a), (struct b_t, b), (enum EC, c)), d), "test_3_check_int_and_b_t_and_EC((char*)__FUNCTION__, a, b, c , d)")
	
#undef CM_FUNCTIONPREFIX
	
	return 1;
}

enum
{
	ECheckaCondition_MayNotBe0 = 1,
	ECheckaCondition_MayNotBeLessThan0 = 2
};

enum
{
	ECheckaAndbCondition_aMayNotBe0 = 1,
	ECheckaAndbCondition_bDotaMayNotBe0 = 2
};

int test_4_check_a(char* functionname, int a, int conditions, char* c)
{
	return 1;
}

int test_4_check_a_and_b(char* functionname, int a, struct b_t b, int conditions, char* c)
{
	return 1;
}

// NOTE: tests..
//       .. CM_CHECK_VARIABLE(S)_USING_CONDITION(S)
//       .. CM_ENUMPREFIX undefined
int test_4()
{
	int a = 123;
	struct b_t b = { .a = 456 };
	char c[] = "test";

#define CM_FUNCTIONPREFIX test_4

	TEST(CM_CHECK_VARIABLE_USING_CONDITION(a, MayNotBe0, c), "test_4_check_a((char*)__FUNCTION__, a, ECheckaCondition_MayNotBe0 , c)")
	// ^
	// identical to above..
	TEST(CM_CHECK_VARIABLE_USING_CONDITIONS(a, (MayNotBe0), c), "test_4_check_a((char*)__FUNCTION__, a, ECheckaCondition_MayNotBe0 , c)")
	
	TEST(CM_CHECK_VARIABLE_USING_CONDITIONS(a, (MayNotBe0, MayNotBeLessThan0), c), "test_4_check_a((char*)__FUNCTION__, a, ECheckaCondition_MayNotBe0 | ECheckaCondition_MayNotBeLessThan0 , c)")
	TEST(CM_CHECK_VARIABLES_USING_CONDITION((a, b), aMayNotBe0, c), "test_4_check_a_and_b((char*)__FUNCTION__, a, b, ECheckaAndbCondition_aMayNotBe0 , c)")
	// ^
	// identical to above..
	TEST(CM_CHECK_VARIABLES_USING_CONDITIONS((a, b), (aMayNotBe0), c), "test_4_check_a_and_b((char*)__FUNCTION__, a, b, ECheckaAndbCondition_aMayNotBe0 , c)")
	
	TEST(CM_CHECK_VARIABLES_USING_CONDITIONS((a, b), (aMayNotBe0, bDotaMayNotBe0), c), "test_4_check_a_and_b((char*)__FUNCTION__, a, b, ECheckaAndbCondition_aMayNotBe0 | ECheckaAndbCondition_bDotaMayNotBe0 , c)")
	
	TEST(CM_CHECK_VARIABLE_USING_CONDITIONS2(a, 0, c), "test_4_check_a((char*)__FUNCTION__, a, 0 , c)")
	TEST(CM_CHECK_VARIABLES_USING_CONDITIONS2((a, b), 0, c), "test_4_check_a_and_b((char*)__FUNCTION__, a, b, 0 , c)")

#undef CM_FUNCTIONPREFIX
	
	return 1;
}

enum
{
	ETest5CheckintCondition_MayNotBe0 = 1,
	ETest5CheckintCondition_MayNotBeLessThan0 = 2
};

enum
{
	ETest5CheckintAndintCondition_firstIntMayNotBe0 = 1,
	ETest5CheckintAndintCondition_secondIntMayNotBe0 = 2
};

int test_5_check_int(char* functionname, int a, int conditions, char* c)
{
	
	return 1;
}
int test_5_check_int_and_int(char* functionname, int a, int b, int conditions, char* c)
{

	return 1;
}

// NOTE: tests CM_CHECK_VARIABLE(S)_OF_TYPE_USING_CONDITION(S)
int test_5()
{
	int a;
	int b;
	char c[] = "test";

#define CM_FUNCTIONPREFIX test_5
#define CM_ENUMPREFIX Test5

	TEST(CM_CHECK_VARIABLE_OF_TYPE_USING_CONDITION(int, a, MayNotBe0, c), "test_5_check_int((char*)__FUNCTION__, a, ETest5CheckintCondition_MayNotBe0 , c)")
	// ^
	// identical to above..
	TEST(CM_CHECK_VARIABLES_OF_TYPE_USING_CONDITION(int, (a), MayNotBe0, c), "test_5_check_int((char*)__FUNCTION__, a, ETest5CheckintCondition_MayNotBe0 , c)")
	TEST(CM_CHECK_VARIABLE_OF_TYPE_USING_CONDITIONS(int, a, (MayNotBe0), c), "test_5_check_int((char*)__FUNCTION__, a, ETest5CheckintCondition_MayNotBe0 , c)")
	TEST(CM_CHECK_VARIABLES_OF_TYPE_USING_CONDITIONS(int, (a), (MayNotBe0), c), "test_5_check_int((char*)__FUNCTION__, a, ETest5CheckintCondition_MayNotBe0 , c)")
	
	TEST(CM_CHECK_VARIABLE_OF_TYPE_USING_CONDITIONS(int, a, (MayNotBe0, MayNotBeLessThan0), c), "test_5_check_int((char*)__FUNCTION__, a, ETest5CheckintCondition_MayNotBe0 | ETest5CheckintCondition_MayNotBeLessThan0 , c)")
	
	TEST(CM_CHECK_VARIABLES_OF_TYPE_USING_CONDITION(int, (a, b), firstIntMayNotBe0, c), "test_5_check_int_and_int((char*)__FUNCTION__, a, b, ETest5CheckintAndintCondition_firstIntMayNotBe0 , c)")
	// ^
	// identical to above..
	TEST(CM_CHECK_VARIABLES_OF_TYPE_USING_CONDITIONS(int, (a, b), (firstIntMayNotBe0), c), "test_5_check_int_and_int((char*)__FUNCTION__, a, b, ETest5CheckintAndintCondition_firstIntMayNotBe0 , c)")
	
	TEST(CM_CHECK_VARIABLES_OF_TYPE_USING_CONDITIONS(int, (a, b), (firstIntMayNotBe0, secondIntMayNotBe0), c), "test_5_check_int_and_int((char*)__FUNCTION__, a, b, ETest5CheckintAndintCondition_firstIntMayNotBe0 | ETest5CheckintAndintCondition_secondIntMayNotBe0 , c)")

	TEST(CM_CHECK_VARIABLE_OF_TYPE_USING_CONDITIONS2(int, a, 0, c), "test_5_check_int((char*)__FUNCTION__, a, 0 , c)")
	TEST(CM_CHECK_VARIABLES_OF_TYPE_USING_CONDITIONS2(int, (a, b), 0, c), "test_5_check_int_and_int((char*)__FUNCTION__, a, b, 0 , c)")
	
#undef CM_FUNCTIONPREFIX
#undef CM_ENUMPREFIX
	
	return 1;
}

enum
{
	ETest6CheckintAndb_tCondition_intMayNotBe0 = 1,
	ETest6CheckintAndb_tCondition_b_tDotaMayNotBe0 = 2
};

int test_6_check_int_and_b_t(char* functionname, int a, struct b_t b, int conditions, char* c)
{
	return 1;
}

// NOTE: tests..
//       .. CM_CHECK_VARIABLE(S)_OF_TYPES_USING_CONDITION(S)
//       .. CM_ENUMPREFIX defined
int test_6()
{
	int a;
	struct b_t b;
	char c[] = "test";

#define CM_FUNCTIONPREFIX test_6
#define CM_ENUMPREFIX Test6

	TEST(CM_CHECK_VARIABLES_OF_TYPES_USING_CONDITION(((int, a), (struct b_t, b)), intMayNotBe0, c), "test_6_check_int_and_b_t((char*)__FUNCTION__, a, b, ETest6CheckintAndb_tCondition_intMayNotBe0 , c)")
	// ^
	// identical to above..
	TEST(CM_CHECK_VARIABLES_OF_TYPES_USING_CONDITIONS(((int, a), (struct b_t, b)), (intMayNotBe0), c), "test_6_check_int_and_b_t((char*)__FUNCTION__, a, b, ETest6CheckintAndb_tCondition_intMayNotBe0 , c)")
	
	TEST(CM_CHECK_VARIABLES_OF_TYPES_USING_CONDITIONS(((int, a), (struct b_t, b)), (intMayNotBe0, b_tDotaMayNotBe0), c), "test_6_check_int_and_b_t((char*)__FUNCTION__, a, b, ETest6CheckintAndb_tCondition_intMayNotBe0 | ETest6CheckintAndb_tCondition_b_tDotaMayNotBe0 , c)")

	TEST(CM_CHECK_VARIABLES_OF_TYPES_USING_CONDITIONS2(((int, a), (struct b_t, b)), 0, c), "test_6_check_int_and_b_t((char*)__FUNCTION__, a, b, 0 , c)")
	
#undef CM_FUNCTIONPREFIX
#undef CM_ENUMPREFIX
	
	return 1;
}

#undef TEST

//*****************************************************************************

int main(int argc, char** argv)
{
	TM_TEST2(1);
	TM_TEST2(2);
	TM_TEST2(3);
	TM_TEST2(4);
	TM_TEST2(5);
	TM_TEST2(6);
	
	return 0;
}
